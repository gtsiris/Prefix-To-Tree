/* This code is from Chapter 4 of the book "Algorithms in C" by Robert Sedgewick. */

#include <stdlib.h>
#include "STACKInterface.h"

static StackNodePtr head;

StackNodePtr NEW(TreeNodePtr node, StackNodePtr next) {
  StackNodePtr x = malloc(sizeof *x);
  x->node = node; x->next = next;
  return x;
}

void STACKinit(void) {
  head = NULL;
}

int STACKempty(void) {
  return head == NULL;
}

void STACKpush(TreeNodePtr node) {
  head = NEW(node, head);
}

TreeNodePtr STACKpop(void) {
  TreeNodePtr node = head->node;
  StackNodePtr link = head->next;
  free(head);
  head = link;
  return node;
}
