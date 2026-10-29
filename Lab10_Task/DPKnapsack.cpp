#include<iostream>
using namespace std;
int DPKnapsack(int wt[],int p[],int n,int m){
    int r[30][30];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0||w==0){
                r[i][w]=0;
            }
            else if(wt[i-1]<=w){
                r[i][w]=max(p[i-1]+r[i-1][w-wt[i-1]],r[i-1][w]);
            }
            else{
                r[i][w]=r[i-1][w];
            }
        }
    }
    return r[n][m];
}
int main(){
    int wt[30],p[30];
    int n,m;
    cout<<"enter the no of items:";
    cin>>n;
    cout<<"enter the capacity:";
    cin>>m;
    cout<<"enter the weights of the items:";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"enter the profits of the items:";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"Maximum Profit:"<<DPKnapsack(wt,p,n,m);
    return 0;
}