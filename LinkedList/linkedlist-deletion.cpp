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

//insertion at the begining of the linked list
void insert(int new_data) 
{ 
   Node* new_node = new Node();
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
} 

//deletion at the beginning
void delete_first()
{
    Node* temp=new Node();
    temp=head;
    head=head->next;
    delete temp;
}


//deletion at a given position  
void delete_position(int pos)
{
    Node* current=new Node();
    Node* previous=new Node();
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
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
   
   delete_first();
   delete_position(3);
   
   cout<<"The linked list is: ";
   display(); 
   return 0; 
} 


