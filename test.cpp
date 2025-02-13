#include "queue.h"
#include <string>
#include <tuple>
#include <cstdint>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;
class Memory : public IMemory
{
    size_t pos{0};
    std::vector<void *> vec;
    uint8_t block[8192];

public:
    MOCK_METHOD(void *, malloc, (size_t size), (override));
    MOCK_METHOD(void, free, (void *ptr), (override));
    void *allocate(size_t size)
    {

        void *ptr{nullptr};

        if ((pos + size) < sizeof(block))
        {
            ptr = &block[pos];
            vec.push_back(ptr);
            pos += size;
        }

        return ptr;
    }

    void release(void *ptr)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), ptr), vec.end());
    }

    ~Memory() { EXPECT_EQ(0, vec.size()); }
};

template <typename T>
class QueueFixture : public ::testing::Test
{
    std::tuple<
        std::vector<int>,
        std::vector<float>,
        std::vector<std::string>>
        allValues{
            {1, 2, 3, 4, 5},
            {1.5f, 2.5f, 3.5f, 4.5f, 5.5f},
            {"aaa", "bbb", "ccc", "ddd", "eee"}};

protected:
    const std::vector<T> values{std::get<std::vector<T>>(allValues)};

    NiceMock<Memory> mock;

    Queue<T> queue{mock};

    void SetUp(void) override
    {
    }

    void TearDown(void) override {}
};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);

TYPED_TEST(QueueFixture, empty)
{
}
