#include "SpriteObjects.h"
#include <iostream>
/*=====================================^^todo^^=================================================*/

SpriteObjects::SpriteObjects() {

	Width = texture.width;
	Height = texture.height;

}

SpriteObjects::~SpriteObjects() {}

/*=====================================^^structors^^=================================================*/

 

void SpriteObjects::Draw(){




}

void SpriteObjects::Load(string filename)
{
	const char* conversion = filename.c_str();

	Image img = LoadImage(conversion);
	texture = LoadTextureFromImage(img);
	

}

void SpriteObjects::OnDraw()  {

	float rotation = (float)atan2(GlobalTransform.m2, GlobalTransform.m1);

	Vector2(GlobalTransform.m7,GlobalTransform.m8) uhh;

	DrawTextureV(texture,
		Vector2 (GlobalTransform.m7,GlobalTransform.m8), //csharp version passes two floats ( but theres no constructor for it apprently )
		WHITE
	);




}

/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/


