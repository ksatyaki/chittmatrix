#include "/home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/src/Matrix.h"
#include <math.h>

using namespace chittmatrix;

/** \brief 2-D Vector
 * Vector in 2-D. A subclass of Matrix
 */
class Vector2d: public Matrix
{
 public:
	Vector2d()
	: Matrix(2,1)
	{
	}
	/**
	 * Find the magnitude of a vector.
	 */
	friend double mag(Matrix);
	
	/**
	 * Convert a 1*1 Matrix (scalar) to double.
	 */
	friend double toDouble(Matrix);
};

/** \brief 2-D Vector
 * Vector in 2-D. A subclass of Matrix
 */
class Vector3d: public Matrix
{
 public:
	Vector3d()
	: Matrix(3,1)
	{
	}
	friend double mag(Matrix);
};	

double toDouble(Matrix a);

double mag(Matrix a);
