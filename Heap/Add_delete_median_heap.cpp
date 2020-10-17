#include<bits/stdc++.h>
using namespace std;


void DeleteMedian(priority_queue<int> &MaxHeap,priority_queue<int, vector<int>, greater<int> > &MinHeap)
{
    int MaxSize = MaxHeap.size();
    int MinSize = MinHeap.size();
    
    if(MaxSize==0)
    {
        cout<<"No element present to get deleted";
    }
    
    if((MaxSize+MinSize)%2==0)
    {  
        MaxHeap.pop();
        int i=MinHeap.top();
        MaxHeap.push(i);
        MinHeap.pop();
    }
    
    else
        MaxHeap.pop();
        
}

void AddElement(priority_queue<int> &MaxHeap,priority_queue<int, vector<int>, greater<int> > &MinHeap,int n)
{
    //First check total number of element added till now are even or odd
    //Max Heap contains k+1 element if total Elements are Odd else both contain k-k elements
    
    int MaxSize = MaxHeap.size();
    int MinSize = MinHeap.size();
    
    if((MaxSize+MinSize)%2==0)
    {   //Now Comes two cases either the new element is smaller than present Median or greater;
        if(n<=MaxHeap.top())
            MaxHeap.push(n); //Simply push the element in Max MaxHeap
        
        else
        {  //First push the element in Heap
            MinHeap.push(n);
            int i = MinHeap.top();
            MinHeap.pop();
            MaxHeap.push(i);
        }
    }
    
    else
    {
        if(n<=MaxHeap.top())
        {
            int i = MaxHeap.top();
            MinHeap.push(i);
            MaxHeap.pop();
            MaxHeap.push(n);
        }
        else
            MinHeap.push(n);
    }
    
}


int main()
{   int operation,n;
priority_queue<int> MaxHeap;
priority_queue<int, vector<int>, greater<int> > MinHeap;
    cout<<endl<<"0-for exiting the Program \n 1-for adding Element \n 2-for deleting Median \n ";
    cin>>operation;
    
    MaxHeap.push(10);
    MinHeap.push(12);
    while(operation)
    {  if(operation==1 || operation==2)
       {
        if(operation==1)
        {
            cout<<"Enter Element you want to add = ";
            cin>>n;
            AddElement(MaxHeap,MinHeap,n);
        }
        
        if(operation==2)
            DeleteMedian(MaxHeap,MinHeap);
        if(MaxHeap.size()!=0)
            cout<<"Median after operation is="<<MaxHeap.top()<<endl;
            
        cout<<endl<<"Enter operation u want to perform = ";
        cin>>operation;
       }
       else
        {
            cout<<"WRONG OPERATION";
            break;
        }
    }
    
    return 0;
}
