#pragma once
#include "Object.h"

Object::Object(const Object & obj)
{
	m_position     = obj.m_position;
	m_velocity     = obj.m_velocity;
	m_acceleration = obj.m_acceleration;
	setMass(obj.m_mass);
}

void Object::update()
{
	m_acceleration += m_netForce / m_mass;
	m_velocity     += m_acceleration;
	m_position     += m_velocity;

	m_netForce      = sf::Vector2f(0.f, 0.f);
	m_acceleration  = sf::Vector2f(0.f, 0.f);
}
