#ifndef _cShapeFactory_HG_
#define _cShapeFactory_HG_

#include "iShape.h"

#include <string>
#include <vector>

class cGameObject;

class cShapeFactory
{
public:
	iShape* CreateShape(std::string objType, cGameObject* newObj);

	void AssembleShape(iShape* pNewObject, std::string objType, cGameObject* newObj);

	void physicsStep(double deltaTime);

private:
	std::vector <iShape*> vec_pShapes;
};


#endif