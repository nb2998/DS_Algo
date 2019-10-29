#ifndef MODIFIEDEULER_H
#define MODIFIEDEULER_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>
#ifndef error
#define error 0.000000001
#endif

using namespace std;

class Modifiedeuler{
	 private:
	 	double *x,*y,h,in_x;
	 	int n;
	 public:
	 	bool input_data(double,double,double);
	 	void result();
	 	bool main();
};

bool Modifiedeuler::input_data(double tempx0, double tempy0, double tempin){
	x = new double[n+1];
	y = new double[n+1];
	*x = tempx0;
	*y = tempy0;
	in_x = tempin;
	for ( int i=0 ; i<=n ; i++)
		*(x+i) = *x+i*h;
	return 0;
}

void Modifiedeuler::result(){
	double tempvalue;
	cout.setf( ios::floatfield , ios::fixed );
	cout << endl << setprecision(8) << "values_of_x     value_of_y/f(x)" << endl
	             << setw(11) << *x << setw(20) << *y  << endl;
	for ( int i=1 ; i<=n ; i++ ){
		tempvalue = *(y+i-1) + h * fxy( *(x+i-1) , *(y+i-1) );
		*(y+i)    = *(y+i-1) + h * ( fxy(*(x+i-1),*(y+i-1)) + fxy(*(x+i),tempvalue) ) / 2;
		cout << setw(11) << *(x+i) << setw(20) << *(y+i) << endl;
	}
}

bool Modifiedeuler::main(){
	double tempx0,tempy0,tempin;
	bool choice;
	cout << endl << "Enter x0 and y0 : ";
	if( !(cin >> tempx0 >> tempy0)){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	cout << endl << "Enter value of x : ";
	if( !(cin >> tempin) ){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	cout << endl << "Chose steps h(0) or n(1) ? : ";
	if ( !(cin >> choice) ){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	if ( choice ) {
		cout << endl << "Enter value of n (step number) : ";
		if( !(cin >> n) ){
			cerr << "Enter valid input." << endl;
			return 1;
		}
		h = ( tempin - tempx0 ) / n;
	}
	else {
		cout << endl << "Enter value of h (step size) : ";
		if( !(cin >> h) ){
			cerr << "Enter valid input." << endl;
			return 1;
		}
		n = round(( tempin - tempx0 ) / h);
	}
	
	if ( mod( (tempx0+n*h) , tempin ) > error ){
		cerr << "y(x) can\'t be found using given data.";
		return 1;
	}
	
	if( input_data(tempx0,tempy0,tempin) )
		return 0;
	result();
	return 0;
}

#endif
