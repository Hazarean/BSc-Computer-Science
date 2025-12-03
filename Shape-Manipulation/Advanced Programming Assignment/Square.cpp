
// Includes
#include "Shape.h";
#include "Square.h";

using namespace std;

// Constructor
Square::Square(int x = 0, int y = 0, int e = 1) {
	leftTop = Point(x, y);
	edge = e;
	isCircular = false;
};

// Returns area of the square
float Square::calculateArea() {
	float area = edge * edge;
	return area;
};

// Returns perimeter of the square
float Square::calculatePerimeter() {
	float perimeter = edge * 4;
	return perimeter;
};

// Returns vector containing all 4 points of the square
vector<Point> Square::calculatePoints() {
	vector<Point> returnVector;
	Point rightTop(leftTop.xCoord + edge, leftTop.yCoord);
	Point leftBottom(leftTop.xCoord, leftTop.yCoord + edge);
	Point rightBottom(rightTop.xCoord, leftBottom.yCoord);
	returnVector.push_back(leftTop);
	returnVector.push_back(rightTop);
	returnVector.push_back(leftBottom);
	returnVector.push_back(rightBottom);

	return returnVector;
};

// Returns string containing information corresponding to the square
string Square::toString() {

	string output =
		"\nSquare[e=" + to_string(edge) + ']' +
		"\nPoints[" + '(' +
		to_string(calculatePoints()[0].xCoord) + ',' + to_string(calculatePoints()[0].yCoord) + ")(" +
		to_string(calculatePoints()[1].xCoord) + ',' + to_string(calculatePoints()[1].yCoord) + ")(" +
		to_string(calculatePoints()[2].xCoord) + ',' + to_string(calculatePoints()[2].yCoord) + ")(" +
		to_string(calculatePoints()[3].xCoord) + ',' + to_string(calculatePoints()[3].yCoord) + ")]" +
		"\nArea=" + to_string(calculateArea()) + " Perimeter=" + to_string(calculatePerimeter());
	return output;
}

// Overwrites leftTop point to given coordinates to relocate the square
void Square::move(int newX, int newY) {
	leftTop.xCoord = newX;
	leftTop.yCoord = newY;
}

// Multiplies edge of the square by given scale factor 
void Square::scale(float scaleF) {

	// Squares must be scaled by the same factor in both directions
	edge = edge * scaleF;
}