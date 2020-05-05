#include "CppUnitTest.h"
#include "Segment.h"

#include<functional>
#include<sstream>

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

            TEST_METHOD(TestCtrTwoSamePoints)
            {
                Point p(10.0, 20.0, 30.0);

                auto f = [p] {Segment s(p, p); };
                Assert::ExpectException<VectorLengthException>(f);
            }

            TEST_METHOD(TestEquals)
            {
                Segment s1(Point(10, 20, 30), Point(20, 30, 40));
                Segment s2(Point(10, 20, 30), Point(20, 30, 40));
                Segment s3(Point(10, 20, 30), Point(30, 30, 40));

                Assert::IsTrue(s1 == s1);
                Assert::IsTrue(s1 == s2);
                Assert::IsTrue(s2 == s1);

                Assert::IsFalse(s1 == s3);
                Assert::IsFalse(s3 == s1);
            }

            TEST_METHOD(TestLength)
            {
                Vector v(10, 20, 30);
                Vector offset(5, 4, 15);
                Segment s(offset, v + offset);

                Assert::AreEqual(v.length(), s.length());
            }

            TEST_METHOD(TestMiddle)
            {
                Vector v(10, 20, 30);
                Vector offset(5, 4, 15);
                Segment s(offset, v + offset);
                Point middle = (v * 0.5) + offset;

                Assert::IsTrue(middle == s.middle());
            }

            TEST_METHOD(TestPointOnSegment)
            {
                Vector v(10, 20, 30);
                Vector offset(5, 4, 15);
                Segment s(offset, v + offset);
                Point middle = (v * 0.5) + offset;

                Assert::IsTrue(middle == s);
                Assert::IsTrue(s == middle);

                Assert::IsFalse(Point() == s);
                Assert::IsFalse(s == Point());
            }

            TEST_METHOD(TestStreams)
            {
                Segment s1(Point(10, 20, 30), Point(20, 30, 40));
                Segment s2(Point(-3.14, 29, 59), Point(3, -25, 10));

                stringstream stream;
                stream << s1 << " " << s2;

                Segment l1_read;
                Segment l2_read;
                stream >> l1_read >> l2_read;

                Assert::IsTrue(s1 == l1_read);
                Assert::IsTrue(s2 == l2_read);
            }
        };
    }
}
