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
int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    // left subtree-> Root node -> right subtree
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{

    // root node
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // // Linking the nodes to construct the binary tree
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("\nInOrder Traversal: ");
    inOrder(p);

    int x = isBST(p);

    if(x){
        printf("\nYes, the given binary tree is BST\n");
    }else{
        printf("\nThe given binary tree is not a BST\n");

    }
    return 0;
}