#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node{
    string key;
    Node* left;
    Node* right;

    Node(const string& k) : key(k), left(nullptr), right(nullptr) {}
}Tree;

struct TNode {
    string raw, low; TNode *left, *right;
    TNode(const string& r, const string& l): raw(r), low(l), left(nullptr), right(nullptr) {}
};
// คล้ายข้อ Toy
Tree* insertNode(Tree* root, const string &word){
    if (root == nullptr) return new Tree(word);

    if (word < root->key){
        root->left = insertNode(root->left, word);
    }else{
        root->right  =insertNode(root->right, word);
    }
    return root;
}

char ToLower(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}

bool equalIgnoreCase(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (ToLower(a[i]) != ToLower(b[i]))
            return false;
    }
    return true;
}
Tree* insertMatch(Tree* root, const string &word){
    if (!root) return new Tree(word);
    if (word < root->key) root->left = insertMatch(root->left, word);
    else                  root->right = insertMatch(root->right, word);
    return root;
}


void inorderCollect(Node* root, const string& target, Tree* &matchRoot) {
    if (!root) return;
    inorderCollect(root->left, target, matchRoot);
    if (equalIgnoreCase(root->key, target)) matchRoot = insertMatch(matchRoot, root->key);
    inorderCollect(root->right, target, matchRoot);
}


void printInorder(Node* root, bool &first) {
    if (!root) return;
    printInorder(root->left, first);
    if (!first) cout << ' ';
    cout << root->key;
    first = false;
    printInorder(root->right, first);
}

vector<string> splitLine(const string& line) {
    vector<string> words;
    string cur;
    for (char c : line) {
        if (c == ' ') {
            if (!cur.empty()) { words.push_back(cur); cur.clear(); }
        } else cur.push_back(c);
    }
    if (!cur.empty()) words.push_back(cur);
    return words;
}


string toLowerStr(const string& s){
    string t=s; for (char &c: t) c=ToLower(c); return t;
}

TNode* insertTarget(TNode* root, const string& raw){
    string low = toLowerStr(raw);
    if (!root) return new TNode(raw, low);
    if (low < root->low) root->left = insertTarget(root->left, raw);
    else                 root->right= insertTarget(root->right, raw);
    return root;
}

void processTargetsDesc(TNode* troot, Node* namesRoot){
    if (!troot) return;
    processTargetsDesc(troot->right, namesRoot);

    Node* matchRoot = nullptr;
    inorderCollect(namesRoot, troot->raw, matchRoot);
    if (!matchRoot){
        cout << "\"" << troot->low << "\" is not found!\n";
    } else {
        bool first=true; printInorder(matchRoot, first); cout << '\n';
    }

    processTargetsDesc(troot->left, namesRoot);
}


int main(){
    string line; if (!getline(cin, line)) return 0;
    vector<string> targets = splitLine(line);

    Node* namesRoot = nullptr;
    string name;
    while (getline(cin, name)){
        if (!name.empty()) namesRoot = insertNode(namesRoot, name);
    }

    TNode* troot = nullptr;
    for (const string& t: targets) troot = insertTarget(troot, t);

    processTargetsDesc(troot, namesRoot);
    return 0;
}