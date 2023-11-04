#include <stdio.h>

void add(int poly1[], int poly2[], int n1, int n2){
	int mdeg = (n1 > n2) ? n1 : n2;
	int r[mdeg + 1];
	for(int i = 0; i<= mdeg;i++){
		r[i] = 0;
	}
	for(int i = 0;i<n1;i++){
		r[i] += poly1[i];
	}
	for(int i = 0; i<n2; i++){
		r[i] += poly2[i];
	}
	printf("Result of addition: ");
	for(int i = mdeg;i>=0;i--){
		printf("%d ",r[i]);
		if(i!=0){
			printf("x^%d + ",i);
		}
	}
	printf("\n");
}

void sub(int poly1[], int poly2[], int n1, int n2){
	int mdeg = (n1 > n2) ? n1 : n2;
	int r[mdeg + 1];
	for(int i = 0; i<= mdeg;i++){
		r[i] = 0;
	}
	for(int i = 0;i<n1;i++){
		r[i] += poly1[i];
	}
	for(int i = 0; i<n2; i++){
		r[i] -= poly2[i];
	}
	printf("Result of subtraction: ");
	for(int i = mdeg;i>=0;i--){
		printf("%d ",r[i]);
		if(i!=0){
			printf("x^%d + ",i);
			if(r[i-1]>=0) printf("+ ");
		}
	}
	printf("\n");
}


int main(){
	int n1,n2;
	printf("Enter no. of coefficients of polynomial 1: ");
	scanf("%d",&n1);
	printf("Enter no. of coefficients of polynomial 2: ");
	scanf("%d",&n2);
	int poly1[n1], poly2[n2];
	printf("Enter polynomial 1 coefficients : ");
	int x;
	for(int i=0;i<n1;i++){
		scanf("%d",&x);
		poly1[i] = x;
	}
	printf("Enter polynomial 2 coefficients : ");
	for(int i=0;i<n2;i++){
		scanf("%d",&x);
		poly2[i] = x;
	}
	
	add(poly1,poly2,n1,n2);
	sub(poly1,poly2,n1,n2);
	return 0;
}
