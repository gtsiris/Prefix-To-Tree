#include "TREETypes.h"

TreeNodePtr CreateTreeNode(Item);
int EmptyTree(TreeNodePtr); //return true if the tree is empty, otherwise return false.
TreeNodePtr MakeTree(Item root, TreeNodePtr left, TreeNodePtr right); /* (Root, Left, Right): create a binary tree with Root as the root element and Left (resp. Right) as the left (resp. right) subtree. */
TreeNodePtr MakeExpressionTree(Item **);
void PrintTree(TreeNodePtr, int); // print the tree using an intuitive representation
int EvaluateExpressionTree(TreeNodePtr);
void ExpressionTreeToParenthesizedInfix(TreeNodePtr);
void InOrder(TreeNodePtr);
int CountLeaves(TreeNodePtr);
int StrangeCount(TreeNodePtr);

