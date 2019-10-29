#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

#ifndef accuracy
#define accuracy 0.00001
#endif

using namespace std;

class Newtonraphson{
	 private:
	 	double a,fa,f1a;
	 public:
	 	bool input_approx(double);
	 	void print();
	 	bool main();
};

bool Newtonraphson::input_approx(double x){
	a=x; fa=f(x); f1a=f1(x);
	if ( fa == 0 ) {
		cout << "Root is " << x << endl;
		return 1;
	}
	return 0;
}

void Newtonraphson::print(){
	double root=0,value,prev_root;
	int i = 1;
	cout << "Iteration   Approx_Root   Value_of__f(x)" << endl;
	do {
		prev_root = root;
		root = (a - fa/f1a);
		value = f(root);
		if ( value == 0 ) {
			cout << endl << endl << "Root of given function is " << root << endl;
			return;
		}
		
		a=root; fa=value; f1a=f1(root);
		
		cout << setw(9) << left << i;
		cout.setf(ios::floatfield,ios::fixed);
		cout << setprecision(8)  << setw(14) << right << root;
		cout << setprecision(10) << setw(17) << right << value << endl;
		i++;
	}while( mod(root,prev_root) > accuracy);
	cout << endl << endl << "Root of given function is " << setprecision(8) << root << endl;
}

bool Newtonraphson::main(){
	double temp1;
	cout << endl << "Enter approximated root : ";
	if( !(cin >> temp1)){
		cerr << "Enter valid input." << endl;
		return 1;
	}
	
	if(input_approx(temp1))
		return 0;
	print();
	return 0;
}

#endif
