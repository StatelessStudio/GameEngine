#include "Entity.h"

namespace SSGE
{

Entity::Entity() :
	scale(Vec3(1, 1, 1))
{
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
