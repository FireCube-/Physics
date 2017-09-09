#include "Blob.h"

Blob::Blob(const Blob &b)
{
	m_position     = b.m_position;
	m_velocity     = b.m_velocity;
	m_acceleration = b.m_acceleration;
	m_mass         = b.m_mass;
	m_netForce     = b.m_netForce;
	m_radius       = b.m_radius;
}

void Blob::draw(sf::RenderWindow & window)
{
	sf::CircleShape circle     (m_radius);
	circle.setFillColor        (sf::Color::Green);
	circle.setOutlineColor     (sf::Color::Black);
	circle.setOutlineThickness (3.f);
	circle.setPosition         (sf::Vector2f(m_position.x, m_position.y));

	window.draw(circle);
}

void Blob::checkEdges()
{
	if (m_position.x + 2 * m_radius >= C_WIDTH) {
		m_position.x = C_WIDTH - 2 * m_radius;
		m_velocity.x *= -1;
	}
	else if (m_position.x < 0) {
		m_velocity.x *= -1;
		m_position.x = 0;
	}

	if (m_position.y + 2 * m_radius> C_HEIGHT) {
		m_position.y = C_HEIGHT - 2 * m_radius;
		m_velocity.y *= -1;
	}
}
