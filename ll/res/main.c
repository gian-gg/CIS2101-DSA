#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orderedll.h"

//open project file when using devc

void main(){
	LIST head;
	init(&head);
	
	insertSorted(&head, "Joenell");
	insertSorted(&head, "Migo");
	insertSorted(&head, "Louie");
	insertSorted(&head, "Margot");
	insertSorted(&head, "Cindy");
	insertSorted(&head, "Chris Michael");
	insertSorted(&head, "Chris Evans");
	insertSorted(&head, "asdf");
	show(head);
	printf("\n");
	del(&head, "asdf");
	show(head);
	printf("\n");
	edit(&head, "Marga", "Margot");
	show(head);
}
