#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int d;
    struct node *next;
};

struct node *head=NULL,*p,*q,*nw;

void ins_beg(){
    int x;
    printf("Enter Value: ");
    scanf("%d",&x);
    nw=(struct node*)malloc(sizeof(struct node));
    nw -> d=x;
    nw -> next = NULL;
    if(head == NULL)
        head=nw;
    else{
        nw -> next = head;
        head =nw;
    }
    printf("Value Inserted\n");
}
void ins_end(){
    int x;
    printf("Enter Value: ");
    scanf("%d",&x);
    nw=(struct node*)malloc(sizeof(struct node));
    nw -> d=x;
    nw -> next = NULL;
    q=head;
    if(head == NULL)
        head=nw;
    else{
        while(q->next!=NULL)
            q=q->next;
        q->next=nw;
    }
    printf("Value Inserted\n");
}
void ins_pos(){
    int pos,x,c=0;
    printf("Enter pos and value: ");
    scanf("%d %d",&pos,&x);
    nw=(struct node*)malloc(sizeof(struct node));
    nw -> d=x;
    nw -> next = NULL; 
    p=head;
    if(head == NULL)
        head=nw;
    else{
        while(p!=NULL && c<pos-1){
            q=p;
            p=p->next;
            c++;
        }
        q->next=nw;
        nw->next=p;
    }
    printf("Value Inserted\n");
}
void del_beg(){
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        head=p->next;
        printf("Value deleted\n");
        free(p);
    }
}
void del_end(){
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        while(p->next != NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
        printf("Value deleted\n");
    }
}
void del_pos(){
    int pos,c=0;
    printf("Enter Pos to delete: ");
    scanf("%d",&pos);
    p=head;
    if(head==NULL)
        printf("Empty List\n");
    else{
        while(p->next!= NULL && c<pos-1){
            q=p;
            p=p->next;
            c++;
        }
        q->next=p->next;
        free(p);
        printf("Value deleted\n");
    }
}
void dis_list(){
    p=head;
    if(p==NULL)
        printf("Empty List\n");
    else{
        while(p!=NULL){
            printf("%d->",p->d);
            p=p->next;
        }printf("\n");
    }
}
int main(){
    int ch;
    do{
        printf("1.Ins Beg 2.Ins End 3.Ins Any Pos \n4.Display \n5.Del Beg 6.Del End 7.Del Any Pos: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                ins_beg();
                break;
            case 2:
                ins_end();
                break;
            case 3:
                ins_pos();
                break;
            case 4:
                dis_list();
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_end();
                break;
            case 7:
                del_pos();
                break;
            default:
                break; 
        }
    }while(1);
    
    return 0;
}