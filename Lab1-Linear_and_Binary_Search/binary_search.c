#include <stdio.h>
int main()
{
    int n,key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int start = 0;
    int end = n - 1;
    int found=0;
    while(start <= end)
    {
        int mid=(start+end)/2;
        if(arr[mid] == key)
        {
            printf("Element found at index %d", mid);
            found=1;
            break;
        }
        else if(arr[mid] < key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    if(found==0)
    {
        printf("Element not found");
    }
    return 0;
}