#pragma once

namespace MathClasses
{
    struct Vector3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        //Implement maths operators
        //implement Floating Imprecision and quality tests
        //implement ToString
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

        ~Vector3();

    /*===================================^^^Structors^^^========================================================*/
    public:








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
        //this part done below is done wrong so completely ignore it idk why im not deleteing it but thats what im doing
        Vector3 operator * (const Vector3& rhs) const;




    /*=======================================^^^overloads/casting^^^======================================================================*/

	};
}