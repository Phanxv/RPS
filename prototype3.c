#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void delay(int milliseconds);
char comHandRight();
char comHandLeft();

char comHandLeft(){
    srand(time(NULL));
	int com_rand;
	com_rand = rand()%3 + 1;
	switch(com_rand){
		case 1:
			//printf("computer's hand : rock\n");
			return 'r';
			break;
		case 2:
			//printf("computer's hand : paper\n");
			return 'p';
			break;
		case 3:
			//printf("computer's hand : scissor\n");
			return 's';
			break;
	}
}

char comHandRight(){
    srand(time(NULL));
	int com_rand;
	com_rand = rand()%3 + 1;
	switch(com_rand){
		case 1:
			//printf("computer's hand : rock\n");
			return 'r';
			break;
		case 2:
			//printf("computer's hand : paper\n");
			return 'p';
			break;
		case 3:
			//printf("computer's hand : scissor\n");
			return 's';
			break;
	}
}

int main(){
    char comHandR,comHandL;
    comHandR = comHandRight();
    comHandL = comHandLeft();
    printf("%c ",comHandR);
    printf("%c \n",comHandL);
    /*if(comHandR=='r'){
        printf("Computer's right hand : rock\n");
    }
    if(comHandR=='p'){
        printf("Computer's right hand : paper\n");
    }
    if(comHandR=='s'){
        printf("Computer's right hand : scissor\n");
    }
    if(comHandL=='r'){
        printf("Computer's left hand : rock\n");
    }
    if(comHandL=='p'){
        printf("Computer's left hand : paper\n");
    }
    if(comHandL=='s'){
        printf("Computer's left hand : scissor\n");
    }*/
    
}

/*void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}*/