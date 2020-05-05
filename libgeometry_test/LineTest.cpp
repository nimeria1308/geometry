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

                Assert::AreEqual(0.0, l.start().getX());
                Assert::AreEqual(0.0, l.start().getY());
                Assert::AreEqual(0.0, l.start().getZ());

                Assert::IsTrue(l.direction().isZero());
            }

            TEST_METHOD(TestCtrPointVector)
            {
                Point p(10.0, 20.0, 30.0);
                Vector v(10.0, 5.0, 17.0);

                Line l(p, v);
                Assert::AreEqual(10.0, l.getX());
                Assert::AreEqual(20.0, l.getY());
                Assert::AreEqual(30.0, l.getZ());

                Assert::AreEqual(10.0, l.start().getX());
                Assert::AreEqual(20.0, l.start().getY());
                Assert::AreEqual(30.0, l.start().getZ());

                Assert::AreEqual(0.491473, 0.00001, l.direction().getX());
                Assert::AreEqual(0.245737, 0.00001, l.direction().getY());
                Assert::AreEqual(0.835504, 0.00001, l.direction().getZ());
            }

            TEST_METHOD(TestCtrPointZeroVector)
            {
                Point p(10, 20, 30);

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
            }

            TEST_METHOD(TestCtrTwoSamePoints)
            {
                Point p(10.0, 20.0, 30.0);

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

            TEST_METHOD(TestNormal)
            {
                // ima 2 normalni vectora na ravnina,
                // no bezbroi mnogo normalni na prava
                // dostatachno usolvie e da sa perpendikuliarni
                Line l(Point(10, 20, 30), Point(20, 30, 40));
                Vector normal = l.normal();

                Assert::IsTrue(l.direction().isOrthogonal(normal));
            }

            TEST_METHOD(TestAngle)
            {
                Line l1(Point(), Vector(4, -3, 5));
                Line l2(Point(), Vector(9, 7, -10));

                Assert::AreEqual(1.903, 0.001, l1.angle(l2));
                Assert::AreEqual(1.903, 0.001, l2.angle(l1));
            }

            TEST_METHOD(TestPointOnLine)
            {
                // tochka leji na prava
                Point p1(30, 20, 0);
                Point p2(20, 20, 0);
                Line l(Point(10, 0, 0), Vector(1, 1, 0));

                Assert::IsTrue(l + p1);
                Assert::IsTrue(p1 + l);

                Assert::IsFalse(l + p2);
                Assert::IsFalse(p2 + l);
            }

            TEST_METHOD(TestParallel)
            {
                // usporednost na pravi
                Vector v(10, 20, 30);
                Line l1(Point(20, 30, 40), v);
                Line l2(Point(-3, 4, 9), v);
                Line l3(Point(20, 30, 40), v + Vector(0, 0, 1));

                Assert::IsTrue(l1 || l1);

                Assert::IsTrue(l1 || l2);
                Assert::IsTrue(l2 || l1);

                Assert::IsFalse(l1 || l3);
                Assert::IsFalse(l3 || l1);
            }

            TEST_METHOD(TestIntersect)
            {
                // dali se presichat
                Line l1(Point(0, 10, 0), Vector(1, 0, 0));
                Line l2(Point(10, 0, 0), Vector(0, 1, 0));
                Line l3(Point(-5, -5, 0), Vector(0, 0, 1));

                Assert::IsTrue(l1 && l2);
                Assert::IsTrue(l2 && l1);

                Assert::IsFalse(l1 && l3);
                Assert::IsFalse(l3 && l1);
            }

            TEST_METHOD(TestSkewed)
            {
                // dali sa krastosani (ne se presichat i ne sa usporedni)
                Line l1(Point(0, 10, 0), Vector(1, 0, 0));
                Line l2(Point(-5, -5, 0), Vector(0, 0, 1));
                Line l3(Point(0, 20, 0), Vector(1, 0, 0));
                Line l4(Point(10, 0, 0), Vector(0, 1, 0));

                Assert::IsTrue(l1 != l2);
                Assert::IsTrue(l2 != l1);

                Assert::IsFalse(l1 != l3);
                Assert::IsFalse(l3 != l1);

                Assert::IsFalse(l1 != l4);
                Assert::IsFalse(l4 != l1);
            }

            TEST_METHOD(TestOrthogonal)
            {
                // dali sa perpendikuliarni
                //bool operator|(const Line & other) const;
                Line l1(Point(0, 10, 0), Vector(1, 0, 0));
                Line l2(Point(10, 0, 0), Vector(0, 1, 0));
                Line l3(Point(10, 0, 0), Vector(1, 1, 0));

                Assert::IsTrue(l1 | l2);
                Assert::IsTrue(l2 | l1);

                Assert::IsFalse(l1 | l3);
                Assert::IsFalse(l3 | l1);
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
