#include "Convex2d.h"


Convex2d::Convex2d(): Polygone2d(std::vector<Vector2d>())
{
}

/* Create a convex from 3 point put in trigo order
*	a, b, c : point of triangle
*/
Convex2d::Convex2d(const Vector2d & a, const Vector2d & b, const Vector2d & c)
{
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

/* Create a convex set from a convex and a point (point will be in the convex and point of convex may be erased)
* convex : Convex polygon
* verteces : Point to add to previous convex
*/
Convex2d::Convex2d(Convex2d convex, const Vector2d & verteces) : Polygone2d() // add a vertex to convex set
{
	sommets = convex.sommets;
	for (int i = 0; i < sommets.size() - 1; ++i)
	{

		if (!IsEdgeLookingAtPoint(sommets[i], sommets[i + 1], verteces))
		{
			sommets.erase(sommets.begin() + i);
		}
	}
	sommets.push_back(verteces);
}

/* Create a convex polygon from set of point in any order
* vertices : set of point
*/
Convex2d::Convex2d(std::vector<Vector2d> verteces)
{
	int size = (int)verteces.size();
	Convex2d firstTriangle = Convex2d(verteces[size - 1], verteces[size - 2], verteces[size - 3]);
	sommets = firstTriangle.sommets;
	for (int i = 0; i < 3; ++i)
		verteces.pop_back();
	while (verteces.size() > 0)
	{
		firstTriangle = Convex2d(firstTriangle, verteces.back());
		sommets = firstTriangle.sommets;
		verteces.pop_back();
	}
}



/* Check if an edge "looking at point" in an anti-clockwise way
*	a, b : point of edges
*   p : point which look at
*/
bool Convex2d::IsEdgeLookingAtPoint(const Vector2d & a, const Vector2d & b, const Vector2d & p) const
{
	return Vector2d::DotProduct(Vector2d::Normalize(b - a), p) > 0.f;
}

Convex2d & Convex2d::operator+(const Convex2d &C) {

	for (int i = 0; i < C.sommets.size(); ++i) {
		for (int j = 0; j < sommets.size(); ++j) {
			sommets[j] = sommets[j] + C.sommets[i];
		}
	}

	return *this;
}
