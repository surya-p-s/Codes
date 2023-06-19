#include<stdio.h>
#include<conio.h>

int main(){

    int n;
    scanf("%d",&n);
    int c=0,j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t",(c+j));        
        }
        c=c+j;
        printf("\n");
    }
    


    return 0;
}