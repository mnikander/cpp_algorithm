#include <array>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/meta/result.hpp"
#include "../../src/common.hpp"

namespace meta {

// usage example for implementation 3
template<typename Range>
auto doStuff(Range const& range) -> decltype(makeContainer<bool>(range))
{
    return makeContainer<bool>(range);
}

TEST(result, vector3)
{
    vb8 result = doStuff(std::vector<int>(5)); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

TEST(result, array3)
{
    const std::array<bool, 5> result = doStuff(std::array<int, 5>()); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

}
