#include "Critter.h"
#include "raymath.h"
#include "Engine.h"

int Critter::m_maxSpeed = 50;

Critter::Critter()
{
	m_position = Vector2{ 0, 0 };
	m_velocity = Vector2{ 0, 0 };
	m_radius = 0;
	m_isLoaded = false;
}

Critter::Critter(Vector2 position, Vector2 velocity, float radius, const char* texturePath)
{

	m_position = position;
	m_velocity = velocity;
	m_radius = radius;

	m_texture = LoadTexture(texturePath);

	m_loadedTexture = true;

	m_texture.width = radius;
	m_texture.height = radius;

	m_isLoaded = true;
}

void Critter::Init(Vector2 position, Vector2 velocity, float radius, const char* texturePath)
{

	m_position = position;
	m_velocity = velocity;
	m_radius = radius;

	if (!m_loadedTexture)
	{
		m_texture = LoadTexture(texturePath);
		m_loadedTexture = true;
	}

	m_texture.width = radius;
	m_texture.height = radius;

	m_isLoaded = true;
}

Critter::~Critter()
{
	if (m_loadedTexture)
		UnloadTexture(m_texture);

	m_isLoaded = false;
}


void Critter::Update(float dt)
{
	if (m_isLoaded == false)
		return;


	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;

	// check each critter against screen bounds
	if (GetX() < 0) {
		SetX(0);
		SetVelocity(Vector2{ -GetVelocity().x, GetVelocity().y });
	}
	if (GetX() > Engine::getScreenWidth()) {
		SetX(Engine::getScreenWidth());
		SetVelocity(Vector2{ -GetVelocity().x, GetVelocity().y });
	}
	if (GetY() < 0) {
		SetY(0);
		SetVelocity(Vector2{ GetVelocity().x, -GetVelocity().y });
	}
	if (GetY() > Engine::getScreenHeight()) {
		SetY(Engine::getScreenHeight());
		SetVelocity(Vector2{ GetVelocity().x, -GetVelocity().y });
	}

	m_isDirty = false;
}


void Critter::Draw()
{
	if (m_isLoaded == false)
		return;

	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
}

void Critter::setMoveDirection(Vector2 direction)
{
	SetVelocity(Vector2Scale(direction, m_maxSpeed));
}

bool Critter::operator==(Critter other)
{
	//The simplest comparison without performing a deep copy. 
	//Collision detection makes it impossible that two critters could naturally be in the same position.
	return Vector2Distance(other.GetPosition(), other.GetPosition()) == 0 && Vector2Distance(other.GetVelocity(), other.GetVelocity()) == 0;
}

int Critter::getMaxSpeed()
{
	return m_maxSpeed;
}
