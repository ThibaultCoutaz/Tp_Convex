//#include "simple_svg.hpp"
#include "Svg.h"
#include "Convex2d.h"
#include "Vector2d.h"
#include <iostream>

//using namespace svg;

int main(int argc, char ** argv)
{
	const int WIDTH = 1600;
	const int HEIGHT = 900;

	// Test convex 2D creation
	/*********************************************************************************************************************************************/
	//std::vector<Vector2d> testConvex = std::vector<Vector2d>({ Vector2d(1.f, 0.f), Vector2d(1.f, 1.f), Vector2d(0.f, 1.f), Vector2d(-1.f, -1.f) });
	//Convex2d convexTmp(Vector2d(1.f, 0.f), Vector2d(1.f, 1.f), Vector2d(0.f, 1.f));

	//Convex2d convex(testConvex);
	//convex.displayData();
	std::vector<Vector2d> testConvexRandom;
	for (int i = 0; i < 10; ++i)
	{
		testConvexRandom.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
	}

	Polygone2d poly2(testConvexRandom);
	Convex2d convex2(testConvexRandom);
	std::cout << " Poly : " << std::endl;
	poly2.displayData();

	std::cout << " Convex : " << std::endl;
	convex2.displayData();
	Svg doc("test.svg", WIDTH, HEIGHT);
	doc.addPolygon(poly2);
	doc.save();

	//std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-10), Vector2d(0,10), Vector2d(10,0) });
	//std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(10,-10), Vector2d(10,10) });

	//Convex2d c1 = Convex2d(triangle_1);
	//Convex2d c2 = Convex2d(triangle_2);

	//Convex2d test = c1 + c2;
	//test.displayData();




	//Svg doc("test.svg", 100.f, 100.f);

	//std::vector<Vector2d> points = { Vector2d(0.f, 0.f), Vector2d(0.f, 21.f) , Vector2d(1.f, 21.f) , Vector2d(21.f, 0.f) };
	//Polygone2d polygon(triangle_1, ColorRGB(255.f, 0.f, 0.f));
	//Polygone2d polygon2(triangle_2, ColorRGB(0.f, 255.f, 0.f));
	//doc.addPolygon(polygon);
	//doc.addPolygon(polygon2);
	//doc.save();

	system("pause");
	return 1;
}