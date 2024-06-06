using System;
using Raylib_cs;

namespace Matrix_01 {
    class Program {
        static void Main(string[] args) {
            // init objects
            Raylib.InitWindow(640, 480, "Matrix Transformation - Math - AIE");
            Game_01 GM = new Game_01();
            GM.Init();

            // run
            while (!Raylib.WindowShouldClose()) {
                GM.Update();
                GM.Draw();
            }

            // exit 
            GM.Shutdown();
            Raylib.CloseWindow();
        }
    }
}
