#pragma once

namespace MathClasses
{
    struct Vector4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        //basically copy stuff from vector3 to this 
    /*===============================^^todo^^=====================================================================*/
	
    public:

        // this union is a total of 12-bytes
       // the struct and float inside the union share the same memory
        union
        {
            struct { float x, y, z, w; };  // 16-bytes
            float data[4];              // 16-bytes
        };




    
    
    
    
    /*=================================^^Properties^^========================================================*/
    
        Vector4() {

            x = 0.f;

            y = 0.f;

            z = 0.f;

            w = 0.f;

        };

        Vector4(float X, float Y, float Z, float W) {
            x = X;
            y = Y;
            z = Z;
            w = W;
        }

        ~Vector4() {};
    
    
    
    
    
    /*===================================^^^Structors^^^========================================================*/
    
            //just prints the vectors to console
        std::string ToString() const {

            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);

        }



        //finds the magnitude of a vector
        float Magnitude() const {

            return sqrtf(x * x + y * y + z * z + w * w);

        }

        //sqaures all the Vectors variables
        float MagnitudeSqr() const {

            return x * x + y * y + z * z + w * w;

        }

        float Distance(const Vector4& other) const {

            return (*this - other).Magnitude();

        }

        float Dot(const Vector4& other) {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }











    /*=======================================^^Methods^^===========================================================*/
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

        operator const float* ()const
        {
            return data;
        }

        Vector4 operator+ (const Vector4& rhs) const {

            Vector4 sum;

            // x is the LEFT vector's x-component
            // rhs.x is the RIGHT vector's x-component
            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;
            sum.w = w + rhs.w;


            return sum;

        }
        
        Vector4 operator- (const Vector4& rhs) const {

            Vector4 sum;

            // x is the LEFT vector's x-component
            // rhs.x is the RIGHT vector's x-component
            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;
            sum.w = w - rhs.w;

            return sum;

        }

        Vector4 operator * (const float& scaler) const {

            Vector4 sum;

            sum.x = x * scaler;
            sum.y = y * scaler;
            sum.z = z * scaler;
            sum.w = w * scaler;

            return sum;


        }

        friend Vector4 operator * (const float& scaler, Vector4& rhs) {

            Vector4 sum;

            sum.x = scaler * rhs.x;
            sum.y = scaler * rhs.y;
            sum.z = scaler * rhs.z;
            sum.w = scaler * rhs.w;


            return sum;

        }

        Vector4 operator / (const float& scaler) const {

            Vector4 sum;

            sum.x = x / scaler;
            sum.y = y / scaler;
            sum.z = z / scaler;
            sum.w = w / scaler;
            

            return sum;
        }

        void operator += (const Vector4& rhs) {

            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;


        }

        void operator -= (const Vector4& rhs) {

            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;

        }

        void operator *= (const float scaler) {

            x *= scaler;
            y *= scaler;
            z *= scaler;
            w *= scaler;

        }

        void operator /= (const float scaler) {

            x /= scaler;
            y /= scaler;
            z /= scaler;
            w /= scaler;

        }

        bool operator == (const Vector4& rhs) {

            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);
            float wDist = fabsf(w - rhs.w);

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD && wDist<THRESHOLD;

        }

        bool operator != (const Vector4& rhs) {

            return !(*this == rhs);

        }


     /*=======================================^^^overloads/casting^^^======================================================================*/
    };
}