using System;
using System.Collections.Generic;
using System.Text;

namespace RaylibStarterCS {
    class Game_02 {
        public Game_02() { }

        sampleTimer_01 gameTime = new sampleTimer_01();
        private float timer = 0;
        private int fps = 1;
        private int frames;
        private float deltaTime;

        public void Update() {
            deltaTime = gameTime.GetDeltaTime();
            timer += deltaTime; 
            if (timer >= 1) { 
                fps = frames; 
                frames = 0; 
                timer -= 1; 
            }
            frames++;
            
            // insert game logic here
        }
    }
}
