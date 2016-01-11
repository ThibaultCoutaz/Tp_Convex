#include <vector>

#include "Convex2d.h"

int main(int argc, char ** argv)
{
	std::vector<Vector2d> triangle_1 = std::vector<Vector2d>({ Vector2d(0,-1), Vector2d(0,1), Vector2d(1,0) });
	std::vector<Vector2d> triangle_2 = std::vector<Vector2d>({ Vector2d(0,0), Vector2d(1,-1), Vector2d(1,1) });

	Convex2d c1 = Convex2d(triangle_1);
	Convex2d c2 = Convex2d(triangle_2);

	Convex2d test = c1 + c2;

	test.displayData();

	std::cin.get();

	return 1;
}