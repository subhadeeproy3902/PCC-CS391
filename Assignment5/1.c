#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

void insert(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	struct Node *temp = head;
	while(temp->next != NULL) temp = temp->next;
	temp->next = newNode;
}

void delete(int data){
	struct Node *temp = head, *prev;
	if (temp !=NULL && temp->data == data){
		head = temp->next;
		free(temp);
		return;
	}
	while(temp !=NULL && temp->data != data){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL){
		printf("Element not found\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
}

void display(){
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse(){
	struct Node *prev = NULL,*current = head, *next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

struct Node* sortedMerge(struct Node* a, struct Node* b){
	struct Node *result = NULL;
	if (a==NULL) return (b);
	else if (b==NULL) return (a);
	if (a->data <= b->data){
		result = a;
		result->next = sortedMerge(a->next,b);
	}
	else{
		result = b;
		result->next = sortedMerge(a,b->next);
	}
	return (result);
}

void split(struct Node* source, struct Node** frontRef, struct Node** backRef){
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;
	while(fast != NULL){
		fast = fast->next;
		if (fast !=NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void merge(struct Node** headRef){
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;
	if ((head == NULL) || (head->next == NULL)) return;
	split(head, &a,&b);
	merge(&a);
	merge(&b);
	*headRef = sortedMerge(a,b);
}


void sort(){
	merge(&head);
}		


int main(){
	int choice,data;
	printf("1. Insert\t");
	printf("2. Delete\t");
	printf("3. Display\n");
	printf("4. Reverse\t");
	printf("5. Sort\t\t");
	printf("6. Exit\n");
	while (1){
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d",&data);
				delete(data);
				break;
			case 3:
				display();
				break;
			case 4:
				reverse();
				break;
			case 5:
				sort();
				break;
			case 6:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
