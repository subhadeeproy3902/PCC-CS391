#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
	int *arr;
	int front;
	int rear;
	int size;
} deque;

void initDeque(deque *dq){
	dq->arr = (int *)malloc(MAX *sizeof(int));
	dq->front = -1;
	dq->rear = -1;
	dq->size = 0;
}

int isfull(deque *dq){ return dq->size == MAX;}

int isempty(deque *dq){ return dq->size==0;}

void insertFront(deque *dq, int val){
	if (isfull(dq)){
		printf("Deque is full");
		return;
	}
	
	if (isempty(dq)){ dq->front = dq->rear =0;}
	else if (dq->front==0){dq->front = MAX-1;}
	else{dq->front--;}
	
	dq->arr[dq->front] = val;
	dq->size++;
}

void insertRear(deque *dq, int val){
	if(isfull(dq)){
		printf("Deque is full");
		return;
	}
	if (isempty(dq)){ dq->front = dq->rear = 0;}
	else if (dq->rear==MAX-1){dq->rear = 0;}
	else{dq->rear++;}
	
	dq->arr[dq->rear] = val;
	dq->size++;
}

int deleteFront(deque *dq){
	if (isempty(dq)){
		printf("Deque is empty");
		return -1;
	}
	
	int val = dq->arr[dq->front];
	if (dq->front == dq->rear){ dq->front = dq->rear = -1;}
	else if(dq->front == MAX-1){dq->front = 0;}
	else{ dq->front++;}
	
	dq->size--;
	return val;
}


int deleteRear(deque *dq){
	if (isempty(dq)){
		printf("Deque is empty");
		return -1;
	}
	
	int val = dq->arr[dq->rear];
	if (dq->front == dq->rear){ dq->front = dq->rear = -1;}
	else if(dq->rear == 0){dq->rear = MAX-1;}
	else{ dq->rear--;}
	
	dq->size--;
	return val;
}


void display(deque *dq){
	if (isempty(dq)){
		printf("Deque is empty");
		return;
	}
	int i = dq->front;
	printf("Deque: ");
	while(1){
		printf("%d ",dq->arr[i]);
		if (i==dq->rear) break;
		i = (i+1)%MAX;
	}
	printf("\n");
	
}


int main(){
	deque dq;
	initDeque(&dq);
	printf("1. En-Front\t");
        printf("2. En-Rear\n");
        printf("3. De-Front\t");
        printf("4. De-Rear\n");
        printf("5. Display\t");
        printf("6. Exit\n");
        int choice, x,val;
       while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		    case 1:
		    	printf("Enter element to insert: ");
		    	scanf("%d",&x);
		        insertFront(&dq,x);
		        break;
		    case 2:
		        printf("Enter element to insert: ");
		    	scanf("%d",&x);
		        insertRear(&dq,x);
		        break;
		    case 3:
		        val = deleteFront(&dq);
		        if (val!=-1){printf("Deleted: %d\n",val);}
		        break;
		    case 4:
		        val = deleteRear(&dq);
		        if (val!=-1){printf("Deleted: %d\n",val);}
		        break;
		    case 5:
		    	display(&dq);
		    	break;
		    case 6:
		   	 printf("Exit...");
		    	exit(0);
		    default:
		        printf("Invalid choice");
		}
	    }	
	    	return 0;
}	
	
