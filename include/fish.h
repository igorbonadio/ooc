#ifndef FISH
#define FISH

#include "animal.h"

typedef struct {
  Animal base;
  int swim;
} Fish;

Fish* fishNew(char* name, int swim);

void fishInit(Fish* fish, char* name, int swim);

void fishPrint(void* fish);

void fishDestroy(Fish* fish);

#endif
