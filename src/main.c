#include <stdio.h>
#include <stdlib.h>

#include "ooc.h"
#include "object.h"

int main () {
  struct Object* obj = new(Object);

  printf("%s\n", obj->klass->name);
  printf("%s\n", obj->klass->klass->name);
  return 0;
}
