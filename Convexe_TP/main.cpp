#include "Convex2d.h"
#include "Vector2d.h"
#include <iostream>



int main(int argc, char ** argv)
{

	// Test convex 2D from 3 point
	// put in trigo order :
	//Convex2d convex(Vector2d(1.f, 0.f), Vector2d(1.f, 1.f), Vector2d(0.f, 1.f));

	//for (int i = 0; i < convex.sommets.size(); ++i)
	//{
	//	std::cout << " sommet " << i << " : " << convex.sommets[i].x << " " << convex.sommets[i].y << std::endl;
	//}

	std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-1), Vector2d(0,1), Vector2d(1,0) });
	std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(1,-1), Vector2d(1,1) });

	Convex2d c1 = Convex2d(triangle_1);
	Convex2d c2 = Convex2d(triangle_2);

	Convex2d test = c1 + c2;

	test.displayData();

	std::cin.get();
	system("pause");

	return 1;
}