#include "CppUnitTest.h"
#include "Vector.h"

#include <functional>
#include <sstream>

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

            TEST_METHOD(TestEquals)
            {
                Vector a(10.0, 20.0, 30.0);
                Vector b(10.0, 20.0, 30.0);
                Vector c(10.0, 20.0, 30.1);

                Assert::IsTrue(a == a);
                Assert::IsTrue(a == b);
                Assert::IsTrue(b == a);
                Assert::IsFalse(a == c);
                Assert::IsFalse(c == a);
            }

            TEST_METHOD(TestLength)
            {
                Vector zero;
                Vector identity(1, 0, 0);
                Vector v1(10, 0, 0);
                Vector v2(3, 4, 0);

                Assert::AreEqual(0.0, zero.length());
                Assert::AreEqual(1.0, identity.length());
                Assert::AreEqual(10.0, v1.length());
                Assert::AreEqual(5.0, v2.length());
            }

            TEST_METHOD(TestDirection)
            {
                Vector identity(1, 0, 0);
                Vector v1(10, 0, 0);
                Vector v2(3, 4, 0);

                auto f = [] { Vector().direction(); };
                Assert::ExpectException<VectorLengthException>(f);

                Assert::IsTrue(identity == identity.direction());
                Assert::IsTrue(identity.direction() == v1.direction());
                Assert::IsTrue(Vector(0.6, 0.8, 0) == v2.direction());
            }

            TEST_METHOD(TestIsZero)
            {
                Vector zero;
                Vector identity(1, 0, 0);

                Assert::IsTrue(zero.isZero());
                Assert::IsFalse(identity.isZero());
            }

            TEST_METHOD(TestIsParallel)
            {
                Vector v1(1, 0, 0);
                Vector v2(4, 0, 0);
                Vector v3(1, 1, 0);

                auto f1 = [v1] { Vector().isParallel(v1); };
                Assert::ExpectException<VectorLengthException>(f1);

                auto f2 = [v1] { v1.isParallel(Vector()); };
                Assert::ExpectException<VectorLengthException>(f2);

                Assert::IsTrue(v1.isParallel(v2));
                Assert::IsTrue(v2.isParallel(v1));
                Assert::IsFalse(v1.isParallel(v3));
                Assert::IsFalse(v3.isParallel(v1));
            }

            TEST_METHOD(TestIsPerpendicular)
            {
                Vector v1(1, 0, 0);
                Vector v2(0, 1, 0);
                Vector v3(4, 0, 0);

                auto f1 = [v1] { Vector().isPerpendicular(v1); };
                Assert::ExpectException<VectorLengthException>(f1);

                auto f2 = [v1] { v1.isPerpendicular(Vector()); };
                Assert::ExpectException<VectorLengthException>(f2);

                Assert::IsTrue(v1.isPerpendicular(v2));
                Assert::IsTrue(v2.isPerpendicular(v1));
                Assert::IsFalse(v1.isPerpendicular(v3));
                Assert::IsFalse(v3.isPerpendicular(v1));
            }

            TEST_METHOD(TestAdditionVector)
            {
                Vector v1(10, 20, 30);
                Vector v2(100, 200, 300);
                Vector v3(110, 220, 330);

                Assert::IsTrue(v3 == (v1 + v2));
                Assert::IsTrue(v3 == (v2 + v1));
            }

            TEST_METHOD(TestSubtractionVector)
            {
                Vector v1(110, 220, 330);
                Vector v2(100, 200, 300);
                Vector v3(10, 20, 30);
                Vector v4(-10, -20, -30);

                Assert::IsTrue(v3 == (v1 - v2));
                Assert::IsTrue(v4 == (v2 - v1));
            }

            TEST_METHOD(TestMultiplicationDouble)
            {
                Vector v1(10, 20, 30);
                Vector v2(40, 80, 120);

                Assert::IsTrue(v2 == (v1 * 4));
                Assert::IsTrue(v2 == (4 * v1));
            }

            TEST_METHOD(TestScalarProduct)
            {
                Vector v1(1, 2, 3);
                Vector v2(3, 4, 5);

                // direction does not matter
                Assert::AreEqual(26.0, v1 * v2);
                Assert::AreEqual(26.0, v2 * v1);
            }

            TEST_METHOD(TestVectorProduct)
            {
                Vector v1(1, 2, 3);
                Vector v2(3, 4, 5);

                // direction matters
                Assert::IsTrue(Vector(-2, 4, -2) == (v1 ^ v2));
            }

            TEST_METHOD(TestMixedProduct)
            {
                Vector v1(1, 4, 8);
                Vector v2(3, 4, 5);
                Vector v3(5, 6, 7);

                // v1 * (v2 ^ v3)
                // (1, 4, 8) * (-2, 4, -2) = 0
                Assert::AreEqual(-2.0, v1(v2, v3));
            }

            TEST_METHOD(TestStreams)
            {
                Vector v1(10, -7.12, 3.1415);
                Vector v2(40, -1.13, 5.05);
                stringstream stream;
                stream << v1 << " " << v2;

                Vector v1_read;
                Vector v2_read;
                stream >> v1_read >> v2_read;

                Assert::IsTrue(v1 == v1_read);
                Assert::IsTrue(v2 == v2_read);
            }
        };
    }
}
