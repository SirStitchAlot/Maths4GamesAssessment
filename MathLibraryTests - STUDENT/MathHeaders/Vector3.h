#pragma once
#include <cmath>
#include <string>

namespace MathClasses
{
    struct Vector3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here... 
     /*==============================^^todo^^====================================================*/
    public:

        // this union is a total of 12-bytes
       // the struct and float inside the union share the same memory
        union
        {
            struct { float x, y, z; };  // 12-bytes
            float data[3];              // 12-bytes
        };




    /*=================================^^Properties^^========================================================*/
    public:

        Vector3() {

            x = 0.f;

            y = 0.f;

            z = 0.f;

        };

        Vector3(float X, float Y,float Z) {
            x = X;
            y = Y;
            z = Z;
        }

        ~Vector3() {};

    /*===================================^^^Structors^^^========================================================*/ 
    public:
        //just prints the vectors to console
        std::string ToString() const {

            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);

        }

        //finds the magnitude of a vector
        float Magnitude() const {

            return sqrtf(x * x + y * y + z * z);

        }

        //sqaures all the Vectors variables
        float MagnitudeSqr() const {

            return x * x + y * y + z * z;

        }

        //calculates the difference between two vectors
        float Distance(const Vector3& other) const {

            return (*this - other).Magnitude();

        }

        //This Normalises the vector
        void Normalise() {

            float m = Magnitude();

            x /= m;
            y /= m;
            z /= m;

        }

        //returns a copy of the normialised vector
        Vector3 Normalised() const {

            Vector3 copy = *this;
            copy.Normalise();

            return copy;

        }

        //idk
        float Dot(const Vector3& other) {
            return x * other.x + y * other.y + z * other.z;
        }

        //idk
        Vector3 Cross(const Vector3& other) {
            return Vector3(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
        }

        //returns the angle between two vectors
        float AngleBetween(const Vector3& other) const {
            // normalise the vectors
            Vector3 a = Normalised();
            Vector3 b = other.Normalised();

            // calculate the dot product
            float d = a.Dot(other);

            // return the angle between them
            return acosf(d);
        }
    
    



    /*=======================================^^Methods^^===========================================================*/
    public:

		float& operator [](int dim)
		{
			return data[dim];
		}

		//subscript Operator that allows us to sort through data
		const float& operator [](int dim) const
		{
			return data[dim];
		}

		// cast to float array
		operator float* ()
		{
			return data;
		}

		// cast to float array - const-qualified
		operator const float* ()const
		{
			return data;
		}

		Vector3 operator + (const Vector3& rhs) const {

			Vector3 sum;

			// x is the LEFT vector's x-component
			// rhs.x is the RIGHT vector's x-component
			sum.x = x + rhs.x;
			sum.y = y + rhs.y;
			sum.z = z + rhs.z;

			return sum;

		}

		Vector3 operator - (const Vector3& rhs) const {

			Vector3 sum;

			// x is the LEFT vector's x-component
			// rhs.x is the RIGHT vector's x-component
			sum.x = x - rhs.x;
			sum.y = y - rhs.y;
			sum.z = z - rhs.z;

			return sum;

		}

		Vector3 operator * (const float& scaler) const {

			Vector3 sum;

			sum.x = x * scaler;
			sum.y = y * scaler;
			sum.z = z * scaler;

			return sum;


		}

		friend Vector3 operator * (const float& scaler,Vector3& rhs) {

			Vector3 sum;

			sum.x = scaler * rhs.x;
			sum.y = scaler * rhs.y;
			sum.z = scaler * rhs.z;


			return sum;

		}


		Vector3 operator / (const float& scaler) const {

			Vector3 sum;

			sum.x = x / scaler;
			sum.y = y / scaler;
			sum.z = z / scaler;

			return sum;
		}

		void operator += (const Vector3& rhs) {

			x += rhs.x;
			y += rhs.y;
			z += rhs.z;


		}

		void operator -= (const Vector3& rhs) {

			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;

		}

		void operator *= (const float scaler) {

			x *= scaler;
			y *= scaler;
			z *= scaler;

		}

		void operator /= (const float scaler) {

			x /= scaler;
			y /= scaler;
			z /= scaler;

		}

		bool operator == (const Vector3& rhs) {

			float xDist = fabsf(x - rhs.x);
			float yDist = fabsf(y - rhs.y);
			float zDist = fabsf(z - rhs.z);

			const float THRESHOLD = 0.00001f;

			return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;

		}

		bool operator != (const Vector3& rhs) {

			return !(*this == rhs);

		}


    /*=======================================^^^overloads/casting^^^======================================================================*/
        
	};
}