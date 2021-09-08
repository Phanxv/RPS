#include<stdio.h>
int main(){
    int input;
    printf("Enter smt > ");
    scanf("%d",&input);
    while(input<0){
        printf("Enter smt > ");
        scanf("%d",&input);
    }
    printf("%d",input);
}