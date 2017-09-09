#include "Main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(C_WIDTH, C_HEIGHT), "Physics");
	window.setFramerateLimit(30);

	Blob test(40.f, sf::Vector2f(C_WIDTH/2, C_HEIGHT/2));

	std::vector<Blob> blobs;
	for (int i = 0; i < 10; ++i)
	{
		float radius = randomRange(10, 100);
		sf::Vector2f pos = sf::Vector2f(float(randomRange(0, 800)), float(randomRange(0, 600)));
		blobs.push_back(Blob(radius, pos));
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) 
		{
			for (auto &b : blobs) {
				b.applyForce(sf::Vector2f(5.f, 0.f));

			}
		}
		for (auto &b : blobs) {
			b.update();
			b.checkEdges();
			b.draw(window);
		}
		window.display();
	}

	return 0;
}

int randomRange(const int &min, const int &max)
{
	boost::random::uniform_int_distribution<> dist(min, max);
	return dist(rng);
}
