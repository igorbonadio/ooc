#include "stdio.h"

#include "animal.h"
#include "dog.h"
#include "fish.h"

void print(void* animal) {
  printf("*********************\n");
  animalPrint((Animal*)animal);
}

int main () {
  Dog* poodle = dogNew("Spike", 1);
  print(poodle);

  Fish* guppy = fishNew("Linguado", 3);
  print(guppy);

  printf("*********************\n");

  dogDestroy(poodle);
  fishDestroy(guppy);
  return 0;
}
