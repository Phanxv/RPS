#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	char cont = 'y', usr_hand, com_hand;
	int com_rand, tie = 0, win = 0, lose = 0;
	srand(time(NULL));
	do{
		printf("Your hand (r,p,s) : ");
		scanf(" %c",&usr_hand);
		com_rand = rand()%3 + 1 ;
		switch(com_rand){
			case 1:
				com_hand = 'r';
				printf("computer's hand : rock\n");
				break;
			case 2:
				com_hand = 'p';
				printf("computer's hand : paper\n");
				break;
			case 3:
				com_hand = 's';
				printf("computer's hand : scissor\n");
				break;
		}
		switch(usr_hand){
			case 'r':
				printf("user's hand : rock\n");
				if(com_hand == 'r'){
					printf("tie");
					tie++;
				}
				else if(com_hand == 'p'){
					printf("user lose");
					lose++;
				}
				else if(com_hand == 's'){
					printf("user win");
					win++;
				}	
				break;
			case 'p':
				printf("user's hand : paper\n");
				if(com_hand == 'p'){
					printf("tie");
					tie++;
				}
				else if(com_hand == 's'){
					printf("user lose");
					lose++;
				}
				else if(com_hand == 'r'){
					printf("user win");
					win++;
				}
				break;
			case 's':
				printf("user's hand : scissor\n");
				if(com_hand == 's'){
					printf("tie");
					tie++;
				}
				else if(com_hand == 'r'){
					printf("user lose");
					lose++;
				}
				else if(com_hand == 'p'){
					printf("user win");
					win++;
				}
				break;
			default :
				printf("Invalid input");
				break;
		}
		printf("\nDo you want to continue (y/n) : ");
		scanf(" %c",&cont);
	}while(cont == 'y' || cont == 'Y');
	printf("Summary win : %d | lose : %d | tie : %d",win,lose,tie);
}