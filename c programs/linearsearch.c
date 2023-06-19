#include<stdio.h>
#include<conio.h>

int main(){

    int a[100],n,e,i,f=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    // linearsearch
    scanf("%d",&e);
    for (i = 0; i < n; i++)
    {   
        if (a[i]==e)
        {
            printf("Element found at position %d\n",i+1);
            f=1;
        } 
    }
    if (i==n && f==0)
    {
        printf("Element not found");
    }
    return 0;
}