#pragma once

#include <raymath.h>
#include <iostream>
#include <vector>
using namespace std;



class SceneObject{
public:	
	SceneObject();
	~SceneObject();

	SceneObject* parent = nullptr;
	vector<SceneObject> children;

	void Update();
	virtual void Draw();


	SceneObject GetChild(int index);
	int GetChildCount();
	void AddChild(SceneObject* child); 
};

