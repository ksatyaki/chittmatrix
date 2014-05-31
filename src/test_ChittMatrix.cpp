#include "Matrix.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using chittmatrix::Matrix;

#define DEBUG(x) printf(x)

int main()
{
		Matrix a(8,8);
		a.Get();

		try
		{
			(~a).Display();
		}
		catch(chittmatrix::SingularMatrixException& e)
		{
			printf("The exception is %s\n", e.what());
		}

		std::cout<<"Determinant: "<<delta(a)<<std::endl;

		std::cout<<"sucks?"<<std::endl;

		while(1) { }
		sleep(1);

}
