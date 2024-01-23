#include<stdio.h>

int addint(int a){
    if(a==0){
        return 1;
    }
    else{
        return (a*addint(a-1));
    }
}

// 1*1*2*3*4*5=
int main(){

    int a=5,b=19;
    int r= addint(a);
    printf("%d",&r);
    return 0;
}
