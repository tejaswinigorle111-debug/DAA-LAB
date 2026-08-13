#include<stdio.h>
#include<math.h>
int main(){
    int x;//base
    int n;// power
    printf("enter x and n:");
    scanf("%d%d",&x,&n);

    //O(N^2) time complexity
    int sum1=0;
    for(int i=0;i<=n;i++){
        int term=1;
        for(int j=0;j<i;j++){
            term=term*x;
        }
         sum1=sum1+term;
    }
    printf("summation of series is (O(N^2 complexity)) : %d",sum1);

    //O(N) time complexity
    int exp=1;
    int sum2=0;
    for(int i=0;i<=n;i++){
        sum2=sum2+exp;
        exp=x*exp;
    }
    printf("\nsummation of series is (O(N)complexity) : %d",sum2);

    //O(logn) time complexity
    int sum3=0;
    if(x==1){
        sum3=n+1;
    }
    else{
        sum3=(pow(x,n+1)-1)/(x-1);
    }
    printf("\nsummation of series is (O(logn) complexity) : %d",sum3);
    return 0;
}