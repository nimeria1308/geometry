#include "CppUnitTest.h"
#include "Point.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace geometry
{
    namespace test {
        TEST_CLASS(PointTest)
        {
        public:
            TEST_METHOD(TestCtrDefault)
            {
                Point p;
                Assert::AreEqual(0.0, p.getX());
                Assert::AreEqual(0.0, p.getY());
                Assert::AreEqual(0.0, p.getZ());
            }

            TEST_METHOD(TestCtrXYZ)
            {
                Point p(10.0, -9.12, 3.1415);
                Assert::AreEqual(10.0, p.getX());
                Assert::AreEqual(-9.12, p.getY());
                Assert::AreEqual(3.1415, p.getZ());
            }

            TEST_METHOD(TestEquals)
            {
                Point a(10.0, 20.0, 30.0);
                Point b(10.0, 20.0, 30.0);
                Point c(10.0, 20.0, 30.1);

                Assert::IsTrue(a == a);
                Assert::IsTrue(a == b);
                Assert::IsTrue(b == a);
                Assert::IsTrue(a == Point(a));
                Assert::IsFalse(a == c);
                Assert::IsFalse(c == a);
                Assert::IsFalse(Point(a) == c);
            }

            TEST_METHOD(TestPrecision)
            {
                double p_under = getPrecision() / 10.0;
                double p_over = getPrecision() * 10;
                Point a(10, 20, 30);
                Point b(10 + p_under, 20 + p_under, 30 + p_under);
                Point c(10 + p_over, 20 + p_over, 30 + p_over);

                Assert::IsTrue(a == b);
                Assert::IsFalse(a == c);
            }

            TEST_METHOD(TestStreams)
            {
                Point p1(10, -7.12, 3.1415);
                Point p2(40, -1.13, 5.05);
                stringstream stream;
                stream << p1 << " " << p2;

                Point p1_read;
                Point p2_read;
                stream >> p1_read >> p2_read;

                Assert::IsTrue(p1 == p1_read);
                Assert::IsTrue(p2 == p2_read);
            }
        };
    }
}
