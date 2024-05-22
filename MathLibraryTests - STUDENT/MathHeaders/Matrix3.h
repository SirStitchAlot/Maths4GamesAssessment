#pragma once
#include "Vector3.h"
namespace MathClasses
{
    struct Matrix3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // figure out why static wont work in the cpp file for make identity() and why the object inside doesn't want to be made
        //add all my math operators M*M, M*V, M==M, M!=M and obv the compounds
        
        
        
        
        //if something goes wrong with M*M its probably the overloaded constructor


    /*===========================================^^todo^^======================================================================*/
    public:  
        union
        {
            // as individual floats
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            // as a 1-D array
            float v[9];

            // as a 2-D array
            float mm[3][3];

            // as Vector3s
            Vector3 axis[3];
        };
    /*========================================^^properties^^============================================================*/
    public:
        // Default constructor - zero initializes all values
        Matrix3() {

            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;

        }

       Matrix3(float M1, float M2, float M3, 
               float M4, float M5, float M6, 
               float M7, float M8, float M9) {
        
                m1 = M1, m2 = M2, m3 = M3, 
                m4 = M4, m5 = M5, m6 = M6,
                m7 = M7, m8 = M8, m9 = M9;
        
        
        }

        ~Matrix3() {};
       




    





    /*=========================================^^Structors^^============================================================================================*/

         static Matrix3 MakeIdentity() {

             Matrix3 identity;
             identity.m1 = 1;
             identity.m2 = 0;
             identity.m3 = 0;

             identity.m4 = 0;
             identity.m5 = 1;
             identity.m6 = 0;

             identity.m7 = 0;
             identity.m8 = 0;
             identity.m9 = 1;

             return identity;



         }






    /*===========================================^^methods^^====================================================*/
	
        // mutable access to each element
         float& operator [](int dim) {
             return v[dim];
         }

         // const-qualified access to each element
         const float& operator [](int dim) const {
             return v[dim];
         }

         Matrix3 operator *(Matrix3 rhs) const
         {
             return Matrix3(
                 m1 * rhs.m1 + m4 * rhs.m2 + m7 * rhs.m3,
                 m2 * rhs.m1 + m5 * rhs.m2 + m8 * rhs.m3,
                 m3 * rhs.m1 + m6 * rhs.m2 + m9 * rhs.m3,

                 m1 * rhs.m4 + m4 * rhs.m5 + m7 * rhs.m6,
                 m2 * rhs.m4 + m5 * rhs.m5 + m8 * rhs.m6,
                 m3 * rhs.m4 + m6 * rhs.m5 + m9 * rhs.m6,

                 m1 * rhs.m7 + m4 * rhs.m8 + m7 * rhs.m9,
                 m2 * rhs.m7 + m5 * rhs.m8 + m8 * rhs.m9,
                 m3 * rhs.m7 + m6 * rhs.m8 + m9 * rhs.m9);

         }

         Vector3 operator *(Vector3 rhs) const
         {
             return Vector3(
                 Vector3(m1, m4, m7).Dot(rhs),
                 Vector3(m2, m5, m8).Dot(rhs),        
                 Vector3(m3, m6, m9).Dot(rhs)
             );
         }

    
    
    
    /*===========================================^^overloads/casting^^========================================================================*/


    };
}