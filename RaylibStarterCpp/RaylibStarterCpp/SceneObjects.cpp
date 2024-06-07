#include "SceneObjects.h"

/*=====================================^^todo^^=================================================*/

SceneObjects::SceneObjects() {

	LocalTransform.MakeIdentity();

};

SceneObjects::~SceneObjects() {

	

};

/*=====================================^^structors^^=================================================*/

MathClasses::Matrix3 SceneObjects::GetLocalTransform()
{
	return LocalTransform.Transposed();
}

MathClasses::Matrix3 SceneObjects::GetGlobalTransform() 
{
	return GlobalTransform.Transposed();
}

void SceneObjects::Update(float  deltaTime) {};

void SceneObjects::Draw() {};












/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/




