#include "CollisionEntity.h"

namespace SSGE
{

CollisionEntity::CollisionEntity() :
	mass(0),
	restitution(0.25),
	friction(0.5)
{
}

float CollisionEntity::getMass()
{
	return mass;
}

void CollisionEntity::setMass(float _mass)
{
	mass = _mass;
}

float CollisionEntity::getRestitution()
{
	return restitution;
}

void CollisionEntity::setRestitution(float _restitution)
{
	restitution = _restitution;
}

float CollisionEntity::getFriction()
{
	return friction;
}

void CollisionEntity::setFriction(float _friction)
{
	friction = _friction;
}

} // namespace SSGE
