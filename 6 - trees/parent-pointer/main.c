#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef enum {
    ROOT = -1,
    EMPTY = -2
} STATUS;

typedef int TREE[MAX];

void init(TREE);
void insert(TREE, int, int);
void delete(TREE, int);

int getParent(TREE, int);
int* getChildren(TREE, int, int*);
bool hasChildren(TREE, int);

bool isEmpty(TREE);
bool isFull(TREE);

void visualize(TREE);
void visualize_recursive(TREE, int, int);

int main() {
    TREE T;
    // 1. Initialize and Test Empty Tree
    init(T);
    printf("--- Initializing Tree ---\n");
    printf("Is tree empty? %s\n", isEmpty(T) ? "true" : "false");

    // 2. Insert Nodes
    printf("--- Inserting Nodes ---\n");
    insert(T, ROOT, 5); // Insert root
    insert(T, ROOT, 8); // Error: Root already exists
    insert(T, 5, 2);    // Insert child of 5
    insert(T, 5, 7);    // Insert child of 5
    insert(T, 2, 1);    // Insert child of 2
    insert(T, 7, 6);    // Insert child of 7
    insert(T, 7, 9);    // Insert child of 7
    printf("\n");

    // 3. Test Invalid Inserts
    printf("--- Testing Invalid Inserts ---\n");
    insert(T, 10, 11);  // Error: Parent 10 does not exist
    insert(T, 5, 30);   // Error: Value 30 out of bounds
    insert(T, 7, 2);    // Error: Index 2 is already occupied
    printf("\n");

    // 4. Visualize and Test Status
    printf("--- Current Tree State ---\n");
    visualize(T);
    printf("Is tree empty? %s\n", isEmpty(T) ? "true" : "false");
    printf("Is tree full? %s\n", isFull(T) ? "true" : "false");
    printf("\n");

    // 5. Test Utility Functions
    printf("--- Testing Utilities ---\n");
    printf("Parent of 6 is %d (Expected: 7)\n", getParent(T, 6));
    printf("Parent of 5 is %d (Expected: -1 for ROOT)\n", getParent(T, 5));
    printf("Parent of 10 is %d (Expected: -2 for EMPTY/Not Found)\n", getParent(T, 10));

    printf("Node 5 has children? %s (Expected: true)\n", hasChildren(T, 5) ? "true" : "false");
    printf("Node 6 has children? %s (Expected: false)\n", hasChildren(T, 6) ? "true" : "false");
    printf("\n");

    // 6. Test getChildren
    printf("--- Testing getChildren ---\n");
    int count = 0;
    int* children_of_7 = getChildren(T, 7, &count);
    if (children_of_7 != NULL) {
        printf("Found %d children for node 7: ", count);
        for (int i = 0; i < count; i++) {
            printf("%d ", children_of_7[i]);
        }
        printf("\n");
        free(children_of_7); // IMPORTANT: Free the allocated memory
    } else {
        printf("Node 7 has no children.\n");
    }

    // 7. Delete Nodes
    printf("--- Deleting Nodes ---\n");
    delete(T, 5);  // Error: Node 5 is a parent
    delete(T, 6);  // Success: Node 6 is a leaf
    visualize(T);

    delete(T, 9);  // Success: Node 9 is a leaf
    visualize(T);

    printf("Node 7 has children? %s (Expected: false)\n", hasChildren(T, 7) ? "true" : "false");
    delete(T, 7);  // Success: Node 7 is now a leaf
    visualize(T);

    delete(T, 1);  // Success
    delete(T, 2);  // Success
    visualize(T);

    delete(T, 5);  // Success: Root is now a leaf
    visualize(T);

    // 8. Final Status Check
    printf("--- Final Status Check ---\n");
    printf("Is tree empty? %s (Expected: true)\n", isEmpty(T) ? "true" : "false");

    return 0;
}

// Utility Functions
bool isEmpty(TREE T) {
    int i;
    for(i = 0; i < MAX && T[i] == EMPTY; i++) {}

    return (i < MAX) ? false: true;
}

bool isFull(TREE T) {
    int i;
    for(i = 0; i < MAX && T[i] != EMPTY; i++) {}

    return (i < MAX) ? false: true;
}

void init(TREE T) {
    for(int i = 0; i < MAX; i++) {
        T[i] = EMPTY;
    }
}

int getParent(TREE T, int child) {
    int i;
    for(i = 0; i < MAX && i < child; i++) {}

    return (i < MAX) ? T[i] : EMPTY;
}

int* getChildren(TREE T, int parent, int* count) {
    int* children = (int*)malloc(sizeof(int)*MAX);
    if (children != NULL) {
        int childrenIdx = 0;
        for(int i = 0; i < MAX; i++) {
            if (T[i] == parent) children[childrenIdx++] = i;
        }

        *count = childrenIdx;

        // TO DO: realloc
        return children;
    } else {
        printf("malloc failed!\n");
    }

    free(children);
    return NULL;
}

bool hasChildren(TREE T, int parent) {
    for(int i = 0; i < MAX; i++) {
        if (T[i] == parent) return true;
    }

    return false;
}

// major operations
void insert(TREE T, int parent, int child) {
    if (child > MAX) {
        printf("[%d][%d] out of bounds!\n", parent, child);
    } else if (isFull(T)) {
        printf("[%d][%d] tree is full!\n", parent, child);
    } else {
        if (parent == ROOT) {
            if (isEmpty(T)) {
                T[child] = ROOT;
            } else {
                printf("[ROOT][%d] tree already has a root!\n", child);
            }
        } else {
            if (T[parent] == EMPTY) {
                printf("[%d][%d] parent does not exist!\n", parent, child);
            } else if (T[child] == EMPTY) {
                T[child] = parent;
            } else {
                printf("[%d][%d] node is occupied!\n", parent, child);
            }
        }
    }
}

void delete(TREE T, int val) {
    if (!hasChildren(T, val)) {
        T[val] = EMPTY;
        printf("[%d] deleted!\n", val);
    } else {
        printf("[%d] this is a parent node, delete children first!\n", val);
    }
}


/**
 * @brief Recursively visualizes the tree structure.
 * @param T The tree.
 * @param node The current node index to print.
 * @param depth The current depth for indentation.
 */
void visualize_recursive(TREE T, int node, int depth) {
    // Print indentation for depth
    for (int i = 0; i < depth; i++) {
        printf("   "); // per depth level
    }

    // Print the current node
    printf("|- %d\n", node);

    // Find and recursively print all children
    for (int i = 0; i < MAX; i++) {
        if (T[i] == node) {
            visualize_recursive(T, i, depth + 1);
        }
    }
}

/**
 * @brief Visualizes the tree by finding the root and printing from there.
 */
void visualize(TREE T) {
    int root = -1;
    // Find the root
    for (int i = 0; i < MAX; i++) {
        if (T[i] == ROOT) {
            root = i;
            break;
        }
    }

    printf("\n--- Tree Visualization ---\n");
    if (root == -1) {
        if(isEmpty(T)) {
             printf("Tree is empty.\n");
        } else {
             // This case can happen if the root is deleted but children remain
             printf("No root node found! Printing raw array contents:\n");
             for(int i = 0; i < MAX; i++) {
                if(T[i] != EMPTY) {
                    printf("  T[%d] = %d\n", i, T[i]);
                }
             }
        }
    } else {
        // Start recursive print from the root
        visualize_recursive(T, root, 0);
    }
    printf("--------------------------\n");
}
