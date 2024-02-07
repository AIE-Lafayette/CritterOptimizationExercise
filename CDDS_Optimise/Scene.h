#pragma once
#include "Critter.h"
#include "LinkedList.h"

class Scene
{
public:

	/// <summary>
	/// Called when the game starts.
	/// </summary>
	virtual void start();
	/// <summary>
	/// Called every time the game loops. Mainly used to update game logic.
	/// </summary>
	/// <param name="deltaTime">The amount of time that has passed between this frame and the last.</param>
	virtual void update(float deltaTime);
	/// <summary>
	/// Called every time the game loops. Mainly used to update game visuals.
	/// </summary>
	virtual void draw();
	/// <summary>
	/// Called when the application is about to exit.
	/// </summary>
	virtual void end();

	/// <summary>
	/// Adds a critter to the scene list. The scene calls this critter's update and draw.
	/// </summary>
	/// <param name="critter">A reference to the critter to add to the scene.</param>
	void addCritter(Critter* critter) { m_critters.pushBack(critter); }

protected:
	/// <summary>
	/// Gets the list of all critters in the scene.
	/// </summary>
	/// <returns></returns>
	LinkedList<Critter*>* getCritterList() { return &m_critters; }

private:
	LinkedList<Critter*> m_critters;
};

