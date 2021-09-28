#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>

char comhand();
char compare(char *player, char computer);
int play();
void mainMenu(char name[]);
void exit(int status);
void writeStat(char name[],int win, int lose, int tie);
void readFile(char *FileName);

char compare2(char *P1, char *P2, char *COM, char P1N[], char P2N[]);
void mainMenu2(char name1[],char name2[]);
void play2(char name1[],char name2[]);
const char* comHand2(char *P1,char *P2);
void writeStat2(char name1[], char name2[], int P1W, int P2W, int CW);

int main()
{
    char mode[2];
    char name[50];
    char name1[50],name2[50];
    system("cls");
    printf("\n\nPlease select play mode by input mode number");
    printf("\n\n\t1. Single Player VS Computer\n");
    printf("\n\t2. 2 Player VS computer\n");
    printf("\nMode >> ");
    gets(mode);
    while (strcmp(mode,"1") != 0 && strcmp(mode,"2") != 0)
    {
        printf("Invalid input (input 1 or 2)");
        printf("\nMode >> ");
        gets(mode);
    }
    if (strcmp(mode,"1") == 0)
    {
        system("cls");
        printf("\n\n\tPlease Enter your name ( <50 characters ) : ");
        gets(name);
        mainMenu(name);
    }
    else if (strcmp(mode,"2") == 0)
    {
        system("cls");
        char name1[50],name2[50];
        printf("\n\n\tEnter Player 1's name : ");
        gets(name1);
        printf("\tEnter Player 2's name : ");
        gets(name2);
        mainMenu2(name1,name2);
    }
}

void mainMenu(char name[])
{
    char menu[20];
    system("cls");
	readFile("logo.txt");
    readFile("SinglePlayer.txt");
	printf("\n\nHello %s, Welcome to (ROCK PAPER SCISSOR)^2. \nplease select menu by input a number of menu.",name);
	printf("\n\n\t1. Play the game\n");
	printf("\t2. How to play?\n");
	printf("\t3. Statatistic\n");
	printf("\t4. Log out & Exit\n\n");

	printf("Select Menu >> ");
	scanf("%s",menu);

	while ( strcmp(menu,"1")!=0 && strcmp(menu,"2")!=0 && strcmp(menu,"3")!=0 && strcmp(menu,"4")!=0 )
    {
        printf("Invalid input\n");
        printf("Select Menu >> ");
	    scanf("%s",menu);
    }

	if ( strcmp(menu,"1")==0 )
	{
        system("cls");
        play(name);
        getch();
        mainMenu(name);
	}
	else if ( strcmp(menu,"2")==0 )
    {
        system("cls");
        readFile("HOW2PLAY.txt");
        getch();
        mainMenu(name);
    }
	else if ( strcmp(menu,"3")==0 )
    {
        system("cls");
        printf("\n");
        readFile("stat banner.txt");
        readFile("stat.txt");
        printf("Press any keys to go back to the main menu.");
        getch();
        mainMenu(name);
    }
	else if ( strcmp(menu,"4")==0 )
    {
        printf("Farewell, %s!",name);
        getch();
        exit(0);
	}
}

void mainMenu2(char name1[],char name2[])
{
    char menu[20];
    system("cls");
	readFile("logo.txt");
    readFile("TwoPlayers.txt");
	printf("\n\nHello %s and %s, Welcome to (ROCK PAPER SCISSOR)^2 2 Players mode. \nplease select menu by input a number of menu.",name1,name2);
	printf("\n\n\t1. Play the game\n");
	printf("\t2. How to play?\n");
	printf("\t3. Statatistic\n");
	printf("\t4. Log out & Exit\n\n");

	printf("Select Menu >> ");
	scanf("%s",menu);

	while ( strcmp(menu,"1")!=0 && strcmp(menu,"2")!=0 && strcmp(menu,"3")!=0 && strcmp(menu,"4")!=0 )
    {
        printf("Invalid input\n");
        printf("Select Menu >> ");
	    scanf("%s",menu);
    }
    if ( strcmp(menu,"1")==0 )
    {
        system("cls");
        play2(name1,name2);
        getch();
        mainMenu2(name1,name2);
    }
    else if ( strcmp(menu,"2")==0 )
	{
        printf("Not yet available");
        getch();
        mainMenu2(name1,name2);
	}
    else if ( strcmp(menu,"3")==0 )
    {
        system("cls");
        printf("\n");
        readFile("stat banner 2.txt");
        readFile("stat 2.txt");
        printf("Press any keys to go back to the main menu.");
        getch();
        mainMenu2(name1,name2);
    }
    else if ( strcmp(menu,"4")==0 )
	{
        printf("Farewell, %s and %s!",name1,name2);
        getch();
        exit(0);
	}
}

int play(char name[])
{
	char usr_l[20], usr_r[20], usr_fd[20], usr_fh[20],com_fh, result, cont[2]="y";
    char answ[50];
    int tie = 0, win = 0, lose = 0, round = 1;
    do{
        system("cls");
        printf("\n\n******************** ROUND %d ********************\n\n",round);

        do {
            printf("\n  Your left hand (r,p,s)>> ");
            scanf("%s", usr_l);
            if (strcmp(usr_l,"r") == 0 || strcmp(usr_l,"p") == 0 || strcmp(usr_l,"s") == 0
                || strcmp(usr_l,"R") == 0|| strcmp(usr_l,"P") == 0|| strcmp(usr_l,"S") == 0)
                {
                    if(strcmp(usr_l,"r")==0||strcmp(usr_l,"R")==0)
                        {
                            readFile("rock.txt");
                        }
                    if(strcmp(usr_l,"p")==0||strcmp(usr_l,"P")==0)
                        {
                            readFile("paper.txt");
                        }
                    if(strcmp(usr_l,"s")==0||strcmp(usr_l,"S")==0)
                        {
                            readFile("scissor.txt");
                        }
                    break;
                }
            else
                {
                    printf("\n\tInvalid input please try again...\n\t( r for rock, p for paper, s for scissor )\n");
                }
        } while ( (strcmp(usr_l,"r") != 0 && strcmp(usr_l,"p") != 0 && strcmp(usr_l,"s") != 0 )
               || ( strcmp(usr_l,"R") != 0&& strcmp(usr_l,"P") != 0&& strcmp(usr_l,"S") != 0));

        do {
            printf("\n  Your right hand (r,p,s)>> ");
            scanf("%s", usr_r);
            if (strcmp(usr_r,"r") == 0 || strcmp(usr_r,"p") == 0 || strcmp(usr_r,"s") == 0
                || strcmp(usr_r,"R") == 0|| strcmp(usr_r,"P") == 0|| strcmp(usr_r,"S") == 0)
                {
                    if(strcmp(usr_r,"r")==0||strcmp(usr_r,"R")==0)
                        {
                            readFile("rock.txt");
                        }
                    if(strcmp(usr_r,"p")==0||strcmp(usr_r,"P")==0)
                        {
                            readFile("paper.txt");
                        }
                    if(strcmp(usr_r,"s")==0||strcmp(usr_r,"S")==0)
                        {
                            readFile("scissor.txt");
                        }
                    break;
                }
            else
                {
                    printf("\n\tInvalid input please try again...\n\t( r for rock, p for paper, s for scissor )\n");
                }
        } while ( (strcmp(usr_r,"r") != 0 && strcmp(usr_r,"p") != 0 && strcmp(usr_r,"s") != 0 )
               || ( strcmp(usr_r,"R") != 0&& strcmp(usr_r,"P") != 0&& strcmp(usr_r,"S") != 0));

        printf("\n\n\n  >> press any keys to show computer's hand <<\n");
        getch();

        printf("\n\n");
        com_fh = comhand();

        printf("\n\n  Your final decision (%s,%s) >> ", usr_l, usr_r);
        scanf("%s",usr_fd);

        while(strcmp(usr_fd,usr_l) != 0 && strcmp(usr_fd,usr_r) != 0)
        {
            if (strcmp(usr_fd,usr_l) == 0 && strcmp(usr_fd,usr_r) == 0)
                {
                    break;
                }
            else
                {
                    printf("\n\tInvalid input (please choose what is on your left hand or your right hand)\n");
                }
            printf("\n\n  Your final decision (%s,%s) >> ", usr_l, usr_r);
            scanf("%s",usr_fd);
        }

        strcpy(usr_fh,usr_fd);
        result = compare(usr_fh, com_fh);
        if(result == 'w')
            {
                readFile("win.txt");
                win++;
            }
	    if(result == 'l')
            {
                readFile("lose.txt");
                lose++;
            }
	    if(result == 't')
            {
                readFile("tie.txt");
                tie++;
            }
        printf("Continue? (y/n) >> ");
		scanf("%s",cont);
		while ( (strcmp(cont,"y")!=0 && strcmp(cont,"Y")!=0)
                && (strcmp(cont,"n")!=0 && strcmp(cont,"N")!=0) )
            {
                printf("Continue? (y/n) >> ");
                scanf("%s",cont);
            }
        round++;
    }   while( (strcmp(cont,"y")==0 || strcmp(cont,"Y")==0) );
    readFile("GameOver.txt");
    writeStat(name,win,lose,tie);
}

void play2(char name1[],char name2[])
{
    srand(time(NULL));
    char P1[20],P2[20],COM[2],cont[2]="Y",WHOW;
    int round=1,P1W=0,P2W=0,CW=0;
    do
    {
        system("cls");
        printf("\n\n******************** ROUND %d ********************\n\n",round);

        do
        {
            printf("\n  Enter %s's hand (r,p,s) >> ", name1);
            scanf("%s",P1);
            if ( strcmp(P1,"r")==0 || strcmp(P1,"p")==0 || strcmp(P1,"s")==0
                || strcmp(P1,"R")==0 || strcmp(P1,"P")==0 || strcmp(P1,"S")==0 )
                {
                    if(strcmp(P1,"r")==0||strcmp(P1,"R")==0)
                        {
                            readFile("rock.txt");
                        }
                    if(strcmp(P1,"p")==0||strcmp(P1,"P")==0)
                        {
                            readFile("paper.txt");
                        }
                    if(strcmp(P1,"s")==0||strcmp(P1,"S")==0)
                        {
                            readFile("scissor.txt");
                        }
                    break;
                }
            else
                {
                    printf("\n\tInvalid input please try again...\n\t( r for rock, p for paper, s for scissor )\n");
                }
        } while ( (strcmp(P1,"r")!=0 && strcmp(P1,"p")!=0 && strcmp(P1,"s")!=0)
                || (strcmp(P1,"R")!=0 && strcmp(P1,"P")!=0 && strcmp(P1,"S")!=0) );

        do
        {
            printf("\n  Enter %s's hand (r,p,s) >> ", name2);

            scanf("%s",P2);
            if ( strcmp(P2,"r")==0 || strcmp(P2,"p")==0 || strcmp(P2,"s")==0
                || strcmp(P2,"R")==0 || strcmp(P2,"P")==0 || strcmp(P2,"S")==0 )
                {
                    if(strcmp(P2,"r")==0||strcmp(P2,"R")==0)
                        {
                            readFile("rock.txt");
                        }
                    if(strcmp(P2,"p")==0||strcmp(P2,"P")==0)
                        {
                            readFile("paper.txt");
                        }
                    if(strcmp(P2,"s")==0||strcmp(P2,"S")==0)
                        {
                            readFile("scissor.txt");
                        }
                    break;
                }
            else
                {
                    printf("\n\tInvalid input please try again...\n\t( r for rock, p for paper, s for scissor )\n");
                }
        } while ( (strcmp(P2,"r")!=0 && strcmp(P2,"p")!=0 && strcmp(P2,"s")!=0)
                || (strcmp(P2,"R")!=0 && strcmp(P2,"P")!=0 && strcmp(P2,"S")!=0) );

        strcpy(COM,comHand2(&P1,&P2));
        printf(">> press any keys to continue <<\n\n");
        getch();
        printf("\n  Computer's hand : %s\n\n",COM);

        WHOW = compare2(P1,P2,COM,name1,name2);
        if(WHOW=='A')
            {
                P1W++;
            }
        if(WHOW=='B')
            {
                P2W++;
            }
        if(WHOW=='C')
            {
                CW++;
            }
        if(WHOW=='D')
            {
                P1W++;
                P2W++;
            }
        if(WHOW=='F')
            {
                P1W++;
                CW++;
            }
        if(WHOW=='G')
            {
                P2W++;
                CW++;
            }
        printf("\n\nContinue? (y/n)>> ");
        scanf("%s",cont);
        round++;

    }   while( strcmp(cont,"y")==0 || strcmp(cont,"Y")==0 );

    writeStat2(name1,name2,P1W,P2W,CW);
    readFile("GameOver.txt");
    getch();
    mainMenu2(name1,name2);
}

char comhand()
{
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

            if (com_Left==1)
                {
                    printf("  computer's hand are: rock ");
                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1)
                        {
                            printf("and paper\n");
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)
                            {
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

                        if(com_Right==2)
                        {
                            printf("and scissor\n");
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

            if (com_Left==2)
                {
                    printf("  computer's hand are: paper ");
                        srand(time(NULL));
                        com_Right = 1 + rand()%2 ;
                        if(com_Right==1){
                            printf("and rock\n");
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
                            printf("and scissor\n");
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

            if (com_Left==3)
                {
                printf("  computer's hand are: scissor ");
                    srand(time(NULL));
                    com_Right = 1 + rand()%2 ;

                        if(com_Right==1){
                            printf("and rock\n");
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
                            printf("and paper\n");
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

const char* comHand2(char *P1,char *P2)
{
    srand(time(NULL));
    int ComHand;

    if(strcmp(P1,P2)==0)
    {
        ComHand = rand()%3+1;
        if ( ComHand == 1 )
            {
                return "r";
            }
        else if ( ComHand == 2 )
            {
                return "p";
            }
        else if ( ComHand == 3 )
            {
                return "s";
            }
    }
    else if(strcmp(P1,P2)!=0)
    {
        ComHand = rand()%2+1;
        if ( ComHand == 1 )
            {
                if (strcmp(P1,"r")==0 || strcmp(P1,"R")==0)
                {
                    return "r";
                }
                else if (strcmp(P1,"p")==0 || strcmp(P1,"P")==0)
                {
                    return "p";
                }
                else if (strcmp(P1,"s")==0 || strcmp(P1,"S")==0)
                {
                    return "s";
                }
            }
        if ( ComHand == 2)
            {
                if (strcmp(P2,"r")==0 || strcmp(P2,"R")==0)
                {
                    return "r";
                }
                else if (strcmp(P2,"p")==0 || strcmp(P2,"P")==0)
                {
                    return "p";
                }
                else if (strcmp(P2,"s")==0 || strcmp(P2,"S")==0)
                {
                    return "s";
                }
            }
    }
}


char compare(char *player, char computer)
{
	if ( strcmp(player,"r")==0 || strcmp(player,"R")==0 )
	{
            readFile("rock.txt");
            printf("  >> press any keys to see the result <<\n");
            getch();
			if(computer == 'r')
            {
				printf("\n\n  computer's final hand : rock\n");
                readFile("rock.txt");
				return 't';
			}
			else if(computer == 'p')
            {
				printf("\n\n  computer's final hand : paper\n");
                readFile("paper.txt");
				return 'l';
			}
			else if(computer == 's')
            {
				printf("\n\n  computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 'w';
			}
	}
    else if  ( strcmp(player,"p")==0 || strcmp(player,"P")==0 )
    {
            readFile("paper.txt");
            printf("  >> press any keys to see the result <<\n");
            getch();
			if(computer == 'p')
            {
				printf("\n\n  computer's final hand : paper\n");
                readFile("paper.txt");
				return 't';
			}
			else if(computer == 's')
            {
				printf("\n\n  computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 'l';
			}
			else if(computer == 'r')
			{
				printf("\n\n  computer's final hand : rock\n");
                readFile("rock.txt");
				return 'w';
			}
	}
	else if  ( strcmp(player,"s")==0 || strcmp(player,"S")==0 )
	{
            readFile("scissor.txt");
            printf("  >> press any keys to see the result <<\n");
            getch();
			if(computer == 's'){
				printf("\n\n  computer's final hand : scissor\n");
                readFile("scissor.txt");
				return 't';
			}
			else if(computer == 'r'){
				printf("\n\n  computer's final hand : rock\n");
                readFile("rock.txt");
				return 'l';
			}
			else if(computer == 'p'){
				printf("\n\n  computer's final hand : paper\n");
                readFile("paper.txt");
				return 'w';
			}
	}
}

char compare2(char *P1, char *P2, char *COM, char P1N[], char P2N[])
{
    //return A = P1 win, B = P2 win, C = Com win, D = P1&P2 win, F = P1&Com win, G = P2&Com win
    if(strcmp(P1,P2)==0)
    {
        if(strcmp(P1,"r")==0||strcmp(P1,"R")==0)
        {
            if(strcmp(COM,"r")==0)
            {
                readFile("rock.txt");
                readFile("tie.txt");
            }
            if(strcmp(COM,"p")==0)
            {
                readFile("paper.txt");
                printf("Computer win");
                return 'C';
            }
            if(strcmp(COM,"s")==0)
            {
                readFile("scissor.txt");
                printf("\n\n  %s & %s win",P1N,P2N);
                return 'D';
            }
        }
        if(strcmp(P1,"p")==0||strcmp(P1,"P")==0)
        {
            if(strcmp(COM,"p")==0)
            {
                readFile("paper.txt");
                readFile("tie.txt");
            }
            if(strcmp(COM,"s")==0)
            {
                readFile("scissor.txt");
                printf("  Computer win");
                return 'C';
            }
            if(strcmp(COM,"r")==0)
            {
                readFile("rock.txt");
                printf("\n\n  %s & %s win",P1N,P2N);
                return 'D';
            }
        }
        if(strcmp(P1,"s")==0||strcmp(P1,"S")==0)
        {
            if(strcmp(COM,"s")==0)
            {
                readFile("scissor.txt");
                readFile("tie.txt");
            }
            if(strcmp(COM,"r")==0)
            {
                readFile("rock.txt");
                printf("Computer win");
                return 'C';
            }
            if(strcmp(COM,"p")==0)
            {
                readFile("paper.txt");
                printf("\n\n  %s & %s win",P1N,P2N);
                return 'D';
            }
        }
    }

    if(strcmp(P1,P2)!=0)
    {
        if( (strcmp(P1,"r")==0||strcmp(P1,"R")==0) && strcmp(P1,COM)==0 )
        {
            if(strcmp(P2,"r")==0||strcmp(P2,"R")==0)
            {
                readFile("rock.txt");
                readFile("tie.txt");
            }
            if(strcmp(P2,"p")==0||strcmp(P2,"P")==0)
            {
                readFile("rock.txt");
                printf("  %s win",P2N);
                return 'B';
            }
            if(strcmp(P2,"s")==0||strcmp(P2,"S")==0)
            {
                readFile("rock.txt"); 
                printf("  %s & Computer win",P1N);
                return 'F';
            }
        }
        if( (strcmp(P1,"p")==0||strcmp(P1,"P")==0) && strcmp(P1,COM)==0 )
        {
            if(strcmp(P2,"p")==0||strcmp(P2,"P")==0)
            {
                readFile("paper.txt");
                readFile("tie.txt");
            }
            if(strcmp(P2,"s")==0||strcmp(P2,"S")==0)
            {
                readFile("paper.txt");
                printf("  %s win",P2N);
                return 'B';
            }
            if(strcmp(P2,"r")==0||strcmp(P2,"R")==0)
            {
                readFile("paper.txt");
                printf("  %s & Computer win",P1N);
                return 'F';
            }
        }
        if( (strcmp(P1,"s")==0||strcmp(P1,"S")==0) && strcmp(P1,COM)==0 )
        {
            if(strcmp(P2,"s")==0||strcmp(P2,"S")==0)
            {
                readFile("scissor.txt");
                readFile("tie.txt");
            }
            if(strcmp(P2,"r")==0||strcmp(P2,"R")==0)
            {
                readFile("scissor.txt");
                printf("  %s win",P2N);
                return 'B';
            }
            if(strcmp(P2,"p")==0||strcmp(P2,"P")==0)
            {
                readFile("scissor.txt");
                printf("  %s & Computer win",P1N);
                return 'F';
            }
        }
        if( (strcmp(P2,"r")==0||strcmp(P2,"R")==0) && strcmp(P2,COM)==0 )
        {
            if(strcmp(P1,"r")==0||strcmp(P1,"R")==0)
            {
                readFile("rock.txt");
                readFile("tie.txt");
            }
            if(strcmp(P1,"p")==0||strcmp(P1,"P")==0)
            {
                readFile("rock.txt");
                printf("  %s win",P1N);
                return 'A';
            }
            if(strcmp(P1,"s")==0||strcmp(P1,"S")==0)
            {
                readFile("rock.txt");
                printf("  %s & Computer win",P2N);
                return 'G';
            }
        }
        if( (strcmp(P2,"p")==0||strcmp(P2,"P")==0) && strcmp(P2,COM)==0 )
        {
            if(strcmp(P1,"p")==0||strcmp(P1,"P")==0)
            {
                readFile("paper.txt");
                readFile("tie.txt");
            }
            if(strcmp(P1,"s")==0||strcmp(P1,"S")==0)
            {
                readFile("paper.txt");
                printf("  %s win",P1N);
                return 'A';
            }
            if(strcmp(P1,"r")==0||strcmp(P1,"R")==0)
            {
                readFile("paper.txt");
                printf("  %s & Computer win",P2N);
                return 'G';
            }
        }
        if( (strcmp(P2,"s")==0||strcmp(P2,"S")==0) && strcmp(P2,COM)==0 )
        {
            if(strcmp(P1,"s")==0||strcmp(P1,"S")==0)
            {
                readFile("scissor.txt");
                readFile("tie.txt");
            }
            if(strcmp(P1,"r")==0||strcmp(P1,"R")==0)
            {
                readFile("scissor.txt");
                printf("  %s win",P1N);
                return 'A';
            }
            if(strcmp(P1,"p")==0||strcmp(P1,"P")==0)
            {
                readFile("scissor.txt");
                printf("  %s & Computer win",P2N);
                return 'G';
            }
        }

    }
}

void writeStat(char name[],int win, int lose, int tie)
{
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

void writeStat2(char name1[], char name2[], int P1W, int P2W, int CW)
{
	time_t t;
	time(&t);
	char stat[100];
	FILE *stat_pointer;
	stat_pointer = fopen("stat 2.txt","a");
	printf("%s win : %d | %s win : %d | Computer win : %d",name1,P1W,name2,P2W,CW);
	sprintf(stat,"%s win : %d | %s win : %d | Computer win : %d | %s ",name1,P1W,name2,P2W,CW,ctime(&t));
	fputs(stat,stat_pointer);
	fprintf(stat_pointer, "\n");
	fclose(stat_pointer);
}

void readFile(char *FileName)
{
    printf("\n");
	char line[200];
	FILE *fp = fopen(FileName,"r");
	while(fgets(line, sizeof(line), fp))
        {
		printf("%s",line);
        }
}
