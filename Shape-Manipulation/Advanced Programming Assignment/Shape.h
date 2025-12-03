#pragma once

// Includes
#include "Point.h";
#include <vector>;
#include <string>;

using namespace std;

// Abstract shape class
class Shape {

private:

	// Define private common variables
	float area;
	float perimeter;
	vector<Point> points;

public:

	// Define public common variables
	bool isCircular;
	Point leftTop;

	// Default constructor
	Shape();

	// Virtual funtions
	virtual vector<Point> calculatePoints();
	virtual float calculateArea();
	virtual float calculatePerimeter();
	virtual string toString();
};