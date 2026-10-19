#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#define LAST 25   
double term(const int N, const int k)
{
    return std::sqrt(1. + (double)N / k);
}

double P0(const int N)
{
    double p = 1;
    for (int k = N; k <= LAST; k++)
        p *= term(N, k);
    return p;
}

double P1(const int N, const int k, double t)
{
    t = t * term(N, k);
    if (k <= N)
        return t;
    else
        return P1(N, k - 1, t);
}

double P2(const int N, const int k, double t)
{
    t = t * term(N, k);
    if (k >= LAST)
        return t;
    else
        return P2(N, k + 1, t);
}

double P3(const int N, const int k)
{
    if (k < N)
        return 1;
    else
        return term(N, k) * P3(N, k - 1);
}

double P4(const int N, const int k)
{
    if (k > LAST)
        return 1;
    else
        return term(N, k) * P4(N, k + 1);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab54
{
    TEST_CLASS(UnitTestLab54)
    {
    public:

        
        TEST_METHOD(TestIterative_N1)
        {
            Assert::AreEqual(std::sqrt(26.0), P0(1), 1e-9);
        }

        
        TEST_METHOD(TestIterative_N25)
        {
            Assert::AreEqual(std::sqrt(2.0), P0(25), 1e-9);
        }

        
        TEST_METHOD(TestIterative_N5)
        {
            Assert::AreEqual(std::sqrt(1131.0), P0(5), 1e-9);
        }

        
        TEST_METHOD(TestRecursiveEqualsIterative)
        {
            for (int N = 1; N <= 25; N++)
            {
                double p0 = P0(N);
                Assert::AreEqual(p0, P1(N, 25, 1), 1e-9);
                Assert::AreEqual(p0, P2(N, N, 1), 1e-9);
                Assert::AreEqual(p0, P3(N, 25), 1e-9);
                Assert::AreEqual(p0, P4(N, N), 1e-9);
            }
        }
    };
}