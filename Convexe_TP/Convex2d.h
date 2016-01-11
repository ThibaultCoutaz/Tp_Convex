#pragma once

#include <iostream>

#include "Polygone2d.h"
#include <iostream>
class Convex2d : public Polygone2d
{
public:
	Convex2d(); // to remove
	Convex2d(Vector2d, Vector2d, Vector2d); // put in trigo order
	//Convex2d(Convex2d, Vector2d); // add a vertex to convex set
	//Convex2d(std::vector<Vector2d>); // call previous constructor
	Convex2d(const std::vector<Vector2d> & vs) : Polygone2d() { sommets = vs; }
	void displayData();
	

};

// Somme de Minkoswki
inline Convex2d operator+(const Convex2d &A, const Convex2d &B) {
	std::vector<Vector2d> res = std::vector<Vector2d>();

	for (int i = 0; i < B.sommets.size(); ++i) {
		for (int j = 0; j < A.sommets.size(); ++j) {
			Vector2d new_sommet = A.sommets[j] + B.sommets[i];
			res.push_back(new_sommet);
		}
	}

	return Convex2d(res);
}
