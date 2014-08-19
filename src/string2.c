#include "string2.h"

#include <stdio.h>
#include <string.h>

#include "printer.h"

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

void string_printer_print(void* self) {
  ((struct String*)self)->klass->print(self);
}


static const struct PrinterInterface _StringPrinter = {
  "Printer",
  string_printer_print
};

const struct PrinterInterface* StringPrinter = &_StringPrinter;
