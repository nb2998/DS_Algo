#ifndef RKMETHOD2_H
#define RKMETHOD2_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>
#ifndef error
#define error 0.000000001
#endif

using namespace std;

class Rkmethod2{
	 private:
	 	double *x,*y,h,in_x;
	 	int n;
	 public:
	 	bool input_data(double,double,double);
	 	void result();
	 	bool main();
};

bool Rkmethod2::input_data(double tempx0, double tempy0, double tempin){
	x = new double[n+1];
	y = new double[n+1];
	*x = tempx0;
	*y = tempy0;
	in_x = tempin;
	for ( int i=0 ; i<=n ; i++)
		*(x+i) = *x+i*h;
	return 0;
}

void Rkmethod2::result(){
	double k,k1,k2;
	cout.setf( ios::floatfield , ios::fixed );
	cout << endl << setprecision(8) << "values_of_x     value_of_y/f(x)" << endl
	             << setw(11) << *x << setw(20) << *y  << endl;
	for ( int i=1 ; i<=n ; i++ ){
		k1 = fxy( *(x+i-1)   , *(y+i-1)      );
		k2 = fxy( *(x+i-1)+h , *(y+i-1)+h*k1 );
		k  = (k1 + k2) / 2;
		*(y+i) = *(y+i-1) + h * k;
		cout << setw(11) << *(x+i) << setw(20) << *(y+i) << endl;
	}
}

bool Rkmethod2::main(){
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
