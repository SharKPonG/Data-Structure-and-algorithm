#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;          
    list<int>* adj;   

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool BFS(int s, int f) {
        bool visited[100] = {false};
        list<int> q;

        visited[s] = true;
        q.push_back(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop_front();

            if (u == f) return true; 

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(31);

    for (int i = 0; i < 30; i++) {
        g.addEdge(i, i + 1);
    }
   
    g.addEdge(0, 5);
    g.addEdge(5, 10);
    g.addEdge(2, 7);
    g.addEdge(7, 15);
    g.addEdge(10, 20);
    g.addEdge(20, 25);
    g.addEdge(25, 30);

    int start = 0, finish = 30;

    cout << (g.BFS(start, finish) ? "YES\n"  : "NO\n");
    return 0;
}