#include<stdio.h>
#include<conio.h>

int part(int a[],int l,int u){
    int t;
    int p=a[l];
    int s=l,e=u;
    while (s<e)
    {
        while(a[s]<=p && s<e)
            s++;
        while(a[e]>p)    
            e--;
        if(s<e){
            t=a[s];
            a[s]=a[e];
            a[e]=t;
        }
    }
    a[l]=a[e];
    a[e]=p;
    return (e);
}

void quick_sort(int a[],int l,int u){
    int p;
    if(l<u){
        p=part(a,l,u);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,u);
    }
}

int main(){

    int a[100],n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    return 0;
}
