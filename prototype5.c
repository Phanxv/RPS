#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void Single();
void TwoPlayer();
void compare(char P1, char P2, char COM, char P1N[], char P2N[]);
void play2(char name1[],char name2[]);
char comHand2(char P1,char P2);

int main(){
    int mode;
    system("cls");
    printf("Please select play mode by input mode number");
    printf("\n1. Single Player VS Computer\n");
    printf("2. 2 Player VS computer\n");
    printf("\nMode >> ");
    scanf("%d",&mode);
    switch(mode){
        case 1 :
            Single();
            break;
        case 2 :
            TwoPlayer();
            break;
        default :
            printf("Error");
            break;
    }
}

void Single(){
    char player[50];
    printf("Enter your name : ");
    scanf("%s",player);
    system("cls");
    printf("Hello %s\nWelcome to single player mode",player);
}

void TwoPlayer(){
    char player1[50],player2[50];
    printf("Enter Player 1's name : ");
    scanf("%s",player1);
    printf("Enter Player 2's name : ");
    scanf("%s",player2);
    //system("cls");
    printf("Hello %s and %s\nWelcome to 2 player mode",player1,player2);
    getch();
    play2(player1,player2);
}

void play2(char name1[],char name2[]){
    srand(time(NULL));
    char P1,P2,COM;
    printf("\n\nEnter %s's hand >> ",name1);
    scanf(" %c",&P1);
    printf("Enter %s's hand >> ",name2);
    scanf(" %c",&P2);
    COM = comHand2(P1,P2);
    printf("\nComputer's hand : %c\n",COM);
    compare(P1,P2,COM,name1,name2);
}

char comHand2(char P1,char P2){
    char ComHand;
    if(P1 == P2){
        ComHand = rand()%3+1;
        switch(ComHand){
            case 1:
                //printf("Com : rock");
                return 'r';
                break;
            case 2:
                //printf("Com : paper");
                return 'p';
                break;
            case 3:
               //printf("Com : scissor");
                return 's';
                break;
        }
    }
    else{
        ComHand = rand()%2+1;
        switch(ComHand){
            case 1:
                return P1;
                break;
            case 2:
                return P2;
                break;
        }
    }
}

void compare2(char P1, char P2, char COM, char P1N[], char P2N[]){
    if(P1==P2){
        if(P1=='r'){
            if(COM == 'r'){
                printf("TIE");
            }
            if(COM == 'p'){
                printf("Computer win");
            }
            if(COM == 's'){
                printf("%s & %s win",P1N,P2N);
            }
        }
        if(P1=='p'){
            if(COM == 'p'){
                printf("TIE");
            }
            if(COM == 's'){
                printf("Computer win");
            }
            if(COM == 'r'){
                printf("%s & %s win",P1N,P2N);
            }
        }
        if(P1=='s'){
            if(COM == 's'){
                printf("TIE");
            }
            if(COM == 'r'){
                printf("Computer win");
            }
            if(COM == 'p'){
                printf("%s & %s win",P1N,P2N);
            }
        }
    }
    if(P1!=P2){
        if(P1=='r'&&P1==COM){
            if(P2=='r'){
                printf("TIE");
            }
            if(P2=='p'){
                printf("%s win",P2N);
            }
            if(P2=='s'){
                printf("%s win",P1N);
            }
        }
        if(P1=='p'&&P1==COM){
            if(P2=='p'){
                printf("TIE");
            }
            if(P2=='s'){
                printf("%s win",P2N);
            }
            if(P2=='r'){
                printf("%s win",P1N);
            }
        }
        if(P1=='s'&&P1==COM){
            if(P2=='s'){
                printf("TIE");
            }
            if(P2=='r'){
                printf("%s win",P2N);
            }
            if(P2=='p'){
                printf("%s win",P1N);
            }
        }
        if(P2=='r'&&P2==COM){
            if(P1=='r'){
                printf("TIE");
            }
            if(P1=='p'){
                printf("%s win",P1N);
            }
            if(P1=='s'){
                printf("%s win",P2N);
            }
        }
        if(P2=='p'&&P2==COM){
            if(P1=='p'){
                printf("TIE");
            }
            if(P1=='s'){
                printf("%s win",P1N);
            }
            if(P1=='r'){
                printf("%s win",P2N);
            }
        }
        if(P2=='s'&&P2==COM){
            if(P1=='s'){
                printf("TIE");
            }
            if(P1=='r'){
                printf("%s win",P1N);
            }
            if(P1=='p'){
                printf("%s win",P2N);
            }
        }
    }
}