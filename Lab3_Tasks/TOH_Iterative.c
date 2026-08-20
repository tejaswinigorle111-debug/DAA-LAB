#include <stdio.h>
#include <math.h>

int main()
{
    int n, move, disk, x;
    int totalMoves;
    char pos[30];
    printf("Enter number of disks: ");
    scanf("%d", &n);
    totalMoves = (int)pow(2, n) - 1;
    for (int i = 1; i <= n; i++)
    {
        pos[i]='S';
    }
    for (move=1;move<=totalMoves;move++)
    {
        disk = 1;
        x=move;
        while (x%2==0)
        {
            x=x/2;
            disk++;
        }
        char from=pos[disk];
        char to;
        if(n%2==1){
            if(disk%2==1){
                if(from=='S'){
                    to='D';
                }
                else if(from=='D'){
                    to='A';
                }
                else{
                    to='S';
                }
            }
            else{
                if(from=='S'){
                    to='A';
                }
                else if(from=='A'){
                    to='D';
                }
                else{
                    to='S';
                }
            }

        }
        else{
                 if (disk % 2 == 1){
                if (from == 'S') {
                    to = 'A';
                }
                else if (from == 'A'){
                    to = 'D';
                }
                else to= 'S';
            }
            else
            {
                if (from=='S') {
                to = 'D';
                }
                else if(from =='D'){
                   to ='A';  
                } 
                else {
                    to ='S';
                }            
            }
        }
            pos[disk]=to;
            printf("Move disk %d from %c to %c\n",disk,from,to);
    
        }
    }
