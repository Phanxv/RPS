#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>

int readQuiz(int item_num);
void readFile(char *FileName);
char check(int item_num, char *ans);
char quiz(int item_num);

int main(){
    int i,round=1,quizNum=0;
    while (round <= 15)
    {
        printf("Round %d\n",round);
        getch();
        if(round%3==0){
            quizNum++;
            if(quiz(quizNum)=='n'){
                break;
            }
        }
        round++;
    }
    printf("Game over");
}

char quiz(int item_num){
    int i;
    char ans[50];
    readQuiz(item_num);
    printf("\n\nAnswer >> ");
    gets(ans);
    printf("%c",check(item_num,ans));
}
int readQuiz(int item_num){
    char item[10];
    sprintf(item,"Quiz %d.txt",item_num);
    readFile(item);
}

char check(int item_num, char *ans){
    char *ans_arr[] = {"d","69x^2 + 420x","a","d","b"};
    if(strcmp(ans,ans_arr[item_num-1])==0){
        return 'y';
    }
    else{
        return 'n';
    }
}

void readFile(char *FileName){
    printf("\n");
	char line[100];
	FILE *fp = fopen(FileName,"r");
	while(fgets(line, sizeof(line), fp)){
		printf("%s",line);
	}
}