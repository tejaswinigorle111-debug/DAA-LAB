#include <stdio.h>
int main(){
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    int hash[n];
    int freq[n];
    for(int i=0;i<n;i++){
        hash[i]=-1;
        freq[i]=0;
    }
    printf("Enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int key=arr[i];
        int index=key%n;
        if(index<0)
            index=index+n;
        while(hash[index]!=-1&&hash[index]!=key){
            index=(index+1)%n;
        }
        if(hash[index]==-1){
            hash[index]=key;
            freq[index]=1;
        }
        else{
            freq[index]++;
        }
    }
    for(int i=0;i<n;i++){
        if(hash[i]!=-1){
            printf("Frequency of %d is %d\n",hash[i],freq[i]);
        }
    }
    return 0;
}