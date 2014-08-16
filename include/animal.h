#ifndef ANIMAL
#define ANIMAL

typedef struct Animal {
  struct AnimalVirtualTable* vtable;
  char* name;
} Animal;

typedef struct AnimalVirtualTable {
  void (* print)(Animal* animal);
} AnimalVirtualTable;

Animal* animalNew(char* name);

void animalInit(Animal* animal, char* name);

void animalPrint(Animal* animal);

void animalDestroy(Animal* animal);

#endif

/* 2228 */
