#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int id;
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;


void TreeTraversal_PreOrder(BTNode *cur) {
    printf("%d ",cur->item);
    if (cur->left != NULL){
        TreeTraversal_PreOrder(cur->left);
    } 
    if (cur->right != NULL)
    {
        TreeTraversal_PreOrder(cur->right);
    }
}
void TreeTraversal_InOrder(BTNode *cur) {
    if (cur->left != NULL){
        TreeTraversal_InOrder(cur->left);
    }
    printf("%d ",cur->item);
    if (cur->right != NULL){
        TreeTraversal_InOrder(cur->right);
    }    
}
void TreeTraversal_PostOrder(BTNode *cur) {
    if (cur->left != NULL){
        TreeTraversal_PostOrder(cur->left);
    }
    if (cur->right != NULL)
    {
        TreeTraversal_PostOrder(cur->right);
    } 
    printf("%d ",cur->item);
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

int checkNumberTreeNode(BTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + checkNumberTreeNode(root->left) + checkNumberTreeNode(root->right);
}

int findNumberOfNodesAtLevel(BTNode *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    if (level == 0)
    {
        printf("%d ", root->id);
        return 1;
    }
    return findNumberOfNodesAtLevel(root->left, level - 1) + findNumberOfNodesAtLevel(root->right, level - 1) - 1;
}

int findNumberOfLeaf(BTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return findNumberOfLeaf(root->left) + findNumberOfLeaf(root->right);
}

int heightNode(BTNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightNode(root->left);
    int rightHeight = heightNode(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int checkFullBinaryTree(BTNode *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    if (root->left != NULL && root->right != NULL)
    {
        return checkFullBinaryTree(root->left) && checkFullBinaryTree(root->right);
    }
    return 0;
}

int reflectBTree(BTNode *root1, BTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    return (root1->item == root2->item) &&
           reflectBTree(root1->left, root2->right) &&
           reflectBTree(root1->right, root2->left);
}

int checkSymmetricTree(BTNode *root1, BTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    return (root1->item == root2->item) &&
           checkSymmetricTree(root1->right, root2->right) &&
           checkSymmetricTree(root1->left, root2->left);
}

int findFatherValue(BTNode *root, int id){
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL && root->left->id == id)
    {
        return root->item;
    }
    if (root->right != NULL && root->right->id == id)
    {
        return root->item;
    }
    int leftValue = findFatherValue(root->left, id);
    if (leftValue != NULL)
    {
        return leftValue;
    }
    int rightValue = findFatherValue(root->right, id);
    if (rightValue != NULL)
    {
        return rightValue;
    }
    return 0;

}

int main(void)
{
    FILE *inputFile = fopen("inputbai1.txt", "r");
    FILE *outputFile = fopen("OUTPUT.txt", "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Khong the mo file\n");
        return 1;
    }

    int N, root_id;
    fscanf(inputFile, "%d", &N);
    fscanf(inputFile, "%d", &root_id);
    // printf("N = %d, root_id = %d\n", N, root_id);
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



    int N1, root_id1;
    fscanf(inputFile, "%d", &N1);
    fscanf(inputFile, "%d", &root_id1);
    // printf("N = %d, root_id = %d\n", N1, root_id1);
    BTNode **nodes1 = malloc(N1 * sizeof(BTNode *));

    for (int i = 0; i < N1; i++)
    {
        int node_id1, value1, left_child_id1, right_child_id1;
        fscanf(inputFile, "%d %d %d %d", &node_id1, &value1, &left_child_id1, &right_child_id1);
        nodes1[node_id1] = createNode(node_id1, value1);

        nodes1[node_id1]->left = (BTNode *)(long)left_child_id1;
        nodes1[node_id1]->right = (BTNode *)(long)right_child_id1;
    }

    for (int i = 0; i < N; i++)
    {
        int left_id = (int)(long)nodes1[i]->left;
        int right_id = (int)(long)nodes1[i]->right;
        nodes1[i]->left = (left_id != -1) ? nodes1[left_id] : NULL;
        nodes1[i]->right = (right_id != -1) ? nodes1[right_id] : NULL;
    }



    TreeTraversal_InOrder(nodes[0]);
    printf("\n");
    TreeTraversal_InOrder(nodes1[0]);
    printf("\n");



    int find_root_id;
    int generation;
    fscanf(inputFile, "%d", &find_root_id);
    fscanf(inputFile, "%d", &generation);

    printf("find_root_id = %d, generation = %d\n", find_root_id, generation);
    int number_of_nodes = checkNumberTreeNode(nodes[find_root_id]);
    printf("So nut trong cay la: %d\n", number_of_nodes);
    fprintf(outputFile, "So nut trong cay la: %d\n", number_of_nodes);

    int number_of_nodes_at_level = findNumberOfNodesAtLevel(nodes[find_root_id], generation);
    printf("\nSo nut o the he thu %d la: %d\n", generation, number_of_nodes_at_level);
    fprintf(outputFile, "So nut o the he thu %d la: %d\n", generation, number_of_nodes_at_level);

    int height = heightNode(nodes[find_root_id]);
    printf("\nChieu cao cua cay la: %d\n", height);
    fprintf(outputFile, "Chieu cao cua cay la: %d\n", height);

    int number_of_leaf = findNumberOfLeaf(nodes[find_root_id]);
    printf("\nSo nut la la: %d\n", number_of_leaf);
    fprintf(outputFile, "So nut la la: %d\n", number_of_leaf);

    int father_value = findFatherValue(nodes[0], find_root_id);
    if (father_value != 0)
    {
        printf("\nGia tri cha cua nut %d la: %d\n", find_root_id, father_value);
        fprintf(outputFile, "Gia tri cha cua nut %d la: %d\n", find_root_id, father_value);
    }
    else
    {
        printf("\nKhong tim thay cha cua nut %d\n", find_root_id);
        fprintf(outputFile, "Khong tim thay cha cua nut %d\n", find_root_id);
    }


    printf(checkFullBinaryTree(nodes[0]) ? "Co\n" : "Khong\n");
    fprintf(outputFile, checkFullBinaryTree(nodes[0]) ? "Co\n" : "Khong\n");
    fprintf(outputFile, " la cay nhi phan day du\n");

    printf(checkSymmetricTree(nodes[0], nodes1[0]) ? "Co\n" : "Khong\n");
    fprintf(outputFile, checkSymmetricTree(nodes[0], nodes1[0]) ? "Co\n" : "Khong\n");

    printf(reflectBTree(nodes[0], nodes1[0]) ? "Co\n" : "Khong\n");
    fprintf(outputFile, reflectBTree(nodes[0], nodes1[0]) ? "Co\n" : "Khong\n");
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        free(nodes[i]);
    }
    free(nodes);
    fclose(inputFile);
    fclose(outputFile);
}


