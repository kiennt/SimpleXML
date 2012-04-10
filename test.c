#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "simple_vector.h"

void test_vector() {
  Vector *v;
  int a, b, c, i;
  a = 10; 
  b = 20; 
  c = 30;

  // test allocate
  v = vector_create(v);
  assert(v->_size == 0 && "create size FAILED");
  assert(v->_capacity == 8 && "create capacity FAILED");

  // test push back
  vector_push_back(v, &a);
  vector_push_back(v, &b);
  assert(vector_size(v) == 2 && "insert element FAILED");
  assert(vector_get_element_at(v, 0) == &a && "insert element FAILED");
  assert(vector_get_element_at(v, 1) == &b && "insert element FAILED");
  
  // test push front 
  vector_push_front(v, &a);
  vector_push_front(v, &b);
  vector_push_front(v, &c);
  assert(vector_size(v) == 5);
  assert(vector_get_element_at(v, 0) == &c);
  assert(vector_get_element_at(v, 1) == &b);
  assert(vector_get_element_at(v, 2) == &a);
  assert(vector_get_element_at(v, 3) == &a);
  assert(vector_get_element_at(v, 4) == &b);
  
  // test insert
  vector_insert_at_index(v, &c, 2);
  assert(vector_size(v) == 6);
  assert(vector_get_element_at(v, 0) == &c);
  assert(vector_get_element_at(v, 1) == &b);
  assert(vector_get_element_at(v, 2) == &c);
  assert(vector_get_element_at(v, 3) == &a);
  assert(vector_get_element_at(v, 4) == &a);
  assert(vector_get_element_at(v, 5) == &b);

  // test remove
  vector_remove_element_at_index(v, 2);
  assert(vector_size(v) == 5);
  assert(vector_get_element_at(v, 0) == &c);
  assert(vector_get_element_at(v, 1) == &b);
  assert(vector_get_element_at(v, 2) == &a);
  assert(vector_get_element_at(v, 3) == &a);
  assert(vector_get_element_at(v, 4) == &b);

  // test re-allocate
  for (i = 0; i < 100; ++i) {
    vector_push_back(v, &a);
  }
  assert(vector_size(v) == 105);
  assert(vector_get_element_at(v, 0) == &c);
  assert(vector_get_element_at(v, 1) == &b);
  assert(vector_get_element_at(v, 2) == &a);
  assert(vector_get_element_at(v, 3) == &a);
  assert(vector_get_element_at(v, 4) == &b);
  for (i = 5; i < 105; ++i) {
    assert(vector_get_element_at(v, i) == &a);
  }

  vector_release(v);
}

int main(int argc, char** argv) {
  test_vector();
  return 0;
}
