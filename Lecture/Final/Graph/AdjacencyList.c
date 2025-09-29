#include <stdio.h>
#include <stdlib.h>

struct Node** createGraph(int n){
    struct Node** adjList = malloc(sizeof(struct Node*)*n);
    for(int i = 0; i < n; i++) adjList[i] = NULL;
    return adjList;
}

struct Node{
    int adjVertex;
    struct Node* next;
};

void addEdge(struct Node** adjList, int u, int v){
    struct Node* node = adjList[u];
    if(node == NULL){
        node = malloc(sizeof(struct node));
        node->adjVertex = v;
        node->next = NULL;
        adjList[u] = node;
    }else{
        while(node->next != NULL) node = node->next;
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->adjVertex = v;
        newNode->next = NULL;
        node->next = newNode;
    }
}

void printGraph(struct Node** adjList, int n){
    for (int u = 0; u < n; u++){
        printf("[%d] head: ", u);
        struct Node* node = adjList[u];
        while(node){
            printf("-> %d", node->adjVertex);
            node = node->next;
        }

        printf("-> NULL \n");
    }
}

void deleteGraph(struct Node** adjList, int n){
    for (int u = 0; u < n; u++){
        struct Node* node = adjList[u];
        while(node != NULL){
            struct Node* nextNode =  node->next;
            free(node);
            node = nextNode;
        }
    }

    free(adjList);
}

