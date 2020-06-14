#include "menus.h"

#include <fstream>

using namespace std;
using namespace geometry;

MainMenu::MainMenu()
	: Menu(cin, true)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::show()
{
	cout << "Main menu" << endl;

	// choose an operation
	while (true) {
		cout << "Available operations:" << endl;
		cout << "[ 0]: Exit application" << endl;
		cout << "[ 1]: Run in interactive mode" << endl;
		cout << "[ 2]: Automated mode from file" << endl;
		cout << endl;

		int op = (int)readNumber("Select an operation (0-2)");

		switch (op) {
		case 0:
			return;

		case 1:
		{
			GeometrySelectMenu menu;
			menu.show();
			break;
		}

		case 2:
		{
			string filename;
			cout << "Enter filename: ";
			while (filename.empty()) {
				getline(cin, filename);
			}
			ifstream f(filename, istream::in);
			if (f.fail()) {
				cout << "Could not open `" << filename << "`" << endl;
				break;
			}

			cout << "Reading from file `" << filename << "`" << endl;

			GeometrySelectMenu menu(f, false);
			menu.show();

			break;
		}

		default:
			cout << "Invalid operation " << op << endl;
			continue;
		}
	}
}
