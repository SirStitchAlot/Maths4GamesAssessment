using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace Matrix_01 {
    public class SceneObject {
        // vars
        protected SceneObject parent = null;
        protected List<SceneObject> children = new List<SceneObject>();

        protected Matrix3 localTransform = new Matrix3(1);
        protected Matrix3 globalTransform = new Matrix3(1);

        //con/des
        public SceneObject() {
            localTransform = new Matrix3(1); // initialise with the identity matrix
        }

        ~SceneObject() {
            if (parent != null) { parent.RemoveChild(this); }
            foreach (SceneObject so in children) { so.parent = null; }
        }

        // methods
        public Matrix3 LocalTransform {
            get { return localTransform; }
        }

        public Matrix3 GlobalTransform {
            get { return globalTransform; }
        }

        public SceneObject Parent {
            get { return parent; }
        }

        public int GetChildCount() {
            return children.Count;
        }

        public SceneObject GetChild(int index) {
            return children[index];
        }

        public void AddChild(SceneObject child) {
            Debug.Assert(child.parent == null); // make sure it doesn't have a parent already
            child.parent = this; // assign "this as parent
            children.Add(child); // add new child to collection
        }

        public void RemoveChild(SceneObject child) {
            if (children.Remove(child) == true) child.parent = null;
        }

        public virtual void OnUpdate(float delatTime) { /* code */ }
        public virtual void OnDraw() { /* code */ }


        public void Update(float deltaTime) {
            OnUpdate(deltaTime); // run OnUpdate behaviour
            // update children
            foreach (SceneObject child in children) child.Update(deltaTime);
        }

        public void Draw() {
            OnDraw(); // run OnDraw behaviour
            // draw children
            foreach (SceneObject child in children) child.Draw();
        }

        public void UpdateTransform() {
            if (parent != null) globalTransform = parent.globalTransform * localTransform; // Mpr * Mch
            else globalTransform = localTransform;

            foreach (SceneObject child in children) child.UpdateTransform(); // update children transform
        }

        public void SetPosition(float x, float y) {
            localTransform.SetTranslation(x, y);
            UpdateTransform();
        }

        public void SetRotate(float radians) {
            localTransform.SetRotateZ(radians);
            UpdateTransform();
        }

        public void SetScale(float width, float height) {
            localTransform.SetScaled(width, height, 1);
            UpdateTransform();
        }

        public void Translate(float x, float y) {
            localTransform.Translate(x, y);
            UpdateTransform();
        }

        public void Rotate(float radians) {
            localTransform.RotateZ(radians);
            UpdateTransform();
        }

        public void Scale(float width, float height) {
            localTransform.Scale(width, height, 1);
            UpdateTransform();

            // apply scale to sprite image 
            foreach (SceneObject child in children) {
                SpriteObject u = (SpriteObject)child; // cast to sprite object
                if (u != null) u.Scale_Texture(width, height);
            }
        }
    }

}
