#ifndef INTEGER_H
#define INTEGER_H

#include <stdlib.h>
#include <stdarg.h>

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

void integer_print(void* _self);
void* integer_constructor(void* _self, va_list* app);

const struct IntegerKlass* Integer;
const struct PrinterInterface* IntegerPrinter;

#endif
