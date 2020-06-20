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
	/** ID */
	unsigned long id;

	/** ID can only be received if set */
	bool hasId;

	/** Scale */
	Vec3 scale;

public:
	Entity();

	/**
	 * Get ID
	 * 
	 * @return {unsigned int} Returns the entity id
	 * @throws SSGE::Exception if the value has not been set
	 */
	unsigned int getId();

	/**
	 * Set ID
	 * 
	 * @param {unsigned int} id New ID
	 */
	void setId(unsigned int _id);

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
