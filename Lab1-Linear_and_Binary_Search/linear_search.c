#include<stdio.h>
int main()
{
    int n,key;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search:");
    scanf("%d",&key);
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            printf("Element found at position : %d",i+1);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Element not found");
    }
    return 0;
}