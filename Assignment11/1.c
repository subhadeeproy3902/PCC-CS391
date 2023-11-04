#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  int priority;
  struct node *next;
} Node;

Node *newNode(int d, int p)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = d;
  temp->priority = p;
  temp->next = NULL;
  return temp;
}

int peek(Node **head)
{
  return (*head)->data;
}

void dequeue(Node **head)
{
  Node *temp = *head;
  (*head) = (*head)->next;
  free(temp);
}

void enqueue(Node **head, int d, int p)
{
  Node *start = (*head);
  Node *temp = newNode(d, p);
  if ((*head) == NULL || (*head)->priority > p)
  {
    temp->next = *head;
    (*head) = temp;
  }
  else
  {
    while (start->next != NULL && start->next->priority < p)
    {
      start = start->next;
    }
    temp->next = start->next;
    start->next = temp;
  }
}

int isEmpty(Node **head)
{
  return (*head) == NULL;
}

void display(Node *head)
{
  if (head == NULL)
  {
    printf("Priority queue is empty.\n");
  }
  else
  {
    printf("Priority Queue: ");
    while (head != NULL)
    {
      printf("%d ", head->data);
      head = head->next;
    }
    printf("\n");
  }
}

int main()
{
  Node *pq = NULL;
  int choice, data, priority;
  printf("\nMenu:\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  printf("5. Exit\n");
  while (1)
  {

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data and priority: ");
      scanf("%d %d", &data, &priority);
      enqueue(&pq, data, priority);
      break;

    case 2:
      if (!isEmpty(&pq))
      {
        printf("Dequeued element: %d\n", peek(&pq));
        dequeue(&pq);
      }
      else
      {
        printf("Priority queue is empty.\n");
      }
      break;

    case 3:
      if (!isEmpty(&pq))
      {
        printf("Peeked element: %d\n", peek(&pq));
      }
      else
      {
        printf("Priority queue is empty.\n");
      }
      break;

    case 4:
      display(pq);
      break;

    case 5:
      while (!isEmpty(&pq))
      {
        dequeue(&pq);
      }
      exit(0);

    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
