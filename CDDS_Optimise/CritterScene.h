#pragma once
#include "Scene.h"

class Critter;

class CritterScene :
    public Scene
{
public:
    //Override from scene.
    void start() override;
    void update(float deltaTime) override;

    /// <summary>
    /// Clears the screen of all critters. 
    /// </summary>
    void despawnCritters();
    

    /// <summary>
    /// Adds new critters equal to the critter count to the scene.
    /// </summary>
    void spawnCritters();

private:
    void clearDeletionList();

private:
    Critter* m_destroyer;
    float m_time;
    float m_despawnDelay = 3;
    float m_spawnDelay = 2;
    bool m_crittersDespawned;
    LinkedList<Critter*> m_deletionList = LinkedList<Critter*>();
};

