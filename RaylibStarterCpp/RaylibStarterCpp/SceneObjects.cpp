#include "SceneObjects.h"

/*=====================================^^todo^^=================================================*/

SceneObjects::SceneObjects() {

	LocalTransform.MakeIdentity();

};

SceneObjects::~SceneObjects() {

	delete parent;
	parent = nullptr;

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

void SceneObjects::Update() {};

void SceneObjects::Draw() {


}

SceneObjects SceneObjects::GetChild(int index)
{
	return children[index];
}

int SceneObjects::GetChildCount()
{
	return children.size();
}

void SceneObjects::AddChild(SceneObjects* child)
{
	if (child->parent != nullptr)
	{
		child->parent = this;
		children.push_back(*child);
		cout << " -- SceneObject set in children vector-- " << endl;

	}




}

/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/




