#include<stdio.h>

void pr(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}
int main(){

    int n;
    printf("Provide len: ");
    scanf("%d",&n);

    int arr[100],i;

    printf("Provide elms :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    pr(arr,n);

    int pos = -1, key;
    scanf("%d",&key);

    for(i=0;i<n;i++){
        if(arr[i]==key){
            pos=i;
            break;
        }
    }
    if(pos == -1){
        printf("Not Found!\n");
        return 0;
    }else{
        printf("Found at: %d\n1. Insert\n2. Delete\n>_",pos);
        int ch,nw;
        scanf("%d", &ch);
        if(ch==1){
            printf("New Elm: ");
            scanf("%d",&nw);

            for(i=n;i>pos;i--){
                arr[i]=arr[i-1];
            }
            arr[pos] = nw;
            n++;

        }else if(ch==2){
            for(i=pos;i<n;i++){
                arr[i]=arr[i+1];
            }
            n--;

        }
    }

    pr(arr,n);

    return 0;
}
