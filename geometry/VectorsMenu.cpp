#include <sstream>

#include "menus.h"
#include "Vector.h"

using namespace std;
using namespace geometry;


VectorsMenu::VectorsMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

VectorsMenu::~VectorsMenu()
{
}

Vector VectorsMenu::readVector(const string & message)
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

void VectorsMenu::show()
{
	// main menu for vectors
	cout << "Operations on vectors" << endl;

	// initialize first vector
	Vector v1 = readVector("Enter coordinates of a new vector");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Calculate length" << endl;
			cout << "[ 2]: Calculate direction" << endl;
			cout << "[ 3]: Check if zero" << endl;
			cout << "[ 4]: Check if parallel to another vector" << endl;
			cout << "[ 5]: Check if orthogonal to another vector" << endl;
			cout << "[ 6]: Add to another vector" << endl;
			cout << "[ 7]: Subtract from another vector" << endl;
			cout << "[ 8]: Multiply with a number" << endl;
			cout << "[ 9]: Scalar (dot) product with another vector" << endl;
			cout << "[10]: Vector product with another vector" << endl;
			cout << "[11]: Mixed product with another two vectors" << endl;
			cout << endl;
		}

		showOperations = false;
		int op = (int) readNumber("Select an operation (1-11)");

		try {
			switch (op) {
			case 0:
				return;

			case 1: {
				cout << "Length of vector " << format(v1) << " is " << v1.length() << endl;;
				break;
			}

			case 2:
				cout << "Direction of vector " << format(v1) << " is " << format(v1.direction()) << endl;
				break;

			case 3:
				cout << "Vector " << format(v1) << (v1.isZero() ? " is" : " is NOT") << " zero" << endl;
				break;

			case 4:
			{
				Vector v2 = readVector("Enter coordinates of the other vector");
				cout << "Vector " << format(v1) << (v1.isParallel(v2) ? " is" : " is NOT") << " parallel to vector " << format(v2) << endl;
				break;
			}

			case 5:
			{
				Vector v2 = readVector("Enter coordinates of the other vector");
				cout << "Vector " << format(v1) << (v1.isOrthogonal(v2) ? " is" : " is NOT") << " orthogonal to vector " << format(v2) << endl;
				break;
			}

			case 6:
			{
				Vector v2 = readVector("Enter coordinates of the vector you are adding");
				cout << format(v1) << " + " << format(v2) << " = " << format(v1 + v2) << endl;
				break;
			}

			case 7:
			{
				Vector v2 = readVector("Enter coordinates of the vector you are subtracting");
				cout << format(v1) << " - " << format(v2) << " = " << format(v1 - v2) << endl;
				break;
			}

			case 8:
			{
				double n = readNumber("Enter number to multiply by");
				cout << format(v1) << " * " << n << " = " << format(v1 * n) << endl;
				Vector result = v1 * n;
				break;
			}

			case 9:
			{
				Vector v2 = readVector("Enter coordinates of the second vectory of the scalar (dot) product");
				cout << format(v1) << " * " << format(v2) << " = " << (v1 * v2) << endl;
				break;
			}

			case 10:
			{
				Vector v2 = readVector("Enter coordinates of the second vectory of the vector product");
				cout << format(v1) << " ^ " << format(v2) << " = " << format(v1 ^ v2) << endl;
				break;
			}

			case 11:
			{
				Vector v2 = readVector("Enter coordinates of the second vectory of the mixed product");
				Vector v3 = readVector("Enter coordinates of the third vectory of the mixed product");
				cout << "( " << format(v1) << ", " << format(v2) << ", " << format(v3) << " ) = " << v1(v2, v3) << endl;
				break;
			}

			default:
				cout << "Invalid operation " << op << endl;
				showOperations = true;
				continue;
			}
		}
		catch (const GeometryException& exception) {
			cout << "Operation failed: " << exception.what() << endl;
		}
	}
}
