#include "Vector2f.h"

void Vector2f::limit(const float & lim)
{
	if (abs() > lim) 
	{
		float ratio = x / y;
		y = lim / std::sqrt(ratio * ratio + 1);
		x = ratio * y;
	}
}
