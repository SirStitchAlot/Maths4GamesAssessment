#pragma once

#include <raylib.h>
#include <raymath.h>
#include <iostream>
using namespace std;

#include "SceneObjects.h"

class SpriteObjects : public SceneObjects
{

/*=====================================^^todo^^=================================================*/
private:
	int def_Width = 0;
	int def_Height = 0;

	Texture2D texture = Texture2D();
	Image image = Image();
	
	float Width = texture.width;
	float Height = texture.height;








/*=====================================^^properties^^=================================================*/
public:
	SpriteObjects();

	~SpriteObjects();


/*=====================================^^structors^^=================================================*/

	virtual void Draw() override;
	
	void Load(string filename);

	void OnDraw() override;

	void Scale_Texture(float w, float h);

	void Scale_Reset();








/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/































};

