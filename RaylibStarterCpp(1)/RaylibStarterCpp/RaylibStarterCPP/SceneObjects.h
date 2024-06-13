#pragma once

#include <raymath.h>;
#include <iostream>;
#include "Matrix3.h";
#include <vector>;
#include <cmath>




class SceneObjects
{

	//figure out wth im supposed to do 

/*=====================================^^todo^^=================================================*/
private:

protected:
	MathClasses::Matrix3 LocalTransform;
	MathClasses::Matrix3 GlobalTransform;

	SceneObjects* parent = nullptr;
	std::vector<SceneObjects*> children;
	






/*=====================================^^properties^^=================================================*/
public:
	SceneObjects();

	~SceneObjects();


/*=====================================^^structors^^=================================================*/

	MathClasses::Matrix3 GetLocalTransform();

	MathClasses::Matrix3 GetGlobalTransform();

	SceneObjects* GetParent();

	int GetChildCount();

	SceneObjects* GetChild(int index);

	void AddChild(SceneObjects* child);

	void Update(float deltatime);

	virtual void Draw();

	virtual void OnUpdate(float deltatime);

	virtual void OnDraw();

	void UpdateTransform();

	void SetPosition(float x, float y, float z);

	void SetRotate(float radians);

	void SetScale(float width, float height);

	void Translation(float x, float y,float z);

	void Rotate(float radians);

	void Scale(float width, float height); //leavig this for now since i dont know what to do lol



	//void RemoveChild(SceneObjects * child); // no idea what to do here

/*=====================================^^methods^^=================================================*/


	

/*=====================================^^overloads^^=================================================*/




};

