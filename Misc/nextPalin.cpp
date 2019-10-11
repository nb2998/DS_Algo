// Inspired from the algorithm mentioned here https://stackoverflow.com/questions/7934519/a-better-algorithm-to-find-the-next-palindrome-of-a-number-string
// Most frequently asked question in Coding Rounds of companies like Microsoft, Samsung, etc.
// Task is, given a number, task is to find the next smallest palindrome number.
/*
Find the decimal representation of the input number ("2133").
Split it into the left half and right half ("21", "33");
Compare the last digit in the left half and the first digit in the right half.
a. If the right is greater than the left, increment the left and stop. ("22")
b. If the right is less than the left, stop.
c. If the right is equal to the left, repeat step 3 with the second-last digit in the left and the second digit in the right (and so on).
Take the left half and append the left half reversed. That's your next largest palindrome. ("2222")
Applied to a more complicated number:

1.    1234567887654322
2.    12345678   87654322
3.    12345678   87654322
             ^   ^         equal
3.    12345678   87654322
            ^     ^        equal
3.    12345678   87654322
           ^       ^       equal
3.    12345678   87654322
          ^         ^      equal
3.    12345678   87654322
         ^           ^     equal
3.    12345678   87654322
        ^             ^    equal
3.    12345678   87654322
       ^               ^   equal
3.    12345678   87654322
      ^                 ^  greater than, so increment the left

3.    12345679

4.    1234567997654321  answer
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
string add(string &s)
{
	string ans;
	ll sum = 0;
	ll carry = 1;
	for(ll i=s.size()-1;i>=0;--i)
	{
		ll num = s[i]-'0';
		num+=carry;
		carry = num/10;
		num = num%10;
		ans+=char(num+'0');
		
	}
	if(carry) ans+=(carry+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}
string nextPal(string &s)
{
	ll n = s.size();
	if(n==1)
	{
		if(s[0] < '9') return add(s);
		return "11";
	}
	if(n%2==0)
	{
		string left = s.substr(0,n/2);
		string right = s.substr(n/2);
		ll l = left.size()-1;
		ll r = 0;
		bool ok = false;
		while(l>=0 && r<right.size())
		{
			if(left[l] > right[r]) 
			{
				ok = true;
				break;
			}
			else if(left[l] < right[r]) break;
			--l;
			++r;
		}
		if(ok)
		{
			string ans;
			ans += left;
			reverse(left.begin(),left.end());
			ans += left;
			return ans;
		}
		left = add(left);
		string ans;
		ans+=left;
		if(left.size()==(n/2))
		{
			reverse(left.begin(),left.end());
			ans+=left;
			return ans;
		}
		ll i = left.size()-2;
		while(i>=0)
		{
			ans+=left[i];
			--i;
		}
		return ans;
	}
	string left = s.substr(0,n/2 + 1);
	string right = s.substr(n/2 + 1);
	ll l = left.size()-2;
	ll r = 0;
	bool ok = false;
	while(l>=0 && r<right.size())
	{
		if(left[l] > right[r]) 
		{
			ok = true;
			break;
		}
		else if(left[l] < right[r]) break;
		--l;
		++r;
	}
	if(ok)
	{
		string ans;
		ans += left;
		reverse(left.begin(),left.end());
		for(ll i=1;i<left.size();++i) ans+=left[i];
		return ans;
	}
	ll prevs = left.size();
	left = add(left);
	string ans;
	ans+=left;
	if(left.size()==prevs)
	{	
		reverse(left.begin(),left.end());
		for(ll i=1;i<left.size();++i) ans+=left[i];
		return ans;
	}
	ll i = left.size()-3;
	while(i>=0)
	{
		ans+=left[i];
		--i;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string ans = nextPal(s);
		cout<<ans<<endl;
	}
}
