/*
 * Matrix.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: chittaranjan
 */

#include "Matrix.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

namespace chittmatrix {

/* \brief Constructor
		 * By default initializes the null matrix. r = 0; c = 0 and matrix = NULL */
Matrix::Matrix()
{
	r = 0;
	c = 0;
	matrix = NULL;
}

// Initialize a matrix with a double array. Row and column sizes are also provided.
Matrix::Matrix(double *a, int row, int col)
{
	r = row;
	c = col;
	matrix = (double *) malloc(sizeof(double)*(row*col));
	for(int i = 0; i<row; i++)
	for(int j = 0; j<col; j++)
		*(matrix + i*c + j) = *(a + i*col + j);
}


//Initialze a matrix with a row and column size.
Matrix::Matrix(int row, int col)
{
	int i, j;
	r = row;
	c = col;
	matrix = (double *)malloc(sizeof(double)*(r*c));
	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(matrix + i*col + j) = 0;
}

//Copy constructor
Matrix::Matrix(const Matrix& a)
{
	int i, j;
	r = a.r;
	c = a.c;
	//printf("COPYING");
	matrix = (double *) malloc(sizeof(double)*(r*c));
	for(i = 0; i<r; i++)
		for(j = 0; j<c; j++)
			*(matrix + i*c + j) = *(a.matrix + i*a.c + j);
}

/* Changes the existing values of all elements of the matrix to zeroes
	 	 * Note the british spelling here. */
void Matrix::Zeroes(int row, int col)
{
	// An already initialized Matrix can call Zeroes, so delete the existing array
	if(matrix != NULL)
		free(matrix);

	int i, j;
	r = row;
	c = col;
	matrix = (double *)malloc(sizeof(double)*(r*c));
	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(matrix + i*col + j) = 0;
}

/* Destructor to clean the data structure */
Matrix::~Matrix()
{
	if(matrix != NULL)
	{
		free(matrix);
	}

}

/* Display the contents of the matrix */
void Matrix::Display(void)
{
	int i, j;
	printf("\n");
	for(i = 0; i<c; i++)
		printf("-----");
	printf("\n");


	for(i = 0; i<r; i++)
	{
		for(j = 0; j<c; j++)
			printf("%s%.2lf\t", *(matrix + (i*c) + j) >= 0 ? "+":"-", fabs(*(matrix + (i*c) + j)) );
		printf("\n");
	}
	for(i = 0; i<c; i++)
		printf("-----");
	printf("\n");
}

/* Use standard input to get matrix elements */
void Matrix::Get(void)
{
	int i, j;
	printf("Getting Matrix input. Enter a %d by %d Matrix:\n", r, c);
	for(i = 0; i<r; i++)
		for(j = 0; j<c; j++)
			scanf("%lf", &*(matrix + i*c + j));
}

/* This function returns the element at a particular location in the matrix
	 	 * Usage: GetElement(3,4) returns A[4][5]
	 	*/
double Matrix::GetElement(int i, int j)
{
	return *(matrix + (i*c) + j);
}

/* Use this function to set the value of a particular element in the martix
	 	 * Usage: SetElement(3.00,4,5) sets A[5][6] to the value 3.00
	 	*/
bool Matrix::SetElement(double value, int i, int j)
{

	if(i > r || j > c)
	{
		printf("\nIllegal! Matrix Index out of bounds in call to SetElement(). Element was not set... \n");
		return false;
	}

	else
		*(matrix + (i*c) + j) = value;

	return true;
}

/* Overloaded assignment operator */
Matrix& Matrix::operator = (const Matrix& a)
{
	if(this->matrix != NULL);
		free(this->matrix);

	r = a.r;
	c = a.c;
	matrix = (double *)malloc(sizeof(double)*(r*c));

	int i, j;
	for(i = 0; i<r; i++)
		for(j = 0; j<c; j++)
			*(matrix + i*c + j) = *(a.matrix + i*a.c + j);
	return 	*this;
}

/*---------------------------------------BASIC OPERATIONS '+', '-', '*', '/'------------------------------------------*/
/* --------------------------------------ALL ARE FRIEND FUNCTIONS -----------------------------------------*/


/* Overloaded '+' operator to add two matrices */
Matrix operator + (const Matrix& a, const Matrix& b)
{
	Matrix temp(a.r, b.c);
	int row = temp.r;
	int col = temp.c;


	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) + (*(b.matrix + (i*b.c) + j));

	return temp;
}

/* Overloaded '-' operator to subtract two matrices */
Matrix operator - (const Matrix& a, const Matrix& b)
{
	Matrix temp(a.r, b.c);
	int row = temp.r;
	int col = temp.c;

	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) - (*(b.matrix + (i*b.c) + j));

	return temp;
}

/* Overloaded '*' operator for scalar multiplication */
Matrix operator * (const Matrix& a, double b)
{
	int row, col, i, j;
	Matrix temp(a.r, a.c);
	row = temp.r;
	col = temp.c;

	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) * b;
	return temp;
}

/* Overloaded '/' operator for scalar division */
Matrix operator / (const Matrix& a, double b)
{
	int row, col, i, j;
	Matrix temp(a.r, a.c);
	row = temp.r;
	col = temp.c;

	for(i = 0; i<row; i++)
		for(j = 0; j<col; j++)
			*(temp.matrix + i*col + j) = (*(a.matrix + (i*a.c) + j)) / b;
	return temp;
}

/* Overloaded '*' operator for scalar multiplication ---- JUST IN CASE OPERANDS ARE PASSED REVERSE */
Matrix operator * (double b, const Matrix& a)
{
	return a * b;
}

/* Overloaded '*' operator for multiplying two matrices */
Matrix operator * (const Matrix& a, const Matrix& b)
{

	int row, col;
	if(a.c != b.r)
	{
		printf("Error. Matrices being multiplied are not compatible. Quiting...\n");
		getchar();
		exit(0);
	}
	Matrix temp(a.r, b.c);
	row = temp.r;
	col = temp.c;

	for(int i = 0; i<row; i++)
		for(int j = 0; j<col; j++)
		{
			for(int k = 0; k<a.c; k++)
			 *(temp.matrix + i*col + j) += ( (*(a.matrix + (i*a.c) + k)) * (*(b.matrix + (k*b.c) + j)) );

		}

	return temp;
}

/* Overloaded '!' operator for transpose */
Matrix operator !(const Matrix& a)
{
	int row = a.r;
	int col = a.c;

	Matrix temp(col, row);
	for(int i = 0; i<temp.r; i++)
		for(int j = 0; j<temp.c; j++)
			*(temp.matrix + i*temp.c + j) = *(a.matrix + j*col + i);

	return temp;
}

/* Determinant of a 2 by 2 matrix */
double det2(const Matrix& a)
{
	return (  ((*(a.matrix + 0)) * (*(a.matrix + 3))) - ((*(a.matrix + 1)) * (*(a.matrix + 2)))  );
}

/* Inverse of a 2 x 2 matrix */
Matrix inv2(const Matrix& a)
{
	if(a.r != a.c)
		printf("Error: In function inv2(), Matrix is not square, Aborting...\n");
	if(a.r != 2)
		printf("Error: In function inv2(), Matrix is not 2 x 2. Aborting...\n");

	int col = a.c;
	int row = a.r;

	Matrix temp(row, col);
	*(temp.matrix + 0*temp.c + 0) = (*(a.matrix + 1*col + 1))/det2(a);
	*(temp.matrix + 0*temp.c + 1) = (-1* (*(a.matrix + 0*col + 1)))/det2(a);
	*(temp.matrix + 1*temp.c + 0) = (-1* (*(a.matrix + 1*col + 0)))/det2(a);
	*(temp.matrix + 1*temp.c + 1) = (*(a.matrix + 0*col + 0))/det2(a);

	return temp;
}

/* Get the cofactor matrix of a particular matrix element */
Matrix cofactormatrix(const Matrix& a, int x, int y)
{
	if(a.r!=a.c)
	{
		printf("Error: In function cofactormatrix(), Matrix is not square. Quitting...\n");
		exit(0);
	}
	int i, j, ii = 0, jj = 0;
	int col = a.c;
	int row = a.r;
	Matrix temp(row-1, col-1);
	for(i = 0; i<row-1; i++)
	{
		if(ii == x)
			ii++;
		if(ii == row) ii = 0;
		if(ii == x)
			ii++;

		for(j = 0; j<col-1; j++)
		{
			if(jj == y)
				jj++;

			if(jj == col) jj = 0;

			if(jj == y)
				jj++;

			*(temp.matrix + (i*(col-1)) + j) = *(a.matrix + (ii*col) + jj);
			jj++;
		}
		ii++;
	}
	return temp;
}

/* Get the cofactor (scalar) of a particular matrix element */
double cofactor(const Matrix& a, int x, int y)
{
	int test = (a.r*x + y);
	int minus = 1;
	int i = 0;
	if(a.r!=a.c)
	{
		printf("Error: In function cofactor(), Matrix is not square. Hence Zero returned.\n");
		return 0;
	}
	if(a.r == 2)
	{
		switch(test)
		{
			case 0:
			 return *(a.matrix + 3);
			case 1:
			 return ((-1)*(*(a.matrix + 2)));
			case 2:
			 return ((-1)*(*(a.matrix + 1)));
			case 3:
			 return *(a.matrix + 0);
		}
	}
	Matrix temp1(a.r-1, a.c-1);			// BAD CODE
	temp1 = cofactormatrix(a, x, y);		// BAD CODE

	for(i = 0; i< (x+y); i++)	minus *= -1;

	return (det(temp1)*minus);
}

/* Determinant of a small matrix (max. dimension = 10 x 10)*/
double det(const Matrix& a)
{
	if(a.r!=a.c)
	{
		printf("Error: In function det(), Matrix is not square. Hence Zero returned.\n");
		return 0;
	}
	double delta = 0.0000;
	int j;
	if(a.r==1)
		return *(a.matrix);
	if(a.r==2)
	{
		return det2(a);
	}
	for(j = 0; j< a.c; j++)
	{
		if((*(a.matrix + 0*a.c + j)) == 0) continue;
		delta += (*(a.matrix + 0*a.c + j))*(cofactor(a, 0, j));
	}
	return delta;
}

/* Adjoint of Matrix */
Matrix adjoint(const Matrix& a)
{
	if(a.r!=a.c)
	{
		printf("Error: In function adjoint(), Matrix is not square. Aborted.\n");
		exit(0);
	}
	int col = a.c;
	int row = a.r;
	int i, j;
	Matrix temp1(row, col);

	for(i = 0; i<temp1.r; i++)
		for(j = 0; j<temp1.c; j++)
			*(temp1.matrix + i*temp1.c + j) = cofactor(a, i, j);
	return temp1;
}

/* Inverse for a small Matrix (max. dimension = 10 x 10)*/
Matrix inv(const Matrix& a)
{
	if(a.r!=a.c)
	{
		printf("Error: In function Inv(), Matrix is not square. Aborted.\n");
		exit(0);
	}
	return (!(adjoint(a)) / det(a));
}

/* Create an identity matrix */
Matrix identity(int a)
{
	Matrix mat(a,a);

	for(int i = 0; i<a; i++)
		for(int j = 0; j<a; j++)
		{
			if(i == j) *(mat.matrix + i*a + j) = 1;
			else *(mat.matrix + i*a + j) = 0;
		}
	return mat;
}

/* Inverse for Large and small matrices */
Matrix operator ~(const Matrix& a)
{
	if(a.r!=a.c)
	{
		printf("Error: In function \"operator ~\"(inverse), Matrix is not square. Quitting...\n");
		exit(0);
	}

	Matrix temp = a;

	if(fabs (delta(temp)) < 0.000001)
		return null_matrix();

	double var, test;
	Matrix b = identity(a.r);
	for(int j = 0; j< temp.c; j++)
		for(int i = 0; i< temp.r; i++)
		{
			if(i == j) continue;

			var = *(temp.matrix + i*temp.r + j);
			double elimination_element = *(temp.matrix + j*temp.r + j);


			int index = j;


			if( fabs(elimination_element) < 0.000001)
			{
				for(index = j; fabs(*(temp.matrix + index*temp.r + j)) < 0.000001 && index < temp.c; index++);

				if(index == temp.c) return null_matrix();

				elimination_element = *(temp.matrix + index*temp.r + j);
			}



			test = var/elimination_element;

			//DEBUG LINES
			//printf("\n\nTEST: %lf, VAR/TEST: %lf\n\n", test, elimination_element );
			//DEBUG LINES

			for(int jj = 0; jj< temp.r; jj++)
			{
				*(temp.matrix + i*temp.r + jj) -= (test)*(*(temp.matrix + index*temp.r + jj));
				*(b.matrix + i*b.r + jj) -= (test)*(*(b.matrix + index*b.r + jj));
			}

			//DEBUG LINES
			//printf("\npass %d,%d\n", i,j);
			//temp.Display();
			//printf("\n ***and*** \n");
			//b.Display();
			//DEBUG LINES
		}

	//DEBUG LINES
	//printf("\nTEMP\n");
	//temp.Display();
	//DEBUG LINES

	for(int i = 0; i<temp.r; i++)
	{
		for(int j = 0; j<temp.c; j++)
		{
			*(b.matrix + i*b.c + j) = *(b.matrix + i*b.c + j)/ (*(temp.matrix + i*temp.c + i));
			//*(temp.matrix + i*temp.c + j) = *(temp.matrix + i*temp.c + j)/ (*(temp.matrix + i*temp.c + i));
			//printf("\n(%d,%d)", i,j);
		}
//	b.Display();
	}

	//printf("\n******IDENTITY*****\n");
	//temp.Display();

	return b;
}


// Define a null matrix. This will be returned when computation results in non-invertible matrices
Matrix null_matrix()
{
	Matrix a;
	a.r = 0;
	a.c = 0;
	a.matrix = NULL;

	return a;
}

// Check if a matrix is null or not
bool is_null(const Matrix& a)
{
	return (a.r == 0 && a.c == 0)? true: false;
}


/* Determinants of Larger matrices */

double delta(const Matrix& a)
{
	if(a.r!=a.c)
	{
		printf("Error: In function delta(), Matrix is not square. Aborted.\n");
		exit(0);
	}

	double delta = 1.0000;
	Matrix temp = a;

	double var, test;

	Matrix b = identity(a.r);
	for(int j = 0; j< temp.c; j++)
		for(int i = 0; i< temp.r; i++)
		{
			if(i == j) continue;

			var = *(temp.matrix + i*temp.r + j);
			double elimination_element = *(temp.matrix + j*temp.r + j);

			//DEBUG LINES
			//printf("\n\nJ: %d\n\n", j);
			//printf("\n\nmatrix[J][J]: %lf\n\n", *(temp.matrix + j*temp.r + j));
			//DEBUG LINES


			int index = j;


			if( fabs(elimination_element) < 0.000001)
			{
				for(index = j; fabs(*(temp.matrix + index*temp.r + j)) < 0.000001 && index < temp.c; index++);

				if(index == temp.c) return 0.0;

				elimination_element = *(temp.matrix + index*temp.r + j);
			}



			test = var/elimination_element;

			//DEBUG LINES
			//printf("\n\nTEST: %lf, VAR/TEST: %lf, INDEX: %d\n\n", test, elimination_element, index);
			//DEBUG LINES

			for(int jj = 0; jj< temp.r; jj++)
			{
				*(temp.matrix + i*temp.r + jj) -= (test)*(*(temp.matrix + index*temp.r + jj));
				*(b.matrix + i*b.r + jj) -= (test)*(*(b.matrix + index*b.r + jj));
			}

			//DEBUG LINES
			//printf("\npass %d,%d\n", i,j);
			//temp.Display();
			//DEBUG LINES
		}
	//DEBUG LINES
	//temp.Display();
	//DEBUG LINES

	for(int i = 0; i< temp.r; i++)
		delta*=(*(temp.matrix + i*temp.r + i));


	//printf("\nDET: %lf\n",delta);
	return delta;
}

/* \brief Expand a matrix after retaining contents

		 * Copies the input matrix and returns an expanded matrix. Original
		 * matrix remains unaltered. Usage: Matrix A = xpand(B,4,5); - This
		 * expands matrix B from its original dimensions to a 4 x 5 matrix.
		 * The matrix B is unaltered. The expanded matrix is stored in A.
		 */
Matrix xpand(const Matrix& a, int newr, int newc)
{
	if(newr <= a.r || newc <= a.c)
	{
		printf("Error: In function xpand(), new size is less than or equal to original. Aborting...\n");
		exit(0);
	}

	Matrix temp(newr, newc);

	for(int i = 0; i<a.r; i++)
		for(int j = 0; j<a.c; j++)
			*(temp.matrix + newc*i + j) = *(a.matrix + a.c*i + j);
	return temp;
}

/* \brief Extract a 'sub-matrix' from a bigger matrix
		 * Extracts a part of one matrix and returns it.
		 * Usage: xtract(a,2,2,3,3) will extract a 3x3 matrix
		 * starting from element 2,2 in matrix a.
		 */
Matrix xtract(const Matrix& a, int row_offset, int col_offset, int row_size, int col_size)
{
	row_offset--; col_offset--;
	if( (a.r < row_offset + row_size) || (a.c < col_offset + col_size) )
	{
		printf("Error: In function xtract(), unable to extract matrix. Dimensions out of bounds. Aborting...\n");
		exit(0);
	}

	Matrix temp(row_size, col_size);

	for(int i = 0; i<row_size; i++)
		for(int j = 0; j<col_size; j++)
			*(temp.matrix + (i*temp.c) + j) = *(a.matrix + ((row_offset + i)*a.c)  + j + col_offset);

	return temp;
}
} /* namespace chittmatrix */
