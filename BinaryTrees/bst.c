#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{int info;
struct bst *right,*left;
}bst;
void insert(bst **,int);
void pre_order(bst *);
void in_order(bst *);
void post_order(bst *);
int main()
{
	struct bst *root =NULL;
	int ch,item;
	while(1)
	{
		printf("\n1.Insert \n2.Pre_order \n3.In_order \n4.Post_order \n0.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n enter the item ");
				scanf("%d",&item);
				insert(&root,item);
				break;
			case 2:pre_order(root);
				break;
			case 3:in_order(root);
				break;
			case 4:post_order(root);
				break;
			case 0:exit(0);
			default:printf("\n invalid");
		}
	}
}
void insert(bst **proot,int item)
{
	bst *loc,*par,*newnode;
	loc=*proot;
	par=NULL;
	while(loc!=NULL)
	{
		if(item==loc->info)
		{
			printf("\n duplicate");
			return;
		}
		par=loc;
		if(item<(loc->info))
			loc=loc->left;
		else
			loc=loc->right;
	}
	newnode=(bst *)malloc(sizeof(bst));
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(par==NULL)
		*proot=newnode;
	else if(item<(par->info))
		par->left=newnode;
	else
		par->right=newnode;
}
void pre_order(bst *root)
{
	if(root!=NULL)
	{
		printf("%d->",root->info);
		pre_order(root->left);
		pre_order(root->right);
	}
}
void in_order(bst *root)
{
	if(root!=NULL)
	{
		in_order(root->left);
		printf("%d->",root->info);
		in_order(root->right);
	}
}
void post_order(bst *root)
{
	if(root!=NULL)
	{
		post_order(root->left);
		post_order(root->right);
		printf("%d->",root->info);
	}
}
