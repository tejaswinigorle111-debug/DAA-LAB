#include<stdio.h>
int max,min;
void find(int a[],int low,int high)
{
    if(low==high)
    {
        max=min=a[low];
        return;
    }
    int mid=(low+high)/2;
    find(a,low,mid);
    int leftMax=max;
    int leftMin=min;
    find(a,mid+1,high);
    max=leftMax>max?leftMax:max;
    min=leftMin<min?leftMin:min;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    find(a,0,n-1);
    printf("Maximum = %d\n",max);
    printf("Minimum = %d\n",min);
    return 0;
}