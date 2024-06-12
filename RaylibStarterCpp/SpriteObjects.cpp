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

	Vector2 vec{ vec.x = GlobalTransform.m7,vec.y = GlobalTransform.m8 };

		DrawTextureEx(texture,
		vec,
		rotation * (float)(180.0f / PI),
		1,
		WHITE
	);




}

/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/


