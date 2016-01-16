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
			edges.push_back(Vector2d(i, i + 1));
		}

		edges.push_back(Vector2d(vertices_.size() - 1, 0));
	}
}

/* Write vertices on standard input
*/
void Polygone2d::displayData(unsigned int HEIGHT) const
{
	for (int i = 0; i < vertices.size(); ++i) {
		std::cout << vertices[i].x << "," << HEIGHT - vertices[i].y << " " << std::endl;
	}
	for (int i = 0; i < edges.size(); ++i) {
		std::cout << edges[i] << std::endl;
	}
}

std::string Polygone2d::toString(unsigned int HEIGHT) const
{
	std::stringstream ss;
	ss << elemStart("polygon");

	ss << "points=\"";
	for (unsigned i = 0; i < vertices.size(); ++i)
		ss << vertices[i].x << "," << HEIGHT - vertices[i].y << " ";
	ss << "\" ";

	ss << attribute("fill", color.toString()) << emptyElemEnd();
	return ss.str();
}

std::string Polygone2d::toStringPoint(unsigned int HEIGHT) const
{
	std::stringstream ss;

	for (unsigned i = 0; i < vertices.size(); ++i) {
		ss << elemStart("circle");
		ss << attribute("cx", vertices[i].x) << attribute("cy", HEIGHT - vertices[i].y) << attribute("r", 5) << attribute("fill", color.toString()) << emptyElemEnd();
	}
	return ss.str();
}
