#include <stdio.h>
#include <stdlib.h>

void readFile(char *FileName);

int main(){
    readFile("logo.txt");
}

void readFile(char *FileName){
    printf("\n");
	char line[100];
	FILE *fp = fopen(FileName,"r");
	while(fgets(line, sizeof(line), fp)){
		printf("%s",line);
	}
}