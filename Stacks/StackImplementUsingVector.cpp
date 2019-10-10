#include<iostream>
#include<vector>
using namespace std;

class Stack1{
        vector<int> v;
public:
    void push(int data){
        v.push_back(data);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v[v.size()-1];
    }
    bool isEmpty(){
        return v.size()==0;
    }
};

int main(){

    Stack1 s;
    int n;
    int data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data;
        s.push(data);
    }

    while(!s.isEmpty()){
        cout<<s.top()<<" " ;
        s.pop();
}
return 0;
}
