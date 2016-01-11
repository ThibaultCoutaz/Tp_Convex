#pragma once
#include "Vector2d.h";
#include <vector>
class Polygone2d {

public:
	std::vector<Vector2d> sommets;

	Polygone2d() {}
	Polygone2d(std::vector<Vector2d> sommets);

};
