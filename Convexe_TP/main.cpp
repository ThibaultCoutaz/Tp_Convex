//#include "simple_svg.hpp"
#include "Svg.h"
#include "Convex2d.h"
#include "Vector2d.h"
#include <iostream>

//using namespace svg;

int main(int argc, char ** argv)
{
	// Test convex 2D from 3 point
	// put in trigo order :
	//Convex2d convex(Vector2d(1.f, 0.f), Vector2d(1.f, 1.f), Vector2d(0.f, 1.f));

	//for (int i = 0; i < convex.sommets.size(); ++i)
	//{
	//	std::cout << " sommet " << i << " : " << convex.sommets[i].x << " " << convex.sommets[i].y << std::endl;
	//}

	std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-10), Vector2d(0,10), Vector2d(10,0) });
	std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(10,-10), Vector2d(10,10) });

	Convex2d c1 = Convex2d(triangle_1);
	Convex2d c2 = Convex2d(triangle_2);

	Convex2d test = c1 + c2;

	test.displayData();




	Svg doc("test.svg", 100.f, 100.f);

	std::vector<Vector2d> points = { Vector2d(0.f, 0.f), Vector2d(0.f, 21.f) , Vector2d(1.f, 21.f) , Vector2d(21.f, 0.f) };
	Polygone2d polygon(triangle_1, ColorRGB(255.f, 0.f, 0.f));
	Polygone2d polygon2(triangle_2, ColorRGB(0.f, 255.f, 0.f));
	doc.addPolygon(polygon);
	doc.addPolygon(polygon2);
	doc.save();

	system("pause");
	return 1;
}