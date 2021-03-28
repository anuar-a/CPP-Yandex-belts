#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
 public:
  // –еализуйте конструктор по умолчанию и объ€вленные методы
  Editor() {
	  cursor = data.begin();
  }

  void Left() {
	  if (cursor != data.begin() && !data.empty()) {
		  --cursor;
	  }
  }

  void Right() {
	  if (cursor != data.end() && !data.empty()) {
		  ++cursor;
	  }
  }

  void Insert(char token) {
	  data.insert(cursor, token);
  }

  void Cut(size_t tokens = 1) {
	  buffer.clear();
	  auto cut_it = cursor;
	  while (cut_it != data.end() && tokens != 0) {
		  buffer.push_back(*cut_it);
		  --tokens;
		  ++cut_it;
	  }
	  if (cursor != cut_it) cursor = data.erase(cursor, cut_it);
  }

  void Copy(size_t tokens = 1) {
	  buffer.clear();
	  auto copy_it = cursor;
	  while (copy_it != data.end() && tokens != 0) {
		  buffer.push_back(*copy_it);
		  --tokens;
		  ++copy_it;
	  }
  }
//
  void Paste() {
	  if (!buffer.empty()) {
		  auto it = buffer.begin();
		  while (it != buffer.end()) {
			  Insert(*it);
			  ++it;
		  }
	  }
  }

  string GetText() const {
	  string s;
	  auto it = data.begin();
	  while (it != data.end()) {
		  s.push_back(*it);
		  ++it;
	  }
	  return s;
  }

 private:
  list<char>::iterator cursor;
  list<char> data;
  list<char> buffer;
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);

    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;

    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }

  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");

  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}
