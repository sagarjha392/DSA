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

void inOrder(struct Node *root)
{
    // left subtree-> Root node -> right subtree
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Node * DeleteNode(struct Node *root, int value){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL&&root->right ==NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left= DeleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right= DeleteNode(root->right, value);
    }
    else{
        struct Node *temp = inOrderPredecessor(root);
        root->data = temp->data;
        root->left= DeleteNode(root->left, value);
    }
    return root;
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*
                5
               / \
              3   6
             / \
            1   4
    */
    inOrder(p);
    DeleteNode(p,4);
    printf("\n");
    inOrder(p);


    return 0;
}