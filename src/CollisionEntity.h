#pragma once

#include "Entity.h"

#include <btBulletDynamicsCommon.h>

namespace SSGE
{

/**
 * An CollisionEntity is an Entity attached to the physics engine
 */
class CollisionEntity : public Entity
{
protected:
	friend class PhysicsWorld;

	/** Mass. Set to 0 for a static object */
	float mass;

	/** Restitution */
	float restitution;

	/** Friction */
	float friction;

	/** Bullet Collision Shape */
	btCollisionShape* collisionShape;

	/** Bullet Motion State */
	btDefaultMotionState* motionState;

	/** Bullet Rigid Body */
	btRigidBody* rigidBody;

public:
	CollisionEntity();

	/**
	 * Get mass
	 * 
	 * @return float Returns the mass of the object
	 */
	float getMass();

	/**
	 * Set mass
	 * 
	 * @param float _mass New mass
	 */
	void setMass(float _mass);

	/**
	 * Get restitution
	 * 
	 * @return float Returns restitution
	 */
	float getRestitution();

	/**
	 * Set restitution
	 * 
	 * @param float _restitution New restition value
	 */
	void setRestitution(float _restitution);

	/**
	 * Get friction
	 * 
	 * @return float Returns friction
	 */
	float getFriction();

	/**
	 * Set friction
	 * 
	 * @param float _friction New restition value
	 */
	void setFriction(float _friction);
};

} // namespace SSGE
