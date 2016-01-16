#include "Convex2d.h"


Convex2d::Convex2d(const ColorRGB& color) : Polygone2d(std::vector<Vector2d>(), color)
{
}

/* Create a convex from 3 point put in trigo order
*	a, b, c : point of triangle
*/
Convex2d::Convex2d(const Vector2d & a, const Vector2d & b, const Vector2d & c, const ColorRGB& color) : Polygone2d(std::vector<Vector2d>(), color)
{
	if (Vector2d::CrossProduct(b - a, c - a) >= 0.f)
	{
		vertices.push_back(a);
		vertices.push_back(b);
		vertices.push_back(c);
	}
	else
	{
		vertices.push_back(a);
		vertices.push_back(c);
		vertices.push_back(b);
	}
	if (vertices.size() > 0)
	{
		for (int i = 0; i < vertices.size() - 1; ++i)
		{
			edges.push_back(Vector2d(i, i + 1));
		}

		edges.push_back(Vector2d(vertices.size() - 1, 0));
	}
}

/* Create a convex set from a convex and a point (point will be in the convex and point of convex may be erased)
* convex : Convex polygon
* verteces : Point to add to previous convex
*/
Convex2d::Convex2d(Convex2d convex, const Vector2d & vertex, const ColorRGB& color) : Polygone2d(std::vector<Vector2d>(), color) // add a vertex to convex set
{
	vertices = convex.vertices;
	edges = convex.edges;
	for (int i = 0; i < edges.size(); ++i)
	{
		std::cout << " i " << i << " edges size " << edges.size() << std::endl;
		std::cout << std::endl << " verteces : " << vertex << std::endl;
		if (!IsEdgeLookingAtPoint(vertices[edges[i].x], vertices[edges[i].y], vertex))
		{
			std::cout << "no ! i : " << i << " dir " << vertices[edges[i].y] - vertices[edges[i].x] << std::endl;
			edges.erase(edges.begin() + i);
			--i;
		/*	for (int i = 0; i < edges.size(); ++i)
			{
				if(edges[i].x > 
			}*/
		}
		else 
			std::cout << "yes ! i : " << i << " sommeta " << edges[i].x << " sommetb " << edges[i].y << std::endl;
	}
	vertices.push_back(vertex);
	std::cout << " push back : " << vertex << std::endl;
	int size = vertices.size() - 1;
	edges[edges.size() - 1].y = size;
	edges.push_back(Vector2d(size, 0));
}

/* Create a convex polygon from set of point in any order
* vertices : set of point
*/
Convex2d::Convex2d(std::vector<Vector2d> verteces, const ColorRGB& color2)
{
	int size = (int)verteces.size();
	Convex2d firstTriangle = Convex2d(verteces[size - 1], verteces[size - 2], verteces[size - 3], color2);
	vertices = firstTriangle.vertices;
	edges = firstTriangle.edges;
	for (int i = 0; i < 3; ++i)
		verteces.pop_back();
	while (verteces.size() > 0)
	{
		firstTriangle = Convex2d(firstTriangle, verteces.back(), color2);
		vertices = firstTriangle.vertices;
		edges = firstTriangle.edges;
		verteces.pop_back();
	}
	color = color2;
	
}



/* Check if an edge "looking at point" in an anti-clockwise way
*	a, b : point of edges
*   p : point which look at
*/
bool Convex2d::IsEdgeLookingAtPoint(const Vector2d & a, const Vector2d & b, const Vector2d & p) const
{
	Vector2d AB = b - a;
	Vector2d I = (b + a) * 0.5f;
	return Vector2d::DotProduct(Vector2d::Normalize((b - I).rotate90AntiClockwise() ), Vector2d::Normalize(p - I)) > 0.f;
}

Convex2d & Convex2d::operator+(const Convex2d &C) {

	for (int i = 0; i < C.vertices.size(); ++i) {
		for (int j = 0; j < vertices.size(); ++j) {
			vertices[j] = vertices[j] + C.vertices[i];
		}
	}

	return *this;
}

std::string Convex2d::toStringEdges(const int HEIGHT) const
{
	std::stringstream ss;
	for (unsigned i = 0; i < edges.size(); ++i) {
		ss << elemStart("line");
		ss << attribute("x1", vertices[edges[i].x].x) << attribute("y1", HEIGHT - vertices[edges[i].x].y) << attribute("x2", vertices[edges[i].y].x) << attribute("y2", HEIGHT - vertices[edges[i].y].y);
		ss << "style = 'stroke:#006600;'" << emptyElemEnd();
	}
	return ss.str();
}
