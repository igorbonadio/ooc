#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <stdarg.h>

/************************ Object *************************/

struct Object {
  const struct ObjectKlass *klass;
};

struct ObjectKlass {
  const struct ObjectKlass *klass;
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void* (* clone) (const void* self);
  int (* equals) (const void* self, const void* obj);
  const char* (* to_string) (const void* self);
};

void* object_constructor(void* self, va_list* app);
void* object_destructor(void* self);
void* object_clone(const void* self);
int object_equals(const void* self, const void* obj);
const char* object_to_string(const void* self);

const struct ObjectKlass* Object; /* Type Object */

/************************* Klass *************************/

struct Klass {
  const struct ObjectKlass *klass;
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void* (* clone) (const void* self);
  int (* equals) (const void* self, const void* obj);
  const char* (* to_string) (const void* self);
};

void* klass_destructor(void* self);
const char* klass_to_string(const void* self);

const struct Klass* Klass; /* Type Klass */

#endif
