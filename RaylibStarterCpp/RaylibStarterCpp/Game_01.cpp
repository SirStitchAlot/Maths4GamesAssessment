#include "Game_01.h"

/*=====================================^^todo^^=================================================*/

Game_01::Game_01() {
}

Game_01::~Game_01() {
}


/*=====================================^^structors^^=================================================*/

void Game_01::Init() {

	SetTargetFPS(60);

	// set up the scene object hierarchy - parent the turret to the base, 
	// then the base to the tank sceneObject
	tankObject->AddChild(tankSprite);
}

void Game_01::Update() {
	// detect keyboard input
	if (IsKeyDown(KEY_A)) // code;
		if (IsKeyDown(KEY_D)) // code;
			if (IsKeyDown(KEY_W)) // code;
				if (IsKeyDown(KEY_S)) // code;

					tankObject->Update();

}

void Game_01::Draw() {
	tankObject->Draw();
}







/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/












