#ifndef NODE_STRING_H
#define NODE_STRING_H

#include <stdarg.h>

#include "object.h"

struct NodeString {
  const struct NodeStringKlass *klass;
  struct Node* left;
  struct Node* right;
  char* text;
};

struct NodeStringKlass {
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

const struct NodeStringKlass* NodeString; /* Type Node */

#endif
