#include "integer.h"

#include <stdio.h>

#include "object.h"
#include "printer.h"

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

void integer_printer_print(void* self) {
  ((struct Integer*)self)->klass->print(self);
}

static const struct PrinterInterface _IntegerPrinter = {
  "Printer",
  integer_printer_print
};

const struct PrinterInterface* IntegerPrinter = &_IntegerPrinter;
