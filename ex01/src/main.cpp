//
// Created by tjooris on 1/13/26.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"
#include "Serializer.hpp"

TEST_CASE("Serializer serialize and deserialize")
{
    Data originalData;
    originalData.intValue = 42;
    originalData.strValue = "Hello, World!";

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    CHECK(deserializedData->intValue == originalData.intValue);
    CHECK(deserializedData->strValue == originalData.strValue);
}

TEST_CASE("Serializer with multiple Data instances")
{
    Data data1;
    data1.intValue = 1;
    data1.strValue = "Data One";

    Data data2;
    data2.intValue = 2;
    data2.strValue = "Data Two";

    uintptr_t raw1 = Serializer::serialize(&data1);
    uintptr_t raw2 = Serializer::serialize(&data2);

    Data* deserializedData1 = Serializer::deserialize(raw1);
    Data* deserializedData2 = Serializer::deserialize(raw2);

    CHECK(deserializedData1->intValue == data1.intValue);
    CHECK(deserializedData1->strValue == data1.strValue);
    CHECK(deserializedData2->intValue == data2.intValue);
    CHECK(deserializedData2->strValue == data2.strValue);
}