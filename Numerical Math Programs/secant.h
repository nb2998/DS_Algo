#ifndef SECANT_H
#define SECANT_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

#ifndef accuracy
#define accuracy 0.00001
#endif

using namespace std;

class Secant{
	 private:
	 	double a,b,fa,fb;
	 public:
	 	bool input_range(double,double);
	 	void print();
	 	bool main();
};

bool Secant::input_range(double x, double y){
	double fx=f(x) , fy=f(y);
	if ( fx == 0 ) {
		cout << "Root is " << x << endl;
		return 1;
	}
	else if( fy == 0 ){
		cout << "Root is " << y << endl;
		return 1;
	}
	else if( ( fx < 0 && fy < 0 ) || ( fx > 0 && fy > 0 ) ){
		cerr << "There is no root in given range." << endl;
		return 1;
	}
	else{
		if( fx < 0 ){
			a=x; b=y; fa=fx; fb=fy;
		}
		else {
			a=y; b=x; fa=fy; fb=fx;
		}
		return 0;
	}
}

void Secant::print(){
	double position=0,prev_position,value;
	int i = 1;
	cout << "Iteration   Approx_Root   Value_of__f(x)" << endl;
	do {
		prev_position = position;
		position = ((a*fb)-(b*fa))/(fb-fa);
		value = f(position);
		if ( value == 0 ) {
			cout << endl << endl << "Root of given function is " << position << endl;
			return;
		}
		
		a=b; fa=fb;
		b=position; fb=value;
		
		cout << setw(9) << left << i;
		cout.setf(ios::floatfield,ios::fixed);
		cout << setprecision(8)  << setw(14) << right << position;
		cout << setprecision(10) << setw(17) << right << value << endl;
		i++;
	}while( mod(position,prev_position) > accuracy);
	cout << endl << endl << "Root of given function is " << setprecision(8) << position << endl;
}

bool Secant::main(){
	double temp1,temp2;
	cout << endl << "Enter range in which root lies : ";
	if( !(cin >> temp1 >> temp2)){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	if(input_range(temp1,temp2))
		return 0;
	print();
	return 0;
}

#endif
