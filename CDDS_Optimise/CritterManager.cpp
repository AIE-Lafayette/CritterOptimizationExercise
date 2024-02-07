#include "CritterManager.h"
#include "Critter.h"

CritterManager::CritterManager()
{
    //Initialize object pool here.
}

Critter* CritterManager::spawnCritter(Vector2 position, Vector2 velocity, const char* texturePath)
{
    //Try to get a critter from the pool.

    //If there isn't a critter in the pool...
        //...create one.
    //Otherwise...
        //...call the critters initialize function again.

    //Make the critter active so it can update and draw.

    //Return the critter.
}

void CritterManager::despawnCritter(Critter* critter)
{
    //Set the critter to inactive so that it doesn't update and draw.
    //Place it back in the pool.
}
