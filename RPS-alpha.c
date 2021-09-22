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

int main(){
	char name[50];
	printf("\n\n");
	printf("Please enter your name (Maximum 50 Characters) >> ");
	gets(name);
	mainMenu(name);
}

void mainMenu(char name[]){
    system("cls");
	int menu;
	readFile("logo.txt");
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
			printf("Not yet available");
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

int play(char name[]){
	char usr_l, usr_r, usr_fd, usr_fh,com_fh, result, cont='y';
    char answ[50];
    int tie = 0, win = 0, lose = 0, round = 1;
    do{
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
        printf("user's left hand : ");
        if(usr_l == 'r')
            printf("rock\n");
        if(usr_l == 'p')
            printf("paper\n");
        if(usr_l == 's')
            printf("scissor\n");
        printf("user's right hand : ");
        if(usr_r == 'r')
            printf("rock\n");
        if(usr_r == 'p')
            printf("paper\n");
        if(usr_r == 's')
            printf("scissor\n");
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
		    readFile("lose.txt");
		    lose++;
	    }
	    if(result == 'l'){
	    	readFile("lose.txt");			
            lose++;
	    }
	    if(result == 't'){
	    	readFile("lose.txt");
	        lose++;
	    }
        printf("Continue? (y/n) >> ");
		scanf(" %c",&cont);
        if(lose%3==0 && lose!=0){
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

                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1){
                            printf("computer's hand : paper\n");
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

                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1){
                            printf("computer's hand : rock\n");

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


                    srand(time(NULL));
                    com_Right = 1 + rand()%2 ;

                        if(com_Right==1){
                            printf("computer's hand : rock\n");

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

char compare(char player, char computer){
	switch(player){
		case 'r' :
			printf("user's final hand : rock\n");
			if(computer == 'r'){
				printf("computer's final hand : rock\n");
				return 't';
			}
			else if(computer == 'p'){
				printf("computer's final hand : paper\n");
				return 'l';
			}
			else if(computer == 's'){
				printf("computer's final hand : scissor\n");
				return 'w';
			}	
			break;
		case 'p':
			printf("user's final hand : paper\n");
			if(computer == 'p'){
				printf("computer's final hand : paper\n");
				return 't';
			}
			else if(computer == 's'){
				printf("computer's final hand : scissor\n");
				return 'l';
			}
			else if(computer == 'r'){
				printf("computer's final hand : rock\n");
				return 'w';
			}
			break;
		case 's':
			printf("user's final hand : scissor\n");
			if(computer == 's'){
				printf("computer's final hand : scissor\n");
				return 't';
			}
			else if(computer == 'r'){
				printf("computer's final hand : rock\n");
				return 'l';
			}
			else if(computer == 'p'){
				printf("computer's final hand : paper\n");
				return 'w';
			}
			break;
		default :
			printf("Invalid input");
			break;
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

void readFile(char *FileName){
    printf("\n");
	char line[100];
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