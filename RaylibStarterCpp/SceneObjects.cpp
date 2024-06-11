#include "SceneObjects.h"

/*=====================================^^todo^^=================================================*/

SceneObjects::SceneObjects() {

	LocalTransform.MakeIdentity();

};

SceneObjects::~SceneObjects() {
	if (parent !=NULL)
	{
		delete parent;
		parent = nullptr;
	}
	for( SceneObjects so :children )
	{
		so.parent = NULL;
	}
	

};

/*=====================================^^structors^^=================================================*/

MathClasses::Matrix3 SceneObjects::GetLocalTransform()
{
	return LocalTransform;
}

MathClasses::Matrix3 SceneObjects::GetGlobalTransform() 
{
	return GlobalTransform;
}

void SceneObjects::Update(float deltatime) {
	OnUpdate(deltatime); // run OnUpdate behaviour

	// update children
	for(SceneObjects child : children)
	{
		child.Update(deltatime);
	}

};


void SceneObjects::Draw() {

	//run Ondraw
	OnDraw();

	//drawchildren

	for (SceneObjects child :children)
	{
		child.Draw();
	}

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



//no idea what this one is doing

//void SceneObjects::RemoveChild(SceneObjects child) {
//
//	if (children
//	{
//
//	}
//
//}

/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/




