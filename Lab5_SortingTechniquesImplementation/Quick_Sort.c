#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(i<=j)
    {
        while(i<=high && arr[i]<=pivot)
            i++;

        while(arr[j]>pivot)
            j--;

        if(i<j)
            swap(&arr[i],&arr[j]);
    }

    swap(&arr[low],&arr[j]);
    return j;
}
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr,0,n-1);

    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}