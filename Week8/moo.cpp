#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* parent;
    vector<Node*> children;
    Node(string n) : name(n), parent(nullptr) {}
};

map<string, Node*> nodes;
Node* root = nullptr;

void createNode(const string &node, const string &parent) {
    if (nodes.find(node) == nodes.end()) nodes[node] = new Node(node);

    if (parent == "NULL") {
        // ตั้งเป็น root (ถ้ามี root เดิม จะคงอยู่ — move ไปยัง NULL จะจัดการ reparent)
        root = nodes[node];
        nodes[node]->parent = nullptr;
    } else {
        if (nodes.find(parent) == nodes.end()) nodes[parent] = new Node(parent);
        nodes[node]->parent = nodes[parent];
        nodes[parent]->children.push_back(nodes[node]);
    }
}

void deleteChild(Node* parent, Node* target) {
    if (!parent) return;
    vector<Node*> &siblings = parent->children;
    for (int i = 0; i < (int)siblings.size(); i++) {
        if (siblings[i] == target) {
            for (int j = i; j < (int)siblings.size() - 1; j++) siblings[j] = siblings[j+1];
            siblings.pop_back();
            break;
        }
    }
}

void moveNode(const string &node, const string &parent) {
    if (nodes.find(node) == nodes.end()) return;
    Node* n = nodes[node];

    // เอาออกจาก parent เดิมก่อน
    Node* oldParent = n->parent;
    if (oldParent) deleteChild(oldParent, n);

    if (parent == "NULL") {
        // เก็บ root เดิมไว้
        Node* oldRoot = root;
        root = n;
        n->parent = nullptr;

        // ถ้ามี root เดิม และไม่ใช่ n เอง ให้ย้าย root เดิมไปเป็นลูกของ n
        if (oldRoot && oldRoot != n) {
            // oldRoot ตอนนี้ควรจะไม่มี parent (เพราะเป็น root) แต่เราจะเปลี่ยน parent ให้เป็น n
            oldRoot->parent = n;
            n->children.push_back(oldRoot);
        }
    } else {
        if (nodes.find(parent) == nodes.end()) nodes[parent] = new Node(parent);
        Node* p = nodes[parent];
        n->parent = p;
        p->children.push_back(n);
    }
}

void removeNodeAndSubTree(const string &node) {
    if (nodes.find(node) == nodes.end()) return;
    Node* n = nodes[node];
    if (!n) return;

    if (n->parent) deleteChild(n->parent, n);

    vector<Node*> st;
    st.push_back(n);
    while (!st.empty()) {
        Node* cur = st.back(); st.pop_back();
        for (auto child : cur->children) st.push_back(child);
        nodes.erase(cur->name);
        delete cur;
    }
}

void printTree(Node* node, int level = 0) {
    if (!node) return;
    cout << node->name << "\n";
    for (auto child : node->children) {
        for (int i = 0; i < level; ++i) cout << " ";
        cout << "|_";
        printTree(child, level + 1);
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        vector<string> tokens;
        string word;
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) tokens.push_back(word);
                word.clear();
            } else word.push_back(c);
        }
        if (!word.empty()) tokens.push_back(word);

        if (tokens.empty()) continue;
        if (tokens[0] == "M") {
            if (tokens.size() >= 3) moveNode(tokens[1], tokens[2]);
        } else if (tokens[0] == "R") {
            if (tokens.size() >= 2) removeNodeAndSubTree(tokens[1]);
        } else {
            if (tokens.size() >= 2) createNode(tokens[0], tokens[1]);
        }
    }

    if (!root) cout << "IMPOSSIBLE\n";
    else printTree(root);

    return 0;
}
