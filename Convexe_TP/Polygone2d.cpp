#include "Polygone2d.h"


Polygone2d::Polygone2d() : vertices(std::vector<Vector2d>())
{

}

Polygone2d::Polygone2d(const std::vector<Vector2d> &vertices_, const ColorRGB &color_) : vertices(vertices_), color(color_)
{
	edges = std::vector<Vector2d>();
	if (vertices_.size() > 0)
	{
		for (int i = 0; i < vertices_.size() - 1; ++i)
		{
			edges.push_back(Vector2d((float)i, (float)(i + 1)));
		}

		edges.push_back(Vector2d((float)(vertices_.size() - 1), 0.f));
	}
}

/* Write vertices on standard input
*/
void Polygone2d::displayData() const
{
	for (int i = 0; i < vertices.size(); ++i) {
		std::cout << vertices[i].x << "," << vertices[i].y << " " << std::endl;
	}
	for (int i = 0; i < edges.size(); ++i) {
		std::cout << edges[i] << std::endl;
	}
}

std::string Polygone2d::toString(unsigned int HEIGHT) const
{
	std::stringstream ss;
	ss << SvgHelper::elemStart("polygon");

	ss << "points=\"";
	for (unsigned i = 0; i < vertices.size(); ++i)
		ss << vertices[i].x << "," <<  HEIGHT- vertices[i].y << " ";
	ss << "\" ";

	ss << SvgHelper::attribute("fill", color.toString()) << SvgHelper::emptyElemEnd();
	return ss.str();
}

std::string Polygone2d::toStringPoint(unsigned int HEIGHT) const
{
	std::stringstream ss;

	for (unsigned i = 0; i < vertices.size(); ++i) {
		ss << SvgHelper::elemStart("circle");
		ss << SvgHelper::attribute("cx", vertices[i].x) << SvgHelper::attribute("cy",  HEIGHT - vertices[i].y) << SvgHelper::attribute("r", 5) << SvgHelper::attribute("fill", color.toString()) << SvgHelper::emptyElemEnd();
	}
	return ss.str();
}
