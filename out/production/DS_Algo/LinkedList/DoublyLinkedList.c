/* CREATING A SIMPLE DOUBLY LINKED LIST */
/* DBLINK.C */

# include <stdio.h>
# include <malloc.h>

struct Double
{
	int info;
	struct Double *next;
	struct Double *previous;
};

int num ;
struct Double start;
void Doubly_link_list (struct Double *);
void display (struct Double *);

/* Function creates a simple doubly linked list */

void Doubly_link_list(struct Double *node)
{
	char ch;
	start.next = NULL;  /* Empty list */
	start.previous = NULL;
	node = &start;      /* Point to the start of the list */
	num = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();

	while( ch != 'n')
	{
		node->next = (struct Double *) malloc(sizeof(struct Double));
		node->next->previous = node;
		node = node->next;
		printf("\n Input the values of the node : %d: ", (num+1));
		scanf("%d", &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		num ++;
	}
	printf("\n Total nodes = %d", num);
}

/* Display the list */

void display (struct Double *node)
{
	node = start.next;

	do {
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
	} while (node->next);  /* Show value of last node only one time */

	do {
		printf("\n 0x%x", node );
		printf(" %d", node->info);
		node = node->previous;
	} while (node->previous);
}

int main()
{
	struct Double *node = (struct Double *) malloc(sizeof(struct Double));
	Doubly_link_list(node);
	printf("\n Created doubly linked list is as follows\n");
	display(node);
}