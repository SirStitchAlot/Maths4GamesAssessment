#pragma once

#include <raymath.h>
#include <iostream>
using namespace std;

#include "SceneObject.h"


class SpriteObject : public SceneObject {
public:
	SpriteObject();
	~SpriteObject();

	// vars
	Texture2D texture = Texture2D();
	Image image = Image();

	int def_Width = 0;
	int def_Height = 0;

	float Width;
	float Height;

	virtual void Draw() override;

	void Load(string filename);

};

