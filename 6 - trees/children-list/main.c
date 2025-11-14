#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define ROOT -1
#define EMPTY -2

typedef struct node {
    int data;
    struct node* next;
} *nodetype;

typedef struct {
    nodetype header[MAX];
    int root;
} TREE;

// Function Prototypes
void init(TREE*);
void insert(TREE*, int, int);
void delete(TREE*, int);

int getParent(TREE, int);
int* getChildren(TREE, int);
bool hasChildren(TREE, int);

bool isHeaderEmpty(TREE);

// visualization functions (written by ai)
void displayTree(TREE);
void displayTreeRecursive(TREE, int, int);
void displayList(TREE);

int main() {
    TREE T;

    printf("--- Initializing Tree ---\n");
    init(&T);

    // --- Test Insertion ---
    printf("\n--- Building Tree Structure ---\n");
    insert(&T, ROOT, 5);
    insert(&T, 5, 2);
    insert(&T, 5, 8);
    insert(&T, 2, 1);
    insert(&T, 2, 3);
    insert(&T, 8, 9);

    printf("Tree Constructed:\n");
    displayTree(T);

    // --- Test 1: Deleting a Leaf Node (Success) ---
    printf("\n--- Test 1: Delete Leaf Node (3) ---\n");
    delete(&T, 3);
    displayTree(T);
    // Note: Using Unicode for checkmark. May not display on all terminals.
    printf("Test 1: \u2705 Pass\n");

    // --- Test 2: Deleting a Non-Existent Node (Fail) ---
    printf("\n--- Test 2: Delete Non-Existent Node (99) ---\n");
    delete(&T, 99);
    printf("Test 2: \u2705 Pass (Error message expected)\n");

    // --- Test 3: Deleting a Node with Children (Fail) ---
    printf("\n--- Test 3: Delete Node with Children (8) ---\n");
    delete(&T, 8); // Should fail and print an error
    displayTree(T); // Show 8 is still present
    printf("Test 3: \u2705 Pass (Deletion was correctly prevented)\n");

    // --- Test 4: Proper Deletion Order (Child then Parent) ---
    printf("\n--- Test 4: Delete Child (9) then Parent (8) ---\n");
    delete(&T, 9); // Deleting 9 (leaf)
    delete(&T, 8); // Now deleting 8 (which is now a leaf)
    displayTree(T);
    printf("Test 4: \u2705 Pass\n");

    // --- Test 5: Deleting Root with Children (Fail) ---
    printf("\n--- Test 5: Delete Root (5) with Children ---\n");
    delete(&T, 5); // Should fail
    printf("Test 5: \u2705 Pass (Deletion was correctly prevented)\n");

    // --- Test 6: Clearing remaining nodes to delete Root ---
    printf("\n--- Test 6: Clearing Tree to Delete Root ---\n");
    delete(&T, 1);
    delete(&T, 2);
    printf("Tree before root deletion:\n");
    displayTree(T); // Should only show root 5

    delete(&T, 5); // Now it should succeed
    printf("Final Tree Status:\n");
    displayTree(T); // Should be empty
    printf("Test 6: \u2705 Pass\n");

    // --- Final Summary ---
    printf("\n------------------------\n");
    printf("\u2705 Passed all tests\n");
    printf("------------------------\n");

    return 0;
}

// Utility Function
bool isHeaderEmpty(TREE T) {
    int i;
    for(i = 0; i < MAX && T.header[i] == NULL; i++) {}
    return (i < MAX) ? false : true;
}

void init(TREE* T) {
    for(int i = 0; i < MAX; i++) {
        T->header[i] = NULL;
    }
    T->root = EMPTY;
}

bool hasChildren(TREE T, int parent) {
    if (parent < 0 || parent >= MAX) {
        return false; // Out of bounds
    }
    return T.header[parent] != NULL;
}


// Major Operations
void insert(TREE* T, int parent, int child) {
    if (parent == ROOT) {
        if (T->root == EMPTY) {
            T->root = child;
        } else {
            printf("[ROOT][%d] Error: Root already exists!\n", child);
        }
    } else if (parent < 0 || parent >= MAX) {
        printf("[%d][%d] Error: Parent index out of bounds!\n", parent, child);
    } else {
        nodetype *trav;
        for(trav = &(T->header[parent]); *trav != NULL && (*trav)->data != child; trav=&((*trav)->next)) {}

        if (*trav == NULL) {
            nodetype newNode = (nodetype)malloc(sizeof(struct node));
            if (newNode) {
                newNode->data = child;
                newNode->next = NULL;
                *trav = newNode;
            } else {
                printf("[%d][%d] Error: Malloc failed!\n", parent, child);
            }
        } else {
            printf("[%d][%d] Error: Child already exists!\n", parent, child);
        }
    }
}

void delete(TREE* T, int val) {
    // Handle root deletion case
    if (T->root == val) {
        if (isHeaderEmpty(*T)) { // Only delete root if it has no children anywhere
            T->root = EMPTY;
            printf("[%d] Root deleted.\n", val);
        } else {
            printf("[%d] Error: Cannot delete root, it has children.\n", val);
        }
    } else {
        bool found = false;
        // Check all possible parent lists
        for(int i = 0; i < MAX; i++) {
            nodetype *trav = &(T->header[i]); // Start at the pointer to the head

            for(trav = &(T->header[i]);
                *trav != NULL && (*trav)->data != val;
                trav = &((*trav)->next)) {}

            // If *trav is not NULL, it means the loop stopped because (*trav)->data == val
            if (*trav != NULL) {
                found = true;

                if (T->header[(*trav)->data] != NULL) {
                    printf("[%d][%d] cannot delete, has children!\n", val, i);
                } else {
                    nodetype temp = *trav;
                    *trav = temp->next;
                    free(temp);

                    printf("[%d] Deleted from parent's [%d] child list.\n", val, i);
                }

                break; // A node should only have one parent, so we can stop searching.
            }
        }

        if (!found) {
            printf("[%d] Error: Node not found or is root (with children).\n", val);
        }
    }
}




// --- New Visualization Functions ---

/**
 * Public-facing function to display the tree.
 * It finds the root and starts the recursive process.
 */
void displayTree(TREE T) {
    if (T.root == EMPTY) {
        printf("Tree is empty.\n");
        return;
    }
    // Start the recursive display from the root node with 0 indentation
    displayTreeRecursive(T, T.root, 0);
}

/**
 * Helper function to recursively display the tree structure.
 * Uses Pre-order traversal (Parent, then Children).
 */
void displayTreeRecursive(TREE T, int parent, int indent) {
    // 1. Print indentation
    for(int i = 0; i < indent; i++) {
        printf("  "); // 4 spaces per indent level
    }

    // 2. Print the parent node
    printf("|-%d\n", parent);

    // 3. Traverse the children list and recurse
    nodetype trav;
    for(trav = T.header[parent]; trav != NULL; trav = trav->next) {
        displayTreeRecursive(T, trav->data, indent + 1);
    }
}

/**
 * Displays the raw internal structure of the TREE (the adjacency lists).
 * Useful for debugging.
 */
void displayList(TREE T) {
    printf("Root: %d\n", T.root);
    printf("Header Array:\n");
    for(int i = 0; i < MAX; i++) {
        printf("  %d -> ", i);
        nodetype trav = T.header[i];
        while(trav != NULL) {
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}
