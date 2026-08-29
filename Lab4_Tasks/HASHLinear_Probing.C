#include<stdio.h>
int main(){
    int n,m;
    printf("Enter hash table size:");
    scanf("%d",&n);
    printf("Enter number of elements:");
    scanf("%d",&m);
    int arr[m],hash[n];
    printf("Enter the array elements:");
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        hash[i]=-1;
    }
    for(int i=0;i<m;i++){
        int key=arr[i];
        int index=key%n;
        while(hash[index]!=-1){
            index=(index+1)%n;
        }
        hash[index]=key;
    }
    printf("\nHash Table using Linear Probing:\n");
    for(int i=0;i<n;i++){
        printf("Index %d-> %d\n",i,hash[i]);
    }
    return 0;
}