#include<iostream>
#include<climits>
using namespace std;
int matrixChain(int p[],int n)
{
    int dp[20][20]={0};
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            dp[i][j]=INT_MAX;

            for(int k=i;k<j;k++)
            {
                int cost=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];

                if(cost<dp[i][j])
                    dp[i][j]=cost;
            }
        }
    }
    return dp[1][n];
}
int main()
{
    int n,p[20];
    cout<<"Enter number of matrices: ";
    cin>>n;
    cout<<"Enter dimensions: ";
    for(int i=0;i<=n;i++)
        cin>>p[i];
    cout<<"Minimum multiplication cost: "<<matrixChain(p,n);
    return 0;
}