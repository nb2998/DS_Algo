#include <iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node*buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node*root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

node *buildTreePreIn(int *in, int*pre, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }

    node *root = new node(pre[i]);
    int index = -1;
    for(int j=0;j<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }
    i++;

    root->left = buildTreePreIn(in,pre,s, index-1);
    root->right = buildTreePreIn(in,pre,index+1, e);
    return root;
}

node *buildTreePostIn(int *in, int *post, int s, int e){
    static int i=e;
    if(s>e){
        return NULL;
    }
    node *root = new node(post[i]);
    int index = -1;
    for(int j=0;j<=e;j++){
        if(in[j]==post[i]){
            index = j;
            break;
        }
    }
    i--;
    root->right = buildTreePostIn(in, post, index+1, e);
    root->left = buildTreePostIn(in, post, s, index-1);

    return root;
}
void bfs(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
    return;
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
    return;
}
int main() {
    // node*root = buildTree();
    // print(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printPost(root);
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int post[] ={3,8,4,2,7,6,5,1};
    // int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    // int post[] = {8, 4, 5, 2, 6, 7, 3, 1}; 
    int n = sizeof(in)/sizeof(int);    
    node*root1 = buildTreePreIn(in,pre,0,n-1);
    node*root2 = buildTreePostIn(in,post,0,n-1);
    bfs(root1);
    cout<<endl;
    bfs(root2);
    return 0;
}
