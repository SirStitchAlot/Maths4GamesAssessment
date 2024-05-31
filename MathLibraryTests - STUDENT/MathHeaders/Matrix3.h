#pragma once

#include <string>
#include <cmath>
namespace MathClasses
{
    struct Matrix3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        //matrix transformations
        //MakeScale(F1,f2) // this is for a 2d thingo
        //maketranslation (f1,f2,f3)
        //maketranslation (Vector3)
        
        
       
        
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

       Matrix3(float Numbers[9]) 
       {
        
           m1 = Numbers[0];
           m2 = Numbers[1];
           m3 = Numbers[2];
           m4 = Numbers[3];
           m5 = Numbers[4];
           m6 = Numbers[5];
           m7 = Numbers[6];
           m8 = Numbers[7];
           m9 = Numbers[8];
       
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

         Matrix3 Transposed() const
         {
             return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
         }

         std::string ToString() const
         {
             std::string str = std::to_string(v[0]);
             for (size_t i = 1; i < 9; ++i)
             {
                 str += ", " + std::to_string(v[i]);
             }
             return str;
         }

         static Matrix3 MakeRotateX(float a)
         {
             return Matrix3(1, 0, 0,
                            0, cosf(a), -sinf(a),
                            0, sinf(a), cosf(a));
         }

         static Matrix3 MakeRotateY(float a)
         {
             return Matrix3(cosf(a), 0, -sinf(a),
                             0, 1, 0,
                            sinf(a), 0, cosf(a));
         }

         static Matrix3 MakeRotateZ(float a)
         {
             return Matrix3(cosf(a), sinf(a), 0,
                           -sinf(a), cosf(a), 0,
                             0, 0, 1);
         }

         static Matrix3 MakeScale(float xScale, float yScale, float zScale)
         {
             return Matrix3(xScale, 0.0f, 0.0f,
                            0.0f, yScale, 0.0f,
                            0.0f, 0.0f, zScale);
         }

         static Matrix3 MakeScale(Vector3 scale)
         {
             // just reuses the function we wrote above!
             return MakeScale(scale.x, scale.y, scale.z);
         }

         static Matrix3 MakeEuler(float pitch, float yaw, float roll)
         {
             Matrix3 x = MakeRotateX(pitch);
             Matrix3 y = MakeRotateY(yaw);
             Matrix3 z = MakeRotateZ(roll);

             // combine rotations in a specific order
             return (z * y * x);
         }

         static Matrix3 MakeEuler(Vector3 rot) {
         
         
             return MakeEuler(rot.x, rot.y, rot.z);
         
         
         }

         static Matrix3 MakeTranslation(float x, float y, float z)
         {
             return Matrix3(1, 0, 0,
                            0, 1, 0,
                            x, y, z);
         }

         static Matrix3 MakeTranslation(Vector3 vec)
         {
            return MakeTranslation(vec.x, vec.y, vec.z);
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

         

         Matrix3& operator *=(Matrix3 rhs)
         {
             *this = *this * rhs;
         }

         Vector3 operator *(Vector3 rhs) const
         {
             return Vector3(
                 Vector3(m1, m4, m7).Dot(rhs),
                 Vector3(m2, m5, m8).Dot(rhs),        
                 Vector3(m3, m6, m9).Dot(rhs)
             );
         }

         bool operator == (const Matrix3& rhs) const
         {
             float m1Dist = fabsf(m1 - rhs.m1);
             float m2Dist = fabsf(m2 - rhs.m2);
             float m3Dist = fabsf(m3 - rhs.m3);
             float m4Dist = fabsf(m4 - rhs.m4);
             float m5Dist = fabsf(m5 - rhs.m5);
             float m6Dist = fabsf(m6 - rhs.m6);
             float m7Dist = fabsf(m7 - rhs.m7);
             float m8Dist = fabsf(m8 - rhs.m8);
             float m9Dist = fabsf(m9 - rhs.m9);
             const float THRESHOLD = 0.00001f;

             return m1Dist < THRESHOLD && m2Dist < THRESHOLD && m3Dist < THRESHOLD && m4Dist < THRESHOLD && m5Dist < THRESHOLD && m6Dist < THRESHOLD && m7Dist < THRESHOLD && m8Dist < THRESHOLD && m9Dist < THRESHOLD;
                      
                           
            
         }

         bool operator != (const Matrix3& rhs) const
         {
             return !(*this == rhs);
         }

    /*===========================================^^overloads/casting^^========================================================================*/


    };
}