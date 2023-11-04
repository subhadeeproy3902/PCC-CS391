#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
    int items[MAX_SIZE];
    int top;
};


void initialize(struct stack *s) {
    s->top = -1;
}

int is_full(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

int is_empty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, int x) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = x;
}

int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    int temp = s->items[s->top];
    s->top--;
    return temp;
}

void sortStack(struct stack* stack){
	struct stack tempstack;
	initialize(&tempstack);
	while (!is_empty(stack)){
		int temp = pop(stack);
		while(!is_full(&tempstack) && tempstack.items[tempstack.top] > temp){
			push(stack, pop(&tempstack));
		}
		push(&tempstack, temp);
	}
	while(!is_empty(&tempstack)){
		push(stack, pop(&tempstack));
	}
}

void display(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
	

int main(){
	struct stack s;
	initialize(&s);
	int n,x;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for (int i = 0;i<n;i++){
		scanf("%d",&x);
		push(&s,x);
	}
	display(&s);
	sortStack(&s);
	printf("After sorting-----");
	display(&s);
	return 0;
}
