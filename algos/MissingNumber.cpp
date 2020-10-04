/*
Given an array C of size N-1 and given that there are numbers 
from 1 to N with one element missing, the missing number is to be found.
*/

#include<iostream>
using namespace std;

int main() {
    int testCase;
    int *Arr;
    cin>>testCase;
    while(testCase-- > 0){
        int size = 0, sum = 0;
        cin>>size;
        Arr = new int[size];
        for(int i=1; i<size; i++) {
            cin>>Arr[i-1];
            sum += Arr[i-1]-i;
        }
        cout<<size-sum<<endl;
    }
    return 0;
}