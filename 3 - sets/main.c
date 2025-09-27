#include "./implementations/array/header.h"

int main() {
    mode();
    
    
    SET A;
    init(&A);
    SET B;
    init(&B);
    
    insert(&A, 10);
    insert(&A, 20);
    insert(&A, 30);
    insert(&A, 40);
    insert(&A, 101);
    
    insert(&B, 40);
    insert(&B, 20);
    insert(&B, 10);
    insert(&B, 100);
    insert(&B, 30);
    
    printf("\nA = ");
    read(A);
    printf("B = ");
    read(B);
    
    printf("\nA %s B\n", (equal(A, B)) ? "==" : "!=");
    
    
    SET* C = Union(A, B);
    printf("A U B = ");
    read(*C);
    
    SET* D = Intersection(A, B);
    printf("A ∩ B = ");
    read(*D);
    
    SET* E = Difference(A, B);
    printf("A - B = ");
    read(*E);
    
    
    return 0;
}
