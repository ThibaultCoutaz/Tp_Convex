/*!
* \file main.cpp
* \brief Entry point
*
* Main
*
*/

#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include<fstream>
#include "Svg.h"
#include "Convex2d.h"
#include "Vector2d.h"


int main(void)
{
	srand((int)time(NULL));
	const int WIDTH = 1000;
	const int HEIGHT = 1000;
	const int MAX_VERTEX = 100;
	const int REPEAT_VERTEX = 5;


	// Measure convexe creation from 3 to MAX_VERTEX 
	/*********************************************************************************************************************************************/
	std::ofstream mesureFile("mesureConvex.txt", std::ios::out | std::ios::trunc);

	for (int i = 3; i < MAX_VERTEX; ++i)
	{
		float timeRes = 0.f;
		//Convex2d measureConvex;
		for (int repeat = 0; repeat < REPEAT_VERTEX; ++repeat)
		{
			std::vector<Vector2d> measureVertex;
			for (int j = 0; j < i; ++j)
			{
				measureVertex.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
			}
			std::cout << " i : " << i << " size " << measureVertex.size() << std::endl;
			auto start = std::chrono::high_resolution_clock::now();
			Convex2d measureConvex(measureVertex, ColorRGB(255.f, 0.f, 0.f));
			auto end = std::chrono::high_resolution_clock::now();
			timeRes += std::chrono::duration<float, std::milli>(end - start).count();
		/*	std::string s = "measure";
			s.append(std::to_string(i));
			s.append("_");
			s.append(std::to_string(repeat));
			s.append(".svg");
			Svg doc(s, (float)WIDTH, (float)HEIGHT);
			doc.addConvexPoint(measureConvex, HEIGHT);
			doc.addConvexEdge(measureConvex, HEIGHT);
			doc.save();*/
		}
		mesureFile << i << " " << timeRes / (float)REPEAT_VERTEX << std::endl;
		
	}
	// Test convex 2D
	/*********************************************************************************************************************************************/

	//////convex.displayData();
//	std::vector<Vector2d> testConvexRandom;
//	for (int i = 0; i < 100; ++i)
//	{
//		testConvexRandom.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
//	}
//
////	Polygone2d poly2(testConvexRandom, ColorRGB(0.f, 255.f, 0.f));
//	Convex2d convex2(testConvexRandom, ColorRGB(255.f, 0.f, 0.f));
//	Convex2d convex3({ Vector2d(10, 10), Vector2d(100, 10), Vector2d(100, 100) }, ColorRGB(255.f, 255.f, 0.f));
//	Polygone2d poly2 = convex2;
//	Svg doc("test.svg", WIDTH, HEIGHT);
//	doc.addConvexEdge(convex2, HEIGHT);
//	doc.addConvexPoint(convex2, HEIGHT);
//	doc.save();

	// Test Minkoswki
	/*********************************************************************************************************************************************/

	//std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-10), Vector2d(0,10), Vector2d(10,0) });
	//std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(10,-10), Vector2d(10,10) });

	//Convex2d triangle({ Vector2d(10, 10), Vector2d(100, 10), Vector2d(100, 100) }, ColorRGB(255.f, 255.f, 0.f));

	//Convex2d square({ Vector2d(10, 10), Vector2d(100, 10), Vector2d(100, 100), Vector2d(10, 100) }, ColorRGB(255.f, 255.f, 0.f));
	////Convex2d c1 = Convex2d(triangle);
	////Convex2d c2 = Convex2d(square);

	//Convex2d minkowskiSum(triangle.minkowskiSum(square));
	////test.displayData();
	//Svg minkowskiSumDoc("minkowskiSum.svg", WIDTH, HEIGHT);
	//minkowskiSumDoc.addConvexEdge(minkowskiSum, HEIGHT);
	//minkowskiSumDoc.addConvexPoint(minkowskiSum, HEIGHT);
	//minkowskiSumDoc.save();

	//Svg squareDoc("squareDoc.svg", WIDTH, HEIGHT);
	//squareDoc.addConvexEdge(square, HEIGHT);
	//squareDoc.addConvexPoint(square, HEIGHT);
	//squareDoc.save();

	//Svg triangleDoc("triangleDoc.svg", WIDTH, HEIGHT);
	//triangleDoc.addConvexEdge(triangle, HEIGHT);
	//triangleDoc.addConvexPoint(triangle, HEIGHT);
	//triangleDoc.save();


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
	Convex2d PieceEchec2({ Vector2d(970, 10), Vector2d(880, 10),Vector2d(880, 35),Vector2d(860, 35),Vector2d(860, 65),Vector2d(880, 65),Vector2d(880, 100),Vector2d(850, 125),Vector2d(880, 150),Vector2d(970, 150),Vector2d(1000, 125),Vector2d(970, 100), Vector2d(970, 65),Vector2d(990, 65),Vector2d(990, 35),Vector2d(970, 35) }, ColorRGB(255.f, 255.f, 0.f));
	Convex2d PieceEchec1({ Vector2d(30, 10), Vector2d(120, 10),Vector2d(120, 100), Vector2d(150, 120),Vector2d(150, 140), Vector2d(110, 140),Vector2d(110, 130),Vector2d(90, 130),Vector2d(90, 140),Vector2d(60, 140),Vector2d(60, 130),Vector2d(40, 130),Vector2d(40, 140),Vector2d(0, 140),Vector2d(0, 120),Vector2d(30, 100) }, ColorRGB(255.f, 255.f, 0.f));
	Svg doc("test.svg", (float)WIDTH, (float)HEIGHT);

	Convex2d inter = Convex2d::Metamorph(PieceEchec1, PieceEchec2, 0.5f);

	doc.addConvexEdge(PieceEchec2, HEIGHT);
	doc.addConvexEdge(PieceEchec1, HEIGHT);
	doc.addConvexEdge(inter, HEIGHT);
	doc.save();



	system("pause");
	return 1;
}