#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
    
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
  Node* gethead()
  {
      return head;
  }
};

void print_using_recurssion(Node *head);

void print_using_recurssion(Node *head)
{
    if(head == NULL)
    {
        return ;
    }
    print_using_recurssion(head->next);
    
     cout<<head->data<<" ";
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
    
    print_using_recurssion(A.gethead());
    
    return 0;
}
