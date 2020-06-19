#pragma once

#include <btBulletDynamicsCommon.h>

#include "Vec3.h"
#include "CollisionEntity.h"

namespace SSGE
{

/**
 * The PhysicsWorld exposes the Bullet Physics Engine
 */
class PhysicsWorld
{
protected:
	// TODO: Use multithread? (see bullet3/Extras/BulletMultiThreaded)

	/** World Gravity */
	Vec3 gravity;

	/** Bullet config */
	btDefaultCollisionConfiguration* config;

	/** Default collision dispatcher */
	btCollisionDispatcher* dispatcher;

	/** Broadphase */
	btBroadphaseInterface* broadphase;

	/** Constraint solver */
	btSequentialImpulseConstraintSolver* solver;

	/** Dynamic World */
	btDiscreteDynamicsWorld* world;

public:
	/**
	 * PhysicsWorld
	 */
	PhysicsWorld();

	/**
	 * PhysicsWorld
	 * 
	 * @param Vec3 _gravity Set the world gravity. Default is 0, -10, 0
	 */
	PhysicsWorld(Vec3 _gravity);

	/**
	 * Teardown
	 */
	~PhysicsWorld();

	/**
	 * Get the gravity
	 * 
	 * @return Vec3 Returns gravity
	 */
	Vec3 getGravity();

	/**
	 * Set the gravity
	 * 
	 * @param Vec3 _gravity New gravity
	 */
	void setGravity(Vec3 _gravity);

	/**
	 * Step the engine one frame
	 */
	void step();

	/**
	 * Add CollisionEntity to the physics world
	 * 
	 * @param CollisionEntity* entity Entity to add
	 */
	void PhysicsWorld::addEntity(CollisionEntity& entity);
};

} // namespace SSGE
