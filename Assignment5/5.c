#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *next;
};

struct Queue
{
        struct Node *front;
        struct Node *rear;
};

struct Node *createNode(int data)
{
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
}

struct Queue *createQueue()
{
        struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
        queue->front = queue->rear = NULL;
        return queue;
}

void enqueue(struct Queue *queue, int data)
{
        struct Node *newNode = createNode(data);
        if (queue->rear == NULL)
        {
                queue->front = queue->rear = newNode;
                return;
        }
        queue->rear->next = newNode;
        queue->rear = newNode;
}

int dequeue(struct Queue *queue)
{
        if (queue->front == NULL)
        {
                printf("Queue is empty.\n");
                return -1;
        }
        struct Node *temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        if (queue->front == NULL)
                queue->rear = NULL;
        free(temp);
        return data;
}

void display(struct Queue *queue)
{
	if (queue->front == NULL)
        {
                printf("Queue is empty.\n");
                return;
        }
        struct Node *current = queue->front;
        printf("Queue: ");
        while (current != NULL)
        {
                printf("%d->", current->data);
                current = current->next;
        }
        printf("NULL\n");
}


int main()
{
        struct Queue *queue = createQueue();
        printf("1. Enqueue\t");
        printf("2. Dequeue\n");
        printf("3. Display\t");
        printf("4. Exit\n");
        int choice;
        while (1)
        {
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        int x;
			printf("Enter value: ");
			scanf("%d", &x);
			enqueue(queue, x);
			printf("Enqueued: %d\n",x);
                        break;
                case 2:
                        int data = dequeue(queue);
			if (data != -1) printf("Dequeued: %d\n", data);
                        break;
                case 3:
                        display(queue);
                        break;
                case 4:
                        exit(0);
                default:
                        printf("Invalid choice.\n");
                }
        }

        return 0;
}
