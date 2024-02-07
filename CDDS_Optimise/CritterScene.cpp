#include "CritterScene.h"
#include <raymath.h>
#include "CritterManager.h"
#include "Engine.h"

const unsigned int CRITTER_COUNT = 1000;

void CritterScene::start()
{
    srand(time(NULL));

    // Calculate new random velocity to assign to the destroyer.
    Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
    velocity = Vector2Scale(Vector2Normalize(velocity), Critter::getMaxSpeed());

    //Initialize destroyer critter
    m_destroyer = new Critter(Vector2{ (float)(Engine::getScreenWidth() / 2), (float)(Engine::getScreenHeight() / 2)}, velocity, 75, "res/9.png");
    m_destroyer->setIsDestroyer(true);

    addCritter(m_destroyer);

    //Spawn the smaller critter that will be eaten.
    spawnCritters();
}

void CritterScene::update(float deltaTime)
{
    Scene::update(deltaTime);

    // Loop through the critter list to check if they are colliding with the destroyer.
    for (Iterator<Critter*> iter = getCritterList()->begin(); iter != getCritterList()->end(); ++iter)
    {
        Critter* critter = *iter;
        //If the critter isn't in the scene or if it is marked as the destroyer...
        if (!critter->isActive() || critter == m_destroyer)
            //...skip it.
            continue;

        // Despawn any critter touching the destroyer using circle collision detection.
        float dist = Vector2Distance(critter->GetPosition(), m_destroyer->GetPosition());
        if (dist < critter->getRadius() + m_destroyer->getRadius())
        {
            // DESPAWN CRITTER HERE
            m_deletionList.pushBack(*iter);
        }
    }
    
    clearDeletionList();

    //Increment timer for spawning/despawning waves of critters.
    m_time += deltaTime;

    //If the time has passed the delay for despawning all critters and the critters are active in the scene...
    if (m_time >= m_despawnDelay && !m_crittersDespawned)
    {
        //...despawn them and reset the timer.
        despawnCritters();
        m_crittersDespawned = true;
        m_time = 0;
    }

    //If the time has passed the delay for spawning all critters and the critters aren't active in the scene...
    if (m_time >= m_spawnDelay && m_crittersDespawned)
    {
        //...spawn them in again and reset the timer.
        spawnCritters();
        m_crittersDespawned = false;
        m_time = 0;
    }
}

void CritterScene::spawnCritters()
{
    for (int i = 0; i < CRITTER_COUNT; i++)
    {
        // create a random direction vector for the velocity
        Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
        // normalize and scale by a random speed
        velocity = Vector2Scale(Vector2Normalize(velocity), Critter::getMaxSpeed());

        Vector2 position = { (float)(5 + rand() % (Engine::getScreenWidth() - 10)), (float)(5 + (rand() % Engine::getScreenHeight() - 10)) };

        // SPAWN CRITTER HERE
        Critter* critter = new Critter(position, velocity, 20, "res/10.png");

        if (!getCritterList()->contains(critter))
            addCritter(critter);
    }
}

void CritterScene::clearDeletionList()
{
    Critter* critterToDelete = nullptr;
    int length = m_deletionList.getLength();

    for (int i = 0; i < length; i++)
    {
        critterToDelete = m_deletionList.popBack();
        getCritterList()->remove(critterToDelete);
        delete critterToDelete;
    }

    m_deletionList.destroy();
}

void CritterScene::despawnCritters()
{
    for (Iterator<Critter*> iter = getCritterList()->begin(); iter != getCritterList()->end(); ++iter)
    {
        Critter* critter = *iter;

        //If the critter is the destroyer...
        if (critter->getIsDestroyer())
            //..skip it so only the smaller ones are despawned.
            continue;

        // DESPAWN CRITTERS HERE
        delete critter;
    }

    //DELETE THIS WHEN THE OBJECT POOL IS IMPLEMENTED
    getCritterList()->destroy();
    getCritterList()->pushBack(m_destroyer);
}
