#ifndef BISECTION_H
#define BISECTION_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

#ifndef accuracy
#define accuracy 0.00001
#endif

using namespace std;

class Bisection{
	 private:
	 	double a,b;
	 public:
	 	bool input_range(double,double);
	 	void print();
	 	bool main();
};

bool Bisection::input_range(double x, double y){
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
			a=x; b=y;
		}
		else {
			a=y; b=x;
		}
		return 0;
	}
}

void Bisection::print(){
	double average=0,prev_average,value;
	int i = 1;
	cout << "Iteration   Approx_Root   Value_of__f(x)" << endl;
	do {
		prev_average = average;
		average = (a+b)/2;
		value = f(average);
		if ( value < 0 ) 
			a = average;
		else if ( value > 0 )
			b = average;
		else{
			cout << endl << endl << "Root of given function is " << average << endl;
			return;
		}
		cout << setw(9) << left << i;
		cout.setf(ios::floatfield,ios::fixed);
		cout << setprecision(8)  << setw(14) << right << average;
		cout << setprecision(10) << setw(17) << right << value << endl;
		i++;
	}while( mod(average,prev_average) > accuracy);
	cout << endl << endl << "Root of given function is " << setprecision(8) << average << endl;
}

bool Bisection::main(){
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
