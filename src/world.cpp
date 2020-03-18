//world.cpp
//implementation of World class 


#include "world.h"




void World::addParticle(Mario* p)
{
    objects.push_back(p);
}

void World::runPhysics(float duration)
{
   for (int i = 0; i < objects.size(); ++i)
   {
       objects[i]->integrate(duration);
   }
}


