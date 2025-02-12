#include "queue.h"
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Memory : public IMemory
{

};


template <typename T>

class QueueFixture : public ::testing::Test
{

};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);


TYPED_TEST(QueueFixture, empty)
{

}