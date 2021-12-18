#include <stdio.h>
#include <time.h>
time_t tim;
int main()
{
    tim=clock();
    int j;
    int i,A,N,K[50000],c = 0,t = 0,M = 0;
    for(j=0;j<5000;++j){
        c=t=M=0;
        for(i=0;i<50000;++i)
            K[i]=0;

    
    scanf("%d%d",&N,&A);

    for(i = 0;i < N;i++)
        scanf("%d",&K[i]);

    while(c != N)
    {
        for(i = N - 1;i >= 0;i--)
            if(K[0] > A - t)
                break;
            else
                if(t + K[i] <= A)
                {
                    t += K[i];
                    if(K[i])
                        c++;
                    K[i] = 0;
                }
        M++;
        t = 0;
    }

    printf("%d\n",M);
    }
    tim = clock() - tim;
    printf ("It took me %d clicks (%f seconds).\n",tim,((float)tim)/CLOCKS_PER_SEC);
    return 0;
}
