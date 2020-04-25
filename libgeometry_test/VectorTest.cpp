#include "CppUnitTest.h"
#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace geometry
{
    namespace test {
        TEST_CLASS(VectorTest)
        {
        public:
            TEST_METHOD(TestCtrDefault)
            {
                Vector v;
                Assert::AreEqual(0.0, v.getX());
                Assert::AreEqual(0.0, v.getY());
                Assert::AreEqual(0.0, v.getZ());
            }

            TEST_METHOD(TestCtrXYZ)
            {
                Vector v(10.0, -9.12, 3.1415);
                Assert::AreEqual(10.0, v.getX());
                Assert::AreEqual(-9.12, v.getY());
                Assert::AreEqual(3.1415, v.getZ());
            }

            TEST_METHOD(TestCtrPoint)
            {
                Point p(10.0, -9.12, 3.1415);

                Vector v(p);
                Assert::AreEqual(10.0, v.getX());
                Assert::AreEqual(-9.12, v.getY());
                Assert::AreEqual(3.1415, v.getZ());
            }

            TEST_METHOD(TestCtrTwoPoints)
            {
                Point p1(10.0, 20.0, 30.0);
                Point p2(100.0, 200.0, 300.0);

                Vector v(p1, p2);
                Assert::AreEqual(90.0, v.getX());
                Assert::AreEqual(180.0, v.getY());
                Assert::AreEqual(270.0, v.getZ());
            }
        };
    }
}
