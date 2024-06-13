#include <array>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/meta/result_factory.hpp"
#include "../../src/common.hpp"

namespace meta {

// usage example for implementation 1
template<typename Range>
typename ResultFactory<Range, bool>::Container doStuff1(Range const& range)
{
    return ResultFactory<Range, bool>{}(range);
}

TEST(result, vector1)
{
    vb8 result = doStuff1(std::vector<int>(5)); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

TEST(result, array1)
{
    std::array<bool, 5> const result = doStuff1(std::array<int, 5>()); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

}
