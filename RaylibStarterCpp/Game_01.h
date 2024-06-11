#pragma once

#include <iostream>
#include <raymath.h> 
#include "SceneObjects.h"
#include "SpriteObjects.h"



class Game_01
{

/*=====================================^^todo^^=================================================*/
private:

	long CurrentTime = 0;

	long LastTime = 0;

	float timer = 0;

	int fps = 1;

	int frames;

	float deltaTime = 0.005f;

	float m_timer = 0;

	float speed = 100.0f;

	float scale_multi = .5f;

	bool scale_active = false;

	SceneObjects * tankObject = new SceneObjects();

	SpriteObjects * tankSprite = new SpriteObjects();






/*=====================================^^properties^^=================================================*/
public:

	Game_01();

	~Game_01();

/*=====================================^^structors^^=================================================*/

	void Init();

	void Shutdown();

	void Update();

	void Draw();


/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/












};

