#include <stdio.h>
#define MAX 10

typedef struct {
    int data;
    int link;
} nodetype;

typedef struct {
    nodetype nodes[MAX];
    int avail;
} VirtualHeap;

typedef int listype;

void initVH(VirtualHeap*);
int alloc(VirtualHeap*);
void dealloc(VirtualHeap*, int);

void initList(listype*);
void display(VirtualHeap,listype);

void insertFirst(VirtualHeap*,listype*,int);
void insertLast(VirtualHeap*,listype*,int);
void insertSorted(VirtualHeap*,listype*,int);

void deleteElem(VirtualHeap*,listype*,int);

int main() {
    VirtualHeap VH; initVH(&VH);
    listype L; initList(&L);

    insertLast(&VH, &L, 10);
    insertLast(&VH, &L, 20);
    insertLast(&VH, &L, 30);
    insertLast(&VH, &L, 40);

    display(VH, L);

    insertSorted(&VH, &L, 50);
    insertSorted(&VH, &L, 25);
    insertSorted(&VH, &L, 35);

    display(VH, L);

    deleteElem(&VH, &L, 35);
    deleteElem(&VH, &L, 40);

    display(VH, L);

    return 0;
}

void initVH(VirtualHeap* VH) {
    for(int i = 0; i < MAX; i++) {
        VH->nodes[i].link = i-1;
    }
    VH->avail = MAX-1;
}

int alloc(VirtualHeap* VH) {
    int idx = VH->avail;

    if(idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }

    return idx;
}

void dealloc(VirtualHeap* VH, int idx) {
    if (idx != -1) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void initList(listype *L) {
    *L = -1;
}

void display(VirtualHeap VH, listype L) {
    for(int trav = L; trav != -1; trav=VH.nodes[trav].link) {
        printf("%d ", VH.nodes[trav].data);
    }
    printf("\n");
}

void insertLast(VirtualHeap* VH,listype* L,int data) {
    int newNode = alloc(VH);

    if (newNode != -1) {
        listype *trav;
        for(trav = L; *trav != -1; trav=&(VH->nodes[*trav].link)) {}

        VH->nodes[newNode].data = data;
        VH->nodes[newNode].link = -1;

        *trav = newNode;
    }
}

void insertFirst(VirtualHeap* VH,listype* L,int data) {
    int newNode = alloc(VH);

    if (newNode != -1) {
        VH->nodes[newNode].data = data;
        VH->nodes[newNode].link = *L;

        *L = newNode;
    }
}

void insertSorted(VirtualHeap* VH,listype* L,int data) {
    int newNode = alloc(VH);

    if (newNode != -1) {
        listype *trav;
        for(trav = L; (*trav != -1) && data > VH->nodes[*trav].data ; trav=&(VH->nodes[*trav].link)) {}

        VH->nodes[newNode].data = data;
        VH->nodes[newNode].link = *trav;

        *trav = newNode;
    }
}

void deleteElem(VirtualHeap* VH,listype* L,int data) {
    listype *trav;
    for(trav = L; (*trav != -1) && data != VH->nodes[*trav].data ; trav=&(VH->nodes[*trav].link)) {}

    if (*trav != -1) {
        listype temp = *trav;
        *trav = VH->nodes[temp].link;
        dealloc(VH, temp);
    }
}
