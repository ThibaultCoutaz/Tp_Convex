/*!
* \file Convex2d.cpp
* \brief Source classe Convex2d
*
* Class Convex2d
*
*/

#include "Convex2d.h"

Convex2d::Convex2d() : Polygone2d(std::vector<Vector2d>(), ColorRGB(255.f, 255.f, 0.f))
{
}

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
			edges.push_back(Vector2d((float)i, (float)(i + 1)));
		}

		edges.push_back(Vector2d((float)(vertices.size() - 1), 0.f));
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
	std::vector<Vector2d> erased;
	for (int i = 0; i < edges.size(); ++i)
	{
		if (!IsEdgeLookingAtPoint(vertices[(int)edges[i].x], vertices[(int)edges[i].y], vertex))
		{
			erased.push_back(edges[i]);
			edges.erase(edges.begin() + i);
			--i;
		}
	}
	vertices.push_back(vertex);
	int size = (int)vertices.size() - 1;
	if (erased.size() > 0)
	{
		int newP1=0;
		int newP2=0;
		for (int i = 0; i < edges.size(); ++i)
		{
			bool isYTheLast = true;
			bool isXTheLast = true;
			for (int j = 0; j < edges.size(); ++j)
			{
				if (edges[i].y == edges[j].x)
				{
					isYTheLast = false;
				}
				if (edges[i].x == edges[j].y)
				{
					isXTheLast = false;
				}
			}
			if (isYTheLast)
				newP2 = (int)edges[i].y;

			if (isXTheLast)
				newP1 = (int)edges[i].x;
		}
		edges.push_back(Vector2d((float)size, (float)newP1));
		edges.push_back(Vector2d((float)newP2, (float)size));
	}
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

Convex2d Convex2d::minkowskiSum(const Convex2d &C) {

	std::vector<Vector2d> newVerteces;
	for (int i = 0; i < C.vertices.size(); ++i) {
		for (int j = 0; j < vertices.size(); ++j) {
			newVerteces.push_back(vertices[j] + C.vertices[i]);
		}
	}
	vertices = newVerteces;
	//
	return Convex2d(newVerteces, color);
}

std::string Convex2d::toStringEdges(const int HEIGHT) const
{
	std::stringstream ss;
	for (unsigned i = 0; i < edges.size(); ++i) {
		ss << SvgHelper::elemStart("line");
		ss << SvgHelper::attribute("x1", vertices[(int)edges[i].x].x) << SvgHelper::attribute("y1", HEIGHT - vertices[(int)edges[i].x].y) << SvgHelper::attribute("x2", vertices[(int)edges[i].y].x) << SvgHelper::attribute("y2", HEIGHT - vertices[(int)edges[i].y].y);
		ss << "style = 'stroke:#006600;'" << SvgHelper::emptyElemEnd();
	}
	return ss.str();
}

Convex2d Convex2d::Metamorph(Convex2d a, Convex2d b, float t) {
	return (a*(1 - t)).minkowskiSum(b*t);
}

