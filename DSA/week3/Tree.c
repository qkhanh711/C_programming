#include<stdio.h>

typedef struct _btnode {
    int item;
    // Bổ sung mã chương trình nếu cần
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_Preorder(BTNode *cur){
    printf("%d ", cur->item);
    if (cur->left != NULL) {
        TreeTraversal_Preorder(cur->left);
    }
    if (cur->right != NULL) {
        TreeTraversal_Preorder(cur->right);
    }
}

void TreeTraversal_Inorder(BTNode *cur) {
    if (cur->left != NULL) {
        TreeTraversal_Inorder(cur->left);
    }
    printf("%d ", cur->item);
    if (cur->right != NULL) {
        TreeTraversal_Inorder(cur->right);
    }
}

void TreeTraversal_Postorder(BTNode *cur) {
    if (cur->left != NULL) {
        TreeTraversal_Postorder(cur->left);
    }
    if (cur->right != NULL) {
        TreeTraversal_Postorder(cur->right);
    }
    printf("%d ", cur->item);
}

int main(void){
    int item1 = 1, item2 = 2, item3 = 3;
    BTNode btnode1, btnode2, btnode3;
    btnode1.item = item1;
    btnode2.item = item2;
    btnode3.item = item3;

    btnode2.left = NULL;
    btnode2.right = NULL;

    btnode3.left = NULL;
    btnode3.right = NULL;

    btnode1.left = &btnode2;
    btnode1.right = &btnode3;

    printf("\nDuyet cay theo thu tu truoc: ");
    TreeTraversal_Preorder( &btnode1 );

    printf("\nDuyet cay theo thu tu giua: ");
    TreeTraversal_Inorder( &btnode1 );

    printf("\nDuyet cay theo thu tu sau: ");
    TreeTraversal_Postorder( &btnode1 );
}



// BAI 2: 
// Truoc:
// H E B C D F G L J K
// Giua:
// B C D E F G H J K L
// Sau:
// D C B G F E L J L H

