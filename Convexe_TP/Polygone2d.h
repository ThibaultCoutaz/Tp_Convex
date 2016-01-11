#pragma once
#include "Vector2d.h";
class Polygone2d {

public:
	Vector2d *sommets;

	Polygone2d() {
		sommets = new Vector2d[10];
	}

	Polygone2d(Vector2d* v) {
		sommets = v;
	}

	~Polygone2d() {
		delete sommets;
	}
};
