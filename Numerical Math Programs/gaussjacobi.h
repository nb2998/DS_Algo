#ifndef GAUSSJACOBI_H
#define GAUSSJACOBI_H

// including header files
#include "function.h"
#include <iostream>
#include <iomanip>

#ifndef accuracy
#define accuracy 0.00001
#endif

using namespace std;

class Gaussjacobi{
	 private:
	 	double data[3][4];
	 public:
	 	bool input_data(double[][4]);
	 	void print();
	 	bool main();
};

bool Gaussjacobi::input_data(double temp[][4]){
	bool flag[3]={0,0,0};
	for (int i=0 ; i<3 ; i++){
		int max = (temp[i][0] > temp[i][1])? (temp[i][0] > temp[i][2])? 0 : 2 : (temp[i][1] > temp[i][2])? 1 : 2 ;
		for (int j=0 ; j<4 ; j++)
			data[max][j] = temp[i][j];
		flag[max] = 1;
	}
	if ( (flag[0]+flag[1]+flag[2]) != 3 ) {
		cerr<<"Given system is not diagonally dominant."<<endl;
		return 1;
	}
	return 0;
}

void Gaussjacobi::print(){
	double ans[3]={0,0,0} ,prev_ans[3];
	int i = 1;
	
	cout << endl << "Iteration   Approx_Root_x   Approx_Root_y   Approx_Root_z" << endl
	             << "0              0.00000000      0.00000000      0.00000000" << endl;
	
	do {
		for (int i=0 ; i<3 ; i++)
			prev_ans[i]=ans[i];
		
		ans[0] = (data[0][3] - (data[0][1]*prev_ans[1]) - (data[0][2]*prev_ans[2]) ) / data[0][0];
		ans[1] = (data[1][3] - (data[1][0]*prev_ans[0]) - (data[1][2]*prev_ans[2]) ) / data[1][1];
		ans[2] = (data[2][3] - (data[2][1]*prev_ans[1]) - (data[2][0]*prev_ans[0]) ) / data[2][2];
		
		cout << setw(9) << left << i;
		cout.setf(ios::floatfield,ios::fixed);
		cout << setprecision(8)  << setw(16) << right << ans[0] << setw(16) << ans[1] << setw(16) << ans[2] << endl;
		i++;
	}while( mod(ans[0],prev_ans[0]) > accuracy || mod(ans[0],prev_ans[0]) > accuracy || mod(ans[0],prev_ans[0]) > accuracy );
	
	cout << endl << endl << "Roots of given equations are : " << endl << setprecision(8) << "x = " << ans[0] << "   y = " << ans[1] << "   z = " << ans[2] << endl;
}

bool Gaussjacobi::main(){
	double t[3][4];
	cout << endl << "Input format : " << endl << "If equation is ax + by + cz = d " << endl << "Then input will be a >b >c >d." <<endl;
	for(int i=0;i<3;i++){
		cout << endl << "Enter coefficients of equation" << i+1 << " : ";
		if( !(cin >> t[i][0] >> t[i][1] >> t[i][2] >> t[i][3] ) ){
			cerr << "Enter valid input." << endl;
			return 1;
		}
	}
	
	if( input_data(t) )
		return 0;
	print();
	return 0;
}

#endif
