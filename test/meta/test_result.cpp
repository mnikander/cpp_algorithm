#include <array>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/meta/result.hpp"
#include "../../src/common.hpp"

namespace meta {

// ----------------------------------------------------------------------------

// usage example for implementation 2
template<typename Range>
auto doStuff2(Range const& range) -> decltype(makeContainer<bool>(range)) // this notation is less familiar to me
{
    return makeContainer<bool>(range);
}

TEST(result, vector2)
{
    vb8 result = doStuff2(std::vector<int>(5)); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

TEST(result, array2)
{
    const std::array<bool, 5> result = doStuff2(std::array<int, 5>()); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

// ----------------------------------------------------------------------------

// usage example for implementation 3
template<typename Range>
typename ResultTraits<bool, Range>::Type doStuff3(Range const& range)                   // very compact
{
    return makeContainer<bool>(range);
}

TEST(result, vector3)
{
    vb8 result = doStuff3(std::vector<int>(5)); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

TEST(result, array3)
{
    const std::array<bool, 5> result = doStuff3(std::array<int, 5>()); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

// ----------------------------------------------------------------------------

}
