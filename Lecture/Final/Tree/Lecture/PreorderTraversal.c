#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightChild; 
};

void preorder(struct node* node){
    if (node == NULL) return;

    struct node* child = node->leftChild;

    while (child != NULL){
        preorder(child);
        child = child->rightChild;
    }
    print("%d", node->key);
}

int main(){
    struct node* node1 = createRoot(1);
    struct node* node2 = createNode(2, node1);
    struct node* node3 = createNode(3, node1);
    struct node* node4 = createNode(4, node2);
    struct node* node5 = createNode(5, node1);
    struct node* node6 = createNode(6, node1);
    struct node* node7 = createNode(7, node3);
    struct node* node8 = createNode(8, node7);
    struct node* node9 = createNode(9, node7);
    struct node* node10 = createNode(10, node3);
    struct node* node11 = createNode(11, node3);
    struct node* node12 = createNode(12, node11);
    preorder(node1);
    return 0;
}
