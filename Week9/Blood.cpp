#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};


Node* insertSorted(Node* head, int v) {
    Node* n = new Node(v);
    if (!head || v < head->val) {
        n->next = head;
        return n;
    }
    Node* cur = head;
    while (cur->next && cur->next->val <= v) cur = cur->next;
    n->next = cur->next;
    cur->next = n;
    return head;
}

void freeList(Node* head) {
    while (head) { Node* t = head->next; delete head; head = t; }
}

bool isPrime(int n) {
    if (n < 2) return false;   
    if (n % 2 == 0) return n == 2;
    for (int d = 3; 1LL*d*d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int m; 
        cin >> m;


        Node* raw = nullptr;
        for (int i = 0; i < m; ++i) {
            int v; cin >> v;
            if (v > 0) {                 
                Node* n = new Node(v);
                n->next = raw;    
                raw = n;
            }
        }

        int x, y; 
        cin >> x >> y;  

        Node* ans = nullptr;
        for (Node* p = raw; p; p = p->next) {
            int v = p->val;
            bool inRange = (x <= v && v <= y);
            bool ok = inRange || isPrime(v) || (v % 7 == 0);
            if (ok) ans = insertSorted(ans, v);
        }

        if (!ans) {
            cout << "IMPOSSIBLE\n";
        } else {
            bool first = true;
            for (Node* p = ans; p; p = p->next) {
                if (!first) cout << ' ';
                cout << p->val;
                first = false;
            }
            cout << '\n';
        }

        freeList(raw);
        freeList(ans);
    }
    return 0;
}
