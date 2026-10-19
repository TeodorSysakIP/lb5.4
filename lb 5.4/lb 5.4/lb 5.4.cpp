// Лабораторна робота № 5.4
// Обчислення добутку за допомогою рекурсії
// Варіант 13:  P = prod_{k=N}^{25} sqrt(1 + N/k)

#define _CRT_SECURE_NO_WARNINGS   // для scanf у Visual Studio

#include <stdio.h>
#include <math.h>

#define LAST 25               // верхня межа добутку

// Множник добутку: sqrt(1 + N/k)
double term(const int N, const int k)
{
    return sqrt(1. + (double)N / k);
}

// 5) Ітераційний спосіб (для контролю)
double P0(const int N)
{
    double p = 1;
    for (int k = N; k <= LAST; k++)
        p *= term(N, k);
    return p;
}

// 1) Рекурсивний спуск, параметр k спадає (LAST -> N).
//    Добуток накопичується в параметрі t під час спуску.
double P1(const int N, const int k, double t)
{
    t = t * term(N, k);
    if (k <= N)
        return t;
    else
        return P1(N, k - 1, t);
}

// 2) Рекурсивний спуск, параметр k зростає (N -> LAST).
double P2(const int N, const int k, double t)
{
    t = t * term(N, k);
    if (k >= LAST)
        return t;
    else
        return P2(N, k + 1, t);
}

// 3) Рекурсивний підйом, параметр k спадає (LAST -> N).
//    Добуток обчислюється при поверненні з рекурсії.
double P3(const int N, const int k)
{
    if (k < N)
        return 1;
    else
        return term(N, k) * P3(N, k - 1);
}

// 4) Рекурсивний підйом, параметр k зростає (N -> LAST).
double P4(const int N, const int k)
{
    if (k > LAST)
        return 1;
    else
        return term(N, k) * P4(N, k + 1);
}

int main(void)
{
    int N;

    printf("N (1..%d) = ", LAST);
    if (scanf("%d", &N) != 1 || N < 1 || N > LAST)
    {
        printf("Некоректне N: потрібно 1 <= N <= %d\n", LAST);
        return 1;
    }

    printf("(iter)        P0 = %.10f\n", P0(N));
    printf("(rec down --) P1 = %.10f\n", P1(N, LAST, 1));
    printf("(rec down ++) P2 = %.10f\n", P2(N, N, 1));
    printf("(rec up --)   P3 = %.10f\n", P3(N, LAST));
    printf("(rec up ++)   P4 = %.10f\n", P4(N, N));

    return 0;
}
