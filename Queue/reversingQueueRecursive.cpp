/*
The below code is used to reverse a Queue using recursion and using Recursion Stack
*/
#include <bits/stdc++.h>
using namespace std;

void reverse(queue <int> &q){
    if(q.empty())
        return;
    int x=q.front();
    q.pop();
    reverse(q);
    q.push(x);

}

int main(){

    queue <int> q;
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverse(q);
    while(!q.empty())
        {
            cout<<q.front()<<endl;
            q.pop();
        }


    return 0;
}
