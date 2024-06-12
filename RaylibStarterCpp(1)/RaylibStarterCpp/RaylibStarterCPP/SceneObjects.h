#pragma once

#include <raymath.h>;
#include <iostream>;
#include "Matrix3.h";
#include <vector>;
using namespace std;


class SceneObjects
{

	//figure out wth im supposed to do 

/*=====================================^^todo^^=================================================*/
private:

protected:
	MathClasses::Matrix3 LocalTransform;
	MathClasses::Matrix3 GlobalTransform;
	SceneObjects* parent = nullptr;
	/*MathClasses::Vector3<SceneObjects> children;*/
	vector<SceneObjects> children;






/*=====================================^^properties^^=================================================*/
public:
	SceneObjects();

	~SceneObjects();


/*=====================================^^structors^^=================================================*/

	MathClasses::Matrix3 GetLocalTransform();

	MathClasses::Matrix3 GetGlobalTransform();

	void Update(float deltatime);

	virtual void Draw();

	virtual void OnUpdate(float deltatime);

	virtual void OnDraw();

	SceneObjects GetChild(int index);

	int GetChildCount();

	void AddChild(SceneObjects* child);

	void SetTranslation(float x, float y) {




	}

	//void RemoveChild(SceneObjects * child); // no idea what to do here

/*=====================================^^methods^^=================================================*/


	

/*=====================================^^overloads^^=================================================*/




};

