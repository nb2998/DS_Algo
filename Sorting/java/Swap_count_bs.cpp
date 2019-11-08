#include<iostream>
using namespace std;

int bubble_sort_swap(int array[],int size){

    int swap =0;
    for(int i = size-2;i>=0;i--){
        for(int j=0;j<=i;j++){

            if(array[j] >array[j+1]){
                
                swap++;
                // cout<<"Swap:"<<swap<<endl;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    return swap;
}



int main(){
    int tc;
    scanf("%d",&tc);

    int size;

    int answer;

    for(int test=0;test< (tc);test++){
        scanf("%d",&size);
        int array[size];
        for(int i=0;i<size;i++){
            scanf("%d",&array[i]);
        }

        // for(int i=0;i<size;i++){
        //     printf("%d",array[i]);
        // }

        answer = bubble_sort_swap(array,size);
        printf("%d \n",answer);
    
    }

    


    return 0;
}
