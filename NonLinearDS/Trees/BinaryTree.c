#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;

    return n;
}

void preOrder(struct Node *root)
{
    // Root node -> left subtree-> right subtree
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root)
{
    //  left subtree-> right subtree-> Root node
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct Node *root)
{
    // left subtree-> Root node -> right subtree
     if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    // // root node
    // struct Node *p;
    // p = (struct Node *)malloc(sizeof(struct Node));
    // p->left = NULL;
    // p->right = NULL;
    // p->data = 1;

    // // first node
    // struct Node *p1;
    // p1 = (struct Node *)malloc(sizeof(struct Node));
    // p1->left = NULL;
    // p1->right = NULL;
    // p1->data = 2;

    // // Second node
    // struct Node *p2;
    // p2 = (struct Node *)malloc(sizeof(struct Node));
    // p2->left = NULL;
    // p2->right = NULL;
    // p2->data = 3;

    // // Linking the nodes to construct the binary tree
    // p->left = p1;
    // p->right = p2;

    // root node
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    // // Linking the nodes to construct the binary tree
    p->left = p1;
    p->right = p2;
    
    p1->left = p3;
    p1->right = p4;

    printf("\nPreOrder Traversal\n");
    preOrder(p);

    printf("\nPostOrder Traversal\n");
    postOrder(p);


    printf("\nInOrder Traversal\n");
    inOrder(p);
    return 0;
}