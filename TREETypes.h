#ifndef TREETypes_h
#define TREETypes_h

typedef char Item;

typedef struct TreeNodeTag *TreeNodePtr;

typedef struct TreeNodeTag {
  Item Symbol;
  TreeNodePtr LLink;
  TreeNodePtr RLink;
} TreeNode;

#endif  // TREETypes_h
