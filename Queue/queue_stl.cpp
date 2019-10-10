#include<iostream>
#include<queue>
using namespace std;
int main(){

	queue<int> q;
    int n,data;
    cin>>n;
	for(int i=0;i<n;i++){
        cin>>data;
		q.push(data);
	}

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}	