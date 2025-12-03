#pragma once

using namespace std;

// Abstract movable class
class Movable {

public:

	// Default constructor
	Movable();

	// Virtual functions
	virtual void move(int newX, int newY);
	virtual void scale(float scaleX, float scaleY);
	virtual void scale(float scaleF);
};