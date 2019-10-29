// Set the accuracy as you want.
#define accuracy 0.00001

// Inlcude header files which is required.
#include "bisection.h"

/*
#include "falseposition.h"
#include "secant.h"
#include "newtonraphson.h"
#include "gaussjacobi.h"
#include "gaussseidel.h"
#include "linefitting.h"
#include "newtonforward.h"
#include "newtonbackward.h"
#include "newtondivided.h"
#include "lagrange.h"
#include "trapezoidal.h"
#include "simpson1by3.h"
#include "simpson3by8.h"
#include "trapezoidalnf.h"
#include "simpson1by3nf.h"
#include "simpson3by8nf.h"
#include "euler.h"
#include "modifiedeuler.h"
#include "rkmethod2.h"
#include "rkmethod4.h"
#include "correlation.h"
#include "regressionlines.h"
*/

using namespace std;

int main(){
	Bisection object;  // Change object data type according to header file. make sure first character is capital.
	return object.main();  // Calling main function of object which will do all necessary operations.
}
