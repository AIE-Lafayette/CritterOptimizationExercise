#include "Scene.h"
#include <stdlib.h>
#include <raymath.h>

void Scene::start()
{
}

void Scene::update(float deltaTime)
{
    for (Iterator<Critter*> iter = m_critters.begin(); iter != m_critters.end(); ++iter)
    {
        Critter* critter = *iter;

        if (!critter->isActive())
            continue;

        (*iter)->Update(deltaTime);
    }

    // check for critter-on-critter collisions
    for (Iterator<Critter*> critter1 = m_critters.begin(); critter1 != m_critters.end(); ++critter1)
    {
        for (Iterator<Critter*> critter2 = m_critters.begin(); critter2 != m_critters.end(); ++critter2) {
            if (critter1 == critter2 || (*critter1)->IsDirty()) // note: the other critter (j) could be dirty - that's OK
                continue;

            if ((*critter1)->getIsDestroyer() || (*critter2)->getIsDestroyer())
                continue;

            // check every critter against every other critter
            float dist = Vector2Distance((*critter1)->GetPosition(), (*critter2)->GetPosition());
            if (dist < (*critter1)->getRadius() + (*critter2)->getRadius())
            {
                // collision!
                // do math to get critters bouncing
                Vector2 normal = Vector2Normalize(Vector2Subtract((*critter2)->GetPosition(), (*critter1)->GetPosition()));

                // not even close to real physics, but fine for our needs
                (*critter1)->setMoveDirection(Vector2Scale(normal, -1));
                // set the critter to *dirty* so we know not to process any more collisions on it
                (*critter1)->SetDirty();

                // we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
                // to make sure the other critter is clean before we do the collision response
                if (!(*critter2)->IsDirty()) {
                    (*critter2)->setMoveDirection(normal);
                    (*critter2)->SetDirty();
                }
                break;
            }
        }
    }

}

void Scene::draw()
{
    for (Iterator<Critter*> iter = m_critters.begin(); iter != m_critters.end(); ++iter)
    {
        Critter* critter = *iter;

        if (!critter->isActive())
            continue;

        (*iter)->Draw();
    }
}

void Scene::end()
{
    for (Iterator<Critter*> iter = m_critters.begin(); iter != m_critters.end(); ++iter)
    {
        Critter* critter = *iter;
        delete critter;
    }
}
