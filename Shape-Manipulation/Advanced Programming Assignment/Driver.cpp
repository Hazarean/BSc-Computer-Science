/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

// Includes
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;


int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	// Lays out command list for the user
	string instructions =
		"Command       | Description\n"
		"addR x y h w  | Adds rectangle at position (x,y) with height (h) and width (w)\n"
		"addS x y e    | Adds square at position (x,y) with edge (e)\n"
		"addC x y r    | Adds circle at position (x,y) with radius (r)\n"
		"move s x y    | Moves shape (s) to position (x,y)\n"
		"scale s x y   | [Rectangles] Scales shape (s) by scale factor (x) along the x axis and by factor (y) along the y axis\n"
		"scale s f     | [Squares and Circles] Scales shape (s) by scale factor (f) on both axis\n"
		"display all   | Displays all shapes with indexes\n"
		"display s     | Displays specific shape at index (s)\n"
		"exit          | Exits the program\n";
	cout << instructions << endl;

	while (userCommand.compare("EXIT") != 0)
	{
		// Postprocessing
		parameters.clear();

		// Take user input, make a copy and convert to a list of chars
		cout << "Enter the command: ";
		getline(cin, userCommand);
		while (userCommand.empty()) {
			cout << "Enter the command: ";
			getline(cin, userCommand);
		}
		
		// Convert to upper case
		for (int i = 0;i < userCommand.length();i++) {
			userCommand[i] = toupper(userCommand[i]);
		}
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// String tokenizer to populate parameters vector
		char *token, *nextToken;
		char seperators[] = " ,";
		token = strtok_s(cstr, seperators, &nextToken);
		while (token != NULL) {
			parameters.push_back(token);
			token = strtok_s(NULL, seperators, &nextToken);
		}

		// Seperate the main command from the arguments
		string command = parameters[0];	
		vector<string> arguments(parameters.begin() + 1, parameters.begin() + parameters.size());		

		// Adds a rectangle to shapes
		if (command.compare("ADDR") == 0) {
			if (parameters.size() != 5) { 
				cout << "Invalid number of arguments, please use the following format:\naddR x y h w" << endl;
				continue; 
			}
			
			// Retrieve arguments as usable type
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int w = stoi(parameters[3].c_str());
			int h = stoi(parameters[4].c_str());
			
			// Populate shapes with new rectangle and display corresponding information
			Rectangle* r = new Rectangle(x, y, w, h);
			shapes.push_back(r);
			cout << r->toString();
		}

		// Adds a square to shapes
		else if (command.compare("ADDS") == 0) {
			if (parameters.size() != 4) {
				cout << "Invalid number of arguments, please use the following format:\naddS x y e" << endl;
				continue;
			}

			// Retrieve arguments as usable type
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int e = stoi(parameters[3].c_str());

			// Populate shapes with new square and display corresponding information
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s->toString();
		}

		// Adds circle to shapes
		else if (command.compare("ADDC") == 0) {
			if (parameters.size() != 4) {
				cout << "Invalid number of arguments, please use the following format:\naddC x y r" << endl;
				continue;
			}

			// Retrieve arguments as usable type
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());

			// Populate shapes with new circle and display corresponding information
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c->toString();

		}

		// Allows user to select and scale a given shape from shapes
		else if (command.compare("SCALE") == 0) {
			
			// Check for a valid number of arguments
			if (parameters.size() != 3 && parameters.size() != 4) {
				cout << "Invalid number of arguments, please use one of the following formats:\nscale s x y\nscale s f" << endl;
				continue;
			}

			// Check given index exists
			int shapeNo = stoi(parameters[1].c_str());
			if (shapeNo - 1 >= shapes.size()) {
				cout << "Invalid index, please select a shape between 0 and " << to_string(shapes.size()) << "\n" << endl;
				continue;
			}

			// Type cast given shape to movable at runtime
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);

			// Choose from overloaded scale methods based on the number of parameters and display corresponding information
			if (parameters.size() == 3) {
				float scale = stof(parameters[2].c_str());
				m->scale(scale);
			}
			else if (parameters.size() == 4) {
				float scaleX = stof(parameters[2].c_str());
				float scaleY = stof(parameters[3].c_str());
				m->scale(scaleX, scaleY);
			}
			cout << shapes[shapeNo - 1]->toString();
		}

		// Allows user to select and move a given shape from shapes
		else if (command.compare("MOVE") == 0) {

			// Check for a valid number of arguments
			if (parameters.size() != 4) {
				cout << "Invalid number of arguments, please use the following format:\nmove s x y" << endl;
				continue;
			}

			// Check given index exists
			int shapeNo = stoi(parameters[1].c_str()); 
			if (shapeNo - 1 >= shapes.size()) {
				cout << "Invalid index, please select a shape between 0 and " << to_string(shapes.size()) << "\n" << endl;
				continue;
			}

			// Retrieve arguments as usable type
			int x = stoi(parameters[2].c_str());
			int y = stoi(parameters[3].c_str());

			// Type cast given shape to movable at runtime
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);

			// Move given movable and display corresponding information
			m->move(x, y);
			cout << shapes[shapeNo - 1]->toString();
		}

		// Allows user to display one or all shape(s) in shapes
		else if (command.compare("DISPLAY") == 0) {

			// Check for a valid number of arguments
			if (parameters.size() != 2) {
				cout << "Invalid number of arguments, please use the following format:\display s/all" << endl;
				continue;
			}

			// Display all shapes in shapes
			if (parameters[1].compare("ALL") == 0) {
				for (int i = 0; i < shapes.size(); i++) {
					cout << "\nShape[" << to_string(i+1) << "]:\n" << shapes[i]->toString() << endl;
				}
			}

			// Display specific shape at given index
			else {

				// Check given index exists
				int shapeNo = stoi(parameters[1].c_str());
				if (shapeNo - 1 >= shapes.size()) {
					cout << "Invalid index, please select a shape between 0 and " << to_string(shapes.size()) << "\n" << endl;
					continue;
				}

				cout <<"\nShape[" << to_string(shapeNo) << "]:\n" << shapes[shapeNo-1]->toString() << endl;
			}
		}

		// Avoids "Invalid command" message
		else if (command.compare("EXIT") == 0) { continue; }

		// If input does not match any command (not case sensitive)
		else {
			cout << "Invalid command";
		}
		cout << endl << endl;
	}

	// Allows user to exit the program
	cout << "Press any key to continue...";
	getchar();

	return 0;
}