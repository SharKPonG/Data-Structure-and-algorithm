#include <iostream>
#include <string>
using namespace std;


typedef struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
}Tree;


Tree* insertNode(Tree* root, int v){
    if (root == nullptr) return new Tree(v);
    if (v < root->val){
        root->left = insertNode(root->left, v);
    }else{
        root->right = insertNode(root->right, v);
    }
    return root;
}

// inOrder left root right

void inOrder(Tree* root, string &s) {
    if (!root) return;
    inOrder(root->left, s);
    s += to_string(root->val) + " ";
    inOrder(root->right, s);
}


void reverseInorder(Tree* root, string &s) {
    if (!root) return;
    reverseInorder(root->right, s);
    s += to_string(root->val) + " ";
    reverseInorder(root->left, s);
}
bool findNode(Tree* root, int x){
    if (!root) return false;
    if (root->val == x) return true;
    if (x < root->val) return findNode(root->left, x);
    else return findNode(root->right, x);
}

int depth(Tree* root){
    if (!root) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}


int main() {
    int n;
    cin >> n;
    Tree* root = nullptr;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        root = insertNode(root, v);
    }

    string outputs = "";
    char cmd;
    while (cin >> cmd) {
        if (cmd == 's') {
            string line = "Ascending order: ";
            inOrder(root, line);
            outputs += line + "\n";
        } else if (cmd == 'r') {
            string line = "Descending order: ";
            reverseInorder(root, line);
            outputs += line + "\n";
        } else if (cmd == 'f') {
            int x;
            while (cin >> x) {
                if (x == -111) break;
                if (findNode(root, x)) {
                    outputs += "Node " + to_string(x) + " is in the tree.\n";
                } else {
                    outputs += "Node not found.\n";
                }
            }
        } else if (cmd == 'd') {
            outputs += "Depth: " + to_string(depth(root)) + "\n";
        } else if (cmd == 'e') {
            break;
        } else {
            outputs += "Unknown command.\n";
        }
    }

    cout << outputs;
}