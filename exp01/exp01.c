#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
} Animal;

typedef struct {
  Animal base;
  int tail;
} Dog;

typedef struct {
  Animal base;
  int swim;
} Fish;

void animalPrint(Animal* animal) {
  printf("Animal:\n");
  printf("  name: %s\n", animal->name);
}

void dogPrint(Dog* dog) {
  printf("Dog:\n");
  printf("  name: %s\n", dog->base.name);
  printf("  tail: %d\n", dog->tail);
}

void fishPrint(Fish* fish) {
  printf("Fish:\n");
  printf("  name: %s\n", fish->base.name);
  printf("  swim: %d\n", fish->swim);
}

int main () {
  Dog *poodle = malloc(sizeof(Dog));
  poodle->base.name = malloc(6*sizeof(char));
  strcpy(poodle->base.name, "Spike");
  poodle->tail = 1;
  dogPrint(poodle);

  Fish *guppy = malloc(sizeof(Fish));
  guppy->base.name = malloc(9*sizeof(char));
  strcpy(guppy->base.name, "linguado");
  guppy->swim = 3;
  fishPrint(guppy);

  animalPrint((Animal*)poodle);
  animalPrint((Animal*)guppy);

  free(poodle);
  free(guppy);
  return 0;
}