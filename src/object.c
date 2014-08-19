#include "object.h"

#include <stdio.h>

void* object_constructor(void* self, va_list* app) {
  return self;
}

void* object_destructor(void* self) {
  return self;
}

void object_representation(void* self) {
  printf("%s\n", ((struct Object*)self)->klass->name);
}

static const struct ObjectKlass _Object = {
  "Object",
  sizeof(struct Object),
  object_constructor,
  object_destructor,
  object_representation
};

const struct ObjectKlass* Object = &_Object;
