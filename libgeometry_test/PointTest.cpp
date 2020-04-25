#include "CppUnitTest.h"
#include "Point.h"

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
        };
    }
}
