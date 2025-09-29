#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;


int main() {


    int ns; long long t;
    if (!(cin >> ns >> t)) return 0;

    vector<int> sources(ns);
    for (int i = 0; i < ns; ++i) cin >> sources[i];


    map<int, vector<int>> g;
    set<int> nodes;         
    for (int s : sources) nodes.insert(s);

    int u, v;
    while (cin >> u >> v) {
        g[u].push_back(v);
        nodes.insert(u);    

    }

    set<int> srcset(sources.begin(), sources.end());
    long long candidate_count = 0;
    for (int node : nodes) if (!srcset.count(node)) candidate_count++;
    if (candidate_count == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    map<int,int> dist;        
    queue<int> q;
    for (int s : sources) {
        dist[s] = 0;
        q.push(s);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        auto it = g.find(x);
        if (it == g.end()) continue;
        for (int y : it->second) {
            if (!dist.count(y)) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }

    long long sumHops = 0, cnt = 0;
    for (int node : nodes) {
        if (srcset.count(node)) continue; 
        if (!dist.count(node)) {             
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        sumHops += dist[node];
        ++cnt;
    }
    long long totalSec = (sumHops * t) / cnt;  

    long long h = totalSec / 3600;
    long long m = (totalSec % 3600) / 60;
    long long s = totalSec % 60;
    cout << "Avg time : ";
    if (h > 0) cout << h << " hours ";
    cout << m << " minutes " << s << " seconds\n";
    return 0;
}
