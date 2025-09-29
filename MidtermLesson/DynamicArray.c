#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
} IntList;

void appendFunction(IntList *list, int value){
    list->data = realloc(list->data, (list->size + 1 * sizeof(int)));

    list->data[list->size] = value;
    list->size++;
}

int main(){
    IntList list = {NULL,0};

    append(&list, 10);
    append(&list, 20);
    append(&list, 30);

        
    for (size_t i = 0; i < list.size; i++){
        printf("%d", list.data[i]);
    }


}