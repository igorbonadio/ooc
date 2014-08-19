#include "atom.h"

#include <stdio.h>

#include "string2.h"

void atom_print(void* _self) {
  struct Atom* self = _self;
  printf(":%s\n", self->text);
}

static const struct AtomKlass _Atom = {
  "Atom",
  sizeof(struct Atom),
  string_constructor,
  string_destructor,
  string_representation,
  atom_print
};

const struct AtomKlass* Atom = &_Atom;
