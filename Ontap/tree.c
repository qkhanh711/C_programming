#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int num;
    struct Node *leftNode;
    struct Node *rightNode;
} Node;

typedef struct BinaryTree {
    Node *root;
} BinaryTree;

void insertBinaryTree(BinaryTree *tree, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->num) {
            current = current->leftNode;
        } else if (value > current->num) {
            current = current->rightNode;
        } else {
            free(newNode); 
            return;
        }
    }

    if (value < parent->num) {
        parent->leftNode = newNode;
    } else {
        parent->rightNode = newNode;
    }
}



void deleteBinaryTree(BinaryTree *tree, int value) {
    Node *current = tree->root;
    Node *parent = NULL;

    while (current != NULL && current->num != value) {
        parent = current;
        if (value < current->num) {
            current = current->leftNode;
        } else {
            current = current->rightNode;
        }
    }

    if (current == NULL) {
        printf("Value %d not found in the tree.\n", value);
        return;
    }

    Node *node_to_free = NULL;

    if (current->leftNode == NULL || current->rightNode == NULL) {
        Node *child = (current->leftNode != NULL) ? current->leftNode : current->rightNode;

        if (parent == NULL) {
            tree->root = child;
        } else if (parent->leftNode == current) {
            parent->leftNode = child;
        } else {
            parent->rightNode = child;
        }
        node_to_free = current;
    } else {
        Node *successorParent = current;
        Node *successor = current->rightNode;

        while (successor->leftNode != NULL) {
            successorParent = successor;
            successor = successor->leftNode;
        }

        current->num = successor->num;

        if (successorParent->leftNode == successor) {
            successorParent->leftNode = successor->rightNode;
        } else {
            successorParent->rightNode = successor->rightNode;
        }
        node_to_free = successor;
    }

    free(node_to_free);
}

void PreOrderTraversal(Node *node, FILE *output_file) {
    if (node == NULL) return;
    PreOrderTraversal(node->leftNode, output_file);
    fprintf(output_file, "%d ", node->num);
    PreOrderTraversal(node->rightNode, output_file);
}

int main(){
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(input_file, "%d", &n);
    printf("n = %d\n", n);

    BinaryTree tree;
    tree.root = NULL;

    int choice, value;
    for (int i = 0; i< n; i++){
        fscanf(input_file,"%d %d", &choice, &value);
        if (choice == 1) {
            printf("Inserting %d into the tree\n", value);
            insertBinaryTree(&tree, value);
        } else if (choice == 2) {
            printf("Deleting %d from the tree\n", value);
            deleteBinaryTree(&tree, value);
        } 
    }

    PreOrderTraversal(tree.root, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0;
}
