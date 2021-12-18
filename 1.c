#include <stdio.h>
int K[50],N,A,cnt=0,c,m=0;
void swap(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int func(int i,int C){
    int t=0;
    c=0;
    for(;i >= 0;i--){
        if(K[i] && t + K[i] <= C){
            t += K[i];
            c++;
            if(t + K[m] > C)
                break;

        }
    }
    return C-t;
}
int main(){

    int j,x,y;
    int i,t = 0,M = 0,min,k;
    scanf("%d%d",&N,&A);

    for(i = 0;i < N;i++)
        scanf("%d",&K[i]);
    if(N==1){
        printf("1\n");
        return 0;
    }
    for(i=1;i<N;++i){
        k=i;
        for(j=i-1;j>=0;--j){
            if(K[k]<K[j]){
                swap(&K[k],&K[j]);
                --k;
            }
            else break;
        }
    }
        for(i = N - 1;i >= 0;i--){
            min = 201;
            if(!K[i])
                continue;
            t+=K[i];
            ++cnt;
            K[i]=0;
            for(j=i-1;j>=0;--j){
                if(K[j]==K[j+1]&&j!=i-1)continue;
                x=func(j,A-t);
                if(min>x){
                    min=x;
                    y=j;
                }
                if(!x)
                    break;
            }
            for(j=y;j >= 0;j--){
                if(K[j] && t + K[j] <= A){
                    t += K[j];
                    cnt++;
                    K[j] = 0;
                    if(m==j)
                        while(!K[m])
                            ++m;
                    
                    if(t + K[m] > A)
                        break;
                    
                }
            }
            t=0;M++;
            if(cnt==N)break;
        }
    

    printf("%d\n",M);
    
    
    return 0;
}
