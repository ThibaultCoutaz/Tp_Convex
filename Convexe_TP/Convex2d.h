#pragma once
#include "Polygone2d.h"
#include <iostream>
class Convex2d : public Polygone2d
{
public:
	Convex2d(); // to remove
	Convex2d(Vector2d, Vector2d, Vector2d); // put in trigo order
	//Convex2d(Convex2d, Vector2d); // add a vertex to convex set
	//Convex2d(std::vector<Vector2d>); // call previous constructor
};

