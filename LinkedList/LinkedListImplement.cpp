#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int data){
    // node *temp = head;
    node *n = new node(data);
    n->next = head;
    head = n;   
    }

void insertInMiddle(node*&head, int data, int p){
    if(p==0){
        insertAtHead(head,data);
        return;
    }
    node*temp = head;
    // int jump = 1;
    for(int jump=1; jump<=p-1; jump++){
        temp = temp->next;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

void insertAtTail(node*&head, int data){
    node*temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    node*n = new node(data);
    temp ->next = n;
    n->next = NULL;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node*&head){
    node*temp = head;
    node*prev = head;
    while(temp->next!= NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next= NULL;
    delete temp;
}

void deleteInMiddle(node*&head, int p){
    node*temp = head;
    node*prev = head;
    for(int jump = 1; jump<=p-1; jump++){
        prev = temp;
        temp = temp->next;
    }
    prev ->next = temp->next;
    delete temp;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}
int main() {
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertInMiddle(head, 8, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteInMiddle(head,3);
    print(head);

    return 0;
   
}
