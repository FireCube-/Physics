#pragma once

#include "Constants.h"
#include "Object.h"

class Blob : public Object
{
public:
	Blob() = default;
	Blob(const Blob &b);
	Blob(const float &rad, const sf::Vector2f &v_pos) :Object::Object(v_pos) { setRadius(rad); setMass(1.f); }

	inline float getRadius() const { return m_radius; }
	inline void setRadius(const float &rad) { m_radius = rad; }
	inline void setMass(const float &density) override { m_mass = density * C_PI * pow(m_radius / C_PXlPERCM, 2); }

	void draw(sf::RenderWindow &window);
	void checkEdges();

private:
	float m_radius = 0.f;

};	
