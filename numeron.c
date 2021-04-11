#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int numeron[3]={0},turn=1,Numcombi[720][3]={0};
 int EAT=0,Get_EAT=0,Get_BITE=0; 
void Rule(void);
void Make_num(void);
void Allhands(void);
void Judge(void);
void C_thinking(void);
void SearchEAT(int i,int x );
void SearchBITE(int i,int y);



int main(void){      
    printf("ゲームスタート！\n");
    Rule();
    Make_num();
    Allhands();
    while(1){
    printf("\n\n---%dターン目---\n",turn);
    
    Judge();
    
    C_thinking();
    
    turn++;
    if(EAT==3||Get_EAT==3)break;
    }
    if(EAT==3)printf("プレーヤーの勝ち！\n");
    if(Get_EAT==3) printf("CPの勝ち！");
    return 0;
}




void Rule(void){
        printf("数当てゲームをします！\n");
        printf("------ルール説明------\n");
        printf("0-9までの数字が書かれた10枚のカードのうち3枚を使って、3桁の番号を作成します。\n");
        printf("カードに重複は無いので「550」「377」といった同じ数字を2つ以上使用した番号は作れません。\n");
        printf("先攻のプレイヤーは相手の番号を推理してコールして下さい。\n");
        printf("相手はコールされた番号と自分の番号を見比べ、コールされた番号がどの程度合っているかをしま宣言します。\n");
        printf("数字と桁が合っていた場合は「EAT」（イート）、\n");
        printf("数字は合っているが桁は合っていない場合は「BITE」（バイト）となります。\n");
        printf("これを先攻・後攻が繰り返して行い、先に相手の番号を完全に当てきった\n");
        printf("（3桁なら3EATを相手に宣言させた）プレイヤーの勝利となります。\n");
        printf("---------------------------例---------------------------------\n");
        printf("相手の番号が「765」・コールされた番号が「746」であった場合は、\n");
        printf("3桁のうち「7」は桁の位置が合致しているためEAT、\n");
        printf("「6」は数字自体は合っているが桁の位置が違うためBITE。\n");
        printf("EATが1つ・BITEが1つなので、「1EAT-1BITE」となります。\n");
        printf("--------------------------------------------------------------\n");
}

void Make_num(void){
while(1){for(int i=0;i<3;i++){
        srand((unsigned int) time(NULL));
        rand();rand();rand();rand();
        numeron[i]=rand()%10;
        sleep(1);
    }
    if(numeron[0]!=numeron[1]&&numeron[0]!=numeron[2]&&numeron[1]!=numeron[2])break;
}
    }


void Judge(void){
    int getnum[3]={0},BITE=0,j=0;
        
            EAT=0,BITE=0;
            while(1){
                printf("プレーヤーのターン\n");
                printf("推理した番号を1桁ずつ入力します。\n\n");
                for(j=0;j<3;j++){
                 printf("%d桁目の数字を入力してください。\n",3-j);
                    scanf("%d",&getnum[j]);
                }
            if(getnum[1]==getnum[0])printf("同じ数字を使っています。\nもう一度やり直してください。\n");
            else if(getnum[1]==getnum[2])printf("同じ数字を使っています。\nもう一度やり直してください。\n");
            else if(getnum[2]==getnum[0])printf("同じ数字を使っています。\nもう一度やり直してください。\n");
            else break;
            }

            for(j=0;j<3;j++)if(getnum[j]==numeron[j])EAT++;
            for(j=0;j<3;j++){
                if(getnum[j]==numeron[(j+1)%3])BITE++;
                if(getnum[j]==numeron[(j+2)%3])BITE++;
            }
            
         printf("あなたが推理した番号に対する結果は\n%dEAT-%dBITEです。\n",EAT,BITE);       
}


void Allhands(void){
int i,j,k,l=0;
l<720;         //絶対に配列の上限を超えてメモリを壊さないようにするため
for(i=0;i<10;i++){
    for(j=0;j<10;j++){
        if(i!=j){
        for(k=0;k<10;k++){
            if(i!=j&&i!=k&&j!=k){
                Numcombi[l][0]=i;
                Numcombi[l][1]=j;
                Numcombi[l][2]=k;
                l++;
                }
            }
        }
    }
}
}
int  answer[3]={0};
void C_thinking(void){
     printf("\nコンピューターのターン\n");
    if(turn==1){
        
            while(1){srand((unsigned int)time(NULL));
                rand();rand();
                answer[0]=rand()%10;
                rand();rand;
                answer[1]=rand()%10;
                rand();rand();
                answer[2]=rand()%10;
                if(answer[0]!=answer[1]&&answer[0]!=answer[2]&&answer[1]!=answer[2])break;
            }
            
            printf("あなたの番号は%d%d%dです。\n",answer[0],answer[1],answer[2]);
            
            printf("コンピュータが推理した番号に対する結果を入力して下さい。\n");
            printf("EAT:");
            scanf("%d",&Get_EAT);
            printf("BIte:");
            scanf("%d",&Get_BITE);
           
   }


    else{
            for(int i=0;i<720;i++){
            SearchEAT(Get_EAT,i);                       //同じEAT数になる組み合わせを探す
            SearchBITE(Get_BITE,i);                     //同じBITE数になる組み合わせを探す
          
            }
             for(int i=0;i<720;i++){
             if( Numcombi[i][0]!=-1&&Numcombi[i][1]!=-1&&Numcombi[i][2]!=-1){
                answer[0]=Numcombi[i][0];
                answer[1]=Numcombi[i][1];
                answer[2]=Numcombi[i][2];
                }
             }
            printf("あなたの考えた番号は%d%d%dです。\n", answer[0],answer[1],answer[2]);
            
         
            printf("コンピュータが推理した番号に対する結果を入力して下さい。\n");
            printf("EAT:");
            scanf("%d",&Get_EAT);
                                          
            printf("\nBITE:");
            scanf("%d",&Get_BITE);
            
          
}
}

void SearchEAT(int x,int i ){//xはEAT数
    int eat =0;
    
     if(answer[0]==Numcombi[i][0])eat++;
     if(answer[1]==Numcombi[i][1])eat++;
     if(answer[2]==Numcombi[i][2])eat++;     
            if(eat!=x){for(int j=0;j<3;j++)Numcombi[i][j]=-1;}
}

void SearchBITE(int y,int i){//yはBITE数
    int bite=0;
        for(int j=0;j<3;j++){
            if(answer[j]==Numcombi[i][(j+1)%3])bite++;
            if(answer[j]==Numcombi[i][(j+2)%3])bite++;
        }
        if(bite!=y){for(int j=0;j<3;j++)Numcombi[i][j]=-1;
    }
}