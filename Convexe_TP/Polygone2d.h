#pragma once
#include "Vector2d.h"
#include "SvgHelper.h"
#include "ColorRGB.h"

class Polygone2d 
{
	ColorRGB color;
	std::vector<Vector2d> sommets;
public:
	
	Polygone2d(const std::vector<Vector2d> &s, const ColorRGB &c = ColorRGB());
	std::string toString() const;
};
