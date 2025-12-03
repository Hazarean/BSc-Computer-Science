#pragma once

// Includes
#include "Shape.h";
#include "Movable.h";

// Circle inherits from both shape and movable base classes
class Circle : public Shape, public Movable {

private:

	// Define circle-specific variable
	int radius;

	// Override virtual shape functions
	vector<Point> calculatePoints() override;
	float calculateArea() override;
	float calculatePerimeter() override;

public:

	// Constructor
	Circle(int x, int y, int r);

	// Override virtual shape functions
	string toString() override;
	void move(int newX, int newY) override;
	void scale(float scaleF) override;
};