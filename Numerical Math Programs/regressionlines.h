#ifndef REGRESSIONLINES_H
#define REGRESSIONLINES_H

// including header files
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Regressionlines{
	 private:
	 	double *x,*y;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void print();
	 	bool main();
};

bool Regressionlines::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Regressionlines::print(){
	double tx=0,ty=0,txy=0,txx=0,tyy=0,r,bxy,byx;
	
	for (int i=0 ; i<length ; i++) {
		tx  += *(x+i);
		ty  += *(y+i);
		txy += *(x+i) * *(y+i);
		txx += *(x+i) * *(x+i);
		tyy += *(y+i) * *(y+i);
	}
	bxy = ( txy - tx * ty / length ) / ( tyy - ty * ty / length );
	byx = ( txy - tx * ty / length ) / ( txx - tx * tx / length );
	r   = sqrt( bxy * byx );
	
	cout.setf(ios::floatfield,ios::fixed);
	cout << endl << setprecision(8);
	cout << endl << "Total of x  : " << setw(12) << tx  << endl
	             << "Total of y  : " << setw(12) << ty  << endl
	             << "Total of xy : " << setw(12) << txy << endl
	             << "Total of xx : " << setw(12) << txx << endl
	             << "Total of yy : " << setw(12) << tyy << endl << endl
	             << "Regression coeffient of x on y (bxy) : " << setw(12) << bxy << endl
	             << "Regression coeffient of y on x (byx) : " << setw(12) << byx << endl << endl
	             << "Regression line of x on y :   x = " << setw(12) << bxy << "y + " << (tx / length - ty * bxy / length) <<endl
	             << "Regression line of y on x :   y = " << setw(12) << byx << "x + " << (ty / length - tx * byx / length) <<endl
	     << endl << "Correlation coefficient (r) = " << r << endl;
}

bool Regressionlines::main(){
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
