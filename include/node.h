#ifndef NODE_H
#define NODE_H

#include <stdarg.h>

#include "object.h"

struct Node {
  const struct NodeKlass *klass;
  struct Node* left;
  struct Node* right;
};

struct NodeKlass {
  const struct ObjectKlass *klass;
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void* (* clone) (const void* self);
  int (* equals) (const void* self, const void* obj);
  const char* (* to_string) (const void* self);

  void (* print) (const void*);
  void* (* add_left) (void*, void*);
  void* (* add_right) (void*, void*);
  void (* remove_left) (void*);
  void (* remove_right) (void*);
};

void node_print(const void*);
void* node_add_left(void*, void*);
void* node_add_right(void*, void*);
void node_remove_left(void*);
void node_remove_right(void*);

const struct NodeKlass* Node; /* Type Node */

#endif
