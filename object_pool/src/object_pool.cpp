#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
#include <vector>
using namespace std;

template <class T>
class ObjectPool {
public:

    T* Allocate() {
    	if(!freed.empty()) {
    		T* obj = freed.front();
    		freed.pop();
    		allocated.insert(obj);
    		return obj;
    	} else {
    		T* new_obj = new T;
    		allocated.insert(new_obj);
    		return new_obj;
    	}
    }

    T* TryAllocate() {
    	if(!freed.empty()) {
    		T* obj = freed.front();
    		freed.pop();
    		allocated.insert(obj);
    		return obj;
    	} else {
    		return nullptr;
    	}
    }

    void Deallocate(T* object) {

    	auto it = allocated.find(object);
    	if ( it != allocated.end()) {
    		freed.push(object);
    		allocated.erase(it);
    	} else {
    		throw invalid_argument("Invalid argument");
    	}
    }

    ~ObjectPool() {
    	for (auto& item : allocated) {
    		delete item;
    	}
    	allocated.clear();
    	while (!freed.empty()) {
    		delete freed.front();
    		freed.pop();
    	}
    }

private:
  // Добавьте сюда поля
  queue<T*> freed;
  set<T*> allocated;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";
  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  //pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
