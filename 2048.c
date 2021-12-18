#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int i,j,table[4][4],rx,ry,k,score=0,csum,a,b;
    char cmd;
    bool notfull=false,end=true;
    for(i=0;i<4;++i)
        for(j=0;j<4;++j)
            table[i][j]=0;
    srand(time(NULL));
    printf("2048\nUse WASD to move\n");
    do{
        //system("cls");
        printf("Your Score: %d\n",score);
        end=true;
        for(i=0;i<4;++i){
            for(j=0;j<4;++j){
                if(!table[i][j])
                    break;
            }
            if(!table[i][j])
                break;
        }
        if(!table[i][j])
            notfull=true;
        else notfull=false;
        if(notfull){
            do{
                rx=rand()%4;
                ry=rand()%4;
                
                if(!table[rx][ry])break;
            }while(1);
            table[rx][ry]=rand()%2+1;
        }
        for(i=0;i<4;++i){
            for(j=0;j<3;++j){
                printf("%d ",table[i][j]);
            }
            printf("%d\n",table[i][j]);
        }
        if(!notfull){
            for(i=0;i<4;++i){
                for(j=0;j<4;++j){
                    if(table[i][j]==table[i+1][j]||table[i][j]==table[i][j+1]){
                        end=false;
                        break;
                    }
                }
                if(!end) break;
            }
            
        }
        else end=false;
        if(end){
                printf("You Lost\n");
                //system("pause");
                return 0;        
        }
        do{
            scanf("%c",&cmd);
            cmd=cmd%32;
            if(cmd==23 ||cmd==1 ||cmd==19 ||cmd==4)break;
        }while(1);
        if(cmd==23){
            
            /*for(j=0;j<4;++j){
                for(i=0;i<3;++i){
                    while(!table[i][j] || (table[i][j]==table[i+1][j] && table[i][j])){
                        csum=0;
                        for(k=0;k<4;++k)
                            csum+=table[k][j];
                        if(!csum)break;
                        printf("i,j:%d %d %d\n",table[i][j],i,j);
                        if(!table[i][j]){
                            for(k=i;k<3;++k)
                                table[k][j]=table[k+1][j];
                            table[3][j]=0;
                            printf("case 0\n");
                            for(a=0;a<4;++a){
                                for(b=0;b<3;++b){
                                    printf("%d ",table[a][b]);
                                }
                                printf("%d\n",table[a][b]);
                            }

                            
                        }
                        else {
                            table[i][j]*=2;
                            score+=table[i][j];
                            for(k=i+2;k<4;++k){
                                table[k-1][j]=table[k][j];
                            }
                            table[3][j]=0;
                            printf("case same\n");
                            break;
                        }
             
                    }

                }
            }*/
            
            for(k=0;k<2;++k)for(j=0;j<4;++j){
                for(i=3;i>0;--i){
                    if(!table[i][j]){
                        continue;
                    }
                    else if(!table[i-1][j]){
                        table[i-1][j]=table[i][j];
                        table[i][j]=0;
                    }
                    else if(table[i-1][j]==table[i][j]){
                        table[i-1][j]*=2;
                        score+=table[i-1][j];
                        table[i][j]=0;
                    }
                }
            }
        }
        else if(cmd==4){
            for(k=0;k<2;++k)for(i=0;i<4;++i){
                for(j=0;j<3;++j){
                    if(!table[i][j]){
                        continue;
                    }
                    else if(!table[i][j+1]){
                        table[i][j+1]=table[i][j];
                        table[i][j]=0;
                    }
                    else if(table[i][j+1]==table[i][j]){
                        table[i][j+1]*=2;
                        score+=table[i][j+1];
                        table[i][j]=0;
                    }
                }
            }

        }
        else if(cmd==19){
            for(k=0;k<2;++k)for(j=0;j<4;++j){
                for(i=0;i<3;++i){
                    if(!table[i][j]){
                        continue;
                    }
                    else if(!table[i+1][j]){
                        table[i+1][j]=table[i][j];
                        table[i][j]=0;
                    }
                    else if(table[i+1][j]==table[i][j]){
                        table[i+1][j]*=2;
                        score+=table[i+1][j];
                        table[i][j]=0;
                    }
                }
            }

        }
        else if(cmd==1){
            for(k=0;k<2;++k)for(i=0;i<4;++i){
                for(j=3;j>0;--j){
                    if(!table[i][j]){
                        continue;
                    }
                    else if(!table[i][j-1]){
                        table[i][j-1]=table[i][j];
                        table[i][j]=0;
                    }
                    else if(table[i][j-1]==table[i][j]){
                        table[i][j-1]*=2;
                        score+=table[i][j-1];
                        table[i][j]=0;
                    }
                }
            }

        }
        
    }while(1);
    return 0;
}


