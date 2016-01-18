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


const float M_PI = 3.141592653589793f;

int main(void)
{
	srand((int)time(NULL));
	const int WIDTH = 3000;
	const int HEIGHT = 2000;
	const int MAX_VERTEX = 10000;
	const int REPEAT_VERTEX = 5;


	// Measure convexe creation from 3 to MAX_VERTEX 
	/*********************************************************************************************************************************************/
	//std::ofstream mesureFile("mesureConvex.txt", std::ios::out | std::ios::trunc);

	//for (int i = 3; i < MAX_VERTEX; ++i)
	//{
	//	float timeRes = 0.f;
	//	//Convex2d measureConvex;
	//	for (int repeat = 0; repeat < REPEAT_VERTEX; ++repeat)
	//	{
	//		std::vector<Vector2d> measureVertex;
	//		for (int j = 0; j < i; ++j)
	//		{
	//			measureVertex.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
	//		}
	//		std::cout << " i : " << i << " size " << measureVertex.size() << std::endl;
	//		auto start = std::chrono::high_resolution_clock::now();
	//		Convex2d measureConvex(measureVertex, ColorRGB(255.f, 0.f, 0.f));
	//		auto end = std::chrono::high_resolution_clock::now();
	//		timeRes += std::chrono::duration<float, std::milli>(end - start).count();
	//	/*	std::string s = "measure";
	//		s.append(std::to_string(i));
	//		s.append("_");
	//		s.append(std::to_string(repeat));
	//		s.append(".svg");
	//		Svg doc(s, (float)WIDTH, (float)HEIGHT);
	//		doc.addConvexPoint(measureConvex, HEIGHT);
	//		doc.addConvexEdge(measureConvex, HEIGHT);
	//		doc.save();*/
	//	}
	//	mesureFile << i << " " << timeRes / (float)REPEAT_VERTEX << std::endl;
	//	
	//}
	// Test convex 2D
	/*********************************************************************************************************************************************/

	////convex.displayData();
	std::vector<Vector2d> testConvexRandom;
	for (int i = 0; i < MAX_VERTEX; ++i)
	{
		testConvexRandom.push_back(Vector2d::Random(0.f, (float)WIDTH, 0.f, (float)HEIGHT));
	}
//
//	Polygone2d poly2(testConvexRandom, ColorRGB(0.f, 255.f, 0.f));
	Convex2d convex2(testConvexRandom, ColorRGB(255.f, 0.f, 0.f));
//	Convex2d convex3({ Vector2d(10, 10), Vector2d(100, 10), Vector2d(100, 100) }, ColorRGB(255.f, 255.f, 0.f));
//	Polygone2d poly2 = convex2;
	Svg doc("test.svg", (float)WIDTH, (float)HEIGHT);

	doc.addConvexPoint(convex2, HEIGHT);
	doc.addConvexEdge(convex2, HEIGHT);
	doc.save();

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
	//Svg minkowskiSumDoc("minkowskiSum.svg", (float)WIDTH, (float)HEIGHT);
	//minkowskiSumDoc.addConvexEdge(minkowskiSum, HEIGHT);
	//minkowskiSumDoc.addConvexPoint(minkowskiSum, HEIGHT);
	//minkowskiSumDoc.save();

	//Svg squareDoc("squareDoc.svg", (float)WIDTH, (float)HEIGHT);
	//squareDoc.addConvexEdge(square, HEIGHT);
	//squareDoc.addConvexPoint(square, HEIGHT);
	//squareDoc.save();

	//Svg triangleDoc("triangleDoc.svg", (float)WIDTH, (float)HEIGHT);
	//triangleDoc.addConvexEdge(triangle, HEIGHT);
	//triangleDoc.addConvexPoint(triangle, HEIGHT);
	//triangleDoc.save();

	//Vector2d c(500, 500); float rayon = 90;
	//std::vector<Vector2d> listVectorRond;
	//float factSide = 2.f * M_PI / (float)180;
	//for (unsigned int i = 0; i < 180; i++)
	//{
	//	float angle = i * factSide;
	//	listVectorRond.push_back(Vector2d(c.x + rayon * cos(angle), c.y + rayon*  sin(angle)));
	//}
	//
	//Convex2d Rond(listVectorRond, ColorRGB(255.f, 255.f, 0.f));

	//Svg rond("rond.svg", (float)WIDTH, (float)HEIGHT);
	//rond.addConvexEdge(Rond, HEIGHT);
	////rond.addConvexPoint(Rond, HEIGHT);
	//rond.save();

	//Convex2d maison({
	//	Vector2d(10, 10),
	//	Vector2d(410, 10),
	//	Vector2d(410, 310),
	//	Vector2d(210, 510),
	//	Vector2d(10, 310)
	//}, ColorRGB(255.f, 255.f, 0.f));

	//Svg poly1("poly1.svg", (float)WIDTH, (float)HEIGHT);
	//poly1.addConvexPoint(maison, HEIGHT);
	//poly1.addConvexEdge(maison, HEIGHT);	
	//poly1.save();

	//Convex2d minkowskiSum(maison.minkowskiSum(Rond));
	//Svg minkowskiSumDoc("minkowskiSum.svg", (float)WIDTH, (float)HEIGHT);
	//minkowskiSumDoc.addConvexPoint(minkowskiSum, HEIGHT);
	//minkowskiSumDoc.addConvexEdge(minkowskiSum, HEIGHT);	
	//minkowskiSumDoc.save();


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
	//Convex2d PieceEchec2({ Vector2d(970, 10), Vector2d(880, 10),Vector2d(880, 35),Vector2d(860, 35),Vector2d(860, 65),Vector2d(880, 65),Vector2d(880, 100),Vector2d(850, 125),Vector2d(880, 150),Vector2d(970, 150),Vector2d(1000, 125),Vector2d(970, 100), Vector2d(970, 65),Vector2d(990, 65),Vector2d(990, 35),Vector2d(970, 35) }, ColorRGB(255.f, 255.f, 0.f));
	
	//Vector2d c(2900, 100); float rayon = 90;
	//std::vector<Vector2d> listVectorRond;
	//float factSide = 2.f * M_PI / (float)180;
	//for (unsigned int i = 0; i < 180; i++)
	//{
	//	float angle = i * factSide;
	//	listVectorRond.push_back(Vector2d(c.x + rayon * cos(angle), c.y + rayon*  sin(angle)));
	//}
	//
	//Convex2d Rond(listVectorRond, ColorRGB(255.f, 255.f, 0.f));

	//Convex2d Triangle({Vector2d(10, 10), Vector2d(100, 10), Vector2d(55, 100)}, ColorRGB(255.f, 255.f, 0.f));

	//Convex2d Polygone({ Vector2d(2400, 1500), Vector2d(2700,1400), Vector2d(2900, 2000) ,Vector2d(2600, 1300) }, ColorRGB(255.f, 255.f, 0.f));

	//Svg doc("Metamorph.svg", (float)WIDTH, (float)HEIGHT);
	//Convex2d ListConvex[10]; 
	//Convex2d ListConvex2[5];
	//Convex2d ListConvex3[7];

	//float percent = 0;
	//for (int i = 0; i < 10; i++) {
	//	//Svg doc("Metamorph.svg" + i, WIDTH, HEIGHT);
	//	ListConvex[i] = Convex2d::Metamorph(Triangle, Rond, percent);
	//	percent += 0.1f;

	//	doc.addConvexEdge(ListConvex[i], HEIGHT);
	//	//doc.save();
	//}
	//percent = 0;
	//for (int i = 0; i < 5; i++) {

	//	ListConvex2[i] = Convex2d::Metamorph(Rond, Polygone, percent);

	//	percent += 1.f / 4.f;
	//	doc.addConvexEdge(ListConvex2[i], HEIGHT);
	//}

	//percent = 0;
	//for (int i = 0; i < 7; i++) {

	//	ListConvex3[i] = Convex2d::Metamorph(Polygone, Triangle, percent);

	//	percent += 1.f / 6.f;
	//	doc.addConvexEdge(ListConvex3[i], HEIGHT);
	//}
	
	//doc.addConvexEdge(Polygone, HEIGHT);
	//doc.save();

	system("pause");
	return 1;
}