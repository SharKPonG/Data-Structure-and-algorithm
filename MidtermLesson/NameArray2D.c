#include <stdio.h>
#include <stdlib.h>


int main(){
    char name[5][50];

    for(int i = 0; i < 5; i++){
        pritnf("Enter name: ",i + 1 );
        fgets(name, sizeof(name), stdin);
    }

    for(int i = 0; i < 5; i++){
        pritnf("Enter name: ",i + 1 );
        fgets(name, size(name), stdin);
    }
    return 0;
}