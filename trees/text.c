#include <stdio.h>
#include <stdlib.h>

typedef struct bTree
{
    int info;
    char message[100];
    struct bTree *left;
    struct bTree *right;
} BTREE;

BTREE *root = NULL;

void insert(BTREE *treeRoot, BTREE *newNode)
{

    if (treeRoot == NULL)
    {
        root = newNode;
    }
    else
    {
        if (newNode->info < treeRoot->info)
        {
            if (treeRoot->left == NULL)
            {
                treeRoot->left = newNode;
            }
            else
            {
                insert(treeRoot->left, newNode);
            }
        }
        else
        {
            if (treeRoot->right == NULL)
            {
                treeRoot->right = newNode;
            }
            else
            {
                insert(treeRoot->right, newNode);
            }
        }
    }
}
// pre-order traversal
void traversal(BTREE *treeRoot)
{
    if (treeRoot != NULL)
    {
        printf("%d %s\n", treeRoot->info, treeRoot->message);
        traversal(treeRoot->left);
        traversal(treeRoot->right);
    }
}

BTREE *searchNode(BTREE *treeRoot, int item)
{
    while ((treeRoot != NULL) && (treeRoot->info != item))
    {
        if (item < treeRoot->info)
        {
            treeRoot = treeRoot->left;
        }
        else
        {
            treeRoot = treeRoot->right;
        }
    }
    return treeRoot;
}

BTREE *delete(BTREE *treeRoot, int item)
{
    
}

BTREE *readNode()
{
    BTREE *newNode;
    newNode = (BTREE *)malloc(sizeof(BTREE));
    if (newNode == NULL)
    {
        return NULL;
    }
    else
    {
        printf("Enter info: ");
        scanf("%d", &(newNode->info));
        printf("Enter message: ");
        scanf("%s", (newNode->message));
    }
}

int countNodes(BTREE *treeRoot, int sum)
{
    if (treeRoot == NULL)
    {
        return sum;
    }
    sum++;
    sum = countNodes(treeRoot->left, sum);
    sum = countNodes(treeRoot->right, sum);
}