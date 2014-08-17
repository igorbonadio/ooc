#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/********************** String *********************/
/*
 * class String extends Object implements Printer
 *   void print();
 * }
 *
 */

struct String {
  const struct StringKlass *klass;
  char* text;
};

struct StringKlass {
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void (* representation) (void* self);
  void (* print) (void* self);
};

void string_print(void* _self) {
  struct String* self = _self;
  printf("%s\n", self->text);
}

void string_representation(void* _self) {
  struct String* self = _self;
  printf("%s: %s\n", self->klass->name, self->text);
}

void* string_constructor(void* _self, va_list* app) {
  struct String* self = _self;
  const char* text = va_arg(*app, const char*);
  self->text = malloc(strlen(text) + 1);
  strcpy(self->text, text);
  return self;
}

void* string_destructor(void* _self) {
  struct String* self = _self;
  free(self->text);
  return self;
}

static const struct StringKlass _String = {
  "String",
  sizeof(struct String),
  string_constructor,
  string_destructor,
  string_representation,
  string_print
};

const struct StringKlass* String = &_String;

/********************** Integer ********************/
/*
 * class Integer extends Object implements Printer {
 *   void print();
 * }
 *
 */

struct Integer {
  const struct IntegerKlass *klass;
  int i;
};

struct IntegerKlass {
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void (* representation) (void* self);
  void (* print) (void* self);
};

void integer_print(void* _self) {
  struct Integer* self = _self;
  printf("%d\n", self->i);
}

void* integer_constructor(void* _self, va_list* app) {
  struct Integer* self = _self;
  self->i = va_arg(*app, int);
  return self;
}

static const struct IntegerKlass _Integer = {
  "Integer",
  sizeof(struct Integer),
  integer_constructor,
  object_destructor,
  object_representation,
  integer_print
};

const struct IntegerKlass* Integer = &_Integer;

/*********************** Main **********************/

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

void representation(void* obj) {
  ((struct Object*)obj)->klass->representation(obj);
}

void print(void* obj) {
}

int main () {
  struct String* str = new(String, "Bye");
  struct Integer* i = new(Integer, 321);

  printf("*********** Explicit Calls ***********\n");
  str->klass->print(str);
  str->klass->representation(str);
  i->klass->print(i);
  i->klass->representation(i);
  printf("**************************************\n");

  printf("********* Polymorphic Calls **********\n");
  representation(str);
  representation(i);
  printf("**************************************\n");

  printf("********** Interface Calls ***********\n");
  print(str);
  print(i);
  printf("**************************************\n");

  delete(str);
  delete(i);
  return 0;
}
