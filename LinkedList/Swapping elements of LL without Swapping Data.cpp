#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class linked_list
{
    private:
    Node *head, *tail;
    public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = NULL;
        
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    Node *gethead()
    {
        return head;
    }
};
void print_list(Node *head);
void print_list(Node *head)
{
    Node *ptr = head;
    while(ptr->next != NULL)
    {
        cout<<ptr->data<<" ";
        ptr= ptr->next;
    }
    cout<<ptr->data;
}
Node* swap(Node *head, int x, int y);
Node* swap(Node *head, int x, int y)
{
    if(x==y)
        return head;
        
    Node *current1 = head;
    Node *prev1 = NULL;
    Node *current2 = head;
    Node *prev2 = NULL;
    while(current1->data != x)
    {
        prev1 = current1;
        current1 = current1->next;
    }
    while(current2->data != y)
    {
        prev2 = current2;
        current2 = current2->next;
    }
    if(current1 == NULL || current2 == NULL)
        return head;
    
    if(prev1!=NULL)
        {prev1->next = current2;}
    else
        {head = current2;}
        
    if(prev2!=NULL)
        {prev2->next = current1;}
    else
        {head = current1;}
        
    Node *temp = current2->next;
    current2->next = current1->next;
    current1->next = temp;
    return head;
}
int main()
{
	int n,i,x;
	cin>>n;
	linked_list A;

	for(i=0;i<n;i++)
	{
	    cin>>x;
	    A.add_node(x);
	}
	
	int a,b;
	cin>>a>>b;
	
	Node *h1;
	h1 = swap(A.gethead(),a,b);
	print_list(h1);
	return 0;
}
