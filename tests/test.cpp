#include "prime.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// --- Prime identification ---
TEST_CASE("Prime numbers are correctly identified", "[prime]") {
    long long ops;

    REQUIRE(isPrimeHalf(2, &ops));
    REQUIRE(ops == 0);  // no modulo for 2
    REQUIRE(isPrimeSqrt(2, &ops));
    REQUIRE(ops == 0);

    REQUIRE(isPrimeHalf(3, &ops));
    REQUIRE(isPrimeSqrt(3, &ops));

    REQUIRE(isPrimeHalf(97, &ops));
    REQUIRE(isPrimeSqrt(97, &ops));
}

// --- Composite numbers ---
TEST_CASE("Composite numbers are correctly rejected", "[composite]") {
    long long ops;

    REQUIRE_FALSE(isPrimeHalf(4, &ops));
    REQUIRE_FALSE(isPrimeSqrt(4, &ops));

    REQUIRE_FALSE(isPrimeHalf(9, &ops));
    REQUIRE_FALSE(isPrimeSqrt(9, &ops));

    REQUIRE_FALSE(isPrimeHalf(100, &ops));
    REQUIRE_FALSE(isPrimeSqrt(100, &ops));
}

// --- Consistency check ---
TEST_CASE("Both algorithms give the same result in a range", "[consistency]") {
    for (int n = 2; n <= 200; ++n) {
        REQUIRE(isPrimeHalf(n) == isPrimeSqrt(n));
    }
}

// --- Modulo operation counts ---
TEST_CASE("Modulo operation counts are tracked", "[modops]") {
    long long ops;

    isPrimeHalf(4, &ops);
    REQUIRE(ops >= 1); // should check %2

    isPrimeSqrt(4, &ops);
    REQUIRE(ops >= 1);

    isPrimeHalf(9, &ops);
    REQUIRE(ops > 1); // must test %3
}

//Edge cases
TEST_CASE("Edge cases handled properly", "[edge]") {
    long long ops;

    REQUIRE_FALSE(isPrimeHalf(0, &ops));
    REQUIRE(ops == 0);

    REQUIRE_FALSE(isPrimeSqrt(1, &ops));
    REQUIRE(ops == 0);

    REQUIRE(isPrimeHalf(2, &ops));
    REQUIRE(isPrimeSqrt(2, &ops));
}