//#include "simple_svg.hpp"
#include "Svg.h"
#include "Convex2d.h"
#include "Vector2d.h"
#include <iostream>
#include<random>
#include <time.h>
//using namespace svg;

int main(int argc, char ** argv)
{
	srand(time(NULL));
	const int WIDTH = 800;
	const int HEIGHT = 800;

	// Test convex 2D
	/*********************************************************************************************************************************************/

	//////convex.displayData();
	std::vector<Vector2d> testConvexRandom;
	for (int i = 0; i < 100; ++i)
	{
		testConvexRandom.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
	}

//	Polygone2d poly2(testConvexRandom, ColorRGB(0.f, 255.f, 0.f));
	Convex2d convex2(testConvexRandom, ColorRGB(255.f, 0.f, 0.f));
	Convex2d convex3({ Vector2d(10, 10), Vector2d(100, 10), Vector2d(100, 100) }, ColorRGB(255.f, 255.f, 0.f));
	Polygone2d poly2 = convex2;
	Svg doc("test.svg", WIDTH, HEIGHT);
	doc.addConvexEdge(convex2, HEIGHT);
	doc.addConvexPoint(convex2, HEIGHT);
	doc.save();

	// Test Minkoswki
	/*********************************************************************************************************************************************/

	//std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-10), Vector2d(0,10), Vector2d(10,0) });
	//std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(10,-10), Vector2d(10,10) });

	//Convex2d c1 = Convex2d(triangle_1);
	//Convex2d c2 = Convex2d(triangle_2);

	//Convex2d test = c1 + c2;
	//test.displayData();


	// Test export
	/*********************************************************************************************************************************************/

	//Svg doc("test.svg", 100.f, 100.f);

	//std::vector<Vector2d> points = { Vector2d(0.f, 0.f), Vector2d(0.f, 21.f) , Vector2d(1.f, 21.f) , Vector2d(21.f, 0.f) };
	//Polygone2d polygon(triangle_1, ColorRGB(255.f, 0.f, 0.f));
	//Polygone2d polygon2(triangle_2, ColorRGB(0.f, 255.f, 0.f));
	//doc.addPolygon(polygon);
	//doc.addPolygon(polygon2);
	//doc.save();

	// Test morph
	/*********************************************************************************************************************************************/
	//Polygone2d PieceEchec2({ Vector2d(970, 10), Vector2d(880, 10),Vector2d(880, 35),Vector2d(860, 35),Vector2d(860, 65),Vector2d(880, 65),Vector2d(880, 100),Vector2d(850, 125),Vector2d(880, 150),Vector2d(970, 150),Vector2d(1000, 125),Vector2d(970, 100), Vector2d(970, 65),Vector2d(990, 65),Vector2d(990, 35),Vector2d(970, 35) }, ColorRGB(255.f, 255.f, 0.f));
	//Polygone2d PieceEchec1({ Vector2d(30, 10), Vector2d(120, 10),Vector2d(120, 100), Vector2d(150, 120),Vector2d(150, 140), Vector2d(110, 140),Vector2d(110, 130),Vector2d(90, 130),Vector2d(90, 140),Vector2d(60, 140),Vector2d(60, 130),Vector2d(40, 130),Vector2d(40, 140),Vector2d(0, 140),Vector2d(0, 120),Vector2d(30, 100) }, ColorRGB(255.f, 255.f, 0.f));
	system("pause");
	return 1;
}