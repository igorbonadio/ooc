#include "fish.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fishInit(Fish* fish, char* name, int swim) {
  animalInit(&fish->base, name);
  fish->swim = 3;
}

Fish* fishNew(char* name, int swim) {
  Fish *fish = malloc(sizeof(Fish));
  fishInit(fish, name, swim);
  return fish;
}

void fishPrint(void* fish) {
  ((Fish*)fish)->base.vtable->print((Animal*)fish);
}

void fishDestroy(Fish* fish) {
  free(fish);
}
