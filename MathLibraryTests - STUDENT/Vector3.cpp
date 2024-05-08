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




	const float& Vector3::operator [](int dim) const
	{
		return data[dim];
	}

	// cast to float array
	Vector3::operator float* () 
	{
		return data;
	}

	Vector3::operator const float* ()const  
	{
		return data;
	}


/*=====================================^^^overloads^^^================================================*/
}