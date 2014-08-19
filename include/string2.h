#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdarg.h>

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

void string_print(void* _self);
void string_representation(void* _self);
void* string_constructor(void* _self, va_list* app);
void* string_destructor(void* _self);

const struct StringKlass* String;
const struct PrinterInterface* StringPrinter;

#endif
