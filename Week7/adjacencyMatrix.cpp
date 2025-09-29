#include <iostream>
using namespace std;

int a, b, S, E, P;
int maze[105][105];
bool visited[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool dfs(int x, int y) {
    if (maze[x][y] == E) return true;
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < a && ny >= 0 && ny < b) {
            if (!visited[nx][ny] && (maze[nx][ny] == P || maze[nx][ny] == E)) {
                if (dfs(nx, ny)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> a >> b;
    cin >> S >> E;
    cin >> P;
    int sx, sy;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == S) { sx = i; sy = j; }
        }
    }
    cout << (dfs(sx, sy) ? "Real Labyrinth" : "Faux Labyrinth");
}
