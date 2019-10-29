#ifndef CORRELATION_H
#define CORRELATION_H

// including header files
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Correlation{
	 private:
	 	double *x,*y;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void print();
	 	bool main();
};

bool Correlation::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Correlation::print(){
	double tx=0,ty=0,txy=0,txx=0,tyy=0,r;
	
	for (int i=0 ; i<length ; i++) {
		tx  += *(x+i);
		ty  += *(y+i);
		txy += *(x+i) * *(y+i);
		txx += *(x+i) * *(x+i);
		tyy += *(y+i) * *(y+i);
	}
	r = ( txy - tx*ty / length ) / ( sqrt(txx-tx*tx/length) * sqrt(tyy-ty*ty/length) );
	cout.setf(ios::floatfield,ios::fixed);
	cout << endl << setprecision(8);
	cout << endl << "Total of x  : " << setw(12) << tx  << endl
	             << "Total of y  : " << setw(12) << ty  << endl
	             << "Total of xy : " << setw(12) << txy << endl
	             << "Total of xx : " << setw(12) << txx << endl
	             << "Total of yy : " << setw(12) << tyy << endl
	     << endl << "Correlation coefficient (r) = " << r << endl;
}

bool Correlation::main(){
	unsigned int templ;
	cout << endl << "Enter length of data : ";
	if( !(cin >> templ) || templ<2){
		cerr << "Enter valid length" << endl;
		return 1;
	}
	double tempx[templ],tempy[templ];
	cout << endl << "Enter values of x : ";
	for (int i=0; i<templ ; i++){
		if( !(cin >> tempx[i]) ){
			cerr << "Enter valid data." << endl;
			return 1;
		}
	}
	
	cout << endl << "Enter values of y corresponding to x : ";
	for (int i=0; i<templ ; i++){
		if( !(cin >> tempy[i]) ){
			cerr << "Enter valid data." << endl;
			return 1;
		}
	}
	
	if( input_data(tempx,tempy,templ) )
		return 0;
	print();
	return 0;
}

#endif
