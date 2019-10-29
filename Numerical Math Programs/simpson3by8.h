#ifndef SIMPSON3BY8_H
#define SIMPSON3BY8_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Simpson3by8{
	 private:
	 	double *x,*y,h;
	 	int n;
	 public:
	 	bool input_data(double,double,int);
	 	void result();
	 	bool main();
};

bool Simpson3by8::input_data(double tempa, double tempb, int tempn){
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

void Simpson3by8::result(){
	double ans , remain=0 , mul3=0;
	for ( int i=1 ; i<n ; i++ ) {
		if ( i%3 == 0 )
			mul3 += *(y+i);
		else
			remain += *(y+i);
	}
	ans = (*(y) + *(y+n) + 2 * mul3 + 3 * remain ) * h * 3 / 8; 
	cout << endl << "I = " << ans << endl;
}

bool Simpson3by8::main(){
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
