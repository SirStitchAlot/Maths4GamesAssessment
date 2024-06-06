using System;
using System.Collections.Generic;
using System.Text;
using Raylib_cs;
using static Raylib_cs.Raylib;
using System.Numerics;

namespace RaylibStarterCS {
    public class CustomMatrix3 {
        public float m1, m2, m3, m4, m5, m6, m7, m8, m9;

        public CustomMatrix3() {
            m1 = 1; m2 = 0; m3 = 0;
            m4 = 0; m5 = 1; m6 = 0;
            m7 = 0; m8 = 0; m9 = 1;
        }

        public CustomMatrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
            this.m1 = m1; this.m2 = m2; this.m3 = m3;
            this.m4 = m4; this.m5 = m5; this.m6 = m6;
            this.m7 = m7; this.m8 = m8; this.m9 = m9;
        }

        public static CustomMatrix3 CreateIdentity() {
            return new CustomMatrix3(1.0f, 0.0f, 0.0f,
                           0.0f, 1.0f, 0.0f,
                           0.0f, 0.0f, 1.0f);
        }

        public static CustomMatrix3 CreateTranslation(float x, float y) {
#if ROW_MAJOR
            return new Matrix3(1.0f, 0.0f, x,
                           0.0f, 1.0f, y,
                           0.0f, 0.0f, 1.0f);
#else
            return new CustomMatrix3(1.0f, 0.0f, 0.0f,
                           0.0f, 1.0f, 0.0f,
                           x, y, 1.0f);
#endif
        }

        public static CustomMatrix3 CreateTranslation(Vector3 vec) {
#if ROW_MAJOR
            return new Matrix3(1.0f, 0.0f, vec.x,
                           0.0f, 1.0f, vec.y,
                           0.0f, 0.0f, vec.z);
#else
            return new CustomMatrix3(1.0f, 0.0f, 0.0f,
                           0.0f, 1.0f, 0.0f,
                           vec.X, vec.Y, vec.Z);
#endif
        }

        public static CustomMatrix3 CreateRotation(double rot) {
# if ROW_MAJOR
            return new Matrix3((float)Math.Cos(rot), (float)-Math.Sin(rot), 0.0f,
                           (float)Math.Sin(rot), (float)Math.Cos(rot), 0.0f,
                           0.0f, 0.0f, 1.0f);
#else
            return new CustomMatrix3((float)Math.Cos(rot), (float)Math.Sin(rot), 0.0f,
                           (float)-Math.Sin(rot), (float)Math.Cos(rot), 0.0f,
                           0.0f, 0.0f, 1.0f);
#endif
        }
        public static CustomMatrix3 CreateScale(float xScale, float yScale) {
            return new CustomMatrix3(xScale, 0.0f, 0.0f,
                           0.0f, yScale, 0.0f,
                           0.0f, 0.0f, 1.0f);
        }

        public static Vector3 operator *(CustomMatrix3 lhs, Vector3 rhs) {
#if ROW_MAJOR
            return new Vector3((rhs.x * lhs.m1) + (rhs.y * lhs.m2) + (rhs.z * lhs.m3),
                            (rhs.x * lhs.m4) + (rhs.y * lhs.m5) + (rhs.z * lhs.m6),
                            (rhs.x * lhs.m7) + (rhs.y * lhs.m8) + (rhs.z * lhs.m9));
#else
            return new Vector3((lhs.m1 * rhs.X) + (lhs.m4 * rhs.Y) + (lhs.m7 * rhs.Z),
                            (rhs.X * lhs.m2) + (rhs.Y * lhs.m5) + (rhs.Z * lhs.m8),
                            (rhs.X * lhs.m3) + (rhs.Y * lhs.m6) + (rhs.Z * lhs.m9));

            //return new Vector3((rhs.x * lhs.m1) + (rhs.y * lhs.m4) + (rhs.z * lhs.m7),
            //                (rhs.x * lhs.m2) + (rhs.y * lhs.m5) + (rhs.z * lhs.m8),
            //                (rhs.x * lhs.m3) + (rhs.y * lhs.m6) + (rhs.z * lhs.m9));
#endif
        }

        public static CustomMatrix3 operator *(CustomMatrix3 lhs, CustomMatrix3 rhs) {
#if ROW_MAJOR
	        return new Matrix3(
                rhs.m1* lhs.m1 +rhs.m2* lhs.m4 +rhs.m3* lhs.m7, rhs.m1* lhs.m2 +rhs.m2* lhs.m5 +rhs.m3* lhs.m8, rhs.m1* lhs.m3 +rhs.m2* lhs.m6 +rhs.m3* lhs.m9,
                rhs.m4* lhs.m1 +rhs.m5* lhs.m4 +rhs.m6* lhs.m7, rhs.m4* lhs.m2 +rhs.m5* lhs.m5 +rhs.m6* lhs.m8, rhs.m4* lhs.m3 +rhs.m5* lhs.m6 +rhs.m6* lhs.m9,
                rhs.m7* lhs.m1 +rhs.m8* lhs.m4 +rhs.m9* lhs.m7, rhs.m7* lhs.m2 +rhs.m8* lhs.m5 +rhs.m9* lhs.m8, rhs.m7* lhs.m3 +rhs.m8* lhs.m6 +rhs.m9* lhs.m9);	
#else
            return new CustomMatrix3(
                rhs.m1 * lhs.m1 + rhs.m2 * lhs.m4 + rhs.m3 * lhs.m7, rhs.m1 * lhs.m2 + rhs.m2 * lhs.m5 + rhs.m3 * lhs.m8, rhs.m1 * lhs.m3 + rhs.m2 * lhs.m6 + rhs.m3 * lhs.m9,
                rhs.m4 * lhs.m1 + rhs.m5 * lhs.m4 + rhs.m6 * lhs.m7, rhs.m4 * lhs.m2 + rhs.m5 * lhs.m5 + rhs.m6 * lhs.m8, rhs.m4 * lhs.m3 + rhs.m5 * lhs.m6 + rhs.m6 * lhs.m9,
                rhs.m7 * lhs.m1 + rhs.m8 * lhs.m4 + rhs.m9 * lhs.m7, rhs.m7 * lhs.m2 + rhs.m8 * lhs.m5 + rhs.m9 * lhs.m8, rhs.m7 * lhs.m3 + rhs.m8 * lhs.m6 + rhs.m9 * lhs.m9);
#endif
        }

        // rebuild the matrix
        public void Set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9) {
            this.m1 = m1; this.m2 = m2; this.m3 = m3;
            this.m4 = m4; this.m5 = m5; this.m6 = m6;
            this.m7 = m7; this.m8 = m8; this.m9 = m9;
        }

        public void Set(CustomMatrix3 m) {
            this.m1 = m.m1; this.m2 = m.m2; this.m3 = m.m3;
            this.m4 = m.m4; this.m5 = m.m5; this.m6 = m.m6;
            this.m7 = m.m7; this.m8 = m.m8; this.m9 = m.m9;
        }

        // only set the translation component of the matrix
        public void SetTranslation(float x, float y) {
#if ROW_MAJOR
            m3 = x;
            m6 = y;
#else
            m7 = x;
            m8 = y;
#endif
        }

        // add x and y onto the translation component of the matrix
        public void Translate(float x, float y) {
#if ROW_MAJOR
            m3 += x;
            m6 += y;
#else
            m7 += x;
            m8 += y;
#endif
        }


        // returns the translation component of the matrix
        public Vector3 GetTranslation() {
#if ROW_MAJOR
	        return new Vector3(m3, m6, 0);
#else
            return new Vector3(m7, m8, 0);
#endif
        }

        public void SetRotateX(double a) {
            Set(1, 0, 0,
                0, (float)Math.Cos(a), (float)Math.Sin(a),
                0, (float)-Math.Sin(a), (float)Math.Cos(a));
        }

        public void SetRotateY(double a) {
            Set((float)Math.Cos(a), 0, (float)-Math.Sin(a),
                0, 1, 0,
                (float)Math.Sin(a), 0, (float)Math.Cos(a));
        }

        public void SetRotateZ(double a) {
            Set((float)Math.Cos(a), (float)Math.Sin(a), 0,
                (float)-Math.Sin(a), (float)Math.Cos(a), 0,
                0, 0, 1);
        }

        public void RotateX(double radians) {
            CustomMatrix3 m = new CustomMatrix3();
            m.SetRotateX(radians);

            Set(this * m);
        }

        void SetEuler(float pitch, float yaw, float roll) {

            CustomMatrix3 x = new CustomMatrix3();
            CustomMatrix3 y = new CustomMatrix3();
            CustomMatrix3 z = new CustomMatrix3();
            x.SetRotateX(pitch);
            y.SetRotateY(yaw);
            z.SetRotateZ(roll);

            // combine rotations in a specific order
            Set(z * y * x);
        }


        public void SetScaled(float x, float y, float z) {
            m1 = x; m2 = 0; m3 = 0;
            m4 = 0; m5 = y; m6 = 0;
            m7 = 0; m8 = 0; m9 = z;
        }

        public void SetScaled(Vector3 v) {
            m1 = v.X; m2 = 0; m3 = 0;
            m4 = 0; m5 = v.Y; m6 = 0;
            m7 = 0; m8 = 0; m9 = v.Z;
        }

        void Scale(float x, float y, float z) {
            CustomMatrix3 m = new CustomMatrix3();
            m.SetScaled(x, y, z);

            Set(this * m);
        }

        void Scale(Vector3 v) {
            CustomMatrix3 m = new CustomMatrix3();
            m.SetScaled(v.X, v.Y, v.Z);
            Set(this * m);
        }
    }
}