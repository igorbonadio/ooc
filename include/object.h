#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <stdarg.h>

struct Object {
  const struct ObjectKlass *klass;
};

struct ObjectKlass {
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void (* representation) (void* self);
};

const struct ObjectKlass* Object;

void* object_constructor(void* self, va_list* app);
void* object_destructor(void* self);
void object_representation(void* self);

#endif
