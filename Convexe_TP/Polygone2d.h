#pragma once
#include "Vector2d.h"
#include "SvgHelper.h"
#include "ColorRGB.h"

class Polygone2d 
{
protected:
	ColorRGB color;
	

public:
	std::vector<Vector2d> vertices;
	std::vector<Vector2d> edges;
	Polygone2d();
	Polygone2d(const std::vector<Vector2d> &, const ColorRGB & = ColorRGB());
	virtual std::string toString(unsigned int) const;
	virtual std::string toStringPoint(unsigned int) const;
	/* Write vertices on standard input
	*/
	virtual void displayData(unsigned int) const;
};
