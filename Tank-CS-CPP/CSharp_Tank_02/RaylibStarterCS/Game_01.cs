using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using Raylib_cs;
using System.Numerics;
using static Raylib_cs.Raylib;

namespace RaylibStarterCS {
    class Game_01 {
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;
        private float timer = 0;
        private int fps = 1;
        private int frames;
        private float deltaTime = 0.005f;
        float m_timer = 0;
        float Speed  = 100.0f;




        SceneObject tankObject = new SceneObject();
        SceneObject turretObject = new SceneObject();

        SpriteObject tankSprite = new SpriteObject();
        SpriteObject turretSprite = new SpriteObject();

        AABB PlayerAABB;
        AABB ObjectAABB;

        Color tempColor = Color.GREEN;
        Vector3 tempVec;

        Vector3 ObjectA_Pos;
        Vector3 ObjectB_Pos;
        bool CollisionDetected;

        Vector3 ObjectC_Pos;
        Vector3 ObjectD_Pos;

        public Game_01() {}

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
            
            
            turretSprite.Load("../Images/tankBlue_barrel1_outline.png");
            turretSprite.SetRotate(-90 * (float)(Math.PI / 180.0f));
            // set the turret offset from the tank base
            turretSprite.SetPosition(0, turretSprite.Width / 2.0f);

            // set up the scene object hierarchy - parent the turret to the base, 
            // then the base to the tank sceneObject
            turretObject.AddChild(turretSprite);
            tankObject.AddChild(tankSprite);
            tankObject.AddChild(turretObject);

            // having an empty object for the tank parent means we can set the 
            // position/rotation of the tank without
            // affecting the offset of the base sprite
            tankObject.SetPosition(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f);
            
            // scene objects coordination
            ObjectA_Pos = new Vector3(tankObject.globalTransform.m20 + 100, tankObject.globalTransform.m21 + 0, 0);
            ObjectB_Pos = new Vector3(tankObject.globalTransform.m20, tankObject.globalTransform.m21 - 150, 0);
            // define and update "Axis Aligned Bounding Boxes" objects
            PlayerAABB = new AABB();
            ObjectAABB = new AABB();
            UpdateCollisions();

            // debug objects coordination
            ObjectC_Pos = new Vector3(tankObject.globalTransform.m20 + 300, tankObject.globalTransform.m21 - 150, 0);
            ObjectD_Pos = new Vector3(tankObject.globalTransform.m20 + 25, tankObject.globalTransform.m21 + 200, 0);

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


            if (IsKeyDown(KeyboardKey.KEY_A)) {     tankObject.Rotate(-deltaTime);  }
            if (IsKeyDown(KeyboardKey.KEY_D)) {     tankObject.Rotate(deltaTime);   }
            
            if (IsKeyDown(KeyboardKey.KEY_W)) {
                CustomVector3 facing = new CustomVector3(
                                             tankObject.LocalTransform.m00,
                                             tankObject.LocalTransform.m01,
                                             0
                                             );
                facing *= deltaTime * Speed;
                tankObject.Translate(facing.x, facing.y);
            }

            if (IsKeyDown(KeyboardKey.KEY_S)) {
                CustomVector3 facing = new CustomVector3(
                                             tankObject.LocalTransform.m00,
                                             tankObject.LocalTransform.m01,
                                             0);
                facing *= deltaTime * -Speed;
                tankObject.Translate(facing.x, facing.y);
            }

            if (IsKeyDown(KeyboardKey.KEY_Q)) {     turretObject.Rotate(-deltaTime);    }
            if (IsKeyDown(KeyboardKey.KEY_E)) {     turretObject.Rotate(deltaTime);     }

            tankObject.Update(deltaTime);
        }


        public void Draw() {
            BeginDrawing();

            UpdateCollisions();
            // draw collision box
            PlayerAABB.debugBox2D(tempColor);

            ClearBackground(Color.BLACK);
            DrawText(fps.ToString(), 10, 10, 12, Color.RED);
            DrawText(tankObject.GlobalTransform.debug(), 0, 40, 18, Color.RED);
           
            tankObject.Draw();
            UpdateSceneObjects();
            
            EndDrawing();
        }

        public void UpdateCollisions() {
            PlayerAABB.UpdateBoxBoundries(
            new Vector3(tankObject.globalTransform.m20 - (tankSprite.Width / 2) - 10, tankObject.globalTransform.m21 - (tankSprite.Height / 2) - 10, 0),
            new Vector3(tankObject.globalTransform.m20 + (tankSprite.Width / 2) + 10, tankObject.globalTransform.m21 + (tankSprite.Height / 2) + 10, 0)
            );

            ObjectAABB.UpdateBoxBoundries(
                new Vector3(ObjectB_Pos.X - 40, (int)ObjectB_Pos.Y - 40, 0),
                new Vector3(ObjectB_Pos.X + 40, (int)ObjectB_Pos.Y + 40, 0)
            );
        }
        public void UpdateSceneObjects() {
            // ObjectA - point 
            DrawRectangle((int)ObjectA_Pos.X - 10, (int)ObjectA_Pos.Y - 10, 20, 20, Color.BLUE);
            
            // ObjectB - box object
            DrawRectangle((int)ObjectB_Pos.X - 40, (int)ObjectB_Pos.Y - 40, 80, 80, Color.GOLD);

            // check Overlaps functions and change the color
            CollisionDetected = PlayerAABB.Overlaps(new Vector3((int)ObjectA_Pos.X, (int)ObjectA_Pos.Y, 0)) || PlayerAABB.Overlaps(ObjectAABB);
            
            if (CollisionDetected)  tempColor = Color.RED;
            else                    tempColor = Color.GREEN;


            // //////////// debug
            // draw centre of box object
            DrawRectangle((int)ObjectAABB.Center().X - 5, (int)ObjectAABB.Center().Y - 5, 10, 10, Color.WHITE);
            
            // draw clamps
            tempVec = ObjectAABB.ClosestPoint(new Vector3 (tankObject.Location_X, tankObject.Location_Y, 0 )); // 
            DrawRectangle((int)tempVec.X, (int)tempVec.Y, 5, 5, Color.MAGENTA);
            DrawLine((int)tempVec.X, (int)tempVec.Y, (int)tankObject.Location_X, (int)tankObject.Location_Y, Color.DARKBLUE);

            ObjectAABB.UpdateBoxBoundries(
                new Vector3(ObjectC_Pos.X - 40, (int)ObjectC_Pos.Y - 240, 0),
                new Vector3(ObjectC_Pos.X + 40, (int)ObjectC_Pos.Y + 240, 0)
                );
            ObjectAABB.debugBox2D(Color.GRAY);
            tempVec = ObjectAABB.ClosestPoint(new Vector3(tankObject.Location_X, tankObject.Location_Y, 0));
            DrawRectangle((int)tempVec.X, (int)tempVec.Y, 5, 5, Color.MAGENTA);
            DrawLine((int)tempVec.X, (int)tempVec.Y, (int)tankObject.Location_X, (int)tankObject.Location_Y, Color.DARKBLUE);

            ObjectAABB.UpdateBoxBoundries(
                new Vector3(ObjectD_Pos.X - 240, (int)ObjectD_Pos.Y - 40, 0),
                new Vector3(ObjectD_Pos.X + 240, (int)ObjectD_Pos.Y + 40, 0)
                );
            ObjectAABB.debugBox2D(Color.GRAY);
            tempVec = ObjectAABB.ClosestPoint(new Vector3(tankObject.Location_X, tankObject.Location_Y, 0));
            DrawRectangle((int)tempVec.X, (int)tempVec.Y, 5, 5, Color.MAGENTA);
            DrawLine((int)tempVec.X, (int)tempVec.Y, (int)tankObject.Location_X, (int)tankObject.Location_Y, Color.DARKBLUE);

        }
    }
}

// https://www.raylib.com/cheatsheet/cheatsheet.html