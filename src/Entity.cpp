#include "Entity.h"
#include "Exception.h"

namespace SSGE
{

Entity::Entity() :
	id(0),
	hasId(false),
	scale(Vec3(1, 1, 1))
{
}

unsigned int Entity::getId()
{
	if (hasId) {
		throw SSGE::Exception("ID has not been set for entity");
	}

	return id;
}

void Entity::setId(unsigned int _id)
{
	id = _id;
	hasId = true;
}

Vec3 Entity::getScale()
{
	return scale;
}

void Entity::setScale(Vec3 _scale)
{
	scale = _scale;
}

} // namespace SSGE
