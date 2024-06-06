using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using Raylib_cs;
using System.Numerics;
using static Raylib_cs.Raylib;

namespace Matrix_01 {
    internal class Game_01 {
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;
        private float timer = 0;
        private int fps = 1;
        private int frames;
        private float deltaTime = 0.005f;
        float m_timer = 0;
        float Speed = 100.0f;

        float Scale_Multi = .5f;    // scale multiplier 
        bool Scale_Active = false;  // scale switch

        SceneObject tankObject = new SceneObject();
        SpriteObject tankSprite = new SpriteObject();


        public Game_01() { }

        public void Init() {
            stopwatch.Start();
            lastTime = stopwatch.ElapsedMilliseconds;

            if (Stopwatch.IsHighResolution) {
                Console.WriteLine("Stopwatch high-resolution frequency: {0} ticks per second", Stopwatch.Frequency);
            }

            SetTargetFPS(60);       // Set our game to run at 60 frames-per-second


            tankSprite.Load("../Images/tankBody_blue_outline.png");
            // sprite is facing the wrong way... fix that here 
            tankSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            // sets an offset for the base, so it rotates around the centre
            tankSprite.SetPosition(-tankSprite.Width / 2.0f, tankSprite.Height / 2.0f);
            Console.WriteLine((-tankSprite.Width / 2.0f) + " | " + (tankSprite.Height / 2.0f));

            // set up the scene object hierarchy - parent the turret to the base, 
            // then the base to the tank sceneObject
            tankObject.AddChild(tankSprite);

            // having an empty object for the tank parent means we can set the 
            // position/rotation of the tank without
            // affecting the offset of the base sprite
            tankObject.SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);

        }

        public void Shutdown() { }

        public void Update() {
            lastTime = currentTime;
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;
            timer += deltaTime;
            if (timer >= 1) {
                fps = frames;
                frames = 0;
                timer -= 1;
            }
            frames++;

            // insert game logic here            
            m_timer += deltaTime;

            // Translate
            if (IsKeyDown(KeyboardKey.KEY_W)) {
                CustomVector3 facing = new CustomVector3(
                                             tankObject.LocalTransform.m00,
                                             tankObject.LocalTransform.m01,
                                             0 // <-- z=0 because its vector
                                             );
                facing *= deltaTime * Speed;
                tankObject.Translate(facing.x, facing.y);
            }

            if (IsKeyDown(KeyboardKey.KEY_S)) {
                CustomVector3 facing = new CustomVector3(
                                             tankObject.LocalTransform.m00,
                                             tankObject.LocalTransform.m01,
                                             0 // <-- z=0 because its vector
                                             );
                facing *= deltaTime * -Speed;
                tankObject.Translate(facing.x, facing.y);


            }
            // Rotate
            if (IsKeyDown(KeyboardKey.KEY_A)) { tankObject.Rotate(-deltaTime); }
            if (IsKeyDown(KeyboardKey.KEY_D)) { tankObject.Rotate(deltaTime); }

            // Scale 
            if (IsKeyDown(KeyboardKey.KEY_O)) {
                Scale_Active = true;     // activate scaling
            }
            if (IsKeyDown(KeyboardKey.KEY_I) && Scale_Active) {
                Scale_Active = false;    // deactivate scaling
                tankObject.Scale(Scale_Multi, Scale_Multi);
            }

            tankObject.Update(deltaTime);
        }


        public void Draw() {
            BeginDrawing();

            ClearBackground(Color.BLACK);
            DrawText(fps.ToString(), 10, 10, 12, Color.RED);
            DrawText(tankObject.GlobalTransform.debug(), 0, 40, 18, Color.RED);
            tankObject.Draw();

            EndDrawing();
        }

    }
}
