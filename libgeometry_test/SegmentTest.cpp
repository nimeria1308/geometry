#include "CppUnitTest.h"
#include "Segment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace geometry
{
    namespace test {
        TEST_CLASS(SegmentTest)
        {
        public:
            TEST_METHOD(TestCtrDefault)
            {
                Segment s;
                Assert::AreEqual(0.0, s.getX());
                Assert::AreEqual(0.0, s.getY());
                Assert::AreEqual(0.0, s.getZ());

                Assert::AreEqual(0.0, s.start().getX());
                Assert::AreEqual(0.0, s.start().getY());
                Assert::AreEqual(0.0, s.start().getZ());
                Assert::AreEqual(0.0, s.end().getX());
                Assert::AreEqual(0.0, s.end().getY());
                Assert::AreEqual(0.0, s.end().getZ());
            }

            TEST_METHOD(TestCtrTwoPoints)
            {
                Point p(10.0, 20.0, 30.0);
                Point p2(20.0, 25.0, 47.0);

                Segment s(p, p2);
                Assert::AreEqual(10.0, s.getX());
                Assert::AreEqual(20.0, s.getY());
                Assert::AreEqual(30.0, s.getZ());

                Assert::AreEqual(10.0, s.start().getX());
                Assert::AreEqual(20.0, s.start().getY());
                Assert::AreEqual(30.0, s.start().getZ());
                Assert::AreEqual(20.0, s.end().getX());
                Assert::AreEqual(25.0, s.end().getY());
                Assert::AreEqual(47.0, s.end().getZ());

                Assert::AreEqual(0.491473, 0.00001, s.direction().getX());
                Assert::AreEqual(0.245737, 0.00001, s.direction().getY());
                Assert::AreEqual(0.835504, 0.00001, s.direction().getZ());
            }
        };
    }
}
