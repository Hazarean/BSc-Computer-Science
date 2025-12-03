#pragma once

// Includes
#include "Shape.h";
#include "Movable.h";

// Rectangle inherits from both shape and movable base classes
class Rectangle : public Shape, public Movable {

private:

	// Define rectangle-specific variables
	int width;
	int height;

	// Override virtual shape functions
	vector<Point> calculatePoints() override;
	float calculateArea() override;
	float calculatePerimeter() override;

public:

	// Constructor
	Rectangle(int x, int y, int w, int h);

	// Override virtual shape functions
	string toString() override;
	void move(int newX, int newY) override;
	void scale(float scaleX, float scaleY) override;
};