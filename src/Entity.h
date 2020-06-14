#pragma once

#include "Vec3.h"
#include "Node.h"

namespace SSGE
{

/**
 * An Entity is a Node which represents a type of object in space
 */
class Entity : public Node
{
protected:
	/** Scale */
	Vec3 scale;

public:
	Entity();

	/**
	 * Get scale
	 * 
	 * @return Vec3 Returns the object's scale
	 */
	Vec3 getScale();

	/**
	 * Set scale
	 * 
	 * @param Vec3 _scale New scale
	 */
	void setScale(Vec3 _scale);
};

} // namespace SSGE
