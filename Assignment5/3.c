#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* head=NULL;
int size=0;

void push(int val){
	Node* p=(Node*)malloc(sizeof(Node*));
	p->data=val;
	p->next=NULL;
	if(head==NULL){
		head=p;
	}
	else{
		p->next=head;
		head=p;
	}	
}
int pop(){
 	int popped;
 	if(head==NULL){
		printf("List is Empty\n");
		return -1;
	}
	else{
		popped=head->data;
		head=head->next;
		return popped;
	}	
}
 
void display(){
	if(head == NULL){
		printf("List is Empty\n");
		return;
	}
	else{
		Node* temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}

int main(){
	
	int choice,a;
	printf("1. Push\t\t");
	printf("2. Pop\n");
	printf("3. Display\t");
	printf("4. Exit\n");
	do{
		
		printf("Enter your choice: ");
		
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the value to be added: ");
				scanf("%d",&a);
				push(a);
				break;
			case 2:
				a=pop();
				if (a==-1) break;
				printf("%d is Deleted!\n",a);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting Program.......\n");
				break;
			default:
				printf("Input invalid!!\n");
		}
		
	}while(choice!=4);
		
	return 0;
}

