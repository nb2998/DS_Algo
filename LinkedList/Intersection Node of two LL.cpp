#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
int getCount(Node* head); 
  
int _getIntesectionNode(int d, Node* head1, Node* head2); 
  
int getIntesectionNode(Node* head1, Node* head2) 
{ 
  
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
} 
  
int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
  	while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
} 
  
int getCount(Node* head) 
{ 
    Node* current = head; 
  
    int count = 0; 
  
    while (current != NULL) { 
  
        count++; 
  
        current = current->next; 
    } 
  
    return count; 
} 
  
int main() 
{ 
    
    Node* newNode; 
  
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    cout << "The node of intersection is " << getIntesectionNode(head1, head2); 
} 
