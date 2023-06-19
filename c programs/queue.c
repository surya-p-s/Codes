#include<stdio.h>
#include<conio.h>

// ********* Queue insetion, deletion and printing*********
int a[50],f=-1,r=-1,n;
void que_in(){
    if(r==n-1)
        printf("OverFlow\n");
    else{
        int x;
        printf("Enter value to insert: ");
        scanf("%d",&x);
        r++;
        if(f==-1)
            f++;
        a[r]=x;
        printf("Value Inserted\n");
    }
}
void que_out(){
    if(f==-1 || f==n)
        printf("Under Flow\n");
    else{
        f++;
        printf("Value Deleted\n");
    }
}
int que_pri(){
    for (int i = f; i <= r; i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){

    int op;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    do{
        printf("1.For insertion 2.For deletion 3.For printing 4. For exit: ");
        scanf("%d",&op);
        if (op==1)
            que_in();
        else if (op==2)
            que_out();
        else if(op==3)
            que_pri();
        else if(op==4)
            return 0;
        else
            printf("Enter valid option\n");
    }while(1);
    return 0;
}