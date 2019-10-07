#include <bits/stdc++.h>

using namespace std;
stack <char> s;
char x;

bool isbalanced(string exp)
{
	for(int i=0;i<exp.length();i++)
	{
        if (exp[i]=='('||exp[i]=='['||exp[i]=='{') 
        { 
          
            s.push(exp[i]); 
            continue; 
        }  
         
		switch (exp[i]){

		case '}':
		x=s.top();
		s.pop();
		if(x=='(' || x=='[')
			return false;
		break;

		case ')':
		x=s.top();
		s.pop();
		if(x=='{' || x=='[')
			return false;
		break;


		case']':
		x=s.top();
		s.pop();
		if(x=='(' || x=='{')
			return false;
		break;



      }
	}
    return(s.empty());
}


int main()
{
	string s;
	cin >> s;
	cout << endl;

	if(isbalanced(s))
		cout << "balanced"<< endl;
	else cout << "unbalanced" << endl;

	return 0;
}