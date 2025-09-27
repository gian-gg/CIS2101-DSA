#include "./header.h"

void mode() {
    printf("SETS - ARRAYS\n");
    printf("=============\n\n");
}

void init(SET* S) {
    S->count = 0;
}

bool isFull(SET S) {
    return S.count == MAX;
}

bool isEmpty(SET S) {
    return S.count == 0;
}

bool member(SET S, int data) {
    int idx;
    for(idx = 0; idx < S.count && S.data[idx] != data; idx++) {}
    
    return (idx < S.count) ? true : false;
}

void insert(SET* S, int data) {
    if (!member(*S, data) && !isFull(*S)) {
        S->data[(S->count)++] = data;
    }
}

void delete(SET* S, int data) {
    if (member(*S, data) && !isEmpty(*S)) {
        int idx;
        for(idx = 0; idx < S->count && S->data[idx] != data; idx++) {}
        
        S->data[idx] = S->data[S->count - 1];
        (S->count)--;
    }
}

void read(SET S) {
    printf("{ ");
        
    if (isEmpty(S) != true) {
        for(int i = 0; i < S.count; i++) {
            printf("%d", S.data[i]);
            if (i < S.count - 1) printf(", ");
        }
    }
    
    printf(" }\n");
}

bool equal(SET A, SET B) {
    if (A.count == B.count) {
        for (int i = 0; i < A.count; i++) {
            if (!member(B, A.data[i])) return false;
        }

        return true;
    } else {
         return false;
    }
}


SET* Union(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    
    if (C != NULL) {
        init(C);
        
        for (int i = 0; i < A.count; i++) insert(C, A.data[i]);
        for (int i = 0; i < B.count; i++) insert(C, B.data[i]);
    }
    
    return C;
}

SET* Intersection(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    
    if (C != NULL) {
        init(C);
        
        for (int i = 0; i < A.count; i++) {
            if (member(B, A.data[i])) insert(C, A.data[i]);
        }

    }
    
    return C;
}

SET* Difference(SET A, SET B) {
    SET* C = malloc(sizeof(SET));
    
    if (C != NULL) {
        init(C);
        
        for (int i = 0; i < A.count; i++) {
            if (!member(B, A.data[i])) {
                insert(C, A.data[i]);
            }
        }
    }
    
    return C;
}
