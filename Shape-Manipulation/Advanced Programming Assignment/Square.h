#pragma once

// Includes
#include "Shape.h";
#include "Movable.h";

// Square inherits from both shape and movable base classes
class Square : public Shape, public Movable {

private:

	// Define square specific variable
	int edge;

	// Override virtual shape functions
	vector<Point> calculatePoints() override;
	float calculateArea() override;
	float calculatePerimeter() override;

public:

	// Constructor
	Square(int x, int y, int e);

	// Override virtual shape functions
	string toString() override;
	void move(int newX, int newY) override;
	void scale(float scaleF) override;
};