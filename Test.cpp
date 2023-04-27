//
// Created by super on 4/22/23.
//
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Fraction's constructor throws exception if denominator is 0"){
    CHECK_THROWS_AS(Fraction(1,0), invalid_argument);
}

TEST_CASE("Fraction's constructor don't throw exception if nominator is 0"){
    CHECK_NOTHROW(Fraction(0,1));
}

TEST_CASE("Fraction's constructor will create a reduced formed fraction"){
    Fraction f1(12, 48);
    Fraction f2(1, 4);

    CHECK(f1 == f2);
}

TEST_CASE("+, -, *, / operator return reduce form fraction when accepting fraction as an argument"){
    Fraction f1(12,48);
    Fraction f2(6, 48);
    Fraction f3(3, 8);

    CHECK((f1+f2) == f3);
}

TEST_CASE("- operator return reduce form fraction when accepting fraction as an argument"){
    Fraction f1(12,48);
    Fraction f2(6, 48);
    Fraction f3(1, 8);

    CHECK((f1-f2) == f3);
}

TEST_CASE("* operator return reduce form fraction when accepting fraction as an argument"){
    Fraction f1(12,48);
    Fraction f2(6, 48);
    Fraction f3(1, 32);

    CHECK((f1*f2) == f3);
}

TEST_CASE("/ operator return reduce form fraction when accepting fraction as an argument"){
    Fraction f1(12,48);
    Fraction f2(6, 48);
    Fraction f3(2, 1);

    CHECK((f1/f2) == f3);
}

TEST_CASE("+ operator return reduce form fraction when accepting double as an argument"){
    Fraction f1(12,48);
    Fraction f3(3, 8);

    CHECK((f1+0.125) == f3);
}

TEST_CASE("- operator return reduce form fraction when accepting double as an argument"){
    Fraction f1(12,48);
    Fraction f3(1, 8);

    CHECK((f1-0.125) == f3);
}

TEST_CASE("* operator return reduce form fraction when accepting double as an argument"){
    Fraction f1(12,48);
    Fraction f3(1, 32);

    CHECK((f1*0.125) == f3);
}

TEST_CASE("/ operator return reduce form fraction when accepting double as an argument"){
    Fraction f1(12,48);
    Fraction f3(2, 1);

    CHECK((f1/0.125) == f3);
}

TEST_CASE("+ operator return reduce form fraction when accepting int as an argument"){
    Fraction f1(12,48);
    Fraction f3(3, 8);

    CHECK((f1+0.125) == f3);
}

TEST_CASE("- operator return reduce form fraction when accepting int as an argument"){
    Fraction f1(12,48);
    Fraction f3(1, 8);

    CHECK((f1-0.125) == f3);
}

TEST_CASE("* operator return reduce form fraction when accepting int as an argument"){
    Fraction f1(12,48);
    Fraction f3(1, 32);

    CHECK((f1*0.125) == f3);
}

TEST_CASE("/ operator return reduce form fraction when accepting int as an argument"){
    Fraction f1(12,48);
    Fraction f3(2, 1);

    CHECK((f1/0.125) == f3);
}

TEST_CASE("== operator return true if two fractions are equal"){
    Fraction f1(12,48);
    Fraction f2(1, 4);

    CHECK(f1 == f2);
}

TEST_CASE("== operator return false if two fractions are not equal"){
    Fraction f1(12,48);
    Fraction f2(1, 3);

    CHECK_FALSE(f1 == f2);
}

TEST_CASE("!= operator return true if two fractions are not equal"){
    Fraction f1(12,48);
    Fraction f2(1, 3);

    CHECK(f1 != f2);
}

TEST_CASE("!= operator return false if two fractions are equal"){
    Fraction f1(12,48);
    Fraction f2(1, 4);

    CHECK_FALSE(f1 != f2);
}

TEST_CASE("> operator return true if first fraction is bigger than the second"){
    Fraction f1(1,3);
    Fraction f2(1, 4);

    CHECK(f1 > f2);
}

TEST_CASE("> operator return false if first fraction is smaller than the second"){
    Fraction f1(1,48);
    Fraction f2(1, 3);

    CHECK_FALSE(f1 > f2);
}

TEST_CASE("< operator return true if first fraction is smaller than the second"){
    Fraction f1(12,48);
    Fraction f2(1, 3);

    CHECK(f1 < f2);
}

TEST_CASE("< operator return false if first fraction is bigger than the second"){
    Fraction f1(1,3);
    Fraction f2(1, 4);

    CHECK_FALSE(f1 < f2);
}

TEST_CASE(">= operator return true if first fraction is bigger or equal to the second"){
    Fraction f1(12,48);
    Fraction f2(1, 4);

    CHECK(f1 >= f2);
}

TEST_CASE(">= operator return false if first fraction is smaller than the second"){
    Fraction f1(12,48);
    Fraction f2(1, 3);

    CHECK_FALSE(f1 >= f2);
}

TEST_CASE("<= operator return true if first fraction is smaller or equal to the second"){
    Fraction f1(12,48);
    Fraction f2(1, 3);

    CHECK(f1 <= f2);
}

TEST_CASE("<= operator return false if first fraction is bigger than the second"){
    Fraction f1(1,2);
    Fraction f2(1, 4);

    CHECK_FALSE(f1 <= f2);
}


