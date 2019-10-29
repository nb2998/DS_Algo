#ifndef NEWTONFORWARD_H
#define NEWTONFORWARD_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>
#ifndef error
#define error 0.000000001
#endif

using namespace std;

class Newtonforward{
	 private:
	 	double *x,*y,h;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void get();
	 	bool main();
	 	inline double countp(double,int);
};

bool Newtonforward::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Newtonforward::get(){
	double diff_table[length][length] , in_x , ans , p;
	
	for ( int i=0 ; i<length ; i++ )
		diff_table[i][0] = *(y+i);
		
	for ( int j=1 ; j<length ; j++ ) 
		for ( int i=0 ; i<length-j ; i++ )
			diff_table[i][j] = diff_table[i+1][j-1] - diff_table[i][j-1];
	
	cout << endl << "For exit insert eof." <<endl;
	while ( cout << endl << "Enter value of x : " && cin >> in_x ) {
		ans = *y;
		p = (in_x - *x) / h;
		for ( int i=1 ; i<length ; i++ )
			ans += countp( p , i-1 ) * diff_table[0][i] / double(fact(i));
		cout << "Value of y at x : " << ans << endl;
	}
}

inline double Newtonforward::countp(double p,int n) {
	return (n<1)? p : double( (p-n) * countp (p,n-1) );
}

bool Newtonforward::main(){
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
		if( mod(tempx[i]-tempx[i-1],h) < error ) {
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
