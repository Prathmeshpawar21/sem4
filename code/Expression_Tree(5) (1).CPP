#include <iostream.h>
#include<stdlib.h>
struct node {
   char data;
   node *left;
   node *right;
};
char pf[50];
int top = -1;
node *a[50];
int r(char inputch) {
   if (inputch == '+' || inputch == '-' || inputch == '*' || inputch== '/')
      return (-1);
   else if (inputch >= 'A' || inputch <= 'Z')
      return (1);
   else if (inputch >= 'a' || inputch <= 'z')
      return (1);
   else
      return (-100);
}
void push(node *tree) {
   top++;
   a[top] = tree;
}
node *pop() {
   top--;
   return (a[top + 1]);
}
void exp_tree(char *suffix) {
   char s;
   node *newl, *p1, *p2;
   int flag;
   s = suffix[0];
   for (int i = 1; s != 0; i++) {
      flag = r(s);
      if (flag == 1) {
	 newl = new node;
	 newl->data = s;
	 newl->left = NULL;
	 newl->right = NULL;
	 push(newl);
      } else {
	 p1 = pop();
	 p2 = pop();
	 newl = new node;
	 newl->data = s;
	 newl->left = p2;
	 newl->right = p1;
	 push(newl);
      }
      s = suffix[i];
   }
}
void preOrder(node *tree) {
   if (tree != NULL) {
      cout << tree->data;
      preOrder(tree->left);
      preOrder(tree->right);
   }
}
void inOrder(node *tree) {
   if (tree != NULL) {
      inOrder(tree->left);
      cout << tree->data;
      inOrder(tree->right);
   }
}
void postOrder(node *tree) {
   if (tree != NULL) {
      postOrder(tree->left);
      postOrder(tree->right);
      cout << tree->data;
   }
}
void main(int argc, char **argv)
{
   clrscr();
   cout << "Enter Postfix Expression : ";
   cin >> pf;
   exp_tree(pf);
   cout << "\nIn-Order Traversal : ";
   inOrder(a[0]);
   cout << "\nPre-Order Traversal : ";
   preOrder(a[0]);
   cout << "\nPost-Order Traversal : ";
   postOrder(a[0]);
   getch();

}