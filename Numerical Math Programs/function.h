/* 
 * Change the functions as it is required. 
 * Be careful before change it and follow the syntax else it can produce wrong result.
 */


#ifndef FUNCTION_H
#define FUNCTION_H

// include math header for complex operation
// for operation with e you need to define it.
#include <cmath>

// Factorial function.
inline int fact(int x){
	return (x<1)? 1 : x * fact(x-1);
}

// Creating mod function used in while loop testing.
// It will simply find the difference between numbers and output it in positive value number.
inline double mod(double in, double out) {
	double temp = in - out;
	return (temp < 0)? -temp : temp;
}

// Change the function as you want. it is function used in many headers.
// This function is highly required in bisection and these type of headers.
inline double f(double x){
	return (x*x*x-x-11);
}

// It is differentiated function of above function.
// It is required for newtonraphson method.
inline double f1(double x){
	return (3*x*x-1);
}

// Function of x and y.
// Used in methods like euler, RKmethod and other.
inline double fxy(double x, double y){
	return (x+y);
}

#endif
