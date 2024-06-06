using System;
using Raylib_cs;

namespace RaylibStarterCS
{
	class Program{
		static void Main(string[] args){
            //Game game = new Game();
            Game_01 game_01 = new Game_01();
            sampleTimer_01 customTimer_01 = new sampleTimer_01();

            Raylib.InitWindow(800, 600, "Hello World");

            float elapsedSeconds = customTimer_01.Seconds;

            //game.Init();
            game_01.Init();

            while (!Raylib.WindowShouldClose()){
                //game.Update();
                //game.Draw();                

                game_01.Update();
                game_01.Draw();
            }



            //game.Shutdown();
            game_01.Shutdown();

            Raylib.CloseWindow();
        }
	}
}
