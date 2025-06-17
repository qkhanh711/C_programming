#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int id;
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_PreOrder(BTNode *cur)
{
    printf("%d ", cur->item);
    if (cur->left != NULL)
    {
        TreeTraversal_PreOrder(cur->left);
    }
    if (cur->right != NULL)
    {
        TreeTraversal_PreOrder(cur->right);
    }
}
void TreeTraversal_InOrder(BTNode *cur)
{
    if (cur->left != NULL)
    {
        TreeTraversal_InOrder(cur->left);
    }
    printf("%d ", cur->item);
    if (cur->right != NULL)
    {
        TreeTraversal_InOrder(cur->right);
    }
}
void TreeTraversal_PostOrder(BTNode *cur)
{
    if (cur->left != NULL)
    {
        TreeTraversal_PostOrder(cur->left);
    }
    if (cur->right != NULL)
    {
        TreeTraversal_PostOrder(cur->right);
    }
    printf("%d ", cur->item);
}

BTNode *createNode(int id, int item)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->id = id;
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isBST(BTNode *cur)
{
    if (cur == NULL)
    {
        return 1;
    }
    if (cur->left != NULL && cur->left->item > cur->item)
    {
        return 0;
    }
    if (cur->right != NULL && cur->right->item < cur->item)
    {
        return 0;
    }
    return isBST(cur->left) && isBST(cur->right);
}

BTNode *BSTT(BTNode *cur, int value)
{
    if (cur == NULL)
    {
        return NULL;
    }
    if (cur->item == value)
    {
        return cur;
    }
    if (value < cur->item)
    {
        return BSTT(cur->left, value);
    }
    else
    {
        return BSTT(cur->right, value);
    }
}

BTNode *Predecessor(BTNode *cur)
{
    BTNode *max = cur->left;
    while (max->right != NULL)
    {
        max = max->right;
    }
    return max;
}

BTNode *Successor(BTNode *cur)
{
    BTNode *min = cur->right;
    while (min->left != NULL)
    {
        min = min->left;
    }
    return min;
}

int countNodesInRange(BTNode *cur, int a, int b)
{
    if (cur == NULL)
        return 0;

    int count = 0;
    if (cur->item >= a && cur->item <= b)
        count = 1;

    if (cur->item > a)
        count += countNodesInRange(cur->left, a, b);
    if (cur->item < b)
        count += countNodesInRange(cur->right, a, b);

    return count;
}

BTNode *lastLeftChild(BTNode *t)
{
    BTNode *p = t->right;
    while (p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

BTNode *KthNode(BTNode *cur, int k)
{
    BTNode *last = lastLeftChild(cur);
    while (k > 0)
    {
        last = Successor(last);
        k--;
    }
    return last;
}

int main(void)
{
    FILE *inputFile = fopen("INPUT.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Khong the mo file\n");
        return 1;
    }

    int N, root_id;
    fscanf(inputFile, "%d", &N);
    fscanf(inputFile, "%d", &root_id);
    BTNode **nodes = malloc(N * sizeof(BTNode *));

    for (int i = 0; i < N; i++)
    {
        int node_id, value, left_child_id, right_child_id;
        fscanf(inputFile, "%d %d %d %d", &node_id, &value, &left_child_id, &right_child_id);
        nodes[node_id] = createNode(node_id, value);

        nodes[node_id]->left = (BTNode *)(long)left_child_id;
        nodes[node_id]->right = (BTNode *)(long)right_child_id;
    }

    for (int i = 0; i < N; i++)
    {
        int left_id = (int)(long)nodes[i]->left;
        int right_id = (int)(long)nodes[i]->right;
        nodes[i]->left = (left_id != -1) ? nodes[left_id] : NULL;
        nodes[i]->right = (right_id != -1) ? nodes[right_id] : NULL;
    }

    printf(isBST(nodes[0]) ? "YES\n" : "NO\n");
    fprintf(outputFile, isBST(nodes[0]) ? "YES\n" : "NO\n");
    printf("\n");
    TreeTraversal_InOrder(nodes[0]);

    int value;
    fscanf(inputFile, "%d", &value);
    BTNode *foundNode = BSTT(nodes[0], value);
    int ped = Predecessor(foundNode)->item;
    int suc = Successor(foundNode)->item;
    printf("%d %d\n", ped, suc);
    // printf("%d %d\n", Predecessor(foundNode), Successor(foundNode));
    fprintf(outputFile, "%d %d\n", Predecessor(foundNode)->item, Successor(foundNode)->item);
    int a, b;
    fscanf(inputFile, "%d %d", &a, &b);
    int num = countNodesInRange(nodes[0], a, b);
    printf("%d", num);

    int k;
    fscanf(inputFile, "%d", &k);
    int res = KthNode(nodes[0], k)->item;
    printf("%d", res);

    for (int i = 0; i < N; i++)
    {
        free(nodes[i]);
    }
    free(nodes);
    fclose(inputFile);
    fclose(outputFile);
}
