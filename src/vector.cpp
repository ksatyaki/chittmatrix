#include "vector.h"	

/* Convert a 1*1 Matrix (scalar) to double */
double toDouble(Matrix a)
{
	return ((!a) * (a)).GetElement(0,0);
}

/* Find the magnitude of a vector */
double mag(Matrix a)
{
	double y,x;
	x = a.GetElement(0,0);
	y = a.GetElement(1,0);
	return sqrt( (y*y) + (x*x) );
}	
