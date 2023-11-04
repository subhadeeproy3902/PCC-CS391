#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int arr[MAX];
int r = -1;
int f = -1;


void enq(){
	if(f == -1 && r == -1){
		f++;
		r++;
	}
	else if(r == MAX-1)
	{
		printf("Queue is full\n");
		return;
	}
	else{
		r++;
	}
	printf("Enter data: ");
	scanf("%d",&arr[r]);
}

void deq(){
	if(f==-1 && r==-1) printf("Queue empty!");
	else if(f>r) f=r=-1;
	else{
		printf("Deleted element: %d\n",arr[f]);
		f++;
	}
}

void display(){
	if (f==-1 && r==-1){
		int i;
		printf("Datas: ");
		for(i = f; i<=r;i++) printf("%d ",arr[i]);
		printf("\n");
	}
	else printf("Queue empty");
}
	

int main(){
	printf("1. Enqueue\t");
        printf("2. Dequeue\n");
        printf("3. Display\t");
        printf("4. Exit\n");

    int choice, x;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }	
    	return 0;
}

