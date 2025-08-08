#include <stdio.h>
// 6710405362
#define TABLE_SIZE 11
void printHashTable(int hashTable[]){

    for (int i = 0; i < TABLE_SIZE; i++){
        if (hashTable[i] != -1){
            printf("%-5d | %d\n", i, hashTable[i]);
        }else{
            printf("%-5d | %d\n", i);
        }
    }
}
void insert(int hashTable[], int key){
    int index = key % TABLE_SIZE;
    printf("Inserting %d: initial index = %d\n", key, index);

    while(hashTable[index] != -1 ){
        printf(" -> Collision at index %d! (current value is %d)\n", index, hashTable[index]);
        index = (index + 1) % TABLE_SIZE;
        printf(" -> Probing next index: %d\n", index);
    }
    hashTable[index] = key;
    printf(" -> Placed %d at index %d\n\n", key, index);
}

int main() {
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

 
    int data[] = {12, 99, 58, 32, 10, 8, 19, 70};
    int n = sizeof(data) / sizeof(data[0]);


    for (int i = 0; i < n; i++) {
        insert(hashTable, data[i]);
    }

    printf("Final Hash Table State\n");
    printHashTable(hashTable);

    return 0;
}