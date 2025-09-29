// 6500000000_ass10.cpp   (แก้เป็นรหัสนิสิตของคุณ)
#include <iostream>
using namespace std;

struct Node {
    string name;
    int size;
    bool isDir;
    Node* left;
    Node* right; 


Node* makeFile(string n,int s){
    Node* f=new Node{n,s,false,nullptr,nullptr};
    return f;
}

Node* makeDir(string n,Node* l,Node* r){
    Node* d=new Node{n,0,true,l,r};
    int sum=0;
    if(l) sum+=l->size;
    if(r) sum+=r->size;
    d->size=sum;
    return d;
}


void preorder(Node* u){
    if(!u) return;
    cout<<u->name<<" ("<<u->size<<"K)\n";
    preorder(u->left);
    preorder(u->right);
}


void postorder(Node* u){
    if(!u) return;
    postorder(u->left);
    postorder(u->right);
    cout<<u->name<<" ("<<u->size<<"K)\n";
}

int main(){

    Node* hw1 = makeFile("hw1",3);
    Node* hw2 = makeFile("hw2",2);

    Node* homework = makeDir("homeworks",hw1,hw2);
    Node* grades   = makeFile("grades",8);

    Node* root = makeDir("cs016",homework,grades);

    cout<<"=== PREORDER ===\n";
    preorder(root);
    cout<<"=== POSTORDER ===\n";
    postorder(root);
}
