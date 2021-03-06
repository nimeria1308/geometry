#ifndef GEOMETRY_EXCEPTION_H
#define GEOMETRY_EXCEPTION_H

#include <string>
#include <exception>

namespace geometry
{
    class GeometryException : public std::exception {
    public:
        GeometryException();
        GeometryException(const std::string& what);

        virtual const char* what() const throw();

    private:
        std::string message;
    };

    class EqualPointException : public GeometryException {
    public:
        EqualPointException();
        EqualPointException(const std::string& what);
    };
}

#endif
