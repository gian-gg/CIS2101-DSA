#include <stdio.h>
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

typedef struct {
    studtype studs[ARR_LENGTH];
    int count;
} ArrayList;

void init(ArrayList*);
void displayStud(studtype);
void display(ArrayList);

void insertFirst(ArrayList*, studtype);
void insertLast(ArrayList*, studtype);
void insertLastUnique(ArrayList*, studtype);
void insertAtPos(ArrayList*, studtype, int);
studtype deleteElem(ArrayList*, char[]);
ArrayList separateCourse(ArrayList*, char[]);

int main() {
    ArrayList list;
    init(&list);

    insertLast(&list, (studtype){"24100907", {"Geri Gian", 'C', "Epanto"}, "BSCS", 2});
    insertLast(&list, (studtype){"24103435", {"Emmanuel", 'C', "Cañete"}, "BSIT", 2});
    insertLast(&list, (studtype){"24103754", {"Czachary Xavier", 'C', "Villarin"}, "BSCS", 2});
    insertLast(&list, (studtype){"24103191", {"Ryan Nicolas", 'M', "Romero"}, "BSIT", 2});
    insertAtPos(&list, (studtype){"24103191", {"Martin Nicholas", 'M', "Del Rio"}, "BSIT", 2}, 10);

    ArrayList newList = separateCourse(&list, "BSIT");
    display(list);

    printf("\n\n-=-==-=-=-=-=-=-=-=-=-=-=-\n\n");

    display(newList);

    return 0;
}


void init(ArrayList *list) {
    list->count = 0;
}

void displayStud(studtype stud) {
    printf("===============================================\n");
    printf(" ID\t| %s\n", stud.ID);
    printf(" Name\t| %s %c. %s\n", stud.name.FN, stud.name.MI, stud.name.LN);
    printf(" Course\t| %s\n", stud.course);
    printf(" Year\t| %d\n", stud.yrlevel);
    printf("===============================================\n");
}

void display(ArrayList list) {
    if (list.count < 1) {
        printf("\nNO RECORDS FOUND!\n");
        return;
    }

    for(int i = 0; i < list.count; i++) {
        printf("\nStudent %d:\n", i);
        displayStud(list.studs[i]);
    }
}

void insertLast(ArrayList *list, studtype stud) {
    list->studs[list->count++] =  stud;
}

void insertFirst(ArrayList *list, studtype stud) {
    for(int i = list->count; i > 0; i--) {
        list->studs[i] = list->studs[i-1];
    }

    list->studs[0] = stud;
    list->count++;
}

void insertLastUnique(ArrayList *list, studtype stud) {
    int i;
    for(i = 0; i < list->count && strcmp(stud.ID, list->studs[i].ID) != 0; i++) {}

    if (i >= list->count) {
        list->studs[list->count++] =  stud;
    }
}

void insertAtPos(ArrayList *list, studtype stud, int pos) {
    if (list->count < pos) pos = list->count;
    list->count++;

    for (int i = list->count; i > 0 && i > pos; i--) {
          list->studs[i] = list->studs[i - 1];
    }

    list->studs[pos] = stud;
}

studtype deleteElem(ArrayList* list, char studID[]) {
    studtype result;

    int i;
    for(i = 0; i < list->count && strcmp(studID, list->studs[i].ID) != 0; i++) {}

    if (i < list->count) {
        result = list->studs[i];
        list->count--;

        for(int x = i; x < list->count; x++) {
            list->studs[x] = list->studs[x+1];
        }
    } else {
        result = (studtype){"XXXXXXXX", {"X", 'X', "X"}, "X", 0};
    }

    return result;
}

ArrayList separateCourse(ArrayList* list, char course[]) {
    ArrayList result;
    init(&result);

    int i = 0;
    while(i < list->count) {
        if (strcmp(course, list->studs[i].course) == 0) {
            insertLast(&result, list->studs[i]);

            for(int y = i; y < list->count; y++) {
                list->studs[y] = list->studs[y+1];
            }

            list->count--;
        } else {
            i++;
        }
    }

    return result;
}
