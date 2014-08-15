#ifndef ANIMAL_VIRTUAL_TABLE
#define ANIMAL_VIRTUAL_TABLE

#include "animal.h"

struct AnimalVirtualTable;

typedef struct AnimalVirtualTable {
  void (* print)(Animal* animal);
} AnimalVirtualTable;

#endif
