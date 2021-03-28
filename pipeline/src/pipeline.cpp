#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <forward_list>
#include <optional>

using namespace std;


struct Email {
  string from;
  string to;
  string body;
};


class Worker {
public:
  virtual ~Worker() = default;
  virtual void Process(unique_ptr<Email> email) = 0;
  virtual void Run() {
    // только первому worker-у в пайплайне нужно это имплементировать
    throw logic_error("Unimplemented");
  }

protected:
  // реализации должны вызывать PassOn, чтобы передать объект дальше
  // по цепочке обработчиков
  void PassOn(unique_ptr<Email> email) const {
	  if (next_) {
		  next_.value()->Process(move(email));
	  }
  }

public:
  void SetNext(unique_ptr<Worker> next) {
	  next_ = move(next);
  }
private:
  optional<unique_ptr<Worker>> next_;
};


class Reader : public Worker {
public:
  Reader(istream& is):is_(is) {
  }

  virtual void Run() override {
	  string from, to , body;
	  while (getline(is_, from) && getline(is_, to) && getline(is_, body))
	  {
		  auto u_ptr = make_unique<Email>();
		  u_ptr->from = from;
		  u_ptr->to = to;
		  u_ptr->body = body;
		  Process(move(u_ptr));
	  }
  }

  virtual void Process(unique_ptr<Email> email) override {
	  PassOn(move(email));
  }

private:
  istream& is_;
};


class Filter : public Worker {
public:
  using Function = function<bool(const Email&)>;

public:
  Filter(Function function):pred(function){
  }

  virtual void Process(unique_ptr<Email> email) override {
  	  if (pred(*email)) PassOn(move(email));
    }
private:
  Function pred;
};


class Copier : public Worker {
public:
	Copier(string to):to_(to) {
	}

	virtual void Process(unique_ptr<Email> email) override {
		if (to_ != email->to) {
		  auto u_ptr = make_unique<Email>();
		  u_ptr->from = email->from;
		  u_ptr->to = to_;
		  u_ptr->body = email->body;
		  PassOn(move(email));
		  PassOn(move(u_ptr));
		} else {
		PassOn(move(email));
		}
	}
private:
	string to_;
};


class Sender : public Worker {
public:
	Sender(ostream& os):os_(os) {
	}
	virtual void Process(unique_ptr<Email> email) override {
		os_ << email->from << endl;
		os_ << email->to << endl;
		os_ << email->body << endl;
		PassOn(move(email));
	}
private:
	ostream& os_;
};


// реализуйте класс
class PipelineBuilder {
public:
  // добавляет в качестве первого обработчика Reader
  explicit PipelineBuilder(istream& in):chain(make_unique<Reader>(in)) {
	  ptr = chain.get();
  }

  // добавляет новый обработчик Filter
  PipelineBuilder& FilterBy(Filter::Function filter) {
	  auto u_ptr = make_unique<Filter>(filter);
	  auto temp = u_ptr.get();
	  ptr->SetNext(move(u_ptr));
	  ptr = temp;
	  return *this;
  }

  // добавляет новый обработчик Copier
  PipelineBuilder& CopyTo(string recipient) {
	  auto u_ptr = make_unique<Copier>(recipient);
	  auto temp = u_ptr.get();
	  ptr->SetNext(move(u_ptr));
	  ptr = temp;
	  return *this;
  }

  // добавляет новый обработчик Sender
  PipelineBuilder& Send(ostream& out) {
	  auto u_ptr = make_unique<Sender>(out);
	  auto temp = u_ptr.get();
	  ptr->SetNext(move(u_ptr));
	  ptr = temp;
	  return *this;
  }

  // возвращает готовую цепочку обработчиков
  unique_ptr<Worker> Build() {
	  return move(chain);
  }
private:
  unique_ptr<Worker> chain;
  Worker* ptr;
};


void TestSanity() {
  string input = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "ralph@example.com\n"
    "erich@example.com\n"
    "I do not make mistakes of that kind\n"
  );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  builder.FilterBy([](const Email& email) {
    return email.from == "erich@example.com";
  });
  builder.CopyTo("richard@example.com");
  builder.Send(outStream);
  auto pipeline = builder.Build();

  pipeline->Run();

  string expectedOutput = (
    "erich@example.com\n"
    "richard@example.com\n"
    "Hello there\n"

    "erich@example.com\n"
    "ralph@example.com\n"
    "Are you sure you pressed the right button?\n"

    "erich@example.com\n"
    "richard@example.com\n"
    "Are you sure you pressed the right button?\n"
  );

  ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSanity);
  return 0;
}
