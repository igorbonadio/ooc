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
  void* (* clone) (void* self);
  int (* equals) (void* self, void* obj);
  char* (* to_string) (void* self);
};

void* object_constructor(void* self, va_list* app);
void* object_destructor(void* self);
void* object_clone(void* self);
int object_equals(void* self, void* obj);
char* object_to_string(void* self);

const struct ObjectKlass* Object; /* Type Object */

/************************* Klass *************************/

struct Klass {
  const struct ObjectKlass *klass;
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void* (* clone) (void* self);
  int (* equals) (void* self, void* obj);
  char* (* to_string) (void* self);
};

void* klass_destructor(void* self);
int klass_equals(void* self, void* obj);
char* klass_to_string(void* self);

const struct Klass* Klass; /* Type Klass */

#endif
