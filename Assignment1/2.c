#include<stdio.h>

int hor(int cof[], int x, int num){
    if(x<0) return 0;
    return cof[x] + num * hor(cof, x-1, num);
}

int main(){
    int deg;
    printf("Provide deg of poly: ");
    scanf("%d",&deg);

    int cof[deg+1],i,num;

    printf("Provide coeffs (high to low) :");
    for(i=0;i<deg+1;i++){
        scanf("%d",&cof[i]);
    }

    printf("Provide num to eval: ");
    scanf("%d",&num);

    int val = hor(cof,deg,num);
    printf("Solution using horner: %d\n",val);

    return 0;
}
