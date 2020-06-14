#include <sstream>

#include "menus.h"
#include "Vector.h"

using namespace std;
using namespace geometry;


GeometrySelectMenu::GeometrySelectMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

GeometrySelectMenu::~GeometrySelectMenu()
{
}

void GeometrySelectMenu::show()
{
	// main menu for vectors
	cout << "Geometric types" << endl;

	// choose an operation
	while (true) {
		if (showPrompts) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Points" << endl;
			cout << "[ 2]: Vectors" << endl;
			cout << "[ 3]: Lines" << endl;
			cout << "[ 4]: Segments" << endl;
			cout << "[ 5]: Triangles" << endl;
			cout << "[ 6]: Tetrahedrons" << endl;
			cout << endl;
		}

		int op = (int)readNumber("Select an operation (0-6)");

		switch (op) {
		case 0:
			return;

		case 1:
		{
			PointsMenu menu(input, showPrompts);
			menu.show();
			break;
		}

		case 2:
		{
			VectorsMenu menu(input, showPrompts);
			menu.show();
			break;
		}

		default:
			cout << "Invalid operation " << op << endl;
			continue;
		}
	}
}
