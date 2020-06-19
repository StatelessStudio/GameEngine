#include <iostream>
#include <SSGE/Engine.h>
#include <SSGE/CollisionEntity.h>
#include <SSGE/PhysicsWorld.h>

int main()
{
    SSGE::Engine engine;
    SSGE::PhysicsWorld physicsWorld;

    // A box to drop
    SSGE::CollisionEntity ent1;
    ent1.setPosition(SSGE::Vec3(5, 5, 5));
    ent1.setMass(1);

    physicsWorld.addEntity(ent1);

    // A floor for the box to land on
    SSGE::CollisionEntity ent2;
    ent2.setPosition(SSGE::Vec3(5, -5, 5));
    ent2.setScale(SSGE::Vec3(100, 1, 100));

    physicsWorld.addEntity(ent2);

    // Run simulation
    for (int i = 0; i < 150; i++) {
        physicsWorld.step();
        
        SSGE::Vec3 pos = ent1.getPosition();
        std::cout << "Position: (" << pos.x << ", " << pos.y << ", " << pos.z <<
            ")" << std::endl;
    }

}
