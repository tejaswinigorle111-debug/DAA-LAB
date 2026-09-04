#include<stdio.h>
int main(){
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    int bucket[10][100];
    int count[10]={0};
    int arr[n];
    printf("enter the array elements: ");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int index=arr[i]/1000;//[index for 3 digits input then 1000]
        bucket[index][count[index]]=arr[i];
        count[index]++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i]-1;j++){
            for(int k=j+1;k<count[i];k++){
                if(bucket[i][j]>bucket[i][k]){
                    int temp=bucket[i][j];
                    bucket[i][j]=bucket[i][k];
                    bucket[i][k]=temp;
                }
            }
        }
    }
    int k=0;
    for(int i=0;i<n;i++){
         for(int j=0;j<count[i];j++){
            arr[k]=bucket[i][j];
            k++;
         }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}