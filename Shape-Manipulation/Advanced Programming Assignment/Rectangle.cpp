
// Includes
#include "Shape.h";
#include "Rectangle.h";
#include <iostream>;
#include <ostream>;

using namespace std;

// Constructor
Rectangle::Rectangle(int x = 0, int y = 0, int w = 1, int h = 1) {
	leftTop = Point(x, y);
	width = w;
	height = h;
	isCircular = false;
};

// Returns area of the rectangle
float Rectangle::calculateArea() {
	float area = width * height;
	return area;
};

// Returns perimeter of the rectangle
float Rectangle::calculatePerimeter() {
	float perimeter = 2 * width + 2 * height;
	return perimeter;
};

// Returns vector containing all 4 points of the rectangle
vector<Point> Rectangle::calculatePoints() {
	vector<Point> returnVector;
	Point rightTop(leftTop.xCoord + width, leftTop.yCoord);
	Point leftBottom(leftTop.xCoord, leftTop.yCoord + height);
	Point rightBottom(rightTop.xCoord, leftBottom.yCoord);
	returnVector.push_back(leftTop);
	returnVector.push_back(rightTop);
	returnVector.push_back(leftBottom);
	returnVector.push_back(rightBottom);
	return returnVector;
};

// Returns string containing information corresponding to the rectange
string Rectangle::toString() {
	string output =
		"\nRectangle[h=" + to_string(height) + ",w=" + to_string(width) + ']' +
		"\nPoints[" + '(' +
		to_string(calculatePoints()[0].xCoord) + ',' + to_string(calculatePoints()[0].yCoord) + ")(" +
		to_string(calculatePoints()[1].xCoord) + ',' + to_string(calculatePoints()[1].yCoord) + ")(" +
		to_string(calculatePoints()[2].xCoord) + ',' + to_string(calculatePoints()[2].yCoord) + ")(" +
		to_string(calculatePoints()[3].xCoord) + ',' + to_string(calculatePoints()[3].yCoord) + ")]" +
		"\nArea=" + to_string(calculateArea()) + " Perimeter=" + to_string(calculatePerimeter());
	return output;
};

// Overwrites leftTop point to given coordinates to relocate the rectangle
void Rectangle::move(int newX, int newY) {
	leftTop.xCoord = newX;
	leftTop.yCoord = newY;
}

// Multiplies width and height of the rectangle by given scale factor 
void Rectangle::scale(float scaleX, float scaleY) {

	// Rectangles may be scales on both axis
	width = width * scaleX;
	height = height * scaleY;
}
