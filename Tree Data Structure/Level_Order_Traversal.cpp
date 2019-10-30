
#include <bits/stdc++.h> 
using namespace std; 


struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// Iterative method to find height of Binary Tree 
void printLevelOrder(Node *root) 
{ 
	// Base Case 
	if (root == NULL) return; 

	// Create an empty queue for level order tarversal 
	queue<Node *> q; 

	// Enqueue Root and initialize height 
	q.push(root); 

	while (q.empty() == false) 
	{ 
		// Print  
		Node *node = q.front(); 
		cout << node->data << " "; 
		q.pop(); 

		/* Enqueue left child */
		if (node->left != NULL) 
			q.push(node->left); 

		/*Enqueue right child */
		if (node->right != NULL) 
			q.push(node->right); 
	} 
} 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


int main() 
{ 
	Node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	cout << "Level Order traversal of binary tree is \n"; 
	printLevelOrder(root); 
	return 0; 
} 
