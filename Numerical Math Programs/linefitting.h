#ifndef LINEFITTING_H
#define LINEFITTING_H

// including header files
#include <iostream>
#include <iomanip>

using namespace std;

class Linefitting{
	 private:
	 	double *x,*y;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void print();
	 	bool main();
};

bool Linefitting::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Linefitting::print(){
	double tx=0,ty=0,txy=0,txx=0,a,b;
	
	for (int i=0 ; i<length ; i++) {
		tx  += *(x+i);
		ty  += *(y+i);
		txy += *(x+i) * *(y+i);
		txx += *(x+i) * *(x+i);
	}
	b = ( length * txy - tx * ty ) / ( length * txx - tx * tx );
	a = ty / length - b * tx / length;
	
	cout.setf(ios::floatfield,ios::fixed);
	cout << setprecision(6);
	cout << endl << "Total of x  : " << setw(12) << tx  << endl
	             << "Total of y  : " << setw(12) << ty  << endl
	             << "Total of xy : " << setw(12) << txy << endl
	             << "Total of xx : " << setw(12) << txx << endl
	     << endl << "Normal equations are : " << endl
	             << setw(12) << ty  << " = " << setw(12) << length << "a + " << setw(12) << tx  << endl
	             << setw(12) << txy << " = " << setw(12) << tx     << "a + " << setw(12) << txx << endl
	     << endl << "Required straight line is : " << endl
	             << "y = " << a << " + " << b << "x" << endl;
}

bool Linefitting::main(){
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
