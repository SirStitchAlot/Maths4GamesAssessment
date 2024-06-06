using System;
using System.Collections.Generic;
using System.Text;
using Raylib_cs;
using static Raylib_cs.Raylib;
using System.Numerics;

namespace RaylibStarterCS {
    class AABB {

        Vector3 min = new Vector3(float.NegativeInfinity, float.NegativeInfinity, float.NegativeInfinity);
        Vector3 max = new Vector3(float.PositiveInfinity, float.PositiveInfinity, float.PositiveInfinity);

        public AABB() { }

        public AABB(Vector3 min, Vector3 max) {
            this.min = min;
            this.max = max;
        }


        public bool IsEmpty() {
            if (float.IsNegativeInfinity(min.X) && float.IsNegativeInfinity(min.Y) && float.IsNegativeInfinity(min.Z) &&
                float.IsInfinity(max.X) && float.IsInfinity(max.Y) && float.IsInfinity(max.Z))
                return true;
            return false;
        }

        public void Empty() {
            min = new Vector3(float.NegativeInfinity, float.NegativeInfinity, float.NegativeInfinity);
            max = new Vector3(float.PositiveInfinity, float.PositiveInfinity, float.PositiveInfinity);
        }

        public Vector3 Center() {
            return (min + max) * 0.5f;
        }

        public Vector3 Extents() {
            return new Vector3(Math.Abs(max.X - min.X) * 0.5f,
                    Math.Abs(max.Y - min.Y) * 0.5f,
                    Math.Abs(max.Z - min.Z) * 0.5f);
        }

        public List<Vector3> Corners() {
            // ignoring z axis for 2D
            List<Vector3> corners = new List<Vector3>(4);
            corners[0] = min;
            corners[1] = new Vector3(min.X, max.Y, min.Z);
            corners[2] = max;
            corners[3] = new Vector3(max.X, min.Y, min.Z);
            return corners;
        }

        public void Fit(List<Vector3> points) {
            // invalidate the extents
            min = new Vector3(float.PositiveInfinity,
                                float.PositiveInfinity,
                                float.PositiveInfinity);
            max = new Vector3(float.NegativeInfinity,
                                float.NegativeInfinity,
                                float.NegativeInfinity);

            // find min and max of the points
            foreach (Vector3 p in points) {
                min = Vector3.Min(min, p);
                max = Vector3.Max(max, p);
            }
        }

        public void Fit(Vector3[] points) {
            // invalidate the extents
            min = new Vector3(float.PositiveInfinity,
                                float.PositiveInfinity,
                                float.PositiveInfinity);
            max = new Vector3(float.NegativeInfinity,
                                float.NegativeInfinity,
                                float.NegativeInfinity);

            // find min and max of the points
            foreach (Vector3 p in points) {
                min = Vector3.Min(min, p);
                max = Vector3.Max(max, p);
            }
        }

        public bool Overlaps(Vector3 p) {
            // test for not overlapped as it exits faster
            return !(p.X < min.X || p.Y < min.Y ||
                p.X > max.X || p.Y > max.Y);
        }

        public bool Overlaps(AABB other) {
            // test for not overlapped as it exits faster
            return !(max.X < other.min.X || max.Y < other.min.Y ||
                   min.X > other.max.X || min.Y > other.max.Y);
        }

        public Vector3 ClosestPoint(Vector3 p) {
            return Vector3.Clamp(p, min, max);
        }

        void SetToTransformedBox(AABB box, CustomMatrix3 m) {
            // If we're empty, then exit (an empty box defined as having the min/max 
            // set to infinity)
            if (box.IsEmpty()) {
                Empty();
                return;
            }

            // Examine each of the nine matrix elements
            // and compute the new AABB
            if (m.m1 > 0.0f)    // m1 = m11 in the formula above
            {
                min.X += m.m1 * box.min.X; max.X += m.m1 * box.max.X;
            } else {
                min.X += m.m1 * box.max.X; max.X += m.m1 * box.min.X;
            }
            if (m.m2 > 0.0f)   // m2 = m12 in the formula above
            {
                min.Y += m.m2 * box.min.X; max.Y += m.m2 * box.max.X;
            } else {
                min.Y += m.m2 * box.max.X; max.Y += m.m2 * box.min.X;
            }
            if (m.m3 > 0.0f)   // m3 = m13 in the formula above
            {
                min.Z += m.m3 * box.min.X; max.Z += m.m3 * box.max.X;
            } else {
                min.Z += m.m3 * box.max.X; max.Z += m.m3 * box.min.X;
            }

            // Continue like this for the remaining 6 matrix values

        }
        
        // helper 
        public void UpdateBoxBoundries(Vector3 min, Vector3 max) { // update collision boundries on runtime
            this.min = min;
            this.max = max;
        }
        public void debugBox2D(Color c) { // draw debug box
            DrawRectangle((int)min.X, (int)min.Y, (int)max.X - (int)min.X, (int)max.Y - (int)min.Y, c);
        }

    }
}
