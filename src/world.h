//World.h
#include <vector>

#ifndef WORLD_H
#define WORLD_H



//#include "particle.h"
#include "mario.h"

    
    class World
    {
    
    public:
       std::vector<Mario*> objects;
	   void addParticle(Mario* p);
	   void runPhysics(float time);
        
    };


#endif 