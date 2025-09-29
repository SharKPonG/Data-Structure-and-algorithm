#include <stdio.h>
#include <stdlib.h>

int main(){
    struct flower {
    char id[3];
    char name[10];
    double price;
    char address[50];
    char subdistrice[50];
    char districe[50];
    }flower[3];
    
    printf("Please Enter Flower Information");
    for(int i = 0; i < 3; i++){
        printf("Record %d\n", i+1);
        

        printf("ID:");
        scanf("%s",flower[i].id);
    }
}


