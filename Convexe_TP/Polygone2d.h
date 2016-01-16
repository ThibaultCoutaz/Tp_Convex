#pragma once
#include "Vector2d.h"
#include "SvgHelper.h"
#include "ColorRGB.h"

class Polygone2d 
{
protected:
	ColorRGB color;
	

public:
	std::vector<Vector2d> sommets;
	Polygone2d();
	Polygone2d(const std::vector<Vector2d> &s, const ColorRGB &c = ColorRGB());
	virtual std::string toString() const;
	/* Write vertices on standard input
	*/
	virtual void displayData() const;
};
