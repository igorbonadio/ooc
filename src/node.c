#include "node.h"

#include <stdio.h>

#include "ooc.h"

void* node_constructor(void* _self, va_list* app) {
  struct Node* self = _self;
  self->left = NULL;
  self->right = NULL;
  return self;
}

void* node_destructor(void* _self) {
  struct Node* self = _self;
  delete(self->left);
  delete(self->right);
  return self;
}

void node_print(const void* _self) {
  const struct Node* self = _self;
  printf("%s\n", self->klass->to_string(self));
  if (self->left)
    self->left->klass->print(self->left);
  if (self->right)
    self->right->klass->print(self->right);
}

void* node_add_left(void* _self, void* node) {
  struct Node* self = _self;
  self->left = node;
  return node;
}

void* node_add_right(void* _self, void* node) {
  struct Node* self = _self;
  self->right = node;
  return node;
}

void node_remove_left(void* _self) {
  struct Node* self = _self;
  delete(self->left);
  self->left = NULL;
}

void node_remove_right(void* _self) {
  struct Node* self = _self;
  delete(self->right);
  self->right = NULL;
}

static const struct NodeKlass _Node = {
  (const struct ObjectKlass*)&Klass,
  "Node",
  sizeof(struct Node),
  node_constructor,
  node_destructor,
  object_clone,
  object_equals,
  object_to_string,
  node_print,
  node_add_left,
  node_add_right,
  node_remove_left,
  node_remove_right
};

const struct NodeKlass* Node = &_Node;
