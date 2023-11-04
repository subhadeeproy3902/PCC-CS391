// Write a program to implement AVL tree with suitable operations in C.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};
int height(struct Node *node)
{
  if (node == NULL)
    return 0;
  return node->height;
}
int max(int a, int b)
{
  return (a > b) ? a : b;
}
struct Node *newNode(int key)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}
struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}
struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
int getBalance(struct Node *node)
{
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}
struct Node *insert(struct Node *root, int key)
{
  if (root == NULL)
    return newNode(key);

  if (key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);
  else
    return root;

  root->height = 1 + max(height(root->left), height(root->right));
  int balance = getBalance(root);

  if (balance > 1 && key < root->left->data)
    return rightRotate(root);

  if (balance < -1 && key > root->right->data)
    return leftRotate(root);

  if (balance > 1 && key > root->left->data)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && key < root->right->data)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
void inOrder(struct Node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}
int main()
{
  struct Node *root = NULL;
  int n;
  while (1)
  {
    printf("Enter value to insert: ");
    scanf("%d", &n);
    if (n == 0)
      break;
    root = insert(root, n);
  }
  printf("In-order traversal of the AVL tree: ");
  inOrder(root);

  return 0;
}