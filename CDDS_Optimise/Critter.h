#pragma once


#include "raylib.h"
#include <stdio.h>

class Critter
{
protected:	
	Vector2 m_position;
	Vector2 m_velocity;
	float m_radius;

	Texture2D m_texture;

	bool m_isLoaded;
	bool m_isDirty;		// indicates if we've already processed a collision response for this critter
	
public:
	Critter();

	/// <param name="position">The pixel position of the critter.</param>
	/// <param name="velocity">The speed and direction the critter will travel in.</param>
	/// <param name="radius">The size of the critter texture and collider.</param>
	/// <param name="texturePath">The location of the critter texture to load.</param>
	Critter(Vector2 position, Vector2 velocity, float radius, const char* texturePath);

	~Critter();


	/// <param name="position">The pixel position of the critter.</param>
	/// <param name="velocity">The speed and direction the critter will travel in.</param>
	/// <param name="radius">The size of the critter texture and collider.</param>
	/// <param name="texturePath">The location of the critter texture to load.</param>
	void Init(Vector2 position, Vector2 velocity, float radius, const char* texturePath);

	/// <summary>
	/// Called once per frame by the scene. Used to update position.
	/// </summary>
	void Update(float dt);
	/// <summary>
	/// Called once per frame by the scene. Used to draw the texture.
	/// </summary>
	void Draw();

	/// <summary>
	/// The x position in relation to the window.
	/// </summary>
	float GetX() { return m_position.x; }
	/// <summary>
	/// The y position in relation to the window.
	/// </summary>
	float GetY() { return m_position.y; }

	/// <summary>
	/// Changes the x position in relation to the window.
	/// </summary>
	void SetX(float x) { m_position.x = x; }
	/// <summary>
	/// Changes the y position in relation to the window.
	/// </summary>
	void SetY(float y) { m_position.y = y; }


	/// <summary>
	/// Changes the size of the texture and collider.
	/// </summary>
	void setRadius(float radius) { m_radius = radius; }

	/// <summary>
	/// Gets the size of the texture and collider.
	/// </summary>
	float getRadius() { return m_radius; }


	/// <summary>
	/// Get whether or not this critter is the one that can despawn others.
	/// </summary>
	bool getIsDestroyer() { return m_isDestroyer; }
	/// <summary>
	/// Set whether or not this critter is the one that can despawn others.
	/// </summary>
	void setIsDestroyer(bool value) { m_isDestroyer = value; }


	/// <summary>
	/// Get the position of the critter in relation to the screen.
	/// </summary>
	Vector2 GetPosition() { return m_position; }

	/// <summary>
	/// Set the position of the critter in relation to the screen.
	/// </summary>
	void SetPosition(Vector2 position) { m_position = position; }


	/// <summary>
	/// Get the speed and direction of the critter.
	/// </summary>
	Vector2 GetVelocity() { return m_velocity; }
	/// <summary>
	/// Set the speed and direction of the critter.
	/// </summary>
	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }

	/// <summary>
	/// Changes the velocity of the critter so that it moves in the given direction at max speed.
	/// </summary>
	void setMoveDirection(Vector2 direction);

	bool IsDead() { return m_isLoaded == false; }


	bool IsDirty() { return m_isDirty; }
	void SetDirty() { m_isDirty = true; }

	/// <summary>
	/// Sets whether or not this critter will be updated or drawn.
	/// </summary>
	void setActive(bool value) { m_isLoaded = value; }

	/// <summary>
	/// Gets whether or not this critter will be updated or drawn.
	/// </summary>
	bool isActive() { return m_isLoaded; }

	bool operator == (Critter other);

	/// <summary>
	/// Gets the maximum speed of all critters.
	/// </summary>
	static int getMaxSpeed();

private:
	static int m_maxSpeed;
	bool m_isDestroyer = false;
	bool m_loadedTexture = false;
};

