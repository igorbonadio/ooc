#include <stdio.h>

#include "ooc.h"
#include "node.h"

int main() {
  struct Node* root = new(Node);
  root->klass->add_left(root, new(Node));
  root->klass->add_right(root, new(Node));

  root->klass->print(root);

  delete(root);
  return 0;
}
