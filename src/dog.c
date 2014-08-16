#include "dog.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _dogPrint(void* animal) {
  Dog* dog = (Dog*)animal;
  printf("Dog:\n");
  printf("  name: %s\n", dog->base.name);
  printf("  tail: %d\n", dog->tail);
}

void dogPrint(void* dog) {
  ((Dog*)dog)->base.vtable->print((Animal*)dog);
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

void dogDestroy(Dog* dog) {
  free(dog);
}
