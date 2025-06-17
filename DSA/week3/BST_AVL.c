#include<stdio.h>

typedef struct _listnode {
    char item;
    struct _listnode *next;
} ListNode;

typedef struct _btnode {
    char item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_PreOrder(BTNode *cur) {
    printf("%c ",cur->item);
    if (cur->left != NULL) {
        TreeTraversal_PreOrder(cur->left);
    }
    if (cur->right != NULL) {
        TreeTraversal_PreOrder(cur->right);
    }
}
void TreeTraversal_InOrder(BTNode *cur) {
    if (cur->left != NULL) {
        TreeTraversal_InOrder(cur->left);
    }
    printf("%c ",cur->item);
    if (cur->right != NULL) {
        TreeTraversal_InOrder(cur->right);
    }
}
void TreeTraversal_PostOrder(BTNode *cur) {
    if (cur->left != NULL) {
        TreeTraversal_PostOrder(cur->left);
    }
    if (cur->right != NULL) {
        TreeTraversal_PostOrder(cur->right);
    }
    printf("%c ",cur->item);

}

// b,
// Truoc: H D C E K
// Giua : C D E H K
// Sau  : C E D K H

int main(void) {
    char node1 = 'H', node2 = 'D', node3 = 'K', node4 = 'C', node5 = 'E';
    // ListNode listnode1, listnode2, listnode3, listnode4, listnode5;

    BTNode btnode1, btnode2, btnode3, btnode4, btnode5;
    btnode1.item = node1;
    btnode2.item = node2;
    btnode3.item = node3;
    btnode4.item = node4;
    btnode5.item = node5;

    btnode1.left = &btnode2;
    btnode1.right = &btnode3;
    btnode2.left = &btnode4;
    btnode2.right = &btnode5;

    btnode3.left = NULL;
    btnode3.right = NULL;
    btnode4.left = NULL;
    btnode4.right = NULL;
    btnode5.left = NULL;
    btnode5.right = NULL;

    printf("\nDuyet cay theo thu tu truoc: ");
    TreeTraversal_PreOrder(&btnode1);
    printf("\nDuyet cay theo thu tu giua: ");
    TreeTraversal_InOrder(&btnode1);
    printf("\nDuyet cay theo thu tu sau: ");
    TreeTraversal_PostOrder(&btnode1);

}

BTNode* BSTT2(BTNode *cur, char c) {
    if (cur == NULL) {printf("Can't find!"); return;}
    if (cur==cur->item) { printf("found!\n"); return NULL;}
    if (c < cur->item) {
        if (cur->left == NULL) {return cur;}
        else {return BSTT2(cur->left, c);}
    }
    else {
        if (cur->right == NULL) {return cur;}
        else {return BSTT2(cur->right, c);}
    }
}

// d, Khi them C vao cay thi tra ra found!
// Giai thich 
// Khi gọi BSTT2(root, 'C'):

// So sánh 'C' với H → trái

// So sánh 'C' với D → trái

// D.left là NULL → return D

// Chèn 'C' vào trái của D
// Nhưng C đã có trong cây => không chèn nữa
// => return NULL

// e) 
// H có 2 con (D và K)
//  Đổi chỗ  H với nút kế tiếp trong in-order là K
//  Xóa H:

// f) 
// H có 2 con
// Đổi chỗ  H với nút trước trong in-order là E
// Xóa H:

// g) 
// Tính chiều cao các node:

// C, E, K: cao 0

// D: cao 1 (cân bằng)

// H: trái = 1, phải = 0 → hiệu = 1 ⇒ hợp lệ

// T1 là cây AVL vì mọi nút đều có hiệu độ cao <= 1:

// h)
// 
//     H
//    / \
//   D   K
//  / \
// C   E

//     H
//    / \
//   D   K
//  / \
// C   E
// /
// A

//     H
//    / \
//   C   K
//  / \
// A   D
//      \
//       E

//     D
//    / \
//   C   H
//  /   /  \
// A   E    K
      
// i)
//     H
//    / \
//   C   K
//  / \
// A   D
//      \
//       E
//        \
//         F
//      H
//     / \
//    D   K
//   / \
//  C   E
// /      \
//A        F
//      E
//     / \
//    D   H
//   /   / \
//  C   F   K
// /      
//A        



