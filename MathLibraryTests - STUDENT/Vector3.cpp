#include "MathHeaders/Vector3.h"


namespace MathClasses {



/*==============================^^todo^^====================================================*/
	Vector3::Vector3() {

		 x = 0;

		 y = 0;

		 z = 0;

	};


	Vector3::~Vector3() {};


/*===================================^^^Structors^^^========================================================*/





/*=======================================^^Methods^^===========================================================*/



	//subscript Operator that allows us to sort through data
	const float& Vector3::operator [](int dim) const
	{
		return data[dim];
	}

	// cast to float array
	Vector3::operator float* () 
	{
		return data;
	}

	// cast to float array - const-qualified
	Vector3:: operator const float* ()const
	{
		return data;
	}
	
	//addition opperator+
	Vector3 Vector3::operator+ (const Vector3& rhs) const {
	
		Vector3 sum;

		// x is the LEFT vector's x-component
		// rhs.x is the RIGHT vector's x-component
		sum.x = x + rhs.x;
		sum.y = y + rhs.y;
		sum.z = z + rhs.z;

		return sum;

	}

	//subtraction operator -
	Vector3 Vector3::operator- (const Vector3& rhs) const {

		Vector3 sum;

		// x is the LEFT vector's x-component
		// rhs.x is the RIGHT vector's x-component
		sum.x = x - rhs.x;
		sum.y = y - rhs.y;
		sum.z = z - rhs.z;

		return sum;

	}

	//multiply operator* 
	Vector3 Vector3::operator * (const float scaler) const {
	
		Vector3 sum;

		// x is the LEFT vector's x-component
		
		sum.x = x * scaler;
		sum.y = y * scaler;
		sum.z = z * scaler;

		return sum;
	}

	//I dont know how to impliment operator * (Vector, float) / operator * (float, Vector)

	Vector3 Vector3::operator * (const float scaler) const {

		Vector3 sum;

		// x is the LEFT vector's x-component

		sum.x = scaler * x  ;
		sum.y = scaler * y  ;
		sum.z = scaler * z  ;

		return sum;
	}

	Vector3 Vector3::operator / () const {}

/*=====================================^^^overloads^^^================================================*/
}