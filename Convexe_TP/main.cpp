#include "Convex2d.h"
#include "Vector2d.h"
#include <iostream>

int main(int argc, char ** argv)
{
	// Test convex 2D from 3 point
	// put in trigo order :
	Convex2d convex(Vector2d(1.f, 0.f), Vector2d(1.f, 1.f), Vector2d(0.f, 1.f));
	
	//for (int i = 0; i < convex.sommets.size(); ++i)
	//{
	//	std::cout << " sommet " << i << " : " << convex.sommets[i].x << " " << convex.sommets[i].y << std::endl;
	//}
	system("pause");
	return 1;
}