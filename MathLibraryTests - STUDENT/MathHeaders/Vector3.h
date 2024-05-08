#pragma once

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

        ~Vector3();

    /*===================================^^^Structors^^^========================================================*/
    public:








    /*=======================================^^Methods^^===========================================================*/
    public:

        const float& operator [](int dim) const;
       
        // cast to float array
        operator float* (); 

        // cast to float array - const-qualified
        operator const float* (); 






    /*=======================================^^^overloads/casting^^^======================================================================*/

	};
}