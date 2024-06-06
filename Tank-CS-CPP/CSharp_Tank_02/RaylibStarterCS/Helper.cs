using System;
using System.Collections.Generic;
using System.Text;


public struct CustomVector3 {
    public float x, y, z;

    public CustomVector3(float _x, float _y, float _z) {
        x = _x; y = _y; z = _z;
    }

    public static CustomVector3 operator +(CustomVector3 lhs, CustomVector3 rhs) {
        return new CustomVector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    public static CustomVector3 operator -(CustomVector3 lhs, CustomVector3 rhs) {
        return new CustomVector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    public static CustomVector3 operator *(float lhs, CustomVector3 rhs) {
        return new CustomVector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
    }

    public static CustomVector3 operator *(CustomVector3 lhs, float rhs) {
        return new CustomVector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }

    public static CustomVector3 operator /(CustomVector3 lhs, float rhs) {
        return new CustomVector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    }

    public float Dot(CustomVector3 other) {
        return x * other.x + y * other.y + z * other.z;
    }

    public static float Dot(CustomVector3 v1, CustomVector3 v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    public CustomVector3 Cross(CustomVector3 other) {
        return new CustomVector3(
                            y * other.z - z * other.y,
                            z * other.x - x * other.z,
                            x * other.y - y * other.x
                           );
    }

    public float Magnitude() {
        return (float)Math.Sqrt(x * x + y * y + z * z);
    }

    public void Normalize() {
        float mag = Magnitude();
        x = x / mag;   y = y / mag;   z = z / mag;
    }
}

// ---- matrix 3 ---- // 

public struct Matrix3 {
    public float m00, m01, m02; // local x-axis
    public float m10, m11, m12; // local y-axis
    public float m20, m21, m22; // local z-axis
    public Matrix3(float _m00, float _m01, float _m02, float _m10, float _m11, float _m12, float _m20, float _m21, float _m22) {
        m00 = _m00; m01 = _m01; m02 = _m02;
        m10 = _m10; m11 = _m11; m12 = _m12;
        m20 = _m20; m21 = _m21; m22 = _m22;
    }

    public static Matrix3 identity = new Matrix3(1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1);


    public Matrix3(CustomVector3 X, CustomVector3 Y, CustomVector3 Z) {
        m00 = X.x; m01 = X.y; m02 = X.z;
        m10 = Y.x; m11 = Y.y; m12 = Y.z;
        m20 = Z.x; m21 = Z.y; m22 = Z.z;
    }

    public Matrix3(float uniformScale) {
        m00 = m11 = m22 = uniformScale;
        m01 = m02 = 0;
        m10 = m12 = 0;
        m20 = m21 = 0;
    }

    public static Matrix3 operator *(Matrix3 M1, Matrix3 M2) {
        return new Matrix3(
           /* ROW MAJOR *//*
           M1.m00 * M2.m00 + M1.m01 * M2.m10 + M1.m02 * M2.m20,
           M1.m00 * M2.m01 + M1.m01 * M2.m11 + M1.m02 * M2.m21,
           M1.m00 * M2.m02 + M1.m01 * M2.m12 + M1.m02 * M2.m22,
           M1.m10 * M2.m00 + M1.m11 * M2.m10 + M1.m12 * M2.m20,
           M1.m10 * M2.m01 + M1.m11 * M2.m11 + M1.m12 * M2.m21,
           M1.m10 * M2.m02 + M1.m11 * M2.m12 + M1.m12 * M2.m22,
           M1.m20 * M2.m00 + M1.m21 * M2.m10 + M1.m22 * M2.m20,
           M1.m20 * M2.m01 + M1.m21 * M2.m11 + M1.m22 * M2.m21,
           M1.m20 * M2.m02 + M1.m21 * M2.m12 + M1.m22 * M2.m22
           */
           /* COLUMN MAJOR */ 
            M1.m00 * M2.m00 + M1.m10 * M2.m01 + M1.m20 * M2.m02,
            M1.m01 * M2.m00 + M1.m11 * M2.m01 + M1.m21 * M2.m02,
            M1.m02 * M2.m00 + M1.m12 * M2.m01 + M1.m22 * M2.m02,

            M1.m00 * M2.m10 + M1.m10 * M2.m11 + M1.m20 * M2.m12,
            M1.m01 * M2.m10 + M1.m11 * M2.m11 + M1.m21 * M2.m12,
            M1.m02 * M2.m10 + M1.m12 * M2.m11 + M1.m22 * M2.m12,

            M1.m00 * M2.m20 + M1.m10 * M2.m21 + M1.m20 * M2.m22,
            M1.m01 * M2.m20 + M1.m11 * M2.m21 + M1.m21 * M2.m22,
            M1.m02 * M2.m20 + M1.m12 * M2.m21 + M1.m22 * M2.m22
            
            );

        /*
            m00 m01 m02    m00 m01 m02    
            m10 m11 m12    m10 m11 m12    
            m20 m21 m22    m20 m21 m22    

         */
    }
    // https://gamedev.stackexchange.com/questions/18901/can-someone-explain-the-reasons-for-the-implications-of-colum-vs-row-major-in
    // https://mtrebi.github.io/2017/01/20/row-vs-column.html
    public static CustomVector3 operator *(CustomVector3 V, Matrix3 M) {
        //  V.x * xaxis + V.y * yaxis + V.z * zaxis
        return new CustomVector3(
            V.x * M.m00 + V.y * M.m10 + V.z * M.m20,
            V.x * M.m01 + V.y * M.m11 + V.z * M.m21,
            V.x * M.m02 + V.y * M.m12 + V.z * M.m22
            );
        /*
                          m00 m01 m02        
             Vx Vy Vz  *  m10 m11 m12        
                          m20 m21 m22        

        */
    }
    
    // https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/row-major-vs-column-major-vector


    public void SetRotateX(float radians) {
        float c = (float)Math.Cos(radians);
        float s = (float)Math.Sin(radians + MathF.PI); // radians + MathF.PI --> +z access points into scene 

        m00 = 1; m10 = 0;  m20 = 0;
        m01 = 0; m11 = c;  m21 = s;
        m02 = 0; m12 = -s; m22 = c;
    }

    public void SetRotateY(float radians) {
        float c = (float)Math.Cos(radians);
        float s = (float)Math.Sin(radians + MathF.PI);// radians + MathF.PI --> +z access points into scene

        m00 = c; m10 = 0; m20 = -s;
        m01 = 0; m11 = 1; m21 = 0;
        m02 = s; m12 = 0; m22 = c;
    }

    public void SetRotateZ(float radians) {
        float c = (float)Math.Cos(radians);
        float s = (float)Math.Sin(radians + MathF.PI);// radians + MathF.PI --> +z access points into scene

        m00 = c;  m10 = s; m20 = 0;
        m01 = -s; m11 = c; m21 = 0;
        m02 = 0;  m12 = 0; m22 = 1;
    }

    public void RotateZ(float radians) {
        Matrix3 m = new Matrix3();
        m.SetRotateZ(radians);
        this *= m;
    }

    // set the translation for a 2D homogenous matrix, leaving any scale and rotation as is
    public void SetTranslation(float x, float y) {
        m20 = x; m21 = y;
    }

    // Translate a 2D homogenous matrix by a given delta to x and y 
    public void Translate(float dx, float dy) {
        m20 += dx; m21 += dy;
    }

    public void SetScaled(float x, float y, float z) {
        m00 = x; m10 = 0; m20 = 0;
        m01 = 0; m11 = y; m21 = 0;
        m02 = 0; m12 = 0; m22 = z;
    }

    public void Scale(float x, float y, float z) {
        Matrix3 m = new Matrix3();
        m.SetScaled(x, y, z);
        this *= m;
    }

    public string debug() {
        string s = "";
        s  = m00 + " | " + m01 + " | " + m02 + " | \n";
        s += m10 + " | " + m11 + " | " + m12 + " | \n";
        s += m20 + " | " + m21 + " | " + m22 + " | \n";
        //Console.WriteLine(s); 
        return s;
    }

}


namespace RaylibStarterCS {
    public class Helper { 
        public Helper() { }
    }
}
                                     