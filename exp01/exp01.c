#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
} Animal;

Animal* animalNew(char* name) {
  Animal* animal = malloc(sizeof(Animal));
  animal->name = malloc(strlen(name)*sizeof(char));
  strcpy(animal->name, name);
  return animal;
}

void animalPrint(Animal* animal) {
  printf("Animal:\n");
  printf("  name: %s\n", animal->name);
}

typedef struct {
  Animal* base;
  int tail;
} Dog;

Dog* dogNew(char* name, int tail) {
  Dog *dog = malloc(sizeof(Dog));
  dog->base = animalNew(name);
  dog->tail = 1;
  return dog;
}

void dogPrint(Dog* dog) {
  printf("Dog:\n");
  printf("  name: %s\n", dog->base->name);
  printf("  tail: %d\n", dog->tail);
}

typedef struct {
  Animal* base;
  int swim;
} Fish;

Fish* fishNew(char* name, int swim) {
  Fish *fish = malloc(sizeof(Fish));
  fish->base = animalNew(name);
  fish->swim = 3;
  return fish;
}

void fishPrint(Fish* fish) {
  printf("Fish:\n");
  printf("  name: %s\n", fish->base->name);
  printf("  swim: %d\n", fish->swim);
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