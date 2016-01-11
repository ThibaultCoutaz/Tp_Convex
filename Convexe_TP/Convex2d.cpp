#include "Convex2d.h"



Convex2d::Convex2d(): Polygone2d(std::vector<Vector2d>())
{
}

void Convex2d::displayData() {
	for (int i = 0; i < sommets.size(); ++i) {
		std::cout << "x " << sommets[i].x << " y " << sommets[i].y << std::endl;
	}
}
