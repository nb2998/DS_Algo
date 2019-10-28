
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void reverseUtil(Node* curr, Node* prev, Node** head);

void reverse(Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseUtil(Node* curr, Node* prev, Node** head)
{

    if (!curr->next) {
        *head = curr;


        curr->next = prev;
        return;
    }


    Node* next = curr->next;


    curr->next = prev;

    reverseUtil(next, curr, head);
}

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    cout << "Given linked list\n";
    printlist(head1);
    reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}

