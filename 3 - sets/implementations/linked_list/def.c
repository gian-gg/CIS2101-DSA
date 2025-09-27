#include "header.h"

void mode() {
    printf("SETS - LINKED LIST\n");
    printf("==================\n\n");
}

void init(SET* S) {
    *S = NULL;
}

bool isFull(SET S) {
    return false;
}

bool isEmpty(SET S) {
    return S == NULL;
}

bool member(SET S, int data) {
    SET trav;
    for(trav = S; trav != NULL && trav->data != data; trav = trav->link) {}
    
    return (trav != NULL) ? true : false;
}

void insert(SET* S, int data) {
    SET newNode = malloc(sizeof(struct node));
    
    if (newNode && !isFull(*S)) {
        
        SET* trav;
        for(trav = S; *trav != NULL && (*trav)->data != data; trav = &((*trav)->link)) {}
        
        if (*trav == NULL) {
            newNode->data = data;
            newNode->link = *trav;
            *trav = newNode;
            
        } // else, duplicate found
    }
}

void delete(SET* S, int data) {
    if (!isEmpty(*S)) {
        
        SET* trav;
        for(trav = S; *trav != NULL && (*trav)->data != data; trav = &((*trav)->link)) {}
        
        if (*trav != NULL) {
            SET temp = *trav;
            *trav = temp->link;
            free(temp);
        }
        
    }
}

void read(SET S) {
    printf("{ ");
        
    if (isEmpty(S) != true) {
        
        SET trav;
        for(trav = S; trav != NULL; trav = trav->link) {
            printf("%d", trav->data);
            if(trav->link != NULL) printf(", ");
        }
        
    }
    
    printf(" }\n");
}

bool equal(SET A, SET B) {
    int countA = 0, countB = 0;
    for (SET trav = A; trav != NULL; trav = trav->link) countA++;
    for (SET trav = B; trav != NULL; trav = trav->link) countB++;
    
    if (countA == countB)  {
        for(SET trav = A; trav != NULL; trav = trav->link) {
            if (!member(B, trav->data)) return false;
        }
    
        return true;
    }

    return false;
}


SET* Union(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    if (C != NULL) {
        init(C);
    
        for (SET trav = A; trav != NULL; trav = trav->link) insert(C, trav->data);
        for (SET trav = B; trav != NULL; trav = trav->link) insert(C, trav->data);
    }
    
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    
    if (C != NULL) {
        init(C);
        
        for (SET trav = A; trav != NULL; trav = trav->link) {
            if (member(B, trav->data)) insert(C, trav->data);
        }
        
        
    }
    
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    
    if (C != NULL) {
        init(C);
        
        for (SET trav = A; trav != NULL; trav = trav->link) {
            if (!member(B, trav->data)) insert(C, trav->data);
        }
        
    }
    
    return C;
}
