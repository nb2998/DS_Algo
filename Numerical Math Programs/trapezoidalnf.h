#ifndef TRAPEZOIDALNF_H
#define TRAPEZOIDALNF_H

// including header files
#include <iostream>
#include <iomanip>
#ifndef error
#define error 0.000000001
#endif

using namespace std;

class Trapezoidalnf{
	 private:
	 	double *x,*y,h;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void get();
	 	bool main();
};

bool Trapezoidalnf::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Trapezoidalnf::get(){
	double ans , temp=0;
	for ( int i=1 ; i<length-1 ; i++ ) {
		temp += *(y+i);
	}
	ans = (*(y) + *(y+length-1) + 2 * temp ) * h / 2; 
	cout << endl << "I = " << ans << endl;
}

bool Trapezoidalnf::main(){
	unsigned int templ;
	cout << endl << "Enter length of data : ";
	if( !(cin >> templ) || templ < 2){
		cerr << "Enter valid length" << endl;
		return 1;
	}
	double tempx[templ] , tempy[templ];
	
	cout << endl << "Enter values of x : ";
	for (int i=0; i<templ ; i++){
		if( !(cin >> tempx[i]) ){
			cerr << "Enter valid data." << endl;
			return 1;
		}
	}
	
	h = tempx[1]-tempx[0];
	for(int i=templ-1 ; i>0 ; i--) {
		if( mod(tempx[i]-tempx[i-1],h) > error) {
			cerr << endl << "Sorry given data is not sequential." << endl;
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
	get();
	return 0;
}

#endif
