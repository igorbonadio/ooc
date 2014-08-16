#include "animal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _animalPrint(Animal* animal) {
  printf("Animal:\n");
  printf("  name: %s\n", animal->name);
}

void animalPrint(Animal* animal) {
  animal->vtable->print(animal);
}

AnimalVirtualTable* animalVirtualTable() {
  AnimalVirtualTable* vtable = malloc(sizeof(AnimalVirtualTable));
  vtable->print = _animalPrint;
  return vtable;
}

void animalInit(Animal* animal, char* name) {
  animal->name = malloc(strlen(name)*sizeof(char));
  animal->vtable = animalVirtualTable();
  strcpy(animal->name, name);
}

Animal* animalNew(char* name) {
  Animal* animal = malloc(sizeof(Animal));
  animalInit(animal, name);
  return animal;
}

void animalDestroy(Animal* animal) {
  free(animal);
}
