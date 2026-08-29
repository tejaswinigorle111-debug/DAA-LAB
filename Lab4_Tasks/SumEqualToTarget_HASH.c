#include<stdio.h>
int main(){
    int n,target;
    int found=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n],hash[n],used[n];
    printf("Enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the target element:");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        used[i]=0;
    }
    for(int i=0;i<n;i++){
        int search=target-arr[i];
        int index=search%n;
        int j=0;
        if(index<0)
            index=index+n;
        while(used[index]&&j<n){
            if(hash[index]==search){
                printf("%d + %d = %d\n",search,arr[i],target);
                found=1;
                break;
            }
            index=(index+1)%n;
            j++;
        }
        if(found==1)
            break;
        index=arr[i]%n;
        if(index<0)
            index=index+n;
        j=0;
        while(used[index]&&j<n){
            index=(index+1)%n;
            j++;
        }
        if(j<n){
            hash[index]=arr[i];
            used[index]=1;
        }
    }
    if(found==0)
        printf("No pair found\n");
    return 0;
}
//prints all pairs possible..
/*#include<stdio.h>
int main(){
    int n,target;
    int found=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n],hash[n];
    printf("Enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        hash[i]=-1;
    }
    printf("Enter the target element:");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        int key=arr[i];
        int index=key%n;
        int j=0;
        if(index<0)
            index=index+n;
        while(hash[index]!=-1&&hash[index]!=key&&j<n){
            index=(index+1)%n;
            j++;
        }
        if(hash[index]==-1)
            hash[index]=key;
    }
    for(int i=0;i<n;i++){
        int search=target-arr[i];
        int index=search%n;
        int j=0;
        if(index<0)
            index=index+n;
        while(hash[index]!=-1&&j<n){
            if(hash[index]==search){
                if(arr[i]<=search){
                    printf("%d + %d = %d\n",arr[i],search,target);
                    found=1;
                }
                break;
            }
            index=(index+1)%n;
            j++;
        }
    }
    if(found==0)
        printf("No pair found\n");
    return 0;
}*/