#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
  int data;
  struct Tree *left;
  struct Tree *right;
} node;

node *root = NULL;

node *createNode(int data)
{
  node *n = (node *)malloc(sizeof(node));
  if (n)
  {
    n->data = data;
    n->left = NULL;
    n->right = NULL;
  }
  return n;
}

node *insert(node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }

  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }

  return root;
}

void preorder(node *h)
{
  if (h != NULL)
  {
    printf("%d  ", h->data);
    preorder(h->left);
    preorder(h->right);
  }
}

void inorder(node *h)
{
  if (h != NULL)
  {
    inorder(h->left);
    printf("%d  ", h->data);
    inorder(h->right);
  }
}

void postorder(node *h)
{
  if (h != NULL)
  {
    postorder(h->left);
    postorder(h->right);
    printf("%d  ", h->data);
  }
}

int main()
{
  int data;
  printf("Enter a data to insert into the binary search tree (or -1 to stop): ");
  scanf("%d", &data);

  while (data != -1)
  {
    root = insert(root, data);
    printf("Enter a data to insert into the binary search tree (or -1 to stop): ");
    scanf("%d", &data);
  }
  printf("\n");
  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  printf("Postorder traversal: ");
  postorder(root);
  return 0;
}
