#include <sstream>

#include "menus.h"
#include "Segment.h"

using namespace std;
using namespace geometry;


SegmentsMenu::SegmentsMenu(istream& input, bool showPrompts)
	: Menu(input, showPrompts)
{
}

SegmentsMenu::~SegmentsMenu()
{
}

void SegmentsMenu::show()
{
	// main menu for segments
	cout << "Operations on segments" << endl;

	// initialize first segment
	Segment s1 = readSegment("Enter coordinates of a new segment");

	// choose an operation
	bool showOperations = true;
	while (true) {
		if (showPrompts && showOperations) {
			cout << "Available operations:" << endl;
			cout << "[ 0]: Exit menu" << endl;
			cout << "[ 1]: Calculate length" << endl;
			cout << "[ 2]: Calculate middle point" << endl;
			cout << "[ 3]: Check if a point is in the segment" << endl;
		}
		cout << endl;

		showOperations = false;
		int op = (int)readNumber("Select an operation (0-3)");

		try {
			switch (op) {
			case 0:
				return;

			case 1:
			{
				cout << "Length of the segment is " << s1.length() << endl;
				break;
			}

			case 2:
			{
				cout << "The middle point of the segment is " << format(s1.middle()) << endl;
				break;
			}

			case 3:
			{
				Point p = readPoint("Enter coordinates of the point");
				cout << "Point " << format(p) << (s1 == p ? " is" : " is NOT") << " on the segment" << endl;
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
