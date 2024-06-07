#pragma once

#include <raymath.h>
#include <iostream>
#include "MathHeaders/Matrix3.h"
using namespace std;

#include "Helper.h"
class SceneObjects
{

	//figure out wth im supposed to do 

/*=====================================^^todo^^=================================================*/
private:

protected:
	MathClasses::Matrix3 LocalTransform;
	MathClasses::Matrix3 GlobalTransform;
	SceneObjects* parent = nullptr;






/*=====================================^^properties^^=================================================*/
public:
	SceneObjects();

	~SceneObjects();


/*=====================================^^structors^^=================================================*/

	MathClasses::Matrix3 GetLocalTransform();

	MathClasses::Matrix3 GetGlobalTransform();

	void Update(float deltaTime);

	void Draw();





/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/




};

