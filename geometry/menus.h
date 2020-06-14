#ifndef GEOMETRY_MENUS_H
#define GEOMETRY_MENUS_H

#include <iostream>

#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "Tetrahedron.h"

namespace geometry {

	class Menu {
	public:
		Menu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~Menu();

		// abstract
		virtual void show() = 0;

	protected:
		double readNumber(const std::string& prompt);
		Point readPoint(const std::string& message);
		Vector readVector(const std::string& message);
		Line readLine(const std::string& message);
		Segment readSegment(const std::string& message);
		Triangle readTriangle(const std::string& message);
		Tetrahedron readTetrahedron(const std::string& message);

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

	class PointsMenu : public Menu {
	public:
		PointsMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~PointsMenu();
		virtual void show();
	};

	class VectorsMenu : public Menu {
	public:
		VectorsMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~VectorsMenu();
		virtual void show();
	};

	class LinesMenu : public Menu {
	public:
		LinesMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~LinesMenu();
		virtual void show();
	};

	class SegmentsMenu : public Menu {
	public:
		SegmentsMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~SegmentsMenu();
		virtual void show();
	};

	class TrianglesMenu : public Menu {
	public:
		TrianglesMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~TrianglesMenu();
		virtual void show();
	};

	class TetrahedronsMenu : public Menu {
	public:
		TetrahedronsMenu(std::istream& input = std::cin, bool showPrompts = true);
		virtual ~TetrahedronsMenu();
		virtual void show();
	};
};

#endif
