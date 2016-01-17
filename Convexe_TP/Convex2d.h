#pragma once

#include <iostream>

#include "Polygone2d.h"
#include <iostream>
class Convex2d : public Polygone2d
{
	/* Check if an edge "looking at point" in an anti-clockwise way  
	*	a, b : point of edges
	*   p : point which look at
	*/
	bool IsEdgeLookingAtPoint(const Vector2d &, const Vector2d &, const Vector2d &) const; // check if an edges A, B looking at point P
public:
	Convex2d(const ColorRGB&);
	/* Create a convex from 3 point put in trigo order
	*	a, b, c : point of triangle
	*/
	Convex2d(const Vector2d &, const Vector2d &, const Vector2d &, const ColorRGB&);
	
	/* Create a convex set from a convex and a point (point will be in the convex and point of convex may be erased)
	*  convex : Convex polygon
	*  verteces : Point to add to previous convex
	*/
	Convex2d(Convex2d, const Vector2d &, const ColorRGB&);

	/* Create a convex polygon from set of point in any order
	*  vertices : set of point
	*/
	Convex2d(std::vector<Vector2d>, const ColorRGB&);

	
	// Minkoswki sum
	Convex2d & operator+(const Convex2d &C);


	 std::string toStringEdges(const int) const;

	 Convex2d & operator*(const float& scalar) {
		 for (int i = 0; i < vertices.size(); ++i) {
			 vertices[i] = vertices[i] * scalar;
		 }
		 return *this;
	 }


	 static  Convex2d Metamorph(Convex2d, Convex2d, float);


};

