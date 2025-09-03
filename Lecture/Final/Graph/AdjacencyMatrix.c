#include <stdio.h>
#include <stdlib.h>

int** createGraph(const int n){
    int** adjMatrix = (int**)malloc(n*sizeof(int*));
    for(int i=0; i < n; i++){
        adjMatrix[i] = (int*)malloc(n*sizeof(int));
        for(int j = 0; j < n; j++) adjMatrix[i][j] = 0;
        }
    return adjMatrix;
}

void addEdge(int** adjMatrix, int u, int v){
    adjMatrix[u][v] = 1;
}

void printGraph(int** adjMatrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void deleteGraph(int** adjMatrix, int n){
    for (int i = 0; i < n; i++){
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

void removeEdge(int** adjMatrix, int u, int v){
    adjMatrix[u][v] = 0;
}

int** addVertex(int** adjMatrix, int *n, int u){
    int** newAdjMatrix = createGraph(u+1);
    for (int i = 0; i <*n; i++){
        for (int j = 0; j <*n; j++){
            if(adjMatrix[i][j] == 1) newAdjMatrix[i][j] = 1;
        }
        deleteGraph(adjMatrix, *n);
        *n = u + 1;
        return newAdjMatrix; 
    }
}
int** removeVertex(int** adjMatrix, int* n, int u){
    int** newAdjMatrix = createGraph(*n-1);
    for(int i = 0; i < *n-1; i++){
        for(int j = 0; j < *n-1; j++){
            newAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    deleteGraph(adjMatrix, *n);
    (*n)--;
    return newAdjMatrix;
}


int isAdjacent(int** adjMatrix, int u, int v){
    if(adjMatrix[u][v] == 1){
        return 1;
    }else{
        return 0;
    }
}

int inDegree(int** adjMatrix, const int n, int u){
    int inDeg = 0;
    for(int i = 0; i < n; i++){
        if(adjMatrix[i][u]) inDeg++;
    }
    return inDeg;
}

int outDegree(int** adjMatrix, const int n, int u){
    int outDeg = 0;
    for(int i = 0; i < n; i++){
        if(adjMatrix[u][i]) outDeg++;
    }
    return outDeg;
}


int main(){
    int n = 5;
    int** adjMatrix = createGraph(n);


    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 4, 3);

    printGraph(adjMatrix, n);
    return 0;
}