/*!
* \file Convex2d.h
* \brief Header class Convex2d
*
* Class Convex2d
*
*/

#pragma once

#include <iostream>

#include "Polygone2d.h"


/*! \class Convex2d
* \brief Class Convex2d
*
*  La classe gere les enveloppes convex 2d
*/
class Convex2d : public Polygone2d
{
protected:
	/*!	
	*  \brief Check if an edge "looking at point" in an anti-clockwise way  
	*	
	*	Check if an edges A, B looking at point P.
	*
	*	\param a, b : point of edges
	*   \param p : point which look at
	*/
	bool IsEdgeLookingAtPoint(const Vector2d &, const Vector2d &, const Vector2d &) const;

public:
	/*!
	*  \brief Constructeur
	*
	*  Constructeur de la classe Convex2d
	*
	*  \param c : Couleur
	*/
	Convex2d(const ColorRGB& c);

	/*!
	*  \brief Constructor
	*
	*  Create a convex from 3 point put in trigo order
	*
	*  \param a : Point of a triangle
	*  \param b : Point of a triangle
	*  \param c : Point of a triangle
	*  \param col : Color
	*/
	Convex2d(const Vector2d & a, const Vector2d & b, const Vector2d & c, const ColorRGB& col);
	
	/*!
	*  \brief Constructor
	*
	*  Create a convex set from a convex and a point (point will be in the convex and point of convex may be erased)
	*
	*  \param convex : Convex polygon 2d
	*  \param verteces : Point to add to previous convex
	*  \param col : Color
	*/
	Convex2d(Convex2d convex, const Vector2d & verteces, const ColorRGB& col);

	/*!
	*  \brief Constructor
	*
	*  Create a convex polygon from set of point in any order
	*
	*  \param vertices : set of point
	*  \param col : Color
	*/
	Convex2d(std::vector<Vector2d> vertices, const ColorRGB& col);
	
	/*!
	*  \brief Minkoswki sum
	*
	*  Create a convex polygon from the minkoswki sum
	*
	*  \param C : Convex polygon 2d
	*  \return A convex polygon created from the minkoswki sum
	*/
	Convex2d minkoswkiSum(const Convex2d &C);

	/*!
	*  \brief 
	*
	*  \param i : int
	*/
	std::string toStringEdges(const int i) const;

	/*!
	*  \brief Operator multiply
	*
	*  \param scalar : float
	*/
	Convex2d & operator*(const float& scalar) {
		for (int i = 0; i < vertices.size(); ++i) {
			vertices[i] = vertices[i] * scalar;
		}
		return *this;
	}

	/*!
	*  \brief Metamorphose d'un Convex2d en un autre
	*
	*  \param A : Convex polygon 2d
	*  \param B : Convex polygon 2d
	*  \param T : Time
	*  \return L'interpolation de A en B en fonction de T
	*/
	static Convex2d Metamorph(Convex2d A, Convex2d B, float T);
};
