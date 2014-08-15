#ifndef DOG
#define DOG

#include "animal.h"

typedef struct {
  Animal base;
  int tail;
} Dog;

Dog* dogNew(char* name, int tail);

void dogInit(Dog* dog, char* name, int tail);

void dogPrint(Dog* dog);

void dogDestroy(Dog* dog);

#endif
