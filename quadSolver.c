#include "quadSolver.h"
#include <math.h>
/*
stores calculations in x1 and x2, 
returns the number of real solutions to the quadratic
*/
int quadSolver(double a, double b, double c, double * x1, double * x2){
	if(isDeterminantZero(a,b,c)){
		*x1 = (b * (-1))/(2 * a);
		*x2 = 0.0/0.0;
		return 1;
	}else if(isDeterminantNegative(a,b,c)){
		*x1 = 0.0/0.0;
		*x2 = 0.0/0.0;
		return 0;
	}else{
		double determinant = sqrt((b * b)-4*a*c);
    	double higher = (b * -1) + determinant;
    	higher = higher / (2 * a);
    	double lower = (b * -1) - determinant;
    	lower = lower / (2 * a);
    	*x1 = higher;
    	*x2 = lower;
    	return 2;
	}
}

//returns 1 if the determinant is within 0.0000001 of zero, else returns 0
int isDeterminantZero(double a, double b, double c){
	double determinant = (b * b) - (4 * a * c);
	return approxZero(determinant);
}

//returns 1 if the determinant is negative, else 0
int isDeterminantNegative(double a, double b, double c){
	double determinant = (b * b) - (4 * a * c);
	return (determinant < 0) ? 1 : 0;
}
//returns 1 if z is within 0.0000001 of zero, els returns 0
int approxZero(double z){
	return (z < 0.0000001 && z > -0.0000001)? 1 : 0;
}
