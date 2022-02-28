#include <stdio.h>
#include <stdlib.h>
#include "TREEInterface.h"
#include "STACKInterface.h"


TreeNodePtr CreateTreeNode(Item key) {
  TreeNodePtr treenodeptr;
  treenodeptr = malloc(sizeof(TreeNode));
  if (treenodeptr == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  treenodeptr->Symbol = key;
  treenodeptr->LLink = NULL;
  treenodeptr->RLink = NULL;
  return(treenodeptr);
}

TreeNodePtr MakeTree(Item root, TreeNodePtr left, TreeNodePtr right) {
  TreeNodePtr treenodeptr;
  treenodeptr = CreateTreeNode(root);
  treenodeptr->LLink = left;
  treenodeptr->RLink = right;
  return (treenodeptr);
}

TreeNodePtr MakeExpressionTree(Item **expression) {
  TreeNodePtr temp;
  if (expression[0][0] >= '0' && expression[0][0] <= '9') {
    temp = CreateTreeNode(expression[0][0]);
  }
  else if (expression[0][0] == '+' || expression[0][0] == '-' || expression[0][0] == '*' || expression[0][0] == '/') {
    temp = CreateTreeNode(expression[0][0]);
    *expression += 1;
    temp->LLink = MakeExpressionTree(expression);
    *expression += 1;
    temp->RLink = MakeExpressionTree(expression);
  }
  else {
    printf("Please insert expression with decimal digits and '+', '-', '*', '/' as operators without spaces.");
    return NULL;
  }
  return temp;
}

int EmptyTree(TreeNodePtr root) {
  if (root == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

void PrintTree(TreeNodePtr root, int space) {
  int i;
  if (EmptyTree(root)) {  // Base case
    return;
  }
  space += 10;  // Increase distance between levels
  PrintTree(root->RLink, space);  // Process right child first
  printf("\n");
  for (i = 10; i < space; i++) {
    printf(" ");
  }
  printf("%c\n", root->Symbol);  // Print current node after space
  PrintTree(root->LLink, space);  // Process left child
}

int EvaluateExpressionTree(TreeNodePtr root) {
  if (EmptyTree(root)) {  // empty tree
    return 0;
  }
  else if (root->LLink == NULL && root->RLink == NULL) {
    return(root->Symbol - '0');  // leaf node
  }
  int leftvalue = EvaluateExpressionTree(root->LLink);  // Evaluate left subtree
  int rightvalue = EvaluateExpressionTree(root->RLink);  // Evaluate right subtree
  switch (root->Symbol) {  // Check which operator to apply
    case '+':  return(leftvalue + rightvalue);
    case '-':  return(leftvalue - rightvalue);
    case '*':  return(leftvalue * rightvalue);
    case '/':  return(leftvalue / rightvalue);
  }
}

void ExpressionTreeToParenthesizedInfix(TreeNodePtr root) {
  if(!EmptyTree(root)) {
    if((root->Symbol) >= '0' && (root->Symbol) <= '9') {
      printf("%c", root->Symbol);
    }
    else if((root->Symbol) == '+' || (root->Symbol) == '-' || (root->Symbol) == '*' || (root->Symbol) == '/') {
      printf("(");
      ExpressionTreeToParenthesizedInfix(root->LLink);
      printf("%c", root->Symbol);
      ExpressionTreeToParenthesizedInfix(root->RLink);
      printf(")");
    }
  }
}


void InOrder(TreeNodePtr root) {
  TreeNodePtr current = root;  /* Initialize current as the root of a given tree */
  STACKinit();  /* Initialize stack */
  
  while (1) {
    /* Reach the leftmost node of each subtree which has current as root */
    if(!EmptyTree(current)) {  /* As long as the subtree is not empty, save its root before traversing its left subtree */
      STACKpush(current);
      current = current->LLink;
    }
    /**********************************************************************/
    else {  /* Backtrack from an empty left subtree */
      if (!STACKempty())  {  /* If there is a previous root in Stack */
        current = STACKpop();  /* Take it off */
        printf("%c ", current->Symbol);  /* Print its symbol*/
        current = current->RLink;  /* Visit its right subtree */
      }
      else {  /* If there is not previous root, InOrder traversal accomplished */
        break;  /* Stop the loop */
      }
    }
  }
}

int CountLeaves(TreeNodePtr root) {
  if(EmptyTree(root)) {
    return 0;
  }
  else if(root->LLink == NULL && root->RLink == NULL) {
    return 1;
  }
  else {
    return (CountLeaves(root->LLink) + CountLeaves(root->RLink));
  }
}

int StrangeCount(TreeNodePtr root) {
  if(EmptyTree(root)) {
    return 0;
  }
  else if((root->LLink == NULL && root->RLink != NULL) || (root->LLink != NULL && root->RLink == NULL)) {
    return 1;
  }
  else {
    return (StrangeCount(root->LLink) + StrangeCount(root->RLink));
  }
}

