#pragma once

#include "Vec3.h"

namespace SSGE
{

/**
 * A Node is a point in space, with a position & rotation
 */
class Node
{
protected:
	/** Position */
	Vec3 position;

	/** Rotation */
	Vec3 rotation;

public:
	Node();

	/**
	 * Get position
	 *
	 * @return Vec3 Returns the Node's position
	 */
	Vec3 getPosition();

	/**
	 * Set position
	 * 
	 * @param Vec3 _position New Node position
	 */
	void setPosition(Vec3 _position);

	/**
	 * Translate (or move) the Node
	 * 
	 * @param Vec3 _translation Vector to add to the current position
	 */
	void translate(Vec3 _translation);

	/**
	 * Get rotation
	 * 
	 * @return Vec3 Returns the Node's rotation
	 */
	Vec3 getRotation();

	/**
	 * Set rotation
	 * 
	 * @param Vec3 _rotation New rotation
	 */
	void setRotation(Vec3 _rotation);

	/**
	 * Add rotation to current value
	 * 
	 * @param Vec3 _rotation Rotation value
	 */
	void rotate(Vec3 _rotation);
};

} // namespace SSGE
