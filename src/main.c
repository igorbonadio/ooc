#include "stdio.h"

#include "animal.h"
#include "dog.h"
#include "fish.h"

void print(Animal* animal) {
  printf("*********************\n");
  animalPrint(animal);
}

int main () {
  Dog* poodle = dogNew("Spike", 1);
  print((Animal*)poodle);

  Fish* guppy = fishNew("Linguado", 3);
  print((Animal*)guppy);

  printf("*********************\n");

  dogDestroy(poodle);
  fishDestroy(guppy);
  return 0;
}
