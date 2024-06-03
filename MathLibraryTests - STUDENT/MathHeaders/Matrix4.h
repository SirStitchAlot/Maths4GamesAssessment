#pragma once
namespace MathClasses
{
    struct Matrix4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

        //remember 4*4 = 16 so m1 - m16
    /*===============================^^todo^^=====================================================================*/
    public:
            union {


                struct 
                {
                    float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10,
                        m11, m12, m13, m14, m15, m16;
                };

                //as a 1-d array
                float v[16];

                struct {
                    Vector4 xAxis;
                    Vector4 yAxis;
                    Vector4 zAxis;
                    Vector4 translation;
                };
                Vector4 axis[4];
                float data[4][4];
            };
       

    /*=================================^^Properties^^========================================================*/
            Matrix4() {

                m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10=m11= m12= m13= m14= m15= m16= 0.0f;

            }

            Matrix4(float M1, float M2, float M3,float M4,
                    float M5, float M6, float M7,float M8,
                    float M9, float M10,float M11,float M12,
                    float M13,float M14, float M15,float M16 ){
            
            
                    m1 = M1, m2 = M2, m3 = M3, m4 = M4,
                    m5 = M5, m6 = M6, m7 = M7, m8 = M8,
                    m9 = M9, m10 = M10, m11 = M11, m12 = M12,
                    m13 = M13, m14 = M14, m15 = M15, m16 = M16;
                         
            
            
            }

            Matrix4(float Numbers[16])
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
                m10 = Numbers[9];
                m11 = Numbers[10];
                m12 = Numbers[11];
                m13 = Numbers[12];
                m14 = Numbers[13];
                m15 = Numbers[14];
                m16 = Numbers[15];
            
            
   

            }




            ~Matrix4() {}


    /*===================================^^^Structors^^^========================================================*/
            void setScaled(float x, float y, float z) {
                // set scale of each axis
                xAxis = { x, 0, 0, 0 };
                yAxis = { 0, y, 0, 0 };
                zAxis = { 0, 0, z, 0 };
                translation = { 0, 0, 0, 1 };
            }

            void translate(float x, float y, float z) {
                // apply vector offset
                translation += Vector4(x, y, z, 0);
            }

            static Matrix4 MakeIdentity() {

                Matrix4 identity;
                identity.m1 = 1;
                identity.m2 = 0;
                identity.m3 = 0;
                identity.m4 = 0;
                
                identity.m5 = 0;
                identity.m6 = 1;
                identity.m7 = 0;
                identity.m8 = 0;
                
                identity.m9 = 0;
                identity.m10 =0;
                identity.m11 =1;
                identity.m12 =0;

                identity.m13 = 0;
                identity.m14 = 0;
                identity.m15 = 0;
                identity.m16 = 1;


                return identity;



            }

            static Matrix4 MakeRotateX(float a)
            {
                return Matrix4(1, 0, 0, 0,
                               0, cosf(a), -sinf(a), 0,
                               0, sinf(a), cosf(a), 0,
                               0, 0, 0, 1);
            }

            static Matrix4 MakeRotateY(float a)
            {
                return Matrix4(cosf(a), 0, sinf(a), 0,
                                0, 1, 0, 0,
                                -sinf(a), 0, cosf(a),0,
                                0,0,0,1                         );
            }

            static Matrix4 MakeRotateZ(float a)
            {
                return Matrix4(cosf(a), sinf(a), 0, 0,
                              -sinf(a), cosf(a), 0, 0,
                               0, 0, 1,0,
                               0,0,0,1 );
            }

            static Matrix4 MakeScale(float xScale, float yScale, float zScale)
            {
                return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                               0.0f, yScale, 0.0f, 0.0f,
                               0.0f, 0.0f, zScale, 0.0f,
                               0.0f,0.0f,0.0f,1.f);
            }

           static Matrix4 MakeScale(Vector3 scale) {


               return MakeScale(scale.x, scale.y, scale.z);

            }

           std::string ToString() const
           {
               std::string str = std::to_string(v[0]);
               for (size_t i = 1; i < 16; ++i)
               {
                   str += ", " + std::to_string(v[i]);
               }
               return str;
           }

           static Matrix4 MakeEuler(float pitch, float yaw, float roll)
           {
               Matrix4 x = MakeRotateX(pitch);
               Matrix4 y = MakeRotateY(yaw);
               Matrix4 z = MakeRotateZ(roll);

               // combine rotations in a specific order
               return (z * y * x);
           }

           static Matrix4 MakeEuler(Vector3 rot){
               


              return MakeEuler(rot.x, rot.y, rot.z);


               
           }

           static Matrix4 MakeTranslation(float x, float y, float z)
           {
               return Matrix4(1,0,0,0,
                              0,1,0,0,
                              0,0,1,0,
                              x,y,z,1);
           }

           static Matrix4 MakeTranslation(Vector3 vec) {

               return MakeTranslation(vec.x, vec.y, vec.z);

           }




    /*=======================================^^Methods^^===========================================================*/

           // mutable access to each element
           float& operator [](int dim) {
               return v[dim];
           }

           // const-qualified access to each element
           const float& operator [](int dim) const {
               return v[dim];
           }


            // binary * operator
            Vector4 operator * (const Vector4& v) const {
                Vector4 result;

                result[0] = data[0][0] * v[0] + data[1][0] * v[1] +
                    data[2][0] * v[2] + data[3][0] * v[3];

                result[1] = data[0][1] * v[0] + data[1][1] * v[1] +
                    data[2][1] * v[2] + data[3][1] * v[3];

                result[2] = data[0][2] * v[0] + data[1][2] * v[1] +
                    data[2][2] * v[2] + data[3][2] * v[3];

                result[3] = data[0][3] * v[0] + data[1][3] * v[1] +
                    data[2][3] * v[2] + data[3][3] * v[3];
                return result;
            }

            //// binary * operator
            //Matrix4 operator * (const Matrix4& other) const {
            //    Matrix4 result;

            //    for (int r = 0; r < 4; ++r) {
            //        for (int c = 0; c < 4; ++c) {
            //            float v = 0.0f;                                  //no idea why this is here
            //            for (int i = 0; 0 < 4; ++i) {
            //                v += data[i][r] * other.data[c][i];
            //            }
            //            result.data[c][r] = v;
            //        }
            //    }
            //    return result;
            //}



            bool operator == (const Matrix4& rhs) const
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
                float m10Dist = fabsf(m10 - rhs.m10);
                float m11Dist = fabsf(m11 - rhs.m11);
                float m12Dist = fabsf(m12 - rhs.m12);
                float m13Dist = fabsf(m13 - rhs.m13);
                float m14Dist = fabsf(m14 - rhs.m14);
                float m15Dist = fabsf(m15 - rhs.m15);
                float m16Dist = fabsf(m16 - rhs.m16);

                
                const float THRESHOLD = 0.00001f;

                return m1Dist < THRESHOLD && m2Dist < THRESHOLD && m3Dist < THRESHOLD && m4Dist < THRESHOLD && m5Dist < THRESHOLD && m6Dist < THRESHOLD && m7Dist < THRESHOLD && m8Dist < THRESHOLD && m9Dist < THRESHOLD && m10Dist < THRESHOLD && m11Dist < THRESHOLD && m12Dist < THRESHOLD&& m13Dist < THRESHOLD&& m14Dist < THRESHOLD&& m15Dist < THRESHOLD&& m16Dist < THRESHOLD;



            }

            bool operator != (const Matrix4& rhs) const
            {
                return !(*this == rhs);
            }

            Matrix4 operator *(Matrix4 rhs) const
            {
                return Matrix4(
                    m1 * rhs.m1 + m5 * rhs.m2 +  m9 * rhs.m3 + m13 * rhs.m4,
                    m2 * rhs.m1 + m6 * rhs.m2 + m10 * rhs.m3 + m14 * rhs.m4,
                    m3 * rhs.m1 + m7 * rhs.m2 + m11 * rhs.m3 + m15 * rhs.m4,
                    m4 * rhs.m1 + m8 * rhs.m2 + m12 * rhs.m3 + m16 * rhs.m4,

                    m1 * rhs.m5 + m5 * rhs.m6 +  m9 * rhs.m7 + m13 * rhs.m8,
                    m2 * rhs.m5 + m6 * rhs.m6 + m10 * rhs.m7 + m14 * rhs.m8,
                    m3 * rhs.m5 + m7 * rhs.m6 + m11 * rhs.m7 + m15 * rhs.m8,
                    m4 * rhs.m5 + m8 * rhs.m6 + m12 * rhs.m7 + m16 * rhs.m8,

                    m1 * rhs.m9 + m5 * rhs.m10 +  m9 * rhs.m11 + m13 * rhs.m12,
                    m2 * rhs.m9 + m6 * rhs.m10 + m10 * rhs.m11 + m14 * rhs.m12,
                    m3 * rhs.m9 + m7 * rhs.m10 + m11 * rhs.m11 + m15 * rhs.m12,
                    m4 * rhs.m9 + m8 * rhs.m10 + m12 * rhs.m11 + m16 * rhs.m12,

                    m1 * rhs.m13 + m5 * rhs.m14 +  m9 * rhs.m15 + m13 * rhs.m16,
                    m2 * rhs.m13 + m6 * rhs.m14 + m10 * rhs.m15 + m14 * rhs.m16,
                    m3 * rhs.m13 + m7 * rhs.m14 + m11 * rhs.m15 + m15 * rhs.m16,
                    m4 * rhs.m13 + m8 * rhs.m14 + m12 * rhs.m15 + m16 * rhs.m16);
            }





     /*=======================================^^^overloads/casting^^^======================================================================*/




	};
}