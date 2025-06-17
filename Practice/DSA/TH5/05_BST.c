#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btnode {
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_InOrder2(BTNode *cur) {
    if (cur == NULL) return;
    TreeTraversal_InOrder2(cur->left);
    printf("%d ", cur->item);
    TreeTraversal_InOrder2(cur->right);
}

BTNode *BSTT(BTNode *cur, int c) {
    if (cur == NULL) return NULL;
    if (c == cur->item) return cur;
    if (c < cur->item)
        return BSTT(cur->left, c);
    else
        return BSTT(cur->right, c);
}

BTNode* BSTT2(BTNode *cur, int c) {
    if (c == cur->item)
        return NULL;
    if (c < cur->item) {
        if (cur->left == NULL)
            return cur;
        return BSTT2(cur->left, c);
    } else {
        if (cur->right == NULL)
            return cur;
        return BSTT2(cur->right, c);
    }
}

BTNode* insertNodeBST(BTNode **t, int c) {
    if ((*t) == NULL) {
        (*t) = malloc(sizeof(BTNode));
        (*t)->item = c;
        (*t)->left = NULL;
        (*t)->right = NULL;
        return (*t);
    }

    BTNode *posNode = BSTT2(*t, c);
    if (posNode == NULL) {
        printf("Phan tu da ton tai\n");
        return NULL;
    }

    BTNode *btNewNode = malloc(sizeof(BTNode));
    btNewNode->item = c;
    btNewNode->left = NULL;
    btNewNode->right = NULL;

    if (c < posNode->item)
        posNode->left = btNewNode;
    else
        posNode->right = btNewNode;

    return btNewNode;
}

BTNode* lastLeftChild(BTNode *t) {
    BTNode *p = t->right;
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}

void removeBST(BTNode **t, int num) {
    if (*t == NULL) return;

    if ((*t)->item > num) {
        removeBST(&((*t)->left), num);
    } else if ((*t)->item < num) {
        removeBST(&((*t)->right), num);
    } else {
        if ((*t)->left == NULL) {
            BTNode *r = *t;
            (*t) = (*t)->right;
            free(r);
        } else if ((*t)->right == NULL) {
            BTNode *r = *t;
            (*t) = (*t)->left;
            free(r);
        } else {
            BTNode *p = lastLeftChild(*t);
            (*t)->item = p->item;
            removeBST(&((*t)->right), p->item);
        }
    }
}

int main() {
    char s[200] = "HEBACDFGLJIKM";
    BTNode *t = NULL;

    for (int i = 0; i < (int)strlen(s); i++) {
        insertNodeBST(&t, s[i]);
    }

    printf("\nKet qua duyet cay theo thu tu giua:\n");
    TreeTraversal_InOrder2(t);

    printf("\n\nKet qua duyet cay theo thu tu giua (sau khi xoa):\n");
    char c = 'H';
    removeBST(&t, c);
    TreeTraversal_InOrder2(t);

    printf("\n\nKet qua duyet cay theo thu tu giua (sau khi chen):\n");
    c = 'Q';
    insertNodeBST(&t, c);
    TreeTraversal_InOrder2(t);

    printf("\n");
    return 0;
}
