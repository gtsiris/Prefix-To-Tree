#ifndef STACKTypes_h
#define STACKTypes_h

#include "TREETypes.h"

typedef struct StackNodeTag *StackNodePtr;

typedef struct StackNodeTag {
  TreeNodePtr node;
  StackNodePtr next;
} StackNode;

#endif  // STACKTypes_h
