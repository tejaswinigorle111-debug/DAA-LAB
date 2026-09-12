#include<stdio.h>
#define MAX 30
void add(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}
void subtract(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}
void strassen(int A[MAX][MAX],int B[MAX][MAX],int C[MAX][MAX],int n)
{
    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int k=n/2;
    int A11[MAX][MAX],A12[MAX][MAX],A21[MAX][MAX],A22[MAX][MAX];
    int B11[MAX][MAX],B12[MAX][MAX],B21[MAX][MAX],B22[MAX][MAX];
    int P[MAX][MAX],Q[MAX][MAX],R[MAX][MAX],S[MAX][MAX];
    int T[MAX][MAX],U[MAX][MAX],V[MAX][MAX];
    int x[MAX][MAX],y[MAX][MAX];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }

    add(A11,A22,x,k);
    add(B11,B22,y,k);
    strassen(x,y,P,k);

    add(A21,A22,x,k);
    strassen(x,B11,Q,k);

    subtract(B12,B22,y,k);
    strassen(A11,y,R,k);

    subtract(B21,B11,y,k);
    strassen(A22,y,S,k);

    add(A11,A12,x,k);
    strassen(x,B22,T,k);

    subtract(A21,A11,x,k);
    add(B11,B12,y,k);
    strassen(x,y,U,k);

    subtract(A12,A22,x,k);
    add(B21,B22,y,k);
    strassen(x,y,V,k);

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            C[i][j]=P[i][j]+S[i][j]-T[i][j]+V[i][j];
            C[i][j+k]=R[i][j]+T[i][j];
            C[i+k][j]=Q[i][j]+S[i][j];
            C[i+k][j+k]=P[i][j]+R[i][j]-Q[i][j]+U[i][j];
        }
    }
}
int main()
{
    int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
    int n;

    printf("Enter order of matrix: ");
    scanf("%d",&n);

    printf("Enter first matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter second matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    strassen(A,B,C,n);

    printf("Result matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}