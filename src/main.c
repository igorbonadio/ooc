#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "ooc.h"
#include "object.h"
#include "string2.h"
#include "atom.h"
#include "integer.h"
#include "printer.h"

void representation(void* obj) {
  ((struct Object*)obj)->klass->representation(obj);
}

void print(void* obj, const void* interface) {
  ((struct PrinterInterface*)interface)->print(obj);
}

int main () {
  struct String* str = new(String, "Bye");
  struct Integer* i = new(Integer, 321);
  struct Atom* atom = new(Atom, "test");

  printf("*********** Explicit Calls ***********\n");
  str->klass->print(str);
  str->klass->representation(str);
  i->klass->print(i);
  i->klass->representation(i);
  atom->klass->print(atom);
  atom->klass->representation(atom);
  printf("**************************************\n");

  printf("********* Polymorphic Calls **********\n");
  representation(str);
  representation(i);
  representation(atom);
  printf("**************************************\n");

  printf("********** Interface Calls ***********\n");
  print(str, StringPrinter);
  print(i, IntegerPrinter);
  print(atom, StringPrinter);
  printf("**************************************\n");

  delete(str);
  delete(i);
  return 0;
}
