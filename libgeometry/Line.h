#ifndef GEOMETRY_LINE_H
#define GEOMETRY_LINE_H

#include <cstdbool>
#include "Vector.h"

namespace geometry
{
    class Line : public Vector {
    public:
        // ctr/dtr
        Line();
        Line(const Point& point, const Vector& vector);
        Line(const Point& p1, const Point& p2);
        virtual ~Line() { }

        // methods

        // direction
        const Vector& direction() const;

        // normal vector
        Vector normal() const;

        // angle in radians between the two lines
        double angle(const Line& other) const;

        // operators

        // tochka leji na prava
        bool operator+(const Point& point) const;

        // usporednost na pravi
        bool operator||(const Line& other) const;

        // dali suvpadat
        bool operator==(const Line& other) const;

        // dali se presichat
        bool operator&&(const Line& other) const;

        // dali sa krastosani
        bool operator!=(const Line& other) const;

        // dali sa perpendikuliarni
        bool operator|(const Line& other) const;

    protected:
        // fields

        // tova e posokata na otsechkata
        // Point s koito e inicializirana e offset-a ot nulata
        Vector directionVector;
    };

    // triabva ni non-member za da proverqvame + vector
    bool operator+(const Point& point, const Line& line);
}

std::ostream& operator<<(std::ostream& out, const geometry::Line& line);
std::istream& operator>>(std::istream& in, geometry::Line& line);

#endif