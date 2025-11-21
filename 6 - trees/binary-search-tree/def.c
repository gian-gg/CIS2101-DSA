#include "header.h"

void init(BST* T) {
    *T = NULL;
}

void insert(BST* T, int value) {
    BST newNode = (BST)malloc(sizeof(struct node));
    if (newNode != NULL) {
        BST* trav;
        for(trav = T;
            *trav != NULL && (*trav)->data != value;
            trav = (value > (*trav)->data) ? &((*trav)->right) : &((*trav)->left)) {}

        if (*trav == NULL) {
            newNode->data = value;
            newNode->right = NULL;
            newNode->left = NULL;
            *trav = newNode;
        } else {
            printf("Duplicate Entry Detected [%d]!\n", value);
            free(newNode);
        }
    } else {
        printf("Malloc Failed [%d]!\n", value);
    }
}

void delete(BST* T, int value) {
    if (*T != NULL) {
        BST* trav;
        for (trav = T;
             (*trav) != NULL && (*trav)->data != value;
             trav = (value > (*trav)->data) ? &((*trav)->right) : &((*trav)->left)
             ){}

        if (*trav != NULL) {
            if ((*trav)->left != NULL && (*trav)->right != NULL) {
                BST* pred;
                for(pred = &(*trav)->left; (*pred)->right != NULL; pred = &((*pred)->right)) {}
                (*trav)->data = (*pred)->data;
                trav = pred;
            }

            BST temp = *trav;
            *trav = ((*trav)->left == NULL) ? (*trav)->right : (*trav)->left;
            free(temp);

            printf("[%d] Deleted!\n", value);
        } else {
            printf("[%d] Node does not exist!\n", value);
        }
    } else {
        printf("[%d] Tree is Empty!\n", value);
    }
}


// =========================================================
//  VISUALIZATION HELPERS
// =========================================================

struct Trunk {
    struct Trunk *prev;
    char *str;
};

// Helper to print the history of the trunks
void showTrunks(struct Trunk *p) {
    if (p == NULL) {
        return;
    }
    showTrunks(p->prev);
    printf("%s", p->str);
}

void printTree(BST root, struct Trunk *prev, bool isLeft) {
    if (root == NULL) {
        return;
    }

    char* prev_str = "    ";
    struct Trunk *trunk = (struct Trunk*)malloc(sizeof(struct Trunk));
    trunk->prev = prev;
    trunk->str = prev_str;

    // --- PRINT RIGHT BRANCH (Top of visualization) ---
    printTree(root->right, trunk, true);

    // --- PRINT CURRENT NODE ---
    if (!prev) {
        trunk->str = "---"; // Root node
    } else if (isLeft) {
        trunk->str = ".---"; // Right child (visually up)
        prev_str = "   |";
    } else {
        trunk->str = "`---"; // Left child (visually down)
        prev->str = prev_str;
    }

    showTrunks(trunk);
    printf("%d\n", root->data);

    // --- PRINT LEFT BRANCH (Bottom of visualization) ---
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    free(trunk);
}

void visualize(BST T) {
    printf("+------------------------------------------------+\n");
    printf("\nBST Visualization:\n");
    printf("+------------------------------------------------+\n");
    printTree(T, NULL, false);
    printf("+------------------------------------------------+\n");

}
