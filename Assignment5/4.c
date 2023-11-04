#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int data;
        struct Node *prev;
        struct Node *next;
};

struct Node *createNode(int data)
{
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}

void insert_start(struct Node **head, int data)
{
        struct Node *newNode = createNode(data);
        if (*head == NULL)
        {
                *head = newNode;
                return;
        }
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
}

void insert_end(struct Node **head, int data)
{
        struct Node *newNode = createNode(data);
        if (*head == NULL)
        {
                *head = newNode;
                return;
        }
        struct Node *current = *head;
        while (current->next != NULL)
        {
                current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
}

void delete(struct Node **head, int data)
{
        struct Node *current = *head;
        while (current != NULL)
        {
                if (current->data == data)
                {
                        if (current->prev != NULL)
                                current->prev->next = current->next;
                        if (current->next != NULL)
                                current->next->prev = current->prev;
                        if (*head == current)
                                *head = current->next;
                        free(current);
                        return;
                }
                current = current->next;
        }
        printf("Value Not Found.\n");
}

void display(struct Node *head)
{
        struct Node *current = head;
        while (current != NULL)
        {
                printf("%d->", current->data);
                current = current->next;
        }
        printf("NULL\n");
}

void reverse(struct Node **head)
{
        struct Node *temp = NULL;
        struct Node *current = *head;
        while (current != NULL)
        {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
        }
        if (temp != NULL)
                *head = temp->prev;
}

int main()
{
        struct Node *head = NULL;
        printf("\n1. Insert at beginning\t");
        printf("2. Insert at end\t");
        printf("3. Delete a node\n");
        printf("4. Display the list\t");
        printf("5. Reverse the list\t");
        printf("6. Exit\n");
        int choice;
        while (1)
        {
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                {
                        int val;
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insert_start(&head, val);
                        break;
                }
                case 2:
                {
                        int val;
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insert_end(&head, val);
                        break;
                }
                case 3:
                {
                	if (head == NULL)
			{
				printf("List is empty.\n");
				break;
			}
                        int val;
                        printf("Enter value: ");
                        scanf("%d", &val);
                        delete(&head, val);
                        break;
                }
                case 4:
                	if (head == NULL)
			{
				printf("List is empty.\n");
				break;
			}
                        printf("List: ");
                        display(head);
                        break;
                case 5:
                	if (head == NULL)
			{
				printf("List is empty.\n");
				break;
			}
                        reverse(&head);
                        printf("List has been reversed\n");
                        break;
                case 6:
                        exit(0);
                default:
                        printf("Invalid choice.\n");
                }
        }

        return 0;
}
