#include "menus.h"

#include <sstream>
#include <string>

using namespace std;
using namespace geometry;


Menu::Menu(istream& input, bool showPrompts)
	: input(input), showPrompts(showPrompts)
{
}

Menu::~Menu()
{
}

double Menu::readNumber(const string& prompt)
{
	double value;

	while (true) {
		if (showPrompts) {
			cout << prompt << ": ";
		}

		input >> value;
		if (input.good()) {
			return value;
		}

		if (input.eof()) {
			cout << "Reached end of file unexpectedly!" << endl;
			exit(1);
		}

		if (input.fail()) {
			cout << "Invalid value" << endl;

			// clear fail bit from previous operation
			input.clear();

			// read (and skip) until the end of the line
			string tmp;
			getline(input, tmp);
		}

		// try again
	}
}

Point Menu::readPoint(const string& message)
{
	double x, y, z;

	if (showPrompts) {
		cout << message << endl;
	}

	x = readNumber("Enter X coordinate");
	y = readNumber("Enter Y coordinate");
	z = readNumber("Enter Z coordinate");

	return Point(x, y, z);
}

Vector Menu::readVector(const string& message)
{
	double x, y, z;

	if (showPrompts) {
		cout << message << endl;
	}

	x = readNumber("Enter X coordinate");
	y = readNumber("Enter Y coordinate");
	z = readNumber("Enter Z coordinate");

	return Vector(x, y, z);
}

Line Menu::readLine(const string& message)
{
	double x1, x2, y1, y2, z1, z2;

	while (true) {
		try {
			if (showPrompts) {
				cout << message << endl;
			}

			x1 = readNumber("Enter X coordinate of the first point");
			y1 = readNumber("Enter Y coordinate of the first point");
			z1 = readNumber("Enter Z coordinate of the first point");

			x2 = readNumber("Enter X coordinate of the second point");
			y2 = readNumber("Enter Y coordinate of the second point");
			z2 = readNumber("Enter Z coordinate of the second point");

			return Line(Point(x1, y1, z1), Point(x2, y2, z2));
		}
		catch (const GeometryException&) {
			cout << "Could not create line: the points overlap" << endl;
		}
	}
}

Segment Menu::readSegment(const string& message)
{
	double x1, x2, y1, y2, z1, z2;

	while (true) {
		try {
			if (showPrompts) {
				cout << message << endl;
			}

			x1 = readNumber("Enter X coordinate of the first point");
			y1 = readNumber("Enter Y coordinate of the first point");
			z1 = readNumber("Enter Z coordinate of the first point");

			x2 = readNumber("Enter X coordinate of the second point");
			y2 = readNumber("Enter Y coordinate of the second point");
			z2 = readNumber("Enter Z coordinate of the second point");

			return Segment(Point(x1, y1, z1), Point(x2, y2, z2));
		}
		catch (const GeometryException&) {
			cout << "Could not create segment: the points overlap" << endl;
		}
	}
}

Triangle Menu::readTriangle(const string& message)
{
	Point p1, p2, p3;

	while (true) {
		try {
			if (showPrompts) {
				cout << message << endl;
			}

			p1 = readPoint("Enter coordinates of the first point");
			p2 = readPoint("Enter coordinates of the second point");
			p3 = readPoint("Enter coordinates of the third point");

			return Triangle(p1, p2, p3);
		}
		catch (const GeometryException& ex) {
			cout << "Could not create triangle: " << ex.what() << endl;
		}
	}
}

Tetrahedron Menu::readTetrahedron(const string& message)
{
	Point p1, p2, p3, p4;

	while (true) {
		try {
			if (showPrompts) {
				cout << message << endl;
			}

			p1 = readPoint("Enter coordinates of the first point");
			p2 = readPoint("Enter coordinates of the second point");
			p3 = readPoint("Enter coordinates of the third point");
			p4 = readPoint("Enter coordinates of the fourth point");

			return Tetrahedron(p1, p2, p3, p4);
		}
		catch (const GeometryException& ex) {
			cout << "Could not create triangle: " << ex.what() << endl;
		}
	}
}

string Menu::format(const Point& point)
{
	ostringstream os;
	os << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";
	return os.str();
}
