#include "object.h"

#include <stdio.h>

/************************ Object *************************/

void* object_constructor(void* self, va_list* app) {
  return self;
}

void* object_destructor(void* self) {
  return self;
}

void* object_clone(void* self) {
  return NULL;
}

int object_equals(void* self, void* obj) {
  return 0;
}

char* object_to_string(void* self) {
  return NULL;
}

/************************* Klass *************************/

void* klass_destructor(void* self) {
  return NULL;
}

int klass_equals(void* self, void* obj) {
  return 0;
}

char* klass_to_string(void* self) {
  return NULL;
}

/******************** Initialization *********************/

static const struct Klass _Klass = {
  (const struct ObjectKlass*)&_Klass,
  "Klass",
  sizeof(struct Klass),
  NULL,
  klass_destructor,
  object_clone,
  object_equals,
  object_to_string
};

const struct Klass* Klass = &_Klass;

static const struct ObjectKlass _Object = {
  (const struct ObjectKlass*)&_Klass,
  "Object",
  sizeof(struct Object),
  object_constructor,
  object_destructor,
  object_clone,
  object_equals,
  object_to_string
};

const struct ObjectKlass* Object = &_Object;
