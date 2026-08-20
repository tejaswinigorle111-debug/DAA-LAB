#include<stdio.h>
void TOH(int n,char src,char aux,char dest){
   if(n==1){
       printf("Move disk from %c to %c",src,dest);
       printf("\n");
   }
   else{
    TOH(n-1,src,dest,aux);
    TOH(1,src,aux,dest);
    TOH(n-1,aux,src,dest);
   }
}
int main(){
   int n;
   char src='S',aux='A',dest='D';
   printf("enter no of disks:");
   scanf("%d",&n);
   TOH(n,src,aux,dest);
   return 0;
}