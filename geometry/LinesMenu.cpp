#include <sstream>

#include "menus.h"
#include "Line.h"

using namespace std;
using namespace geometry;


LinesMenu::LinesMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

LinesMenu::~LinesMenu()
{
}

void LinesMenu::show()
{
	// main menu for lines
	cout << "Operations on lines" << endl;

	// initialize first line
	Line l1 = readLine("Enter coordinates of a new line");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Calculate direction" << endl;
			cout << "[ 2]: Calculate normal vector" << endl;
			cout << "[ 3]: Calculate angle with another line" << endl;
			cout << "[ 4]: Check if a point is on the line" << endl;
			cout << "[ 5]: Check if parallel to another line" << endl;
			cout << "[ 6]: Check if overlaps (coincides) with another line" << endl;
			cout << "[ 7]: Check if intersects another line" << endl;
			cout << "[ 8]: Check if skews (is crossed) with another line" << endl;
			cout << "[ 9]: Check if orthogonal to another line" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int)readNumber("Select an operation (0-9)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				cout << "Direction of the line is " << format(l1.direction()) << endl;
				break;
			}

			case 2:
			{
				cout << "A normal vector to the line is " << format(l1.normal()) << endl;
				break;
			}

			case 3:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The angle between the two lines is " << l1.angle(l2) << endl;
				break;
			}

			case 4:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (l1 + p ? " is" : " is NOT") << " on the line" << endl;
				break;
			}

			case 5:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The lines " << (l1 || l2 ? "are" : "are NOT") << " parallel" << endl;
				break;
			}

			case 6:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The lines " << (l1 == l2 ? "" : "do NOT " ) << "overlap (coincide)" << endl;
				break;
			}

			case 7:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The lines " << (l1 && l2 ? "" : "do NOT ") << "intersect" << endl;
				break;
			}

			case 8:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The lines " << (l1 != l2 ? "are" : "are NOT") << " skewed (crossed)" << endl;
				break;
			}

			case 9:
			{
				Line l2 = readLine("Enter coordinates of the second line");
				cout << "The lines " << (l1 | l2 ? "are" : "are NOT") << " orthogonal" << endl;
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
