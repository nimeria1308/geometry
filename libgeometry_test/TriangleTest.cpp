#include "CppUnitTest.h"
#include "Triangle.h"
#include "Exception.h"

#include<functional>
#include<sstream>

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

            TEST_METHOD(TestCtrSamePoints)
            {
                Point a(1, 2, 3);
                Point b(a);
                Point c(10, 20, 30);

                auto f1 = [a, b, c] {Triangle t(a, b, c); };
                Assert::ExpectException<EqualPointException>(f1);

                auto f2 = [a, b, c] {Triangle t(c, a, b); };
                Assert::ExpectException<EqualPointException>(f2);
            }

            TEST_METHOD(TestEquals)
            {
                Point a(1.0, 2.0, 3.0);
                Point b(10.0, 20.0, 30.0);
                Point c(100.0, 200.0, 300.0);
                Point d(200.0, 200.0, 300.0);

                Triangle t1(a, b, c);
                Triangle t2(a, b, c);
                Triangle t3(a, b, d);

                Assert::IsTrue(t1 == t1);

                Assert::IsTrue(t1 == t2);
                Assert::IsTrue(t2 == t1);

                Assert::IsFalse(t1 == t3);
                Assert::IsFalse(t3 == t1);
            }

            TEST_METHOD(TestStreams)
            {
                Point a(1.0, 2.0, 3.0);
                Point b(10.0, 20.0, 30.0);
                Point c(100.0, 200.0, 300.0);
                Point d(200.0, 200.0, 300.0);

                Triangle t1(a, b, c);
                Triangle t2(d, c, b);

                stringstream stream;
                stream << t1 << " " << t2;

                Triangle t1_read;
                Triangle t2_read;
                stream >> t1_read >> t2_read;

                Assert::IsTrue(t1 == t1_read);
                Assert::IsTrue(t2 == t2_read);
            }
        };
    }
}
