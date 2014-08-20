#include <stdio.h>
#include <stdlib.h>

#include "ooc.h"
#include "object.h"

int main () {
  struct Object* obj = new(Object);
  struct Object* obj_clone = obj->klass->clone(obj);

  printf("class name of obj                     -> %s\n", obj->klass->name);
  printf("class name of obs's class             -> %s\n", obj->klass->klass->name);

  printf("class name of obj_clone               -> %s\n", obj_clone->klass->name);
  printf("class name of obs_clone's class       -> %s\n", obj_clone->klass->klass->name);

  printf("obj == obj_clone?                     -> %d\n", obj->klass->equals(obj, obj_clone));
  printf("obj == obj?                           -> %d\n", obj->klass->equals(obj, obj));

  printf("string representation of obj          -> %s\n", obj->klass->to_string(obj));
  printf("string representation of obj_clone    -> %s\n", obj_clone->klass->to_string(obj_clone));

  printf("string representation of Object class -> %s\n", obj->klass->klass->to_string(obj->klass));

  printf("empty interface                       -> %s\n", Interface->name);

  return 0;
}
