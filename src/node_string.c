#include "node_string.h"

#include <stdio.h>
#include <string.h>

#include "ooc.h"
#include "node.h"

void* node_string_constructor(void* _self, va_list* app) {
  struct NodeString* self = _self;
  char* _text = va_arg(*app, char*);
  self->text = malloc(sizeof(char)*(strlen(_text) + 1));
  strcpy(self->text, _text);
  self->left = NULL;
  self->right = NULL;
  return self;
}

void* node_string_destructor(void* _self) {
  struct NodeString* self = _self;
  delete(self->left);
  delete(self->right);
  free(self->text);
  return self;
}

const char* node_string_to_string(const void* _self) {
  const struct NodeString* self = _self;
  return self->text;
}

static const struct NodeStringKlass _NodeString = {
  (const struct ObjectKlass*)&Klass,
  "NodeString",
  sizeof(struct Node),
  node_string_constructor,
  node_string_destructor,
  object_clone,
  object_equals,
  node_string_to_string,
  node_print,
  node_add_left,
  node_add_right,
  node_remove_left,
  node_remove_right
};

const struct NodeStringKlass* NodeString = &_NodeString;
