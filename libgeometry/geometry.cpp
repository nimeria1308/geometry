#include "geometry.h"

namespace geometry {

    const double DEFAULT_PRECISION = 0.001;

    static double gPrecision = DEFAULT_PRECISION;

    double getPrecision()
    {
        return gPrecision;
    }

    void setPrecision(double precision)
    {
        gPrecision = precision;
    }
}