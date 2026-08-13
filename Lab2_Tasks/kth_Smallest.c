#include<stdio.h>
int main(){
    int n,k,temp;
    printf("enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
           }
        }
    }
    printf("enter k value to find kth smallest element:");
    scanf("%d",&k);
    if(k<1||k>n){
        printf("invalid k");
    }
    else{
        printf("the kth(here %dth) smallest element is %d\n",k,arr[k-1]);
  
  }
 //2nd approach
    printf("second approach to find\n");
    int min;
    for (int count=1;count<= k;count++) {
        min = arr[0];
        for (int i=1;i<n;i++) {
            if (arr[i]<min) {
                min=arr[i];
            }
        }
        printf("Smallest number = %d\n", min);
        if(count==k) {    // Stop when we reach kth smallest
            printf("Kth smallest = %d", min);
            break;
        }
        for(int i=0;i<n;i++) 
        {   // Remove the smallest number
            if (arr[i]==min) 
            {
                for (int j=i;j<n-1;j++) 
                {
                    arr[j]=arr[j + 1];
                }
                n--;
                break;
            }
        }
    }
    return 0;
}