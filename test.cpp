#include "queue.h"
#include <string>
#include <cstdint>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Memory : public IMemory
{
    std::vector<void *> vec;
    uint8_t block[8192];
    public:
        MOCK_METHOD(void *, malloc, (size_t size), (override));
        MOCK_METHOD(void, free, (void *ptr), (override));
        void *allocate(size_t size) 
        {
            static size_t pos{0};

            void *ptr{&block[pos]};

            vec.push_back(ptr);
            pos += size;

            return ptr;

        }

        void release(void *ptr)
        {
            vec.erase(std::remove(vec.begin(), vec.end(), ptr), vec.end());
        }

        ~Memory() {EXPECT_EQ(0, vec.size()); }

};


template <typename T>
class QueueFixture : public ::testing::Test
{
    protected:
        Memory memory;
        Queue<T> queue{memory};
};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);


TYPED_TEST(QueueFixture, enqueueAndSize)
{

}

TYPED_TEST(QueueFixture, empty)
{

}