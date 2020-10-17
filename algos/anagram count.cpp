#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int equals(char* A, char* B)
{
    int i,len = strlen(A);
    int a[26],b[26];
    for(i=0;i<26;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    for(i=0;i<len;i++)
    {
        a[A[i]-'a']++;
    }
    for(i=0;i<len;i++)
    {
        b[B[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}
int check(char* s1, char* s2)
{
    int i,j,len1=strlen(s1), len2=strlen(s2), flag=0;

    char arr[len2];

    for(i=0;i<=len1-len2;i++)
    {
        for(j=0;j<len2;j++)
        {
            arr[j]=s1[i+j];
        }
        if(equals(arr,s2))
            flag++;
    }
    return flag;
}
int main()
{
    char text[50]="",pat[50]="";
    cout<<"Enter original string: ";
    cin>>text;
    cout<<"Enter pattern string: ";
    cin>>pat;
    cout<<"No. of anagrams in text are :"<<check(text,pat);
    return 0;
}

