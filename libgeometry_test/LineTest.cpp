#include "CppUnitTest.h"
#include "Line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace geometry
{
    namespace test {
        TEST_CLASS(LineTest)
        {
        public:
            TEST_METHOD(TestCtrDefault)
            {
                Line l;
                Assert::AreEqual(0.0, l.getX());
                Assert::AreEqual(0.0, l.getY());
                Assert::AreEqual(0.0, l.getZ());
            }

            TEST_METHOD(TestCtrPointVector)
            {
                Point p(10.0, 20.0, 30.0);
                Vector v(10.0, 5.0, 17.0);

                Line l(p, v);
                Assert::AreEqual(10.0, l.getX());
                Assert::AreEqual(20.0, l.getY());
                Assert::AreEqual(30.0, l.getZ());

                Assert::AreEqual(0.491473, 0.00001, l.direction().getX());
                Assert::AreEqual(0.245737, 0.00001, l.direction().getY());
                Assert::AreEqual(0.835504, 0.00001, l.direction().getZ());
            }

            TEST_METHOD(TestCtrTwoPoints)
            {
                Point p(10.0, 20.0, 30.0);
                Point p2(20.0, 25.0, 47.0);

                Line l(p, p2);
                Assert::AreEqual(10.0, l.getX());
                Assert::AreEqual(20.0, l.getY());
                Assert::AreEqual(30.0, l.getZ());

                Assert::AreEqual(0.491473, 0.00001, l.direction().getX());
                Assert::AreEqual(0.245737, 0.00001, l.direction().getY());
                Assert::AreEqual(0.835504, 0.00001, l.direction().getZ());
            }
        };
    }
}
