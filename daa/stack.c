#include <stdio.h>
#define N 5
int stack[N];
int top = -1;
void push ();
void pop ();
void display ();
int main () {
    int ch;
    do {
        printf ("Enter your choice 1: push 2: pop 3: display 0: exit: ");
        scanf ("%d", &ch);
        switch (ch) {
            case 1:
                push ();
                break;
            case 2:
                pop ();
                break;
            case 3:
                display ();
                break;
            case 0:
                break;
            default:
                printf ("Enter the right choice\n");
        }
    } while (ch!= 0);
    return 0;
}
void push () {
    int x;
    printf ("Enter the element to be pushed: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("Overflow condition\n");
    } else {
        top++;
        stack[top] = x;
        printf("Push successful\n");
    }
}
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    }
}
void pop()
{
    int temp;
    if (top == -1) {
    printf("Underflow\n");
    }
    else {
        temp = stack[top];
        top--;
        printf("Pop successful\n");
        printf("%d is popped\n", temp);
    }
}