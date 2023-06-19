#include<stdio.h>
#include<conio.h>

int main(){

   int n,op;
   printf("Enter Size of Array: ");
   scanf("%d",&n);
   int a[200];

//    Input array
printf("Enter Elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("1.Bubble Sort\n2.Selection Sort: ");
    scanf("%d",&op);
    if (op==1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                if (a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            
        }
          
    }
    else if (op==2)
    {
        int min;
        for (int i = 0; i < n-1; i++)
        {
            min=i;
            for (int j = i; j < n; j++)
            {
                if (a[min]>a[j])
                {
                    min=j;
                }
                
            }
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
        
    }
    for (int i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        } 

    return 0;
}