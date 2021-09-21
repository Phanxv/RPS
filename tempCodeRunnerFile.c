#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int i,j=0,k,l,item_num, random_num;
    int asked[10];
    srand(time(NULL));
    random_num = random_num = (rand()%10)+1;
    for(k=0;k<10;k++){
        for(i=0;i<10;i++){
            while(random_num == asked[i]){
            random_num = (rand()%10)+1;
            }
            item_num = random_num;
            asked[j]=item_num;
            j++;
            break;
        }
        printf("%d",item_num);
        printf("Randomed ");
        for(l=0;l<10;l++){
            printf("%d ",asked[l]);
        }
    }
}