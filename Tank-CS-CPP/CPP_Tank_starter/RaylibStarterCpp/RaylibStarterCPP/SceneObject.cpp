#include "SceneObject.h"

SceneObject::SceneObject(){
}

SceneObject::~SceneObject(){
	// 1 - remove children from parent
	// code
	// 2 - delete pointer
	delete parent;
	parent = nullptr;

	// do the same for each elements in children vector
}

void SceneObject::Update(){
}

void SceneObject::Draw(){
}

SceneObject SceneObject::GetChild(int index){
	return children[index];
}

int SceneObject::GetChildCount(){
	return children.size();
}


void SceneObject::AddChild(SceneObject* child){
	if (child != nullptr) {
		child->parent = this; // assign this object as parent
		children.push_back(*child); // add new child to children vector
		cout << " -- SceneObject set in children vector-- " << endl;
	}
}
