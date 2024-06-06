using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace RaylibStarterCS {
    class sampleTimer_01 {
        



        Stopwatch stopwatch = new Stopwatch();
        // https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.stopwatch?view=net-6.0
        // https://docs.microsoft.com/en-us/dotnet/api/system.diagnostics.stopwatch.elapsed?view=net-6.0

        private long currentTime = 0; 
        private long lastTime = 0; 
        private float deltaTime = 0.005f;


        public sampleTimer_01() {
            stopwatch.Start();
        }

        public void Reset() { stopwatch.Reset(); }
        public float Seconds {
            get { return stopwatch.ElapsedMilliseconds / 1000.0f; }
        }

        public float GetDeltaTime() { 
            lastTime = currentTime; 
            currentTime = stopwatch.ElapsedMilliseconds; 
            deltaTime = (currentTime - lastTime) / 1000.0f; 
            return deltaTime; 
        }

    }
}
