#include <iostream>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* next;
};

int cmpfunc(const void* a, const void* b)
{
	const char* ia = (const char*)a;
	const char* ib = (const char*)b;
	return strcmp(ia, ib);
}

struct node* getNode(int i)
{
	struct node* nn =
		(struct node*)malloc(sizeof(struct node));
	nn->data = i;
	nn->next = NULL;
	return nn;
}

void addAtLast(struct node** head, struct node* nn)
{
	if (*head == NULL) {
		*head = nn;
		return;
	}
	struct node* temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = nn;
}

void* computeLShift(struct node** head, int index,
					int* l_shift)
{
	l_shift[index] = (*head)->data;
	(*head) = (*head)->next;
}

void invert(char bwt_arr[])
{
	int i,len_bwt = strlen(bwt_arr);
	char* sorted_bwt = (char*)malloc(len_bwt * sizeof(char));
	strcpy(sorted_bwt, bwt_arr);
	int* l_shift = (int*)malloc(len_bwt * sizeof(int));

	int x = 4;

	qsort(sorted_bwt, len_bwt, sizeof(char), cmpfunc);

	struct node* arr[128] = { NULL };

	for (i = 0; i < len_bwt; i++) {
		struct node* nn = getNode(i);
		addAtLast(&arr[bwt_arr[i]], nn);
	}

	for (i = 0; i < len_bwt; i++)
		computeLShift(&arr[sorted_bwt[i]], i, l_shift);

	for (i = 0; i < len_bwt; i++) {
		x = l_shift[x];
		std::cout << bwt_arr[x];
	}
}

int main()
{
	char bwt_arr[1001];
	std::cin >> bwt_arr;
	invert(bwt_arr);
	return 0;
}
