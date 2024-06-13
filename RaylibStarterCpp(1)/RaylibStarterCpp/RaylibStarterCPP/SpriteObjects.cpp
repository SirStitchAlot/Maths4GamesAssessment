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

	def_Width = texture.width;
	def_Height = texture.height;
							  

}

void SpriteObjects::OnDraw() {

	float rotation = (float)atan2(GlobalTransform.m2, GlobalTransform.m1);

	Vector2 vec{ vec.x = GlobalTransform.m7,vec.y = GlobalTransform.m8 };

	DrawTextureEx(texture,
		vec,
		rotation * (float)(180.0f / PI),
		1,
		WHITE
	);
}

void SpriteObjects::Scale_Texture(float w, float h) {
		
	texture.width = (int)(texture.width * w);
	texture.height = (int)(texture.height * h);
		
}

void SpriteObjects::Scale_Reset() {

	texture.width = def_Width;
	texture.height = def_Height;


}




/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/


