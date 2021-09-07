#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

char compare(char player, char computer);
char comhand();

int main(){
    char usr_l, usr_r, usr_fd, usr_fh,com_fh, result, cont='y';
    int tie = 0, win = 0, lose = 0;
    do{
        printf("user left hand >> ");
        scanf(" %c",&usr_l);
        printf("user right hand >> ");
        scanf(" %c",&usr_r);
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
        printf("user final decision >> ");
        scanf(" %c",&usr_fd);
        while(usr_fd != usr_l && usr_fd != usr_r){
        printf("Invalid input (please choose what is on your left hand or your right hand)\n");
        printf("user final decision >> ");
        scanf(" %c",&usr_fd);
        }
        usr_fh = usr_fd;
        result = compare(usr_fh, com_fh);
        if(result == 'w'){
		    printf("user win\n");
		    win++;
	    }
	    if(result == 'l'){
	    	printf("user lose\n");			
            lose++;
	    }
	    if(result == 't'){
	    	printf("tie\n");
	        tie++;
	    }
        printf("Continue? (y/n) >> ");
		scanf(" %c",&cont);
    }while(cont == 'y' || cont == 'Y');
    //call function write stat
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
                            //goto function ask player
                            //************************************************ฝากต่อ******************************************
                            //สุ่มใน2มือ
                            com_Hfinal = 1 + rand()%2 ;
                            switch(com_Hfinal)  {
                                case 1:
                                    com_Hfinal = 'r';
                                    //printf("computer chooses >> rock");
                                    return 'r';
                                break;
                                case 2:
                                    com_Hfinal = 'p';
                                    //printf("computer chooses >> paper\n");
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
                                    //printf("computer chooses >> rock\n");
                                    return 'r';
                                break;
                                case 2:
                                    com_Hfinal = 's';
                                    //printf("computer chooses >> scissor\n");
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
                                    //printf("computer chooses >> paper\n");
                                    return 'p';
                                break;
                                case 2:
                                    com_Hfinal = 'r';
                                    //printf("computer chooses >> rock\n");
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
                                    //printf("computer chooses >> paper\n");
                                    return 'p';
                                break;
                                case 2:
                                    com_Hfinal = 's';
                                    //printf("computer chooses >> scissor\n");
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
                                    //printf("computer chooses >> scissor\n");
                                    return 's';
                                break;
                                case 2:
                                    com_Hfinal = 'r';
                                    //printf("computer chooses >> rock\n");
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
                                    //printf("computer chooses >> scissor\n");
                                    return 's';
                                break;
                                case 2:
                                    com_Hfinal = 'p';
                                    //printf("computer chooses >> paper\n");
                                    return 'p';
                                break;
                            }
                        }
                }

}