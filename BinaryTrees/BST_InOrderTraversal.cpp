#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node*left = NULL;
    struct Node*right = NULL;
};

void inOrder(Node*root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node*addNode(Node*root, long int val)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(val < root->data)
    {
        root->left = addNode(root->left, val);
    }
    else
    {
        root->right = addNode(root->right, val);
    }
    return root;
}

Node* createTree()
{
long int n, tmpData;
Node*root = NULL;
cout<<"Enter the number of nodes"<<endl;
cin>>n;
while(n!=0)
{
cin>>tmpData;
root = addNode(root, tmpData);
n-=1;
}
return root;
}

int main()
{
Node*root = createTree();

inOrder(root);
}
