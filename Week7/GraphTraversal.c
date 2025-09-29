#include <stdio.h>
#include <string.h>

#define MAX_XY 55

int X, Y;
int adjacency[MAX_XY][MAX_XY];
int degree_val[MAX_XY];
int startNode, targetNode;
long long totalPaths = 0;
int visitedNode[MAX_XY];

void DFSearch_count(int u) {
    if (u == targetNode) {
        totalPaths++;
        return;
    }
    visitedNode[u] = 1;
    for (int i = 0; i < degree_val[u]; i++) {
        int v = adjacency[u][i];
        if (!visitedNode[v]) {
            DFSearch_count(v);
        }
    }
    visitedNode[u] = 0;
}

int queue[MAX_XY * MAX_XY];
int parent[MAX_XY];
int used[MAX_XY];

int BFSearch() {
    int front = 0, back = 0;
    for (int i = 0; i < MAX_XY; i++) {
        used[i] = 0;
        parent[i] = -1;
    }

    queue[back++] = startNode;
    used[startNode] = 1;

    while (front < back) {
        int u = queue[front++];
        if (u == targetNode) break;
        for (int i = 0; i < degree_val[u]; i++) {
            int v = adjacency[u][i];
            if (!used[v]) {
                used[v] = 1;
                parent[v] = u;
                queue[back++] = v;
            }
        }
    }

    return used[targetNode];
}

void printShortestPath() {
    int path[MAX_XY], len = 0;
    int current = targetNode;
    while (current != -1) {
        path[len++] = current;
        current = parent[current];
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i) printf(" ");
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &X, &Y);
    for (int i = 0; i < Y; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjacency[u][degree_val[u]++] = v;
        adjacency[v][degree_val[v]++] = u;
    }
    scanf("%d %d", &startNode, &targetNode);

    if (!BFSearch()) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    memset(visitedNode, 0, sizeof(visitedNode));
    totalPaths = 0;
    DFSearch_count(startNode);
    printf("%lld\n", totalPaths);

    printShortestPath();
    return 0;
}
