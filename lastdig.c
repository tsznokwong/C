#include<stdio.h>
int power(int m,int n){
    if(!n)return 1;
    else return (m*power(m,n-1))%10;
}
int main(){
    int m,n,i,k;
    scanf("%d",&k);
    for(i=0;i<k;++i){
        scanf("%d%d",&m,&n);
        m%=10;
        if(n&&!(n%4)){
            printf("%d\n",power(m,4));
            continue;
        }
        n%=4;
        printf("%d\n",power(m,n));
    }
    return 0;
}
/*
1 1 1 1 1 1
1 2 4 8 6 2
1 3 9 7 1 3
1 4 6 4 6 4
1 5 5 5 5 5
1 6 6 6 6 6
1 7 9 3 1 7
1 8 4 2 6 8
1 9 1 9 1 9
1 0 0 0 0 0 */