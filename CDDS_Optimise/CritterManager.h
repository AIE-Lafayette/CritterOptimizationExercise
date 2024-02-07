#pragma once
#include "ObjectPool.h"
#include "raymath.h"

class Critter;
class CritterManager
{

public:
	Critter* spawnCritter(Vector2 position, Vector2 velocity, const char* texturePath);
	void despawnCritter(Critter* critter);
};

