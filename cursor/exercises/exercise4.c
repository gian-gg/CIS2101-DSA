#include <stdio.h>

#define MAX 7

typedef struct {
    char data;
    int link;
} nodetype;

typedef struct {
    nodetype nodes[MAX];
    int avail;
} VirtualHeap;

typedef int listtype;

void initVirtualHeap(VirtualHeap*);
int allocSpace(VirtualHeap*);
void deallocSpace(VirtualHeap*,listtype);

void initList(listtype*);
void displayList(VirtualHeap, listtype);

void insertFirst(VirtualHeap*, listtype*,char);
void insertLast(VirtualHeap*, listtype*,char);
void insertSorted(VirtualHeap*, listtype*,char);

void deleteElem(VirtualHeap*, listtype*,char);

int main() {
    VirtualHeap VH;
    listtype LIST;

    initVirtualHeap(&VH);
    initList(&LIST);

    insertLast(&VH, &LIST, 'G');
    insertLast(&VH, &LIST, 'I');
    insertFirst(&VH, &LIST, 'X');
    insertLast(&VH, &LIST, 'A');
    insertLast(&VH, &LIST, 'N');

    insertSorted(&VH, &LIST, 'E');

    displayList(VH, LIST);

    deleteElem(&VH, &LIST, 'X');

    displayList(VH, LIST);

    return 0;
}

void initVirtualHeap(VirtualHeap *VH) {
    for (int i = MAX - 1; i >= 0; i--) {
        VH->nodes[i].link = i - 1;
    }

    VH->avail = MAX - 1;
}

int allocSpace(VirtualHeap *VH) {
    int idx = VH->avail;

    if (idx != -1) {
        VH->avail = VH->nodes[idx].link;
    }

    return idx;
}

void deallocSpace(VirtualHeap* VH, int idx) {
    if (idx != -1) {
        VH->nodes[idx].link = VH->avail;
        VH->avail = idx;
    }
}

void initList(int* list) {
    *list = -1;
}

void displayList(VirtualHeap VH, listtype LIST) {
    for(int curr = LIST; curr != -1; curr = VH.nodes[curr].link) {
        printf("%c ", VH.nodes[curr].data);
    }
    printf("\n");
}

void insertFirst(VirtualHeap* VH, listtype* LIST,char data) {
    int newNodeIdx = allocSpace(VH);

    if (newNodeIdx != 1) {
        VH->nodes[newNodeIdx].data = data;
        VH->nodes[newNodeIdx].link = *LIST;
        *LIST = newNodeIdx;
    }
}

void insertLast(VirtualHeap *VH, listtype *LIST, char data) {
    int newNodeIdx = allocSpace(VH);

    if (newNodeIdx != -1) {
        int curr;
        for(curr=*LIST; VH->nodes[curr].link!=-1; curr=VH->nodes[curr].link) {}

        VH->nodes[newNodeIdx].data = data;
        VH->nodes[newNodeIdx].link = -1;
        VH->nodes[curr].link = newNodeIdx;
    } else {
        printf("\nNo More Space!\n");
    }
}

void insertSorted(VirtualHeap *VH, listtype *LIST, char data) {
    int newNodeIdx = allocSpace(VH);

    if (newNodeIdx != -1) {
        int curr;
        for(curr=*LIST; VH->nodes[curr].link!=-1 && VH->nodes[curr].data < data; curr=VH->nodes[curr].link) {}

        VH->nodes[newNodeIdx].data = data;
        VH->nodes[newNodeIdx].link = VH->nodes[curr].link;
        VH->nodes[curr].link = newNodeIdx;
    } else {
        printf("\nNo More Space!\n");
    }
}

void deleteElem(VirtualHeap *VH, listtype *LIST, char elem) {
    int curr;
    for (curr=*LIST; curr != -1 && VH->nodes[VH->nodes[curr].link].data != elem; curr = VH->nodes[curr].link) {}

    if (curr != -1) {
        int temp = VH->nodes[curr].link;
        VH->nodes[curr].link = VH->nodes[temp].link;

        deallocSpace(VH, temp);
    }
}
