#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  char data;
  struct Node *left, *right, *next;
};

struct Node *head = NULL;

struct Node *newNode(char data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = node->next = NULL;
}

void push(struct Node *x)
{
  if (head == NULL)
    head = x;
  else
  {
    x->next = head;
    head = x;
  }
}

struct Node *pop()
{
  struct Node *p = head;
  head = head->next;
  return p;
}

void inorder(struct Node *node)
{
  if (node == NULL)
    return;
  inorder(node->left);
  printf("%c ", node->data);
  inorder(node->right);
}

int op(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isValidPostfixExpression(char *exp)
{
  int operand = 0;
  int operator= 0;

  for (int i = 0; exp[i] != '\0'; i++)
  {
    if (op(exp[i]))
    {
      operator++;
    }
    else if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
    {
      operand++;
    }
    else
    {
      return 0;
    }

    if (operator>= operand)
    {
      return 0;
    }
  }
  return (operand == operator+ 1);
}

int main()
{
  char input[100];
  struct Node *x, *y, *z;
  printf("Enter a postfix expression: ");
  scanf("%s", input);

  if (!isValidPostfixExpression(input))
  {
    printf("Invalid postfix expression.\n");
    return 1;
  }

  int len = strlen(input);
  char s[len];

  for (int i = 0; i < len; i++)
  {
    s[i] = input[i];
  }

  int l = sizeof(s) / sizeof(s[0]);
  for (int i = 0; i < l; i++)
  {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
    {
      z = newNode(s[i]);
      x = pop();
      y = pop();
      z->left = y;
      z->right = x;
      push(z);
    }
    else
    {
      z = newNode(s[i]);
      push(z);
    }
  }

  printf("Inorder Traversal of Exp Tree: ");
  inorder(z);
  return 0;
}
