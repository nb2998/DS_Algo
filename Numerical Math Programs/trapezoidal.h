#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Trapezoidal{
	 private:
	 	double *x,*y,h;
	 	int n;
	 public:
	 	bool input_data(double,double,int);
	 	void result();
	 	bool main();
};

bool Trapezoidal::input_data(double tempa, double tempb, int tempn){
	n = tempn;
	x = new double[n+1];
	y = new double[n+1];
	h = ( tempb - tempa ) / tempn;
	for (int i=0 ; i<=n ; i++){
		*(x+i) = tempa + i * h;
		*(y+i) = f( *(x+i) );
	}
	return 0;
}

void Trapezoidal::result(){
	double ans , temp=0;
	for ( int i=1 ; i<n ; i++ ) {
		temp += *(y+i);
	}
	ans = (*(y) + *(y+n) + 2 * temp ) * h / 2; 
	cout << endl << "I = " << ans << endl;
}

bool Trapezoidal::main(){
	double temp1,temp2;
	unsigned int tempn;
	cout << endl << "Enter limits : ";
	if( !(cin >> temp1 >> temp2)){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	cout << endl << "Enter iterations (n) : ";
	if( !(cin >> tempn) || tempn < 2){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	if( input_data(temp1,temp2,tempn) )
		return 0;
	result();
	return 0;
}

#endif
