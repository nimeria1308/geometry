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

string Menu::format(const Point& point)
{
	ostringstream os;
	os << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";
	return os.str();
}
