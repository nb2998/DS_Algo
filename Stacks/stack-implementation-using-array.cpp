#include <iostream>
using namespace std;
int top = -1; //Globally defining the value of top as the stack is empty

    void push (int stack[ ] , int x , int n)
    {
        if ( top == n-1 )       //If the top position is the last of position of the stack, this means that the stack is full.
        {
            cout << "Stack is full.Overflow condition!" ;
        }
        else
        {
            top = top +1 ;            //Incrementing the top position 
            stack[ top ] = x ;       //Inserting an element on incremented position  
        }
    }
    bool isEmpty ( )
    {
        if ( top == -1 )  //Stack is empty
            return true ; 
        else
            return false;
    }
    void pop ( ) 
    {

        if( isEmpty ( ) )
        {
            cout << "Stack is empty. Underflow condition! " << endl ;
        }
        else    
        {
             top = top - 1 ; //Decrementing top’s position will detach last element from stack            
        }
    }
    int size ( )
    {
        return top + 1;
    }
    int topElement (int stack[])
    {
        return stack[ top ];
    }
    //Let's implement these functions on the stack given above 

    int main( )
    {
        int stack[ 3 ];
        // pushing element 5 in the stack .
        push(stack , 5 , 3 ) ;

        cout << "Current size of stack is " << size ( ) << endl ;

        push(stack , 10 , 3);
        push (stack , 24 , 3) ;

        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is full, further pushing will show an overflow condition.
        push(stack , 12 , 3) ;

        //Accessing the top element
        cout << "The current top element in stack is " << topElement(stack) << endl;

        //Removing all the elements from the stack
        for(int i = 0 ; i < 3;i++ )
            pop( );
        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is empty , further popping will show an underflow condition.
        pop ( );  

    }
