#include "cCrazySphere.h"
#include "cGameObject.h"

cCrazySphere::cCrazySphere()
{
	this->Alerter = cCollisionAlert::getInstance();
	return;
}

cCrazySphere::~cCrazySphere()
{
	return;
}

void cCrazySphere::physicsStep(double deltaTime)
{
	if (!this->pObject->bIsUpdatedInPhysics)
		return;

	const glm::vec3 GRAVITY = glm::vec3(0.7f, -2.0f, 0.0f);

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

int cCrazySphere::shapeType()
{
	return 3;
}

void cCrazySphere::setVelocity(glm::vec3 newVelocity)
{
	float r = ((float)rand() / (RAND_MAX));
	float g = ((float)rand() / (RAND_MAX));
	float b = ((float)rand() / (RAND_MAX));
	this->pObject->vel = newVelocity;
	this->pObject->diffuseColour.r = r;
	this->pObject->diffuseColour.g = g;
	this->pObject->diffuseColour.b = b;
}

void cCrazySphere::setPosition(glm::vec3 newPos)
{
	this->pObject->position = newPos;
}

glm::vec3 cCrazySphere::getVelocity()
{
	return this->pObject->vel;
}

glm::vec3 cCrazySphere::getPosition()
{
	return this->pObject->position;
}

void cCrazySphere::issueAlert(int pos1, int pos2, int type2)
{
	Alerter->makeAlert(pos1, pos2, this->shapeType(), type2);
	return;
}