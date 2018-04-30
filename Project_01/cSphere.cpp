#include "cSphere.h"
#include "cGameObject.h"

cSphere::cSphere()
{
	this->Alerter = cCollisionAlert::getInstance();
	return;
}

cSphere::~cSphere()
{
	return;
}

void cSphere::physicsStep(double deltaTime)
{
	if (!this->pObject->bIsUpdatedInPhysics)
		return;

	const glm::vec3 GRAVITY = glm::vec3(0.0f, -2.0f, 0.0f);

	glm::vec3 deltaPosition = (float)deltaTime * this->pObject->vel;
	this->pObject->position += deltaPosition;

	// New velocity is based on acceleration over time
	glm::vec3 deltaVelocity = ((float)deltaTime * this->pObject->accel)
		+ ((float)deltaTime * GRAVITY);

	this->pObject->vel += deltaVelocity;

	if (pObject->position.y < -30.0f)
	{
		this->pObject->position = startPos;
		this->pObject->vel = glm::vec3(0.0f);
		this->pObject->accel = glm::vec3(0.0f);
	}

	return;
}

int cSphere::shapeType()
{
	return 2;
}

void cSphere::setVelocity(glm::vec3 newVelocity)
{
	this->pObject->vel = newVelocity;
}

void cSphere::setPosition(glm::vec3 newPos)
{
	this->pObject->position = newPos;
}

glm::vec3 cSphere::getVelocity()
{
	return this->pObject->vel;
}

glm::vec3 cSphere::getPosition()
{
	return this->pObject->position;
}

void cSphere::issueAlert(int pos1, int pos2, int type2)
{
	Alerter->makeAlert(pos1, pos2, this->shapeType(), type2);
	return;
}