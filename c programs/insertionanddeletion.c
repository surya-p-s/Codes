#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
    // Insertion, deletion and printing of array

    int n,pos,value,op;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int a[200];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("1.Insertion\t2.Deletion\t3.Print Array: ");
    scanf("%d",&op);
    if(op==3){
        // Print array
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        return 0;
    }
    printf("Enter Postion: ");
    scanf("%d",&pos);
    if(op==1){
        // Insertion Code
        printf("Enter Value: ");
        scanf("%d",&value);
        n=n+1;
        for (int i = n-1; i >= pos-1; i--)
        {
            a[i+1]=a[i];

        }
        a[pos-1]=value;

        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else if (op==2)
    {
        // Deletion Code
        for (int i = pos-1; i<n; i++)
        {
            a[i]=a[i+1];
        }
        n=n-1;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        
    }

    return 0;
}