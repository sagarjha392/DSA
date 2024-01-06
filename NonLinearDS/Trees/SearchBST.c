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

struct Node* Search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data>key){
        return Search(root->left, key);
    }
    else{
        return Search(root->right, key);
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

    p->left=p1;
    p->right=p3;
    p1->left=p2;
    p1->right=p6;
    p3->left=p4;
    p3->right=p5;

    /*
                50
               /  \
             40    60
            / \    / \
          20   45 55   70
    */
   struct Node * n =Search(p, 65);
   if(n != NULL){
    printf("\nFound: %d\n", n->data);
   }
   else{
    printf("\nNot Found\n");
   }

    return 0;
}