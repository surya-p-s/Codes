#include<stdio.h>

// ****************Recurssive***************

int rec_bin_search(int a[],int l,int u,int x){
    int m;
    if (l<=u)
    {
        m=(l+u)/2;
        if (a[m]==x)
            return (m);
        else if (a[m]<x)
            return (rec_bin_search(a,m+1,u,x));
        else if(a[m]>x)
            return (rec_bin_search(a,l,m-1,x));
    }
    return (-1);
}

// *****************non recurssive*****************

// int bin_search(int a[],int l,int u,int x){
//     int m;
//     while(l<=u){
//         m=(l+u)/2;
//         if(a[m]==x)
//             return (m);
//         else if (a[m]<x)
//           l=m+1;
//         else if(a[m]>x)
//             u=m-1;
//     }
//     return -1;
// }

int main(){

    int a[100],n,i,x,pos;   
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    pos=rec_bin_search(a,0,n-1,x);
    if(pos==-1)
        printf("Value not present");
    else
        printf("Value present in %d positions",pos+1);
    return 0;
}
