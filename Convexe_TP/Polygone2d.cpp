#include "Polygone2d.h"


Polygone2d::Polygone2d() : sommets(std::vector<Vector2d>())
{

}

Polygone2d::Polygone2d(const std::vector<Vector2d> &s, const ColorRGB &c) : sommets(s), color(c)
{
}

/* Write vertices on standard input
*/
void Polygone2d::displayData() const
{
	for (int i = 0; i < sommets.size(); ++i) {
		std::cout << sommets[i] << std::endl;
	}
}

std::string Polygone2d::toString() const
{
	std::stringstream ss;
	ss << elemStart("polygon");

	ss << "points=\"";
	for (unsigned i = 0; i < sommets.size(); ++i)
		ss << sommets[i].x << "," << sommets[i].y << " ";
	ss << "\" ";

	ss << attribute("fill", color.toString()) << emptyElemEnd();
	return ss.str();
}