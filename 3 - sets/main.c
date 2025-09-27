#include "./implementations/bit_vector/header.h"

int main() {
    mode();
    
    
    SET A;
    init(&A);
    SET B;
    init(&B);
    
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 3);
    insert(&A, 4);
    insert(&A, 11);
    
    insert(&B, 4);
    insert(&B, 2);
    insert(&B, 1);
    insert(&B, 10);
    insert(&B, 3);
    
    insert(&A, 10);
    
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
