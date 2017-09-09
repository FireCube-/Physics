#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML\Graphics.hpp>
#include <boost\random.hpp>

#include "Constants.h"
#include "Blob.h"

boost::random::mt19937 rng(std::time(0));

int randomRange(const int &min, const int &max);
