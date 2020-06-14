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
			cout << "[ 1]: Check if two vectors are equal" << endl;
			cout << "[ 2]: Calculate length" << endl;
			cout << "[ 3]: Calculate direction" << endl;
			cout << "[ 4]: Check if zero" << endl;
			cout << "[ 5]: Check if parallel to another vector" << endl;
			cout << "[ 6]: Check if orthogonal to another vector" << endl;
			cout << "[ 7]: Add to another vector" << endl;
			cout << "[ 8]: Subtract from another vector" << endl;
			cout << "[ 9]: Multiply with a number" << endl;
			cout << "[10]: Scalar (dot) product with another vector" << endl;
			cout << "[11]: Vector product with another vector" << endl;
			cout << "[12]: Mixed product with another two vectors" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int) readNumber("Select an operation (0-12)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				Vector v2 = readVector("Enter coordinates of the second vector");
				cout << format(v1) << (v1 == v2 ? " == " : " != ") << format(v2) << endl;
				break;
			}

			case 2: {
				cout << "Length of " << format(v1) << " is " << v1.length() << endl;;
				break;
			}

			case 3:
				cout << "Direction of " << format(v1) << " is " << format(v1.direction()) << endl;
				break;

			case 4:
				cout << format(v1) << (v1.isZero() ? " is" : " is NOT") << " zero" << endl;
				break;

			case 5:
			{
				Vector v2 = readVector("Enter coordinates of the other vector");
				cout << format(v1) << (v1.isParallel(v2) ? " is" : " is NOT") << " parallel to vector " << format(v2) << endl;
				break;
			}

			case 6:
			{
				Vector v2 = readVector("Enter coordinates of the other vector");
				cout << format(v1) << (v1.isOrthogonal(v2) ? " is" : " is NOT") << " orthogonal to vector " << format(v2) << endl;
				break;
			}

			case 7:
			{
				Vector v2 = readVector("Enter coordinates of the vector you are adding");
				cout << format(v1) << " + " << format(v2) << " = " << format(v1 + v2) << endl;
				break;
			}

			case 8:
			{
				Vector v2 = readVector("Enter coordinates of the vector you are subtracting");
				cout << format(v1) << " - " << format(v2) << " = " << format(v1 - v2) << endl;
				break;
			}

			case 9:
			{
				double n = readNumber("Enter number to multiply by");
				cout << format(v1) << " * " << n << " = " << format(v1 * n) << endl;
				Vector result = v1 * n;
				break;
			}

			case 10:
			{
				Vector v2 = readVector("Enter coordinates of the second vector of the scalar (dot) product");
				cout << format(v1) << " * " << format(v2) << " = " << (v1 * v2) << endl;
				break;
			}

			case 11:
			{
				Vector v2 = readVector("Enter coordinates of the second vector of the vector product");
				cout << format(v1) << " ^ " << format(v2) << " = " << format(v1 ^ v2) << endl;
				break;
			}

			case 12:
			{
				Vector v2 = readVector("Enter coordinates of the second vector of the mixed product");
				Vector v3 = readVector("Enter coordinates of the third vector of the mixed product");
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
