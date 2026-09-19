#include<iostream>
using namespace std;
struct Edge{
    int u,v,w;
};
int parent[50];
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return find(parent[x]);
}
int Unite(int a,int b){
    parent[find(a)]=find(b);
}
int main(){
    int V,E;
    Edge e[30];
    cout<<"Enter the vertices and edges: ";
    cin>>V>>E;
    for(int i=0;i<E;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

    for(int i=0;i<E-1;i++){
        for(int j=i+1;j<E;j++){
            if(e[i].w>e[j].w){
                Edge t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
        }
    }
    for(int i=1;i<=V;i++){
        parent[i]=i;
    }
    int count=0;
    int minCost=0;
    cout<<"MST edges:"<<endl;
    for(int i=0;i<E;i++){
        int u=e[i].u;
        int v=e[i].v;
        if(find(u)!=find(v)){
            cout<<u<<" - "<<v<<" -> "<<e[i].w<<endl;
            Unite(u,v);
            minCost=minCost+e[i].w;
            count++;
            if(count==V)
                break;
        }
    }
    cout<<"Minimum Cost = "<<minCost<<endl;
    return 0;
}