#include<stdio.h>
#include<conio.h>
int a[50],n,f=-1;

int pri_stack(){
    for(int i = 0; i<=f;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void push_stack(){
    if(f==n-1)
        printf("Over Flow\n");
    else{
        int x;
        printf("Enter element to push: ");
        scanf("%d",&x);
        f++;
        a[f]=x;
        printf("Element pushed\n");
        pri_stack();
    }
}
void pull_stack(){
    if(f==-1)
        printf("Under Flow\n");
    else{
        f--;
        printf("Element deleted\n");
    }
    pri_stack();
}


int main(){

    // ********* Stack push, pull and print *********
    
    int op;
    scanf("%d",&n);
    do
    {
        printf("1.To push element in stack   2. To pull element from stack  3. To print stack, 4. Exit: ");
        scanf("%d",&op);
        if(op==1)
            push_stack();
        else if(op==2)
            pull_stack();
        else if (op==3)
            pri_stack();
        else if(op==4)
            return 0;
        else
            printf("Enter valid option\n");
        
    } while(1);

    return 0;
}