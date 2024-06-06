using System;
using System.Collections.Generic;
using System.Text;
using Raylib_cs;
using static Raylib_cs.Raylib;
using System.Numerics;

namespace Matrix_01 {
    public class SpriteObject : SceneObject {
        // vars
        Texture2D texture = new Texture2D();
        Image image = new Image();

        int def_Width = 0;
        int def_Height = 0;

        public float Width {
            get { return texture.width; }
        }

        public float Height {
            get { return texture.height; }
        }

        public SpriteObject() { }

        public void Load(string filename) {
            Image img = LoadImage(filename);
            texture = LoadTextureFromImage(img);

            def_Width = texture.width;
            def_Height = texture.height;
        }

        public override void OnDraw() {
            // local x-axis y and x get passed into Atan2
            float rotation = (float)Math.Atan2(globalTransform.m01, globalTransform.m00);
            DrawTextureEx(texture,
                new Vector2(
                    globalTransform.m20, globalTransform.m21), // translation x and y
                    rotation * (float)(180.0f / Math.PI),
                    1,
                    Color.WHITE
                );
        }

        public void Scale_Texture(float w, float h) {
            texture.width = (int)(texture.width * w);
            texture.height = (int)(texture.height * h);
        }

        public void Scale_Reset() {
            texture.width = def_Width;
            texture.height = def_Height;
        }
    }
}
