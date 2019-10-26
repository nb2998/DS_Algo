#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
           string str1,str2,str3,str4,str5,str6;
           cin>>str1>>str2>>str3>>str4>>str5>>str6;
           string str=str1+" "+str2+" "+str3+" "+str4+" "+str5+" "+str6;
           v.push_back(str);
        }
        sort(v.begin(),v.end());
        /*for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;*/
        map<string,int>m;
        for(int i=0;i<v.size();i++)
        m[v[i]]++;
        map<string,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    }
        return 0;
}
