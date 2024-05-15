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

        Vector3();

        Vector3(float X, float Y,float Z);

        ~Vector3();

    /*===================================^^^Structors^^^========================================================*/
    public:

        std::string ToString() const;







    /*=======================================^^Methods^^===========================================================*/
    public:
        //subscript Operator that allows us to sort through data
        const float& operator [](int dim) const;
       
        // cast to float array
        operator float* (); 

        // cast to float array - const-qualified
        operator const float* ()const; 

        Vector3 operator + (const Vector3& rhs) const;

        Vector3 operator - (const Vector3& rhs) const;
       
        Vector3 operator * (const float scaler) const;

        Vector3 operator * (const float scaler) const;

        Vector3 operator / (const float scaler) const;

        void operator += (const Vector3& rhs);
        
        void operator -= (const Vector3& rhs);
        
        void operator *= (const float scaler);
        
        void operator /= (const float scaler);

        bool operator == (const Vector3 &rhs);

        bool operator != (const Vector3 &rhs);



    /*=======================================^^^overloads/casting^^^======================================================================*/
        
	};
}