#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
} Animal;

void animalInit(Animal* animal, char* name) {
  animal->name = malloc(strlen(name)*sizeof(char));
  strcpy(animal->name, name);
}

Animal* animalNew(char* name) {
  Animal* animal = malloc(sizeof(Animal));
  animalInit(animal, name);
  return animal;
}

void animalPrint(Animal* animal) {
  printf("Animal:\n");
  printf("  name: %s\n", animal->name);
}

typedef struct {
  Animal base;
  int tail;
} Dog;

void dogInit(Dog* dog, char* name, int tail) {
  animalInit(&dog->base, name);
  dog->tail = tail;
}

Dog* dogNew(char* name, int tail) {
  Dog *dog = malloc(sizeof(Dog));
  dogInit(dog, name, tail);
  return dog;
}

void dogPrint(Dog* dog) {
  printf("Dog:\n");
  printf("  name: %s\n", dog->base.name);
  printf("  tail: %d\n", dog->tail);
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
  printf("Fish:\n");
  printf("  name: %s\n", fish->base.name);
  printf("  swim: %d\n", fish->swim);
}

int main () {
  Dog* poodle = dogNew("Spike", 1);
  dogPrint(poodle);
  animalPrint((Animal*)poodle);

  Fish* guppy = fishNew("Linguado", 3);
  fishPrint(guppy);
  animalPrint((Animal*)guppy);

  free(poodle);
  free(guppy);
  return 0;
}