#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AnimalVirtualTable;

typedef struct {
  struct AnimalVirtualTable* vtable;
  char* name;
} Animal;

typedef struct AnimalVirtualTable {
  void (* print)(Animal* animal);
} AnimalVirtualTable;

void _animalPrint(Animal* animal) {
  printf("Animal:\n");
  printf("  name: %s\n", animal->name);
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

typedef struct {
  Animal base;
  int tail;
} Dog;

void _dogPrint(Animal* animal) {
  Dog* dog = (Dog*)animal;
  printf("Dog:\n");
  printf("  name: %s\n", dog->base.name);
  printf("  tail: %d\n", dog->tail);
}

void dogInit(Dog* dog, char* name, int tail) {
  animalInit(&dog->base, name);
  dog->base.vtable->print = _dogPrint;
  dog->tail = tail;
}

Dog* dogNew(char* name, int tail) {
  Dog *dog = malloc(sizeof(Dog));
  dogInit(dog, name, tail);
  return dog;
}

void dogPrint(Dog* dog) {
  dog->base.vtable->print((Animal*)dog);
}

typedef struct {
  Animal base;
  int swim;
} Fish;

void fishInit(Fish* fish, char* name, int swim) {
  animalInit(&fish->base, name);
  fish->swim = 3;
}

Fish* fishNew(char* name, int swim) {
  Fish *fish = malloc(sizeof(Fish));
  fishInit(fish, name, swim);
  return fish;
}

void fishPrint(Fish* fish) {
  fish->base.vtable->print((Animal*)fish);
}

int main () {
  Dog* poodle = dogNew("Spike", 1);
  dogPrint(poodle);

  Fish* guppy = fishNew("Linguado", 3);
  fishPrint(guppy);

  free(poodle);
  free(guppy);
  return 0;
}