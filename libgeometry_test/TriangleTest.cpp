#include "CppUnitTest.h"
#include "Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace geometry
{
    namespace test {
        TEST_CLASS(TriangleTest)
        {
        public:
            TEST_METHOD(TestCtrDefault)
            {
                Triangle t;
                Assert::AreEqual(0.0, t.getA().getX());
                Assert::AreEqual(0.0, t.getA().getY());
                Assert::AreEqual(0.0, t.getA().getZ());
                Assert::AreEqual(0.0, t.getB().getX());
                Assert::AreEqual(0.0, t.getB().getY());
                Assert::AreEqual(0.0, t.getB().getZ());
                Assert::AreEqual(0.0, t.getC().getX());
                Assert::AreEqual(0.0, t.getC().getY());
                Assert::AreEqual(0.0, t.getC().getZ());
            }

            TEST_METHOD(TestCtrThreePoints)
            {
                Point a(1.0, 2.0, 3.0);
                Point b(10.0, 20.0, 30.0);
                Point c(100.0, 200.0, 300.0);

                Triangle t(a, b, c);
                Assert::AreEqual(1.0, t.getA().getX());
                Assert::AreEqual(2.0, t.getA().getY());
                Assert::AreEqual(3.0, t.getA().getZ());
                Assert::AreEqual(10.0, t.getB().getX());
                Assert::AreEqual(20.0, t.getB().getY());
                Assert::AreEqual(30.0, t.getB().getZ());
                Assert::AreEqual(100.0, t.getC().getX());
                Assert::AreEqual(200.0, t.getC().getY());
                Assert::AreEqual(300.0, t.getC().getZ());
            }
        };
    }
}
