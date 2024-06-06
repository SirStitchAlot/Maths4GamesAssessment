#pragma once
#include "MathHeaders/Matrix3.h"
class SceneObjects
{

	//figure out wth im supposed to do 

/*=====================================^^todo^^=================================================*/
private:

protected:
	MathClasses::Matrix3 LocalTransform;
	MathClasses::Matrix3 GlobalTransform;






/*=====================================^^properties^^=================================================*/
public:
	SceneObjects();

	~SceneObjects();


/*=====================================^^structors^^=================================================*/

	void Update(float deltaTime);

	void Draw();





/*=====================================^^methods^^=================================================*/

/*=====================================^^overloads^^=================================================*/




};

