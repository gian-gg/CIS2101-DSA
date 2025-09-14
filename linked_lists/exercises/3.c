#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LENGTH 0XA // 10 in hex


typedef struct {
    char FN[24], MI, LN[16];
} nametype;

typedef struct {
    char ID[9];
    nametype name;
    char course[8];
    int yrlevel;
} studtype;

typedef struct cell {
    studtype stud;
    struct cell *link;
} *LinkList;


void init(LinkList*);
void displayStud(char[], char[], char, char[], char[], int);
void display(LinkList);

void insertFirst(LinkList*, studtype);
void insertLast(LinkList*, studtype);
void insertAtPos(LinkList*, studtype, int);
void insertLastUnique(LinkList*, studtype);
studtype deleteElem(LinkList*, char[]);
LinkList separateCourse(LinkList*, char[]);


int main() {
    LinkList List;
    init(&List);

    insertLast(&List, (studtype){"24100907", {"Geri Gian", 'C', "Epanto"}, "BSCS", 2});
    insertLast(&List, (studtype){"24103435", {"Emmanuel", 'C', "Cañete"}, "BSIT", 2});
    insertLast(&List, (studtype){"24103754", {"Czachary Xavier", 'C', "Villarin"}, "BSCS", 2});
    insertLast(&List, (studtype){"24103191", {"Ryan Nicolas", 'M', "Romero"}, "BSIT", 2});

    printf("Before:");
    display(List);

    LinkList newList = separateCourse(&List, "BSIT");

    printf("\n\n\nAfter:");
    printf("\n\nBSCS:");
    display(List);

    printf("\n\nBSIT:");
    display(newList);

    return 0;
}

void init(LinkList *HEAD) {
    *HEAD = NULL;
}

void displayStud(char ID[], char FN[], char MI, char LN[], char course[], int yrlevel) {
    printf("===============================================\n");
    printf(" ID\t| %s\n", ID);
    printf(" Name\t| %s %c. %s\n", FN, MI, LN);
    printf(" Course\t| %s\n", course);
    printf(" Year\t| %d\n", yrlevel);
    printf("===============================================\n");
}

void display(LinkList HEAD) {
    if (HEAD == NULL) {
        printf("\nNO RECORDS FOUND!\n");
        return;
    }

    int count = 0;
    for(LinkList curr = HEAD; curr!=NULL; curr=curr->link, count++) {
        printf("\nStudent %d:\n", count);
        displayStud(curr->stud.ID, curr->stud.name.FN, curr->stud.name.MI, curr->stud.name.LN, curr->stud.course, curr->stud.yrlevel);
    }
}

void insertFirst(LinkList *HEAD, studtype stud) {
    LinkList newNode = malloc(sizeof(struct cell));
    if (newNode != NULL) {
        newNode->stud = stud;
        newNode->link = *HEAD;
        *HEAD = newNode;
    } else {
        printf("\nMALLOC FAILED!\n");
    }
}

void insertLast(LinkList *HEAD, studtype stud) {
    LinkList *curr;
    for(curr = HEAD; *curr!=NULL; curr=&(*curr)->link);

    LinkList newNode = malloc(sizeof(struct cell));
    if (newNode != NULL) {
        newNode->stud = stud;
        newNode->link = NULL;
        *curr = newNode;
    } else {
        printf("\nMALLOC FAILED!\n");
    }
}

void insertAtPos(LinkList* HEAD, studtype stud, int index) {
    LinkList *curr;
    int i = 0;
    for(curr = HEAD; *curr!=NULL && i < index; curr=&(*curr)->link, i++);

    LinkList newNode = malloc(sizeof(struct cell));
    if (newNode != NULL) {
        newNode->stud = stud;
        newNode->link = *curr;
        *curr = newNode;
    } else {
        printf("\nMALLOC FAILED!\n");
    }
}

void insertLastUnique(LinkList *HEAD, studtype stud) {
    LinkList *curr;
    for(curr = HEAD; *curr!=NULL && strcmp(stud.ID, (*curr)->stud.ID) != 0; curr=&(*curr)->link);

    if (*curr == NULL) {
        LinkList newNode = malloc(sizeof(struct cell));
        if (newNode != NULL) {
            newNode->stud = stud;
            newNode->link = *curr;
            *curr = newNode;
        } else {
            printf("\nMALLOC FAILED!\n");
        }
    }
}

studtype deleteElem(LinkList* HEAD, char studID[]) {
    studtype result;
    LinkList *curr;
    for(curr = HEAD; *curr!=NULL && strcmp(studID, (*curr)->stud.ID) != 0; curr=&(*curr)->link);

    if (*curr != NULL) {
        LinkList temp = *curr;
        result = temp->stud;
        *curr = temp->link;

        free(temp);
    } else {
        result = (studtype){"XXXXXXXX", {"X", 'X', "X"}, "X", 0};
    }

    return result;
}

LinkList separateCourse(LinkList* HEAD, char course[]) {
    LinkList newList = NULL;

    LinkList *curr = HEAD;
    while(*curr!=NULL) {
        if (strcmp(course, (*curr)->stud.course) == 0) {
            LinkList temp = *curr;

            insertLast(&newList, (*curr)->stud);

            *curr = temp->link;
            free(temp);
        } else {
            curr = &(*curr)->link;
        }
    }

    return newList;
}
