#pragma once

#include <raymath.h>
#include <iostream>
using namespace std;

#include "SceneObjects.h"
#include "Helper.h"
class SpriteObjects : public SceneObjects
{

/*=====================================^^todo^^=================================================*/
private:
	int def_Width = 0;
	int def_height = 0;

	Texture2D texture = Texture2D();
	Image image = Image();







/*=====================================^^properties^^=================================================*/
public:
	SpriteObjects();

	~SpriteObjects();


/*=====================================^^structors^^=================================================*/

	void Load(string filename);








/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/































};

