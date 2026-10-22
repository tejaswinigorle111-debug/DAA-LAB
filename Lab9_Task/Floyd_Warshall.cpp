#include <bits/stdc++.h>
using namespace std;
void floydWarshall(int a[20][20],int b[20][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             a[i][j]=b[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]!=9999 && a[k][j]!=9999 && a[i][k]+a[k][j]<a[i][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
}
int main() {
    int n,a[20][20],b[20][20];
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout << "Enter input matrix (9999 for no edge):\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >>b[i][j];
        }
    }
    floydWarshall(a, b, n);
    cout << "Shortest distance matrix:\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            if (a[i][j]==9999)
                cout<<"INF ";
            else
                cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}






























































/*
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int a[20][20], int b[20][20], int n) {
    // Copy input array b into output array a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }

    // Find shortest distances
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] != 999 && a[k][j] != 999 &&
                    a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
}

int main() {
    int n, a[20][20], b[20][20];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter input matrix (999 for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    floydWarshall(a, b, n);

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 999)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/