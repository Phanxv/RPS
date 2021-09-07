#include<stdio.h>
#include<stdlib.h>

int main(){
    char usr_l, usr_r, usr_fd, usr_fh;
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
    //call function comhand
    printf("user final decision >> ");
    scanf(" %c",usr_fd)
    while(usr_fd != usr_l && usr_fd != usr_r){
        printf("Invalid input (please choose what is on your left hand or your right hand)");
    }
    usr_fh = usr_fd;
    //call compare 
}