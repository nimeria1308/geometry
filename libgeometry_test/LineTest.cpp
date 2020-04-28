#include "CppUnitTest.h"
#include "Line.h"

#include<functional>
#include<sstream>

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

                auto f = [p] {Line l(p, Vector()); };
                Assert::ExpectException<VectorLengthException>(f);
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

                auto f = [p] {Line l(p, p); };
                Assert::ExpectException<VectorLengthException>(f);
            }

            TEST_METHOD(TestEquals)
            {
                Line l1(Point(10, 20, 30), Point(20, 30, 40));
                Line l2(Point(10, 20, 30), Point(20, 30, 40));
                Line l3(Point(10, 20, 30), Point(30, 30, 40));

                Assert::IsTrue(l1 == l1);
                Assert::IsTrue(l1 == l2);
                Assert::IsTrue(l2 == l1);
                Assert::IsFalse(l1 == l3);
                Assert::IsFalse(l3 == l1);
            }

            TEST_METHOD(TestStreams)
            {
                Line l1(Point(10, 20, 30), Point(20, 30, 40));
                Line l2(Point(-3.14, 29, 59), Point(3, -25, 10));

                stringstream stream;
                stream << l1 << " " << l2;

                Line l1_read;
                Line l2_read;
                stream >> l1_read >> l2_read;

                Assert::IsTrue(l1 == l1_read);
                Assert::IsTrue(l2 == l2_read);
            }
        };
    }
}
