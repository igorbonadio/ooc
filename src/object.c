#include "object.h"

#include <stdio.h>
#include <string.h>

/************************ Object *************************/

void* object_constructor(void* self, va_list* app) {
  return self;
}

void* object_destructor(void* self) {
  return self;
}

void* object_clone(const void* _self) {
  const struct Object* self = _self;
  void* obj = calloc(1, self->klass->size);
  memcpy(obj, self, self->klass->size);
  return obj;
}

int object_equals(const void* self, const void* obj) {
  return self == obj;
}

const char* object_to_string(const void* _self) {
  const struct Object* self = _self;
  char *str = malloc(sizeof(char)*(strlen(self->klass->name) + 18));
  sprintf(str, "%s(%p)", self->klass->name, self);
  return str;
}

/************************* Klass *************************/

void* klass_destructor(void* self) {
  return NULL;
}

const char* klass_to_string(const void* _self) {
  const struct Klass* self = _self;
  char *str = malloc(sizeof(char)*(strlen(self->name) + 7));
  sprintf(str, "%s class", self->name);
  return str;
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
  klass_to_string
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

static const struct Interface _Interface = {
  "Interface"
};

const struct Interface* Interface = &_Interface;
