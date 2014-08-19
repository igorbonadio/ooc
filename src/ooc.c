#include "ooc.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "object.h"

void* new(const void* _klass, ...) {
  const struct ObjectKlass* klass = _klass;
  void* p = calloc(1, klass->size);
  *(const struct ObjectKlass**) p = klass;
  if (klass->constructor) {
    va_list ap;
    va_start(ap, _klass);
    p = klass->constructor(p, &ap);
    va_end(ap);
  }
  return p;
}

void delete(void* self) {
  const struct ObjectKlass** cp = self;
  if (self && *cp && (*cp)->destructor)
    self = (*cp)->destructor(self);
  free(self);
}
