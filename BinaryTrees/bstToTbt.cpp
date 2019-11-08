#include<iostream>
#include<vector>
#define DUMMY 9999
using namespace std;

struct node{
    int data;
    node *leftptr;
    node *rightptr;
    bool leftThread,rightThread;
}*root,*dummy;

class BST{

    //node *root;
    int value;
    node *temp,*t;
    vector <node*> inorderSeq;

    public:
    BST(){
        root=NULL;
        dummy=new node;
		dummy->data=DUMMY;
		dummy->leftptr=dummy;
		dummy->rightptr=dummy;
		dummy->leftThread=true;
		dummy->rightThread=true;
    }

    void create();
    void insert();
    void searchToInsert(node *t);//function helping to create and not search
    void inorder(node *);

    void createInorder(node*);
    node* inorderSucc(node*);
    node* inorderPrec(node*);
    void convert(node*);
    void convertToTbt();
    void inorderTbt();
    node* getInorderSucc(node*);

};


void BST::create(){

    cout<<"Enter the data to be inserted: ";
    cin>>value;
    temp=new node;
    temp->data=value;
    temp->leftptr=temp->rightptr=NULL;
    temp->leftThread=temp->rightThread=false;

}

void BST::insert(){
    create();
    if(root==NULL)
        root=temp;
    else
        searchToInsert(root);

}

//function tells where the node will be inserted
void BST::searchToInsert(node *t){

         if(temp->data > t->data && t->rightptr!=NULL)
            searchToInsert(t->rightptr);
        else if(temp->data > t->data && t->rightptr==NULL)
            t->rightptr=temp;
        else if(temp->data < t->data && t->leftptr!=NULL)
            searchToInsert(t->leftptr);
        else if(temp->data < t->data && t->leftptr==NULL)
            t->leftptr=temp;

}

void BST::inorder(node *t){

    if(t){
        inorder(t->leftptr);
        cout<<t->data<<" ";
        inorder(t->rightptr);
    }

}

void BST::createInorder(node* t){
    if(t){
        createInorder(t->leftptr);
        inorderSeq.push_back(t);
        createInorder(t->rightptr);
    }

}

node* BST::inorderSucc(node * s){

    int tempd=s->data;

    int i,j;

    for(i=0;i<inorderSeq.size();i++){
        if(tempd==inorderSeq[i]->data)
            break;
    }
    j=i+1;

    if(j==inorderSeq.size())
        return NULL;
    else
        return inorderSeq[j];
}

node* BST::inorderPrec(node * r){
    int tempd=r->data;

    int i,j;

    for(i=0;i<inorderSeq.size();i++){
        if(tempd==inorderSeq[i]->data)
            break;
    }
    j=i-1;

    if(j==-1)
        return NULL;
    else
        return inorderSeq[j];
}

void BST::convertToTbt(){
    createInorder(root);
    convert(root);
}

void BST::convert(node *t){

    node *succ,*precc;

    if(t!=NULL){
        if(t->leftptr==NULL && t->rightptr==NULL){

            succ=inorderSucc(t);
            precc=inorderPrec(t);

            if(succ!=NULL){
                t->rightptr=succ;
                t->rightThread=true;
            }
            else{
                t->rightptr=dummy;
                t->rightThread=true;
            }

            if(precc!=NULL){
                t->leftptr=precc;
                t->leftThread=true;
            }
            else{
                t->leftptr=dummy;
                t->leftThread=true;
            }


        }
        else if(t->leftptr==NULL){
                precc=inorderPrec(t);

                if(precc!=NULL){
                    t->leftptr=precc;
                    t->leftThread=true;

                }
                else{
                    t->leftptr=dummy;
                    t->leftThread=true;
                }
                convert(t->rightptr);


        }
        else if(t->rightptr==NULL){

                succ=inorderSucc(t);

                if(succ!=NULL){
                    t->rightptr=succ;
                    t->rightThread=true;
                }
                else{
                    t->rightptr=dummy;
                    t->rightThread=true;
                }
                convert(t->leftptr);
        }
        else{
            convert(t->leftptr);
            convert(t->rightptr);
        }
    }
    //return;

}
node* BST::getInorderSucc(node *temps){

    if(temps->rightThread)
        return temps->rightptr;

    temps=temps->rightptr;
    while(temps->leftThread==false)
        temps=temps->leftptr;

    return temps;
}

void BST:: inorderTbt(){

    node *temp=root;

    if(temp==NULL)
        return;
    while(temp->leftThread==false){
        temp=temp->leftptr;
    }

    while(temp!=dummy){
        cout<<temp->data<<"\t";
        temp=getInorderSucc(temp);
    }

}



int main(){

	BST b;
	int n,a;
    char c;
    do{
        cout<<"\n\n1.Create a BST "<<endl;
        cout<<"2.Insert node "<<endl;
        cout<<"3.Display BST "<<endl;
        cout<<"4.Convert To TBT "<<endl;
        cout<<"5.Display using TBT traversal "<<endl;
        cout<<"q.Quit"<<endl;
        cin>>c;
        switch(c){
            case '1':cout<<"Enter the no of nodes you want to add ";
                   cin>>n;
                   for(int i=0;i<n;i++)
                        b.insert();
                    break;
            case '2':cout<<"Enter the no of nodes you want to add ";
                   cin>>n;
                   for(int i=0;i<n;i++)
                        b.insert();
                    break;
            case '3':b.inorder(root);
                   break;
            case '4':
                    b.convertToTbt();
                    break;
            case '5':
                    b.inorderTbt();
                    break;

            case 'q':
                    break;


        }
    }
    while(c!='q');

}



