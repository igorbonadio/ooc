#ifndef ATOM_H
#define ATOM_H

#include <stdlib.h>
#include <stdarg.h>

/*
 * class Atom extends String
 *   void print();
 * }
 *
 */

struct Atom {
  const struct AtomKlass *klass;
  char* text;
};

struct AtomKlass {
  const char* name;
  size_t size;
  void* (* constructor) (void* self, va_list* app);
  void* (* destructor) (void* self);
  void (* representation) (void* self);
  void (* print) (void* self);
};

void atom_print(void* _self);

const struct AtomKlass* Atom;

#endif
