#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string name;
    int size;
    bool isDir;
    vector<Node*> child;
};

Node* makeFile(string n, int s) {
    Node* f = new Node{n, s, false, {}};
    return f;
}

Node* makeDir(string n) {
    Node* d = new Node{n, 0, true, {}};
    return d;
}


int computeSize(Node* u) {
    if (!u->isDir) return u->size;
    int sum = 0;
    for (auto v : u->child) sum += computeSize(v);
    u->size = sum;
    return u->size;
}


void preorder(Node* u, int depth=0) {
    for (int i=0;i<depth;i++) cout << "  ";
    cout << u->name << " (" << u->size << "K)\n";
    for (auto v : u->child) preorder(v, depth+1);
}


void postorder(Node* u, int depth=0) {
    for (auto v : u->child) postorder(v, depth+1);
    for (int i=0;i<depth;i++) cout << "  ";
    cout << u->name << " (" << u->size << "K)\n";
}

int main() {
    Node* root = makeDir("/user/rt/courses");

    Node* cs016 = makeDir("cs016");
    cs016->child.push_back(makeFile("grades",8));
    Node* hw = makeDir("homeworks");
    hw->child.push_back(makeFile("hw1",3));
    hw->child.push_back(makeFile("hw2",2));
    hw->child.push_back(makeFile("hw3",4));
    cs016->child.push_back(hw);

    Node* pr = makeDir("programs");
    pr->child.push_back(makeFile("pr1",57));
    pr->child.push_back(makeFile("pr2",97));
    pr->child.push_back(makeFile("pr3",74));
    cs016->child.push_back(pr);

    root->child.push_back(cs016);

    Node* cs252 = makeDir("cs252");
    cs252->child.push_back(makeFile("grades",3));
    Node* projects = makeDir("projects");
    projects->child.push_back(makeFile("buylow",26));
    projects->child.push_back(makeFile("sellhigh",55));
    projects->child.push_back(makeFile("market",4786));
    cs252->child.push_back(projects);

    root->child.push_back(cs252);


    computeSize(root);

    cout << "=== PREORDER ===\n";
    preorder(root);
    cout << "\n=== POSTORDER ===\n";
    postorder(root);

    return 0;
}