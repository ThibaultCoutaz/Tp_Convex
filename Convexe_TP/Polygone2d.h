/*!
* \file Polygone2d.h
* \brief Header classe Polygone2d
*
* Class Polygone2d
*
*/

#pragma once

#include "Vector2d.h"
#include "SvgHelper.h"
#include "ColorRGB.h"


/*! \class Polygone2d
* \brief Class Polygone2d
*
*  La classe gere les polygon 2d
*/
class Polygone2d 
{
protected:
	ColorRGB color;
	
public:
	std::vector<Vector2d> vertices;
	std::vector<Vector2d> edges;

	/*!
	*  \brief Constructor
	*
	*  Create a Polygone2d
	*
	*/
	Polygone2d();

	/*!
	*  \brief Constructor
	*
	*  Create a Polygone2d from a list of point
	*
	*  \param vertices : list of point
	*  \param col : Color
	*/
	Polygone2d(const std::vector<Vector2d> &, const ColorRGB & = ColorRGB());

	/*!
	*  \brief Convert to string
	*
	*  \return The converted string
	*/
	virtual std::string toString(unsigned int) const;

	/*!
	*  \brief Convert to string
	*
	*  \return The converted string
	*/
	virtual std::string toStringPoint(unsigned int) const;
	
	/*!
	*  \brief Display data
	*
	*  Write vertices on standard input
	*
	*/
	virtual void displayData() const;
};
