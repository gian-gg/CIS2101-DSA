#include "header.h"

 int main() {
     MINHEAP m;
     init(&m);

     insert(&m, 5);
     insert(&m, 10);
     insert(&m, 30);
     insert(&m, 6);
     insert(&m, 3);
     insert(&m, 4);
     insert(&m, 2);

     display(m);

     heapSort(&m);
     display(m);

     return 0;
 }
