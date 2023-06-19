#include<stdio.h>
#include<malloc.h>
struct dl{
    struct dl *pev;
    int d;
    struct dl *next;
};
typedef struct dl node;
node *head=NULL,*nw,*p,*q;
void ins_beg(){
    int x;
    printf("Enter value: ");
    scanf("%d",&x);
    nw=(node*)malloc(sizeof(node));
    nw->d=x;
    nw->next=NULL;
    nw->pev=NULL;
    if(head==NULL)
        head=nw;
    else{
        nw->next=head;
        head->pev=nw;
        head=nw;
    } printf("Value Inserted\n");
}
void ins_pos(){
    int pos,x,c=1;
    printf("Enter Position and Value: ");
    scanf("%d %d",&pos, &x);
    nw=(node*)malloc(sizeof(node));
    nw -> d=x;
    nw -> next = NULL;
    nw -> pev = NULL;
    p=head;
    if(p==NULL)
        head=nw;
    else{
        while(p!=NULL && c<pos){
            q=p;
            p=p->next;
            c++;
        }
        q->next=nw;
        nw->pev=q;        
        p->pev=nw;
        nw->next = p;
    }
    printf("Value Inserted\n");
}
void ins_end(){
    int x;
    printf("Enter Value: ");
    scanf("%d",&x);
    nw=(node*)malloc(sizeof(node));
    nw -> d=x;
    nw -> next = NULL;
    p=head;
    if(head==NULL)
        head=nw;
    else{
        while(p->next!=NULL)
            p=p->next;
        
        nw->pev=p;
        p->next=nw;
    }
    printf("Value Inserted\n");
}
void del_beg(){
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        head=p->next;
        head->pev=NULL;
        free(p);
        printf("Value Deleted\n");
    }
}
void del_pos(){
    int pos,c=0;
    printf("Enter position: ");
    scanf("%d",&pos);
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        while(p->next!=NULL && c<pos-1){
            q=p;
            p=p->next;
            c++;
        }
        q->next=p->next;
        p->next->pev=q;
        printf("Value Deleted\n");
        free(p);
    }
}
void del_end(){
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
        printf("Value Deleted\n");
    }
}
void dis_dll(){
    p=head;
    int lr;
    printf("1.F2B  2.B2F: ");
    scanf("%d",&lr);
    if(p==NULL)
        printf("Empty List\n");
    else{
        if(lr==1){
            while (p!=NULL){
                printf("%d<->",p->d);
                p=p->next;
            }printf("\n");
        }   
        else if(lr==2){
            while(p->next!=NULL)
                p=p->next;
            while(p!=NULL){
                printf("%d<->",p->d);
                p=p->pev;
            }printf("\n");
        }
    }
}
int main(){
    int ch;
    do
    {
        printf("1.InsB 2.InsP 3.InsE 4.DelB 5.DelP 6.DelE 7.Dis: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_pos();
            break;
        case 3:
            ins_end();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_pos();
            break;
        case 6:
            del_end();
            break;
        case 7:
            dis_dll();
            break;
        default:
            break;
        }
    } while (1);
        

    return 0;
}