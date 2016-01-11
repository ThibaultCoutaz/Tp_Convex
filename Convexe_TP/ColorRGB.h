#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

struct ColorRGB
{
	float red, green, blue;
	bool transparent;

	ColorRGB()
	{
		transparent = true;
	}

	ColorRGB(const float x, const float y, const float z)
	{
		red = x;
		green = y;
		blue = z;
		transparent = false;
	}

	std::string toString() const
	{
		std::stringstream ss;
		if (transparent)
			ss << "transparent";
		else
			ss << "rgb(" << red << "," << green << "," << blue << ")";
		return ss.str();
	}
};