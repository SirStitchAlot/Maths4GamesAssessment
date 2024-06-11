#pragma once

#include <raymath.h>
#include <iostream>
using namespace std;

#include "SceneObjects.h"

class SpriteObjects : public SceneObjects
{

/*=====================================^^todo^^=================================================*/
private:
	int def_Width = 0;
	int def_height = 0;

	Texture2D texture = Texture2D();
	Image image = Image();
	
	float Width;
	float Height;








/*=====================================^^properties^^=================================================*/
public:
	SpriteObjects();

	~SpriteObjects();


/*=====================================^^structors^^=================================================*/

	virtual void Draw() override;
	
	void Load(string filename);








/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/































};

