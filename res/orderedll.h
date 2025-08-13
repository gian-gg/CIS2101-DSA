#define MAX 100

typedef struct node{
	char data[MAX];
	struct node *link;
}*LIST;

void init(LIST *L);
void insert(LIST *L, char *str);
void insertSorted(LIST *L, char *str);
void show(LIST L);
void del(LIST *L, char *str);
void edit(LIST *L, char *oldstr, char *newstr);



