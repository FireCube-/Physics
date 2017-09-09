#pragma once

#include <SFML\Graphics.hpp>
#include <stdexcept>

#include "Vector2f.h"

class Object
{
public:
	Object() = default;
	Object(const Object &obj);
	Object(const sf::Vector2f &v_pos) : m_position(v_pos) {}
	Object(const float &mass, const sf::Vector2f &v_pos) : Object(v_pos) { setMass(mass); }


	inline sf::Vector2f getPosition() const { return m_position; }
	virtual inline void setPosition(const sf::Vector2f &pos) { m_position = pos; }

	inline sf::Vector2f getVelocity() const { return m_velocity; }
	virtual inline void setVelocity(const sf::Vector2f &vel) { m_velocity = vel; }

	inline sf::Vector2f getAcceleration() const { return m_acceleration; }
	virtual inline void setAcceleration(const sf::Vector2f &acc) { m_acceleration = acc; }

	inline float getMass() const { return m_mass; }
	virtual inline void setMass(const float &mass) { mass == 0 ? throw std::runtime_error("Can't set the mass of an object to zero!") : m_mass = mass; }


	virtual void update();
	virtual void applyForce(const sf::Vector2f &force) { m_netForce += force; }

protected:
	sf::Vector2f m_position	    = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_velocity	    = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_acceleration = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_netForce		= sf::Vector2f(0.f, 0.f);	
	float		 m_mass         = 0.f;
};
