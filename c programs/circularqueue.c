#include<stdio.h>
// ************Circular Queue*************
int a[50],n,r=-1,f=-1,i;
void pri_que(){
    for (i = f; i!=r; i=(i+1)%n)
        printf("%d ",a[i]);
    printf("%d ",a[i]);
    printf("\n");
}
void enqueue(){
    if((f==0)&&(r==n-1)||(r==f-1))
        printf("Overflow\n");
    else{
        int x;
        printf("Enter value to enqueue: ");
        scanf("%d",&x);
        if(f==-1)
            f++;
        r=(r+1)%n;
        a[r]=x;
        printf("Value inserted\n");
    }
}
void dequeue(){
    if(f==-1 && r==-1)
        printf("Underflow\n");
    else
    {
        printf("Value deleted: %d\n",a[f]);
        if(f==r){
            f=-1;
            r=-1;
        }
        else
            f=(f+1)%n;
    }
    
}
int main(){
    int ch;
    printf("Enter size of array: ");
    scanf("%d",&n);
    do
    {
        printf("1.Enqueue 2.Dequeue 3.Print 4.Quit: ");
        scanf("%d",&ch);
        if (ch==1)
            enqueue();
        else if(ch==2)
            dequeue();
        else if(ch==3)
            pri_que();
        else if(ch==4)
            return 0;
        else printf("Enter valid option\n");
    } while (1);
    return 0;
}