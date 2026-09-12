#include<stdio.h>

int maxSum(int a[],int low,int high)
{
    if(low==high){
        return a[low];
    }
    int mid=(low+high)/2;
    int left=maxSum(a,low,mid);
    int right=maxSum(a,mid+1,high);
    int sum=0;
    int LeftSum=a[mid];
    int RightSum=a[mid+1];
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        LeftSum=sum>LeftSum?sum:LeftSum;
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        RightSum=sum>RightSum?sum:RightSum;
    }
    int cross=LeftSum+RightSum;
    return left>right?(left>cross?left:cross):(right>cross?right:cross);
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
    printf("Maximum Subarray Sum = %d",maxSum(a,0,n-1));
    return 0;
}