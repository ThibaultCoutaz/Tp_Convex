#include "Convex2d.h"



Convex2d::Convex2d(): Polygone2d(std::vector<Vector2d>())
{
}

Convex2d::Convex2d(Vector2d a, Vector2d b, Vector2d c)
{
//	std::cout << "cross " << Vector2d::CrossProduct(b - a, c - a) << std::endl;
	if (Vector2d::CrossProduct(b - a, c - a) > 0.f)
	{
		sommets.push_back(a);
		sommets.push_back(b);
		sommets.push_back(c);
	}
	else
	{
		sommets.push_back(a);
		sommets.push_back(c);
		sommets.push_back(b);
	}
}
//
//Convex2d::Convex2d(Convex2d, Vector2d) // add a vertex to convex set
//{
//	
//}
//
//Convex2d::Convex2d(std::vector<Vector2d>)
//{
//
//}
void Convex2d::displayData() {
	for (int i = 0; i < sommets.size(); ++i) {
		std::cout << "x " << sommets[i].x << " y " << sommets[i].y << std::endl;
	}
}
