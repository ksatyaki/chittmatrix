/*
 * Matrix.h
 *
 *  Created on: Jan 21, 2014
 *      Author: chittaranjan
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>


namespace chittmatrix
{

class Matrix
{
	/**
	 * R = Number of rows and C = Number of columns,
	 */
	int r, c;

	/**
	 * Holds the actual matrix in row-major format.
	 */
	double *matrix;



 public:

		/** \brief Constructor
		 * By default initializes the null matrix. r = 0; c = 0 and matrix = NULL.
		 */
	 	Matrix();

	 	/** Initialize a matrix with an array of double numbers. This must be a row
	 	 * major representation of the matrix itself.
	 	 */
	 	Matrix(double *, int, int);

	 	/**
	 	 * Initialize a zero matrix with the specified dimensions.
	 	 */
	 	Matrix(int, int);

	 	/**
	 	 * The copy constructor.
	 	 */
	 	Matrix(const Matrix &);

	 	/**
	 	 * Changes the existing values of all elements of the matrix to zeroes.
	 	 * Note the british spelling here.
	 	 */
	 	void Zeroes(int, int);

	 	/**
	 	 * Destructor to clean the data structure.
	 	 */
	 	~Matrix();

	 	/**
	 	 * Display the contents of the matrix.
	 	 */
	 	void Display(void);

	 	/**
	 	 * Use standard input to get matrix elements.
	 	 */
	 	void Get(void);

	 	/**
	 	 * This function returns the element at a particular location in the matrix
	 	 * Usage: GetElement(3,4) returns A[4][5].
	 	 */
	 	double GetElement(int, int);

	 	/**
	 	 * Use this function to set the value of a particular element in the martix
	 	 * Usage: SetElement(3.00,4,5) sets A[5][6] to the value 3.00.
	 	 */
	 	bool SetElement(double, int, int);

	 	/**
	 	 * Overloaded assignment operator.
	 	 */
	 	Matrix& operator = (const Matrix&);

	 	/**
	 	 * Exchange the rows of a matrix.
	 	 * This xchanges the rows m and n of the matrix.
	 	 */
	 	void XchangeRows(int m, int n);

	 	/**
	 	 * Exchange the columns of a matrix.
	 	 * This xchanges the columns m and n of the matrix.
	 	 */
	 	void XchangeColumns(int m, int n);

	 	/**
	 	 * Returns the row below the m-th row that has the best pivot.
	 	 */
	 	int FindMaxRowPivotBelow(int m);

		/**
		 * Overloaded addition operator to add two matrices.
		 */
		friend Matrix operator + (const Matrix&, const Matrix&);

		/**
		 * Overloaded subtraction operator to subtract a matrix from another.
		 */
		friend Matrix operator - (const Matrix&, const Matrix&);

		/**
		 * Overloaded multiplication operator to multiply two matrices.
		 */
		friend Matrix operator * (const Matrix&, const Matrix&);

		/**
		 * Returns a null matrix
		 */
		friend Matrix null_matrix(void);

		/**
		 * Check if a matrix is null. This is a bad implementation.
		 */
		friend bool is_null(const Matrix&);

		/**
		 * Overloaded multiplication operator to multiply a matrix with a scalar.
		 */
		friend Matrix operator * (const Matrix&, double);

		/**
		 * Overloaded division operator to divide a matrix by a scalar.
		 */
		friend Matrix operator / (const Matrix&, double);

		/**
		 * Overloaded multiplication operator to multiply a matrix with a scalar.
		 */
		friend Matrix operator * (double, const Matrix&);

		/**
		 * Overloaded ! operator to get the transpose of a matrix.
		 */
		friend Matrix operator !(const Matrix&);

		/** \brief Expand a matrix after retaining contents
		 * Copies the input matrix and returns an expanded matrix. Original
		 * matrix remains unaltered. Usage: Matrix A = xpand(B,4,5); - This
		 * expands matrix B from its original dimensions to a 4 x 5 matrix.
		 * The matrix B is unaltered. The expanded matrix is stored in A.
		 */
		friend Matrix xpand(const Matrix&, int, int);

		/**
		 * Determinant of a 2 x 2 matrix.
		 */
		friend double det2(const Matrix&);

		/**
		 * Inverse of a 2 x 2 matrix.
		 */
		friend Matrix inv2(const Matrix&);

		/**
		 * Cofactor matrix of a particular element in a matrix.
		 */
		friend Matrix cofactormatrix(const Matrix&, int, int);

		/**
		 * Cofactor of a particular element in a matrix.
		 */
		friend double cofactor(const Matrix&, int, int);

		/**
		 * Determinant of small matrices.
		 */
		friend double det(const Matrix&);

		/**
		 * Adjoint of small matrices.
		 */
		friend Matrix adjoint(const Matrix&);

		/**
		 * Inverse of small and large matrices.
		 */
		friend Matrix operator ~(const Matrix&);

		/**
		 * Returns an Identity matrix of dimension specified by the parameter.
		 */
		friend Matrix identity(int);

		/**
		 * Inverse of small matrices.
		 */
		friend Matrix inv(const Matrix&);

		/**
		 * Determinant of large and small matrices.
		 */
		friend double delta(const Matrix&);

		/** \brief Extract a 'sub-matrix' from a bigger matrix
		 * Extracts a part of one matrix and returns it.
		 * Usage: xtract(a,2,2,3,3) will extract a 3x3 matrix
		 * starting from element 2,2 in matrix a.
		 */
		friend Matrix xtract(const Matrix&, int, int, int, int);

};

// Global declaration of all the friends
// This is necessary.

Matrix null_matrix(void);
bool is_null(const Matrix&);

Matrix operator + (const Matrix&, const Matrix&);
Matrix operator - (const Matrix&, const Matrix&);
Matrix operator * (const Matrix&, const Matrix&);

Matrix operator * (const Matrix&, double);
Matrix operator / (const Matrix&, double);
Matrix operator * (double, const Matrix&);
Matrix operator !(const Matrix&);
Matrix xpand(const Matrix&, int, int);
double det2(const Matrix&);
Matrix inv2(const Matrix&);
Matrix cofactormatrix(const Matrix&, int, int);
double cofactor(const Matrix&, int, int);
double det(const Matrix&);
Matrix adjoint(const Matrix&);
Matrix operator ~(const Matrix&);
Matrix identity(int);
Matrix inv(const Matrix&);
double delta(const Matrix&);
Matrix xtract(const Matrix&, int, int, int, int);

/**
 * Exception class for singular matrices and zero determinants.
 */
class SingularMatrixException : public std::exception
{
public:
	virtual const char* what() const throw() { return "Matrix is singular!"; };
};

} /* namespace chittmatrix ends here */

#endif /* MATRIX_H_ */
