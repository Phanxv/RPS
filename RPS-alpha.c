#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>

char comhand();
char compare(char player, char computer);
int play();
void mainMenu(char name[]);
void exit(int status);
void writeStat(char name[],int win, int lose, int tie);
void readFile(char *FileName);
int readQuiz(int item_num);
char check(int item_num, char *ans);
char quiz(int item_num);
char compare2(char P1, char P2, char COM, char P1N[], char P2N[]);
void mainMenu2(char name1[],char name2[]);
void play2(char name1[],char name2[]);
char comHand2(char P1,char P2);
void writeStat2(char name1[], char name2[], int P1W, int P2W, int CW);

int main(){
    int mode;
    char name[50];
    char name1[50],name2[50];
    system("cls");
    printf("\n\nPlease select play mode by input mode number");
    printf("\n\n\t1. Single Player VS Computer\n");
    printf("\n\t2. 2 Player VS computer\n");
    printf("\nMode >> ");
    scanf("%d",&mode);
    switch(mode){
        case 1 :
            system("cls");
            printf("\n\nPlease Enter your name ( <50 characters ) : ");
            scanf("%s",name);
            mainMenu(name);
            break;
        case 2 :
            system("cls");
            char name1[50],name2[50];
            printf("\n\nEnter Player 1's name : ");
            scanf("%s",name1);
            printf("Enter Player 2's name : ");
            scanf("%s",name2);
            mainMenu2(name1,name2);
            break;
        default :
            printf("Error");
            break;
    }
}
void mainMenu(char name[]){
    int menu;
    system("cls");
	readFile("logo.txt");
    readFile("SinglePlayer.txt");
	printf("\n\nHello %s, Welcome to (ROCK PAPER SCISSOR)^2. \nplease select menu by input a number of menu.",name);
	printf("\n\n1. Play the game\n");
	printf("2. How to play?\n");
	printf("3. Statatistic\n");
	printf("4. Log out & Exit\n\n");
	printf("Select Menu >> ");
	scanf(" %d",&menu);
	while(menu < 1 || menu > 4){
		printf("Invalid input\n");
        printf("Select Menu >> ");
	    scanf(" %d",&menu);
	}
	switch(menu){
		case 1:
            system("cls");
			play(name);
			getch();
			//menu = 0;
			mainMenu(name);
			break;
		case 2:
            system("cls");
			readFile("HOW2PLAY.txt");
			getch();
			//menu = 0;
			mainMenu(name);
			break;
		case 3:
            system("cls");
			//menu = 0;
			printf("\n");
            readFile("stat banner.txt");
            readFile("stat.txt");
            printf("Press any keys to go back to the main menu.");
			getch();
			mainMenu(name);
			break;
		case 4:
			printf("Farewell, %s!",name);
			getch();
			exit(0);
			break;
	}
}

void mainMenu2(char name1[],char name2[]){
    int menu;
    system("cls");
	readFile("logo.txt");
    readFile("TwoPlayers.txt");
	printf("\n\nHello %s and %s, Welcome to (ROCK PAPER SCISSOR)^2 2 Players mode. \nplease select menu by input a number of menu.",name1,name2);
	printf("\n\n1. Play the game\n");
	printf("2. How to play?\n");
	printf("3. Statatistic\n");
	printf("4. Log out & Exit\n\n");
	printf("Select Menu >> ");
	scanf(" %d",&menu);
	while(menu < 1 || menu > 4){
		printf("Invalid input\n");
        printf("Select Menu >> ");
	    scanf(" %d",&menu);
	}
	switch(menu){
		case 1:
            system("cls");
			play2(name1,name2);
			getch();
			//menu = 0;
			mainMenu2(name1,name2);
			break;
		case 2:
			printf("Not yet available");
			getch();
			//menu = 0;
			mainMenu2(name1,name2);
			break;
		case 3:
            system("cls");
			//menu = 0;
			printf("\n");
            readFile("stat banner 2.txt");
            readFile("stat 2.txt");
            printf("Press any keys to go back to the main menu.");
			getch();
			mainMenu2(name1,name2);
			break;
		case 4:
			printf("Farewell, %s and %s!",name1,name2);
			getch();
			exit(0);
			break;
	}
}

int play(char name[]){
	char usr_l, usr_r, usr_fd, usr_fh,com_fh, result, cont='y';
    char answ[50];
    int tie = 0, win = 0, lose = 0, round = 1;
    do{
        system("cls");
        printf("\n\n********************ROUND %d********************\n\n",round);
        printf("user left hand (r,p,s)>> ");
        scanf(" %c",&usr_l);
        while(usr_l != 'r' && usr_l != 'p' && usr_l != 's'){
            printf("Invalid Input ( r for rock, p for paper, s for scissor )\n");
            printf("user left hand (r,p,s)>> ");
            scanf(" %c",&usr_l);
        }
        printf("user right hand (r,p,s)>> ");
        scanf(" %c",&usr_r);
        while(usr_r != 'r' && usr_r != 'p' && usr_r != 's'){
            printf("Invalid Input ( r for rock, p for paper, s for scissor )\n");
            printf("user right hand (r,p,s)>> ");
            scanf(" %c",&usr_r);
        }
        printf("\nuser's left hand : \n");
        if(usr_l == 'r')
            //printf("rock\n");
            readFile("rock.txt");
        if(usr_l == 'p')
           // printf("paper\n");
            readFile("paper.txt");
        if(usr_l == 's')
            //printf("scissor\n");
            readFile("scissor.txt");
        printf("\n\n\nuser's right hand : \n");
        if(usr_r == 'r')
           // printf("rock\n");
            readFile("rock.txt");
        if(usr_r == 'p')
            //printf("paper\n");
            readFile("paper.txt");
        if(usr_r == 's')
           // printf("scissor\n");
            readFile("scissor.txt");
        printf("\n\n");
        com_fh = comhand();
        printf("user final decision (%c,%c)>> ",usr_l,usr_r);
        scanf(" %c",&usr_fd);
        while(usr_fd != usr_l && usr_fd != usr_r){
        printf("Invalid input (please choose what is on your left hand or your right hand)\n");
        printf("user final decision >> ");
        scanf(" %c",&usr_fd);
        }
        usr_fh = usr_fd;
        result = compare(usr_fh, com_fh);
        if(result == 'w'){
		    readFile("win.txt");
		    win++;
	    }
	    if(result == 'l'){
	    	readFile("lose.txt");			
            lose++;
	    }
	    if(result == 't'){
	    	readFile("tie.txt");
	        tie++;
	    }
        printf("Continue? (y/n) >> ");
		scanf(" %c",&cont);
        if(lose%3==0 && lose!=0 && cont == 'y'){
            readFile("Quiztime.txt");
            getch();
            readQuiz(lose/3);
            printf("\n\nAnswer >> ");
            scanf("%s",&answ);
            cont = check(lose/3,answ);
        }
        round++;
    }while((cont == 'y' || cont == 'Y')&&round<=32);
    readFile("GameOver.txt");
    writeStat(name,win,lose,tie);
}

void play2(char name1[],char name2[]){
    srand(time(NULL));
    char P1,P2,COM,cont='y',WHOW;
    int round=1,P1W=0,P2W=0,CW=0;
    do{
        system("cls");
        printf("\n\n********************ROUND %d********************\n\n",round);
        printf("\n\nEnter %s's hand >> ",name1);
        scanf(" %c",&P1);
        while(P1!='r'&&P1!='p'&&P1!='s'){
            printf("Invalid input");
            printf("\n\nEnter %s's hand >> ",name1);
            scanf(" %c",&P1);
        }
        printf("Enter %s's hand >> ",name2);
        scanf(" %c",&P2);
        while(P2!='r'&&P2!='p'&&P2!='s'){
            printf("Invalid input");
            printf("\n\nEnter %s's hand >> ",name2);
            scanf(" %c",&P2);
        }
        COM = comHand2(P1,P2);
        printf("\nComputer's hand : %c\n",COM);
        WHOW = compare2(P1,P2,COM,name1,name2);
        if(WHOW=='A'){
            P1W++;
        }
        if(WHOW=='B'){
            P2W++;
        }
        if(WHOW=='C'){
            CW++;
        }
        if(WHOW=='D'){
            P1W++;
            P2W++;
        }
        if(WHOW=='F'){
            P1W++;
            CW++;
        }
        if(WHOW=='G'){
            P2W++;
            CW++;
        }
        printf("\n\nContinue? (y/n)>> ");
        scanf(" %c",&cont);
        round++;
    }while(cont=='y'||cont=='Y');
    writeStat2(name1,name2,P1W,P2W,CW);
    readFile("GameOver.txt");
    getch();
    mainMenu2(name1,name2);
}

char comhand() {
    /*  1 = rock
        2 = paper
        3 = scissor
    */
    int com_rand, com_Left, com_Right, com_RightOut;
    char com_Hfinal;
    int i;

        srand(time(NULL));
        i = rand()%3 + 1 ;
        com_Left = i;

            if (com_Left==1) {
                    printf("computer's hand : rock\n");
                    readFile("rock.txt");
                    printf("\n\n");
                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1){
                            printf("computer's hand : paper\n");
                            readFile("paper.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 'r';
                                    return 'r';
                                break;
                                case 2:
                                    com_Hfinal = 'p';
                                    return 'p';
                                break;
                            }
                        }

                        if(com_Right==2){
                            3 == com_Right;
                            printf("computer's hand : scissor\n");
                            readFile("scissor.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 'r';
                                    return 'r';
                                break;
                                case 2:
                                    com_Hfinal = 's';
                                    return 's';
                                break;
                            }
                        }

                }

            if (com_Left==2) {
                    printf("computer's hand : paper\n");
                    readFile("paper.txt");
                    printf("\n\n");
                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1){
                            printf("computer's hand : rock\n");
                            readFile("rock.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 'p';
                                    return 'p';
                                break;
                                case 2:
                                    com_Hfinal = 'r';
                                    return 'r';
                                break;
                            }
                        }
                        if(com_Right==2){
                            3 == com_Right;
                            printf("computer's hand : scissor\n");
                            readFile("scissor.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 'p';
                                    return 'p';
                                break;
                                case 2:
                                    com_Hfinal = 's';
                                    return 's';
                                break;
                            }
                        }

                }

            if (com_Left==3) {
                printf("computer's hand : scissor\n");
                readFile("scissor.txt");
                printf("\n\n");
                    srand(time(NULL));
                    com_Right = 1 + rand()%2 ;

                        if(com_Right==1){
                            printf("computer's hand : rock\n");
                            readFile("rock.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 's';
                                    return 's';
                                break;
                                case 2:
                                    com_Hfinal = 'r';
                                    return 'r';
                                break;
                            }

                        }
                        if(com_Right==2){
                            printf("computer's hand : paper\n");
                            readFile("paper.txt");
                            printf("\n\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 's';
                                    return 's';
                                break;
                                case 2:
                                    com_Hfinal = 'p';
                                    return 'p';
                                break;
                            }
                        }
                }

}

char comHand2(char P1,char P2){
    srand(time(NULL));
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

char compare(char player, char computer){
	switch(player){
		case 'r' :
			printf("user's final hand : rock\n");
            readFile("rock.txt");
			if(computer == 'r'){
				printf("computer's final hand : rock\n");
                readFile("rock.txt");
				return 't';
			}
			else if(computer == 'p'){
				printf("computer's final hand : paper\n");
                readFile("paper.txt");
				return 'l';
			}
			else if(computer == 's'){
				printf("computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 'w';
			}	
			break;
		case 'p':
			printf("user's final hand : paper\n");
            readFile("paper.txt");
			if(computer == 'p'){
				printf("computer's final hand : paper\n");
                readFile("paper.txt");
				return 't';
			}
			else if(computer == 's'){
				printf("computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 'l';
			}
			else if(computer == 'r'){
				printf("computer's final hand : rock\n");
                readFile("rock.txt");
				return 'w';
			}
			break;
		case 's':
			printf("user's final hand : scissor\n");
            readFile("scissor.txt");
			if(computer == 's'){
				printf("computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 't';
			}
			else if(computer == 'r'){
				printf("computer's final hand : rock\n");
                readFile("rock.txt");
				return 'l';
			}
			else if(computer == 'p'){
				printf("computer's final hand : paper\n");
                readFile("paper.txt");
				return 'w';
			}
			break;
		default :
			printf("Invalid input");
			break;
	}
}

char compare2(char P1, char P2, char COM, char P1N[], char P2N[]){
    //return A = P1 win, B = P2 win, C = Com win, D = P1&P2 win, F = P1&Com win, G = P2&Com win
    if(P1==P2){
        if(P1=='r'){
            printf("%s's hand : \n",P1N);
            readFile("rock.txt");
            printf("%s's hand : \n",P2N);
            readFile("rock.txt");
            if(COM == 'r'){
                printf("Computer's hand : \n");
                readFile("rock.txt");
                printf("TIE");
            }
            if(COM == 'p'){
                printf("Computer's hand : \n");
                readFile("paper.txt");
                printf("Computer win");
                return 'C';
            }
            if(COM == 's'){
                printf("Computer's hand : \n");
                readFile("scissor.txt");
                printf("%s & %s win",P1N,P2N);
                return 'D';
            }
        }
        if(P1=='p'){
            printf("%s's hand : \n",P1N);
            readFile("paper.txt");
            printf("%s's hand : \n",P2N);
            readFile("paper.txt");
            if(COM == 'p'){
                printf("Computer's hand : \n");
                readFile("paper.txt");
                printf("TIE");
            }
            if(COM == 's'){
                printf("Computer's hand : \n");
                readFile("scissor.txt");
                printf("Computer win");
                return 'C';
            }
            if(COM == 'r'){
                printf("Computer's hand : \n");
                readFile("rock.txt");
                printf("%s & %s win",P1N,P2N);
                return 'D';
            }
        }
        if(P1=='s'){
            printf("%s's hand : \n",P1N);
            readFile("scissor.txt");
            printf("%s's hand : \n",P2N);
            readFile("scissor.txt");
            if(COM == 's'){
                printf("Computer's hand : \n");
                readFile("scissor.txt");
                printf("TIE");
            }
            if(COM == 'r'){
                printf("Computer's hand : \n");
                readFile("rock.txt");
                printf("Computer win");
                return 'C';
            }
            if(COM == 'p'){
                printf("Computer's hand : \n");
                readFile("paper.txt");
                printf("%s & %s win",P1N,P2N);
                return 'D';
            }
        }
    }
    if(P1!=P2){
        if(P1=='r'&&P1==COM){
            printf("%s's hand : \n",P1N);
            readFile("rock.txt");
            printf("Computer's hand : \n");
            readFile("rock.txt");
            if(P2=='r'){
                printf("%s's hand : \n",P2N);
                readFile("rock.txt");
                printf("TIE");
            }
            if(P2=='p'){
                printf("%s's hand : \n",P2N);
                readFile("paper.txt");
                printf("%s win",P2N);
                return 'B';
            }
            if(P2=='s'){
                printf("%s's hand : \n",P2N);
                readFile("scissor.txt");
                printf("%s win & Computer",P1N);
                return 'F';
            }
        }
        if(P1=='p'&&P1==COM){
            printf("%s's hand : \n",P1N);
            readFile("paper.txt");
            printf("Computer's hand : \n");
            readFile("paper.txt");
            if(P2=='p'){
                printf("%s's hand : \n",P2N);
                readFile("paper.txt");
                printf("TIE");
            }
            if(P2=='s'){
                printf("%s's hand : \n",P2N);
                readFile("scissor.txt");
                printf("%s win",P2N);
                return 'B';
            }
            if(P2=='r'){
                printf("%s's hand : \n",P2N);
                readFile("rock.txt");
                printf("%s win & Computer",P1N);
                return 'F';
            }
        }
        if(P1=='s'&&P1==COM){
            printf("%s's hand : \n",P1N);
            readFile("scissor.txt");
            printf("Computer's hand : \n");
            readFile("scissor.txt");
            if(P2=='s'){
                printf("%s's hand : \n",P2N);
                readFile("scissor.txt");
                printf("TIE");
            }
            if(P2=='r'){
                printf("%s's hand : \n",P2N);
                readFile("rock.txt");
                printf("%s win",P2N);
                return 'B';
            }
            if(P2=='p'){
                printf("%s's hand : \n",P2N);
                readFile("paper.txt");
                printf("%s win & Computer",P1N);
                return 'F';
            }
        }
        if(P2=='r'&&P2==COM){
            printf("%s's hand : \n",P2N);
            readFile("rock.txt");
            printf("Computer's hand : \n");
            readFile("rock.txt");
            if(P1=='r'){
                printf("%s's hand : \n",P1N);
                readFile("rock.txt");
                printf("TIE");
            }
            if(P1=='p'){
                printf("%s's hand : \n",P1N);
                readFile("paper.txt");
                printf("%s win",P1N);
                return 'A';
            }
            if(P1=='s'){
                printf("%s's hand : \n",P2N);
                readFile("scissor.txt");
                printf("%s win & Computer",P2N);
                return 'G';
            }
        }
        if(P2=='p'&&P2==COM){
            printf("%s's hand : \n",P2N);
            readFile("paper.txt");
            printf("Computer's hand : \n");
            readFile("paper.txt");
            if(P1=='p'){
                printf("%s's hand : \n",P1N);
                readFile("paper.txt");
                printf("TIE");
            }
            if(P1=='s'){
                printf("%s's hand : \n",P1N);
                readFile("scissor.txt");
                printf("%s win",P1N);
                return 'A';
            }
            if(P1=='r'){
                printf("%s's hand : \n",P1N);
                readFile("rock.txt");
                printf("%s win & Computer",P2N);
                return 'G';
            }
        }
        if(P2=='s'&&P2==COM){
            printf("%s's hand : \n",P2N);
            readFile("scissor.txt");
            printf("Computer's hand : \n");
            readFile("scissor.txt");
            if(P1=='s'){
                printf("%s's hand : \n",P1N);
                readFile("scissor.txt");
                printf("TIE");
            }
            if(P1=='r'){
                printf("%s's hand : \n",P1N);
                readFile("rock.txt");
                printf("%s win",P1N);
                return 'A';
            }
            if(P1=='p'){
                printf("%s's hand : \n",P1N);
                readFile("paper.txt");
                printf("%s win & Computer",P2N);
                return 'G';
            }
        }
    }
}

void writeStat(char name[],int win, int lose, int tie){
	time_t t;
	time(&t);
	char stat[100];
	FILE *stat_pointer;
	stat_pointer = fopen("stat.txt","a");
	printf("Summary win : %d | lose : %d | tie : %d",win,lose,tie);
	sprintf(stat,"Username : %s | Summary win : %d | lose : %d | tie : %d | %s ",name,win,lose,tie,ctime(&t));
	fputs(stat,stat_pointer);
	fprintf(stat_pointer, "\n");
	fclose(stat_pointer);
}

void writeStat2(char name1[], char name2[], int P1W, int P2W, int CW){
	time_t t;
	time(&t);
	char stat[100];
	FILE *stat_pointer;
	stat_pointer = fopen("stat 2.txt","a");
	printf("%s win : %d | %s lose : %d | Computer win : %d",name1,P1W,name2,P2W,CW);
	sprintf(stat,"%s win : %d | %s lose : %d | Computer win : %d | %s ",name1,P1W,name2,P2W,CW,ctime(&t));
	fputs(stat,stat_pointer);
	fprintf(stat_pointer, "\n");
	fclose(stat_pointer);
}

void readFile(char *FileName){
    printf("\n");
	char line[200];
	FILE *fp = fopen(FileName,"r");
	while(fgets(line, sizeof(line), fp)){
		printf("%s",line);
	}
}

int readQuiz(int item_num){
    char item[10];
    sprintf(item,"Quiz %d.txt",item_num);
    readFile(item);
}

char check(int item_num, char *ans){
    char *ans_arr[] = {"d","c","Wednesday","shi","love","c","8","69x^2 + 420x","d","b"};
    if(strcmp(ans,ans_arr[item_num-1])==0){
        return 'y';
    }
    else{
        return 'n';
    }
}