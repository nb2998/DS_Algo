#include<bits/stdc++.h>
using namespace std;
template<typename T>
class stk
{
	public:
	stk* head;
	stk* next;
	T val;
	stk()
	{
		head = NULL;
		next = NULL;
	}
	T top()
	{
		return head->val;
	}
	bool empty()
	{
		return head == NULL;
	}
	void push(T x)
	{
		stk* node = new stk();
		node->val = x;
		node->next = head;
		head = node;
	}
	void pop()
	{
		head = head->next;
	}
};
//Driver code
int main()
{
	stk<int> st;
	st.push(0);
	st.push(1);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
}
