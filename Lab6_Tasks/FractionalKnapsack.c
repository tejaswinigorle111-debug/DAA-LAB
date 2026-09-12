#include<stdio.h>
void Greedy(int w[],int p[],int n,int m,float x[])
{
    int weight=0;
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(weight+w[i]<=m)
        {
            x[i]=1;
            weight=weight+w[i];
        }
        else
        {
            x[i]=(float)(m-weight)/w[i];
            weight=m;
            break;
        }
    }
}
int main()
{
    int n,m;
    int w[100],p[100];
    float x[100],profit=0;
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("Enter weights:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter profits:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter capacity: ");
    scanf("%d",&m);
    Greedy(w,p,n,m,x);
    for(int i=0;i<n;i++)
        profit=profit+x[i]*p[i];

    printf("Selected fractions:\n");
    for(int i=0;i<n;i++)
        printf("x[%d] = %.2f\n",i+1,x[i]);

    printf("Maximum Profit = %.2f",profit);
    return 0;
}