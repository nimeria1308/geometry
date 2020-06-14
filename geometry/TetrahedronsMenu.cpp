#include <sstream>

#include "menus.h"
#include "Tetrahedron.h"

using namespace std;
using namespace geometry;


TetrahedronsMenu::TetrahedronsMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

TetrahedronsMenu::~TetrahedronsMenu()
{
}

void TetrahedronsMenu::show()
{
	// main menu for tetrahedrons
	cout << "Operations on tetrahedrons" << endl;

	// initialize first tetrahedron
	Tetrahedron t1 = readTetrahedron("Enter coordinates of a new tetrahedron");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Check if regular" << endl;
			cout << "[ 2]: Check if orthogonal" << endl;
			cout << "[ 3]: Find area of the tetrahedron" << endl;
			cout << "[ 4]: Find perimeter of the tetrahedron" << endl;
			cout << "[ 5]: Check if a point is inside the volume of the tetrahedron" << endl;
			cout << "[ 6]: Check if a point is on the surfaces of the tetrahedron" << endl;
			cout << "[ 7]: Check if a point is outside the tetrahedron" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int)readNumber("Select an operation (0-7)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				cout << "The tetrahedron " << (t1.isRegular() ? "is" : "is NOT") << " regular" << endl;
				break;
			}

			case 2:
			{
				cout << "The tetrahedron " << (t1.isOrthogonal() ? "is" : "is NOT") << " orthogonal" << endl;
				break;
			}

			case 3:
			{
				cout << "The area of the tetrahedron is " << t1.area() << endl;
				break;
			}

			case 4:
			{
				cout << "The perimeter of the tetrahedron is " << t1.perimeter() << endl;
				break;
			}

			case 5:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p < t1 ? " is" : " is NOT") << " inside the tetrahedron" << endl;
				break;
			}

			case 6:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p == t1 ? " is" : " is NOT") << " on the surface of the tetrahedron" << endl;
				break;
			}

			case 7:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (p > t1 ? " is" : " is NOT") << " outside the tetrahedron" << endl;
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
