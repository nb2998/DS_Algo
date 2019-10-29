#ifndef SIMPSON1BY3_H
#define SIMPSON1BY3_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Simpson1by3{
	 private:
	 	double *x,*y,h;
	 	int n;
	 public:
	 	bool input_data(double,double,int);
	 	void result();
	 	bool main();
};

bool Simpson1by3::input_data(double tempa, double tempb, int tempn){
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

void Simpson1by3::result(){
	double ans , odd=0 , even=0;
	for ( int i=1 ; i<n ; i++ ) {
		if (i%2)
			odd += *(y+i);
		else
			even += *(y+i);
	}
	ans = (*(y) + *(y+n) + 2 * even + 4 * odd ) * h / 3; 
	cout << endl << "I = " << ans << endl;
}

bool Simpson1by3::main(){
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
