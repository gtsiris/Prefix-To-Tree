#include <stdio.h>
#include "TREEInterface.h"


int main(int argc, char *argv[]) { // Input: Prefix expression without spaces
  TreeNodePtr ROOT = MakeExpressionTree(&argv[1]); // Construct binary tree from prefix expression
  PrintTree(ROOT, 0);
  printf("The value of given prefix expression is: %d\n", EvaluateExpressionTree(ROOT)); // This function receives a node of the syntax tree and recursively evaluates it
  printf("The equivalent fully parenthesized infix expression is: ");
  ExpressionTreeToParenthesizedInfix(ROOT);
  printf("\n");
  printf("The InOrder traversal of the above expression tree is: ");
  InOrder(ROOT);
  printf("\n");
  printf("The above expression tree has %d leaf nodes.", CountLeaves(ROOT));
  printf("\n");
  printf("The above expression tree has %d nodes with both internal and external child nodes.\n", StrangeCount(ROOT));
  return 0;
}
