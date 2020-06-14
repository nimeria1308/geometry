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
			cout << "[ 4]: Lines" << endl;
			cout << "[ 5]: Segments" << endl;
			cout << "[ 6]: Triangles" << endl;
			cout << "[ 7]: Tetrahedrons" << endl;
			cout << endl;
		}

		int op = (int)readNumber("Select an operation (0-7)");

		switch (op) {
		case 0:
			return;

		case 2:
		{
			VectorsMenu menu;
			menu.show();
			break;
		}

		default:
			cout << "Invalid operation " << op << endl;
			continue;
		}
	}
}
