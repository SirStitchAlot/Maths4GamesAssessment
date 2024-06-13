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
	for( auto child :children )
	{
		child->parent = NULL;
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

SceneObjects* SceneObjects::GetParent() {

	return parent;

}

int SceneObjects::GetChildCount() {

	return children.size();


}

SceneObjects* SceneObjects::GetChild(int index) {

	return children[index];


}

void SceneObjects::AddChild(SceneObjects* child) {

	if (child->parent == nullptr); // make sure it doesn't have a parent already
		child->parent = this; // assign "this as parent
		children.push_back(child); // add new child to collection
	
};


void SceneObjects::Update(float deltatime) {
	OnUpdate(deltatime); // run OnUpdate behaviour

	// update children
	for(auto child : children)
	{
		child->Update(deltatime);
	}

};




void SceneObjects::Draw() {

	//run Ondraw
	OnDraw();

	//drawchildren

	for (auto child :children)
	{
		child->Draw();
	}

}

void SceneObjects::UpdateTransform() {

	if (parent != nullptr)
	{
		GlobalTransform = parent->GlobalTransform * LocalTransform;
	}
	else
	{
		GlobalTransform = LocalTransform;
	}

	for ( auto child : children )
	{
		child->UpdateTransform();
	}

}

void SceneObjects::SetPosition(float x, float y,float z) {

	LocalTransform.MakeTranslation(x,y,z);



}

void SceneObjects::SetRotate(float radians) {

	LocalTransform.MakeRotateZ(radians);
	UpdateTransform();
}

void SceneObjects::SetScale(float width, float height) {

	LocalTransform.MakeScale(width, height, 1);
	UpdateTransform();
}



void SceneObjects::Translation(float x, float y, float z) {

	LocalTransform.MakeTranslation(x, y, z);
	UpdateTransform();
}

void SceneObjects::Rotate(float radians) {

	LocalTransform.MakeRotateZ(radians);
	UpdateTransform();

}

//void SceneObjects::Scale(float width, float height) {
//
//	LocalTransform.MakeScale(width, height, 1);
//	UpdateTransform();
//
//	for (SceneObjects* child : children)
//	{
//		for (auto child : children) {
//			if (SceneObjects* spriteObject = dynamic_cast<>(child)) {
//				spriteObject->Scale_Texture(width, height);
//			}
//		}
//	}
//
//}










//no idea what this one is doing



/*=====================================^^methods^^=================================================*/







/*=====================================^^overloads^^=================================================*/




