//
// Created by tjooris on 1/13/26.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"
#include "Base.hpp"

TEST_CASE("Generate and identify types")
{
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness

    for (int i = 0; i < 10; ++i)
    {
        Base* basePtr = generate();

        std::cout << "Identifying using pointer: ";
        identify(basePtr);

        std::cout << "Identifying using reference: ";
        identify(*basePtr);

        delete basePtr;
    }
}

TEST_CASE("Identify with null pointer")
{
    Base* nullPtr = NULL;

    std::cout << "Identifying null pointer: ";
    identify(nullPtr);
}

TEST_CASE("Identify with invalid reference")
{
    class Dummy : public Base {};
    Dummy dummy;

    std::cout << "Identifying invalid reference: ";
    identify(dummy);
}