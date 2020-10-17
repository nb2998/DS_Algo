/*
This program implements fractional knapsack problem using greedy strategy
*/
#include<bits/stdc++.h>
using namespace std;
struct item //represents structure of an item available 
{
    int wt;  //weight of an item
    int p;   //profit associated with the item
};
/*compare function for sorting array of items in descending order of profit/weight ratio*/
bool compare_item(item o1,item o2)  
{
    float val1=o1.p/o1.wt;
    float val2=o2.p/o2.wt;
   return val1>val2;
}
/*function to calculate maximum profit that can be obtained
by keeping the objects according to the capacity of the knapsack*/
float fractional_knapsack(item o[10],int n,float W)
{
    int i=0;  float profit=0.0;
    sort(o,o+n,compare_item);  //library function for sorting array
    float curr_wt=0.0;
    while(curr_wt!=W)
    {
        if(curr_wt+(float) o[i].wt<=W)
        {
            curr_wt=curr_wt+(float) o[i].wt;
            profit=profit+(float) o[i].p;
            cout<<"Object "<<i+1<<": fraction = 1"<<endl;
        }
        else
            {
                float remain=W-curr_wt;
                float fraction= remain/(float) o[i].wt;
                curr_wt=curr_wt+fraction*o[i].wt;
                  profit=profit+fraction*o[i].p;
                  cout<<"Object "<<i+1<<": fraction = "<<fraction<<endl;
            }
            i++;
    }
return profit;
}
int main()
{
    int n; float W;
     item o[10]; //array of objects of structure item
    cout<<"Enter the capacity of the sack : ";
    cin>>W;  //maximum weight that can be placed in sack
    cout<<"\nEnter the number of objects(max. 10) : ";
    cin>>n;  //total number of objects available
    cout<<"\nEnter the weights of objects :\n";
    for(int i=0;i<n;i++)
    {
        cin>>o[i].wt; //getting weight of each object
    }
    cout<<"\nEnter the corresponding profit values of objects :\n";
    for(int i=0;i<n;i++)
    {
        cin>>o[i].p; //getting profit of each object
    }
float total= fractional_knapsack(o,n,W);
cout<<"\nTotal profit earned : "<<total;
    return 0;
}
