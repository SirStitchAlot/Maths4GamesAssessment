using System;
using System.Collections.Generic;
using System.Text;
using Raylib_cs;
using static Raylib_cs.Raylib;
using System.Numerics;

namespace RaylibStarterCS {
    public class SpriteObject : SceneObject {
        Texture2D texture = new Texture2D();
        Image image = new Image();

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
        }

        public override void OnDraw() {
            // local x-axis y and x get passed into Atan2
            //float rotation = (float)Math.Atan2(globalTransform.m01, globalTransform.m00);
            DrawTextureEx(texture,
                new Vector2(
                    globalTransform.m20, globalTransform.m21), // translation x and y
                    GetRotation() * (float)(180.0f / Math.PI),
                    1,
                    Color.WHITE
                );
        }

        public float GetRotation() {
            return (float)Math.Atan2(globalTransform.m01, globalTransform.m00);
        }
    }
}
