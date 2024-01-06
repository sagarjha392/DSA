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
     if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


void Insert(struct Node *root, int key)
{
   struct Node *prev = NULL;
   struct Node *ptr;

   while(root!=NULL){
    prev= root;
    if(key== root->data){
        return ;
    }
    else if(key < root->data){
        root= root->left;

    }
    else{
        root= root->right;
    }
   }

   struct Node *new = createNode(key);
   if(key < prev->data){
    prev->left= new;
   }
   else{
    prev->right= new;
   }
}

int main()
{
    struct Node *p = createNode(50);
    struct Node *p1 = createNode(40);
    struct Node *p2 = createNode(20);
    struct Node *p3 = createNode(60);
    struct Node *p4 = createNode(55);
    struct Node *p5 = createNode(70);
    struct Node *p6 = createNode(45);

    p->left = p1;
    p->right = p3;
    p1->left = p2;
    p1->right = p6;
    p3->left = p4;
    p3->right = p5;

    /*
                50
               /  \
             40    60
            / \    / \
          20   45 55   70
    */
    Insert(p, 65);

    inOrder(p);
    return 0;
}