#include "MathHeaders/Vector3.h"


namespace MathClasses {


	//fix F*V operator overload (got something to do with friend function)
/*==============================^^todo^^====================================================*/
	Vector3::Vector3() {

		 x = 0.f;

		 y = 0.f;

		 z = 0.f;

	};

	Vector3::Vector3(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}


	Vector3::~Vector3() {};


/*===================================^^^Structors^^^========================================================*/

	std::string Vector3::ToString() const{
	
		return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	
	}

	float Vector3::Magnitude()const{
		
		return sqrtf(x * x + y * y + z * z);

	}

	float Vector3::MagnitudeSqr() const{

		return x * x + y * y + z * z;

	}

	float Vector3::Distance(const Vector3& other) const{
	
		return (*this - other).Magnitude();
	
	}

	void Vector3::Normalise(){
	
		float m = Magnitude();

		x /= m;
		y /= m;
		z /= m;
	
	}

	Vector3 Vector3::Normalised() const{
	
		Vector3 copy = *this;
		copy.Normalise();

		return copy;
	
	}

	float Vector3::Dot(const Vector3& other)
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3 Vector3::Cross(const Vector3& other)
	{
		return Vector3(y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}

	float Vector3::AngleBetween(const Vector3& other) const {
		// normalise the vectors
		Vector3 a = Normalised();
		Vector3 b = other.Normalised();

		// calculate the dot product
		float d = a.Dot(other);

		// return the angle between them
		return acosf(d);
	}

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
	
	Vector3 Vector3::operator+ (const Vector3& rhs) const {
	
		Vector3 sum;

		// x is the LEFT vector's x-component
		// rhs.x is the RIGHT vector's x-component
		sum.x = x + rhs.x;
		sum.y = y + rhs.y;
		sum.z = z + rhs.z;

		return sum;

	}

	Vector3 Vector3::operator- (const Vector3& rhs) const {

		Vector3 sum;

		// x is the LEFT vector's x-component
		// rhs.x is the RIGHT vector's x-component
		sum.x = x - rhs.x;
		sum.y = y - rhs.y;
		sum.z = z - rhs.z;

		return sum;

	}

	Vector3 Vector3::operator * (const float& scaler) const {
	
		Vector3 sum;
		
		sum.x = x * scaler;
		sum.y = y * scaler;
		sum.z = z * scaler;

		return sum;

		 
	}

     Vector3 Vector3::operator * (const float& scaler)const{

		Vector3 sum;

		sum.x = scaler * x;
		sum.y = scaler * y;
		sum.z = scaler * z;


		return sum;

	 }
	 

	Vector3 Vector3::operator / (const float& scaler) const {
	
		Vector3 sum;

		sum.x = x / scaler;
		sum.y = y / scaler;
		sum.z = z / scaler;

		return sum;
	}

	void Vector3::operator += (const Vector3& rhs) {

		x += rhs.x;
		y += rhs.y;
		z += rhs.z;


	}

	void Vector3::operator -= (const Vector3& rhs){
	
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;

	}

	void Vector3::operator *= (const float scaler){
	
		x *= scaler;
		y *= scaler;
		z *= scaler;
	
	}

	void Vector3::operator /= (const float scaler){
	
		x /= scaler; 
		y /= scaler; 
		z /= scaler;

	}

	bool Vector3::operator == (const Vector3 &rhs){
	
		float xDist = fabsf(x - rhs.x);
		float yDist = fabsf(y - rhs.y);
		float zDist = fabsf(z - rhs.z);
	
		const float THRESHOLD = 0.00001f;
	
		return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;

	}

	bool Vector3::operator != (const Vector3 &rhs){
	
		return !(*this == rhs);
	
	}


/*=====================================^^^overloads^^^================================================*/
}