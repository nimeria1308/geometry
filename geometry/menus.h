#ifndef GEOMETRY_MENUS_H
#define GEOMETRY_MENUS_H

#include <iostream>

#include "Point.h"
#include "Vector.h"

namespace geometry {

	class Menu {
	public:
		Menu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~Menu();

		// abstract
		virtual void show() = 0;

	protected:
		double readNumber(const std::string& prompt);
		std::string format(const Point& point);

		std::istream& input;
		bool showPrompts;
	};

	class MainMenu : public Menu {
	public:
		MainMenu();
		virtual ~MainMenu();
		virtual void show();
	};

	class GeometrySelectMenu : public Menu {
	public:
		GeometrySelectMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~GeometrySelectMenu();
		virtual void show();
	};

	class VectorsMenu : public Menu {
	public:
		VectorsMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~VectorsMenu();
		virtual void show();

	protected:
		Vector readVector(const std::string& message);
	};
};

#endif
