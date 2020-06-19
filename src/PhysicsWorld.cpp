#include "PhysicsWorld.h"

namespace SSGE
{

PhysicsWorld::PhysicsWorld() : PhysicsWorld(Vec3(0, -10, 0))
{
}

PhysicsWorld::PhysicsWorld(Vec3 _gravity)
{
	gravity = _gravity;
	config = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(config);
	broadphase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver;
	world = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, config);
	world->setGravity(_gravity);
}

Vec3 PhysicsWorld::getGravity()
{
	return gravity;
}

void PhysicsWorld::setGravity(Vec3 _gravity)
{
	world->setGravity(_gravity);
	gravity = _gravity;
}

void PhysicsWorld::addEntity(CollisionEntity& entity)
{
	// TODO: Make sure we clean this stuff up!
	entity.collisionShape = new btBoxShape(entity.scale);

	// Create start transform
	btTransform startTransform;
	btVector3 localInertia(0, 0, 0);

	startTransform.setIdentity();
	startTransform.setOrigin(entity.position);

	if (entity.mass > 0) {
		entity.collisionShape->calculateLocalInertia(
			entity.mass,
			localInertia
		);
	}

	// Create motion state
	entity.motionState = new btDefaultMotionState(startTransform);

	// Create rigid body
	btRigidBody::btRigidBodyConstructionInfo rbInfo(
		entity.mass,
		entity.motionState,
		entity.collisionShape,
		localInertia
	);
	entity.rigidBody = new btRigidBody(rbInfo);
	entity.rigidBody->setRestitution(entity.restitution);
	entity.rigidBody->setFriction(entity.friction);
	entity.rigidBody->setUserPointer(&entity);

	// Add to the world
	world->addRigidBody(entity.rigidBody);
}

void PhysicsWorld::step()
{
	// TODO: Get screen refresh rate or delta time
	world->stepSimulation(1.f / 60.f, 10);

	// Update objects
	int nObjects = world->getNumCollisionObjects();
	for (int i = nObjects - 1; i >= 0; i--) {
		btCollisionObject* obj = world->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		btTransform trans;

		if (body && body->getMotionState()) {
			body->getMotionState()->getWorldTransform(trans);
		}
		else {
			trans = obj->getWorldTransform();
		}

		// Propogate to CollisionEntity
		CollisionEntity* entity = (CollisionEntity*) body->getUserPointer();
		entity->position = Vec3(trans.getOrigin());
		// TODO: Set orientation?
	}
}

PhysicsWorld::~PhysicsWorld()
{
	// Delete Collision Shapes, Rigid Bodies, and Motion States
	int nCollisionObjects = world->getNumCollisionObjects();
	for (int i = nCollisionObjects - 1; i >= 0; i--) {
		btCollisionObject* obj = world->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);

		if (body && body->getMotionState()) {
			delete body->getMotionState();
		}

		CollisionEntity* entity = (CollisionEntity*) body->getUserPointer();
		delete entity->collisionShape;

		world->removeCollisionObject(obj);
		delete obj;
	}

	delete world;
	delete solver;
	delete broadphase;
	delete dispatcher;
	delete config;
}

} // namespace SSGE
