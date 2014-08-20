#include <stdio.h>

#include "ooc.h"
#include "node.h"
#include "node_string.h"

int main() {
  struct Node* root = new(Node);
  root->klass->add_left(root, new(NodeString, "Blah"));
  root->klass->add_right(root, new(Node));

  root->klass->print(root);

  delete(root);
  return 0;
}
