#ifndef LAGRANGE_H
#define LAGRANGE_H

// including header files
#include <iostream>
#include <iomanip>

using namespace std;

class Lagrange{
	 private:
	 	double *x,*y;
	 	int length;
	 public:
	 	bool input_data(double[],double[],int);
	 	void get();
	 	bool main();
};

bool Lagrange::input_data(double tempx[], double tempy[], int templ){
	length = templ;
	x = new double[length];
	y = new double[length];
	for (int i=0 ; i<length ; i++){
		*(x+i) = tempx[i];
		*(y+i) = tempy[i];
	}
	return 0;
}

void Lagrange::get(){
	double ans , tempu , tempd , in_x;
	
	cout << endl << "For exit insert eof." <<endl;
	while ( cout << endl << "Enter value of x : " && cin >> in_x ) {
		ans = 0;
		for ( int i=0 ; i<length ; i++ ){
			tempu = *(y+i);
			for ( int j=0 ; j<length ; j++ ){
				if (i==j)
					continue;
				tempu *= in_x - *(x+j);
			}
			tempd = 1;
			for ( int j=0 ; j<length ; j++ ){
				if (i==j)
					continue;
				tempd *= *(x+i) - *(x+j);
			}
			ans += tempu / tempd;
		}
		cout << "Value of y at x : " << ans << endl;
	}
}

bool Lagrange::main(){
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
