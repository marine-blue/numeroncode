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
    printf("�Q�[���X�^�[�g�I\n");
    Rule();
    Make_num();
    Allhands();
    while(1){
    printf("\n\n---%d�^�[����---\n",turn);
    
    Judge();
    
    C_thinking();
    
    turn++;
    if(EAT==3||Get_EAT==3)break;
    }
    if(EAT==3)printf("�v���[���[�̏����I\n");
    if(Get_EAT==3) printf("CP�̏����I");
    return 0;
}




void Rule(void){
        printf("�����ăQ�[�������܂��I\n");
        printf("------���[������------\n");
        printf("0-9�܂ł̐����������ꂽ10���̃J�[�h�̂���3�����g���āA3���̔ԍ����쐬���܂��B\n");
        printf("�J�[�h�ɏd���͖����̂Łu550�v�u377�v�Ƃ���������������2�ȏ�g�p�����ԍ��͍��܂���B\n");
        printf("��U�̃v���C���[�͑���̔ԍ��𐄗����ăR�[�����ĉ������B\n");
        printf("����̓R�[�����ꂽ�ԍ��Ǝ����̔ԍ�������ׁA�R�[�����ꂽ�ԍ����ǂ̒��x�����Ă��邩�����ܐ錾���܂��B\n");
        printf("�����ƌ��������Ă����ꍇ�́uEAT�v�i�C�[�g�j�A\n");
        printf("�����͍����Ă��邪���͍����Ă��Ȃ��ꍇ�́uBITE�v�i�o�C�g�j�ƂȂ�܂��B\n");
        printf("������U�E��U���J��Ԃ��čs���A��ɑ���̔ԍ������S�ɓ��Ă�����\n");
        printf("�i3���Ȃ�3EAT�𑊎�ɐ錾�������j�v���C���[�̏����ƂȂ�܂��B\n");
        printf("---------------------------��---------------------------------\n");
        printf("����̔ԍ����u765�v�E�R�[�����ꂽ�ԍ����u746�v�ł������ꍇ�́A\n");
        printf("3���̂����u7�v�͌��̈ʒu�����v���Ă��邽��EAT�A\n");
        printf("�u6�v�͐������͍̂����Ă��邪���̈ʒu���Ⴄ����BITE�B\n");
        printf("EAT��1�EBITE��1�Ȃ̂ŁA�u1EAT-1BITE�v�ƂȂ�܂��B\n");
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
                printf("�v���[���[�̃^�[��\n");
                printf("���������ԍ���1�������͂��܂��B\n\n");
                for(j=0;j<3;j++){
                 printf("%d���ڂ̐�������͂��Ă��������B\n",3-j);
                    scanf("%d",&getnum[j]);
                }
            if(getnum[1]==getnum[0])printf("�����������g���Ă��܂��B\n������x��蒼���Ă��������B\n");
            else if(getnum[1]==getnum[2])printf("�����������g���Ă��܂��B\n������x��蒼���Ă��������B\n");
            else if(getnum[2]==getnum[0])printf("�����������g���Ă��܂��B\n������x��蒼���Ă��������B\n");
            else break;
            }

            for(j=0;j<3;j++)if(getnum[j]==numeron[j])EAT++;
            for(j=0;j<3;j++){
                if(getnum[j]==numeron[(j+1)%3])BITE++;
                if(getnum[j]==numeron[(j+2)%3])BITE++;
            }
            
         printf("���Ȃ������������ԍ��ɑ΂��錋�ʂ�\n%dEAT-%dBITE�ł��B\n",EAT,BITE);       
}


void Allhands(void){
int i,j,k,l=0;
l<720;         //��΂ɔz��̏���𒴂��ă��������󂳂Ȃ��悤�ɂ��邽��
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
     printf("\n�R���s���[�^�[�̃^�[��\n");
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
            
            printf("���Ȃ��̔ԍ���%d%d%d�ł��B\n",answer[0],answer[1],answer[2]);
            
            printf("�R���s���[�^�����������ԍ��ɑ΂��錋�ʂ���͂��ĉ������B\n");
            printf("EAT:");
            scanf("%d",&Get_EAT);
            printf("BIte:");
            scanf("%d",&Get_BITE);
           
   }


    else{
            for(int i=0;i<720;i++){
            SearchEAT(Get_EAT,i);                       //����EAT���ɂȂ�g�ݍ��킹��T��
            SearchBITE(Get_BITE,i);                     //����BITE���ɂȂ�g�ݍ��킹��T��
          
            }
             for(int i=0;i<720;i++){
             if( Numcombi[i][0]!=-1&&Numcombi[i][1]!=-1&&Numcombi[i][2]!=-1){
                answer[0]=Numcombi[i][0];
                answer[1]=Numcombi[i][1];
                answer[2]=Numcombi[i][2];
                }
             }
            printf("���Ȃ��̍l�����ԍ���%d%d%d�ł��B\n", answer[0],answer[1],answer[2]);
            
         
            printf("�R���s���[�^�����������ԍ��ɑ΂��錋�ʂ���͂��ĉ������B\n");
            printf("EAT:");
            scanf("%d",&Get_EAT);
                                          
            printf("\nBITE:");
            scanf("%d",&Get_BITE);
            
          
}
}

void SearchEAT(int x,int i ){//x��EAT��
    int eat =0;
    
     if(answer[0]==Numcombi[i][0])eat++;
     if(answer[1]==Numcombi[i][1])eat++;
     if(answer[2]==Numcombi[i][2])eat++;     
            if(eat!=x){for(int j=0;j<3;j++)Numcombi[i][j]=-1;}
}

void SearchBITE(int y,int i){//y��BITE��
    int bite=0;
        for(int j=0;j<3;j++){
            if(answer[j]==Numcombi[i][(j+1)%3])bite++;
            if(answer[j]==Numcombi[i][(j+2)%3])bite++;
        }
        if(bite!=y){for(int j=0;j<3;j++)Numcombi[i][j]=-1;
    }
}