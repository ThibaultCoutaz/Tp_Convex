#pragma once

#include <cmath>
#include <algorithm>

inline float lerp(float t, float v1, float v2)
{
	return (1.f - t) * v1 + t * v2;
}

inline float clamp(float val, float low, float high)
{
	if (val < low) return low;
	else if (val > high) return high;
	else return val;
}

inline float randf(float low, float high)
{
	return low + (float)rand() / (float)(RAND_MAX / (high - low));
}