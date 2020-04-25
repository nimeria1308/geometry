#include "Exception.h"

using namespace geometry;
using namespace std;

GeometryException::GeometryException()
{
}

GeometryException::GeometryException(const string& what)
    : message(what)
{
}

const char* GeometryException::what() const throw()
{
    return message.c_str();
}
