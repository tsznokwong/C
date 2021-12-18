#include<stdio.h>
#include<string.h>

int main(){
    char str1[200];
    int i,j,l;
    int cnt[26][200];
    for(i=0;i<26;++i)
        for(j=0;j<200;++j)
            cnt[i][j]=0;
    
    scanf("%d%s",&l,str1);
    
    for(i=0;i<l;++i){
        cnt[str1[i]%65][0]++;
        cnt[str1[i]%65][cnt[str1[i]%65][0]]=i;
    }
    
    for(i=0;i<26;++i){
        if(cnt[i][0]){
            printf("%c %d ",i+65,cnt[i][0]);
            for(j=1;j<cnt[i][0];++j)
                printf("%d ",cnt[i][j]);
            printf("%d\n",cnt[i][j]);
        }
    }
    return 0;
}