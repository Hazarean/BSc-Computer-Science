
// Inlcudes
#include "Shape.h";
#include "Circle.h";
#define _USE_MATH_DEFINES
#include <math.h>;

using namespace std;

// Constructor
Circle::Circle(int x = 0, int y = 0, int r = 1) {
	leftTop = Point(x, y);
	radius = r;
	isCircular = true;
};

// Returns area of the circle
float Circle::calculateArea() {
	float area = M_PI * radius * radius;
	return area;
};

// Returns perimeter of the circle
float Circle::calculatePerimeter() {
	float perimeter = 2 * M_PI * radius;
	return perimeter;
};

// Returns vector containing both points of the circle
vector<Point> Circle::calculatePoints() {
	vector<Point> returnVector;
	Point rightBottom(leftTop.xCoord + radius * 2, leftTop.yCoord + radius * 2);
	returnVector.push_back(leftTop);
	returnVector.push_back(rightBottom);
	return returnVector;
};

// Returns string containing information corresponding to the circle
string Circle::toString() {

	string output =
		"\nCircle[r=" + to_string(radius) + ']' +
		"\nPoints[" + '(' +
		to_string(calculatePoints()[0].xCoord) + ',' + to_string(calculatePoints()[0].yCoord) + ")(" +
		to_string(calculatePoints()[1].xCoord) + ',' + to_string(calculatePoints()[1].yCoord) + ")]" +
		"\nArea=" + to_string(calculateArea()) + " Circumference=" + to_string(calculatePerimeter());
	return output;
};

// Overwrites leftTop point to given coordinates to relocate the circle
void Circle::move(int newX, int newY) {
	leftTop.xCoord = newX;
	leftTop.yCoord = newY;
}

// Multiplies diameter of the circle by given scale factor 
void Circle::scale(float scaleF) {

	// Circles must be scaled by the same factor on both axis
	radius = ((radius*2) * scaleF)/2;
}