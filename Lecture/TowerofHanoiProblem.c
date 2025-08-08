#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DISKS 10

typedef struct{
    int disks[MAX_DISKS];
    int top;
} Tower;


void initTowerOfHanoi(Tower* t){
    t->top = -1;
}

void push(Tower* t, int disk){
    if (t->top < MAX_DISKS - 1){
        t->top++;
        t->disks[t->top] = disk;
    }
}

int pop(Tower* t){
    if (t->top > -1){
        int disk = t->disks[t->top];
        t->top--;
        return disk;
    }
    return -1;
}
void printTowerOfHanoi(Tower * A, Tower* B, Tower* C){
    printf("Tower A: ");
    for (int i = 0; i <= A->top; i++){
        printf("%d", A->disks[i]);
    }
    printf("Tower B: ");
    for (int i = 0; i <= B->top; i++){
        printf("%d", B->disks[i]);
    }
    printf("Tower C: ");
    for (int i = 0; i <= C->top; i++){
        printf("%d", C->disks[i]);
    }

    printf("\n----------------------------------------\n");
}

void functionOfHanoi(int n, Tower* source, Tower* destination, Tower* aux, int* moveCount, Tower* allTowers[]){
    if (n == 1){
        (*moveCount)++;
        printf("move# %d: move(%d, %c, %c)\n", *moveCount, n,
               source == allTowers[0] ? 'A' : (source == allTowers[1] ? 'B' : 'C'),
               destination == allTowers[0] ? 'A' : (destination == allTowers[1] ? 'B' : 'C'));

        int disk = pop(source);
        push(destination, disk);
        printTowerOfHanoi(allTowers[0], allTowers[1], allTowers[2]);
    } else {
        functionOfHanoi(n - 1, source, aux, destination, moveCount, allTowers);

        (*moveCount)++;
        printf("move# %d: move(%d, %c, %c)\n", *moveCount, n,
               source == allTowers[0] ? 'A' : (source == allTowers[1] ? 'B' : 'C'),
               destination == allTowers[0] ? 'A' : (destination == allTowers[1] ? 'B' : 'C'));

        int disk = pop(source);
        push(destination, disk);
        printTowerOfHanoi(allTowers[0], allTowers[1], allTowers[2]);

        functionOfHanoi(n - 1, aux, destination, source, moveCount, allTowers);
    }
}
int main(){
    int n;
    Tower A, B, C;
    int moveCount = 0;

    initTowerOfHanoi(&A);
    initTowerOfHanoi(&B);
    initTowerOfHanoi(&C);
    
    printf("Input N = ");
    scanf("%d", &n);

    if(n > MAX_DISKS){
        return 1;
    }

    for(int i = n; i > 0; i--){
        push(&A, i);
    }


    Tower* allTowers[] = {&A, &B, &C};

    printf("Start\n");
    printTowerOfHanoi(&A ,&B ,&C);

    functionOfHanoi(n, &A, &C, &B, &moveCount, allTowers);

    printf("Total moves: %d\n", moveCount);
    printf("Total moves (formula): %.0f\n", pow(2, n) - 1);
    return 0;
}