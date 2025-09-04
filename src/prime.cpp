
// prime.cpp
#include "prime.hpp"
#include <cmath>

// TODO: Implement isPrimeHalf
bool isPrimeHalf(int n, long long* modOps) {
    long long ops = 0;

    if (n <= 1) { //neg/zero
        if (modOps) *modOps = 0;
        return false;
    }
    if (n == 2) { // prime 
        if (modOps) *modOps = 0;
        return true;
    }

    // Check even numbers
    ops++;
    if (n % 2 == 0) {
        if (modOps) *modOps = ops;
        return false;
    }

    // Check divisibility from 3 to n/2
    for (int d = 3; d <= n / 2; d += 2) {
        ops++;
        if (n % d == 0) {
            if (modOps) *modOps = ops;
            return false;
        }
    }

    if (modOps) *modOps = ops;
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    long long ops = 0;

    if (n <= 1) {
        if (modOps) *modOps = 0;
        return false;
    }
    if (n == 2) {
        if (modOps) *modOps = 0;
        return true;
    }

    // Check even numbers
    ops++;
    if (n % 2 == 0) {
        if (modOps) *modOps = ops;
        return false;
    }

    int limit = static_cast<int>(std::sqrt(n));
    for (int d = 3; d <= limit; d += 2) {
        ops++;
        if (n % d == 0) {
            if (modOps) *modOps = ops;
            return false;
        }
    }

    if (modOps) *modOps = ops;
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    long long totalOps = 0;
    for (int n = lo; n <= hi; ++n) {
        long long ops = 0;
        isPrime(n, &ops);
        totalOps += ops;
    }
    return totalOps;
}
