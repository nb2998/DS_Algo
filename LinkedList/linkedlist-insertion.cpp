// A C++ program to show all type of insertion on Linked List 
#include <bits/stdc++.h> 
using namespace std; 


// defining a linked list node 
struct Node { 
   int data; 
   Node* next; 
}; 


//initializing the head node with NULL
Node* head = NULL; 

//inserting at the begining of the linked list
void insert(int new_data) 
{ 
   Node* new_node = new Node();
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
} 


//inserting at a given position
void insert_atposition(int pos, int value)
{
    Node* pre=new Node();
    Node* cur=new Node();
    Node* temp=new Node();
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;	
    temp->next=cur;
}
// insert at tail 
void insertAtTail(int data){
    Node*temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    Node*n = new Node();
    temp ->next = n;
    n->data = data;
    n->next = NULL;
}

//printing all the values of the linked list
void display() 
{ 
   
   Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } 
}


//main code
int main() 
{ 
   insert(69);
   insert(36);
   insert(13);
   insert(47);
   insert(54);
   insert_atposition(2, 100);
   // trying insertAtTail method which is recently added
   insertAtTail(200);
   insertAtTail(300);
   
   cout<<"The linked list is: ";
   display(); 
   return 0; 
} 


