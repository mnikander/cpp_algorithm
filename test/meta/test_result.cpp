#include <array>
#include <vector>
#include <gtest/gtest.h>
#include "../../src/meta/datatype_aliases.hpp"
#include "../../src/meta/result.hpp"
#include "../../src/size.hpp"

namespace {

// usage example for implementation 3
template<typename Range>
auto doStuff(Range const& range) -> decltype(meta::makeContainer<bool>(range))
{
    return meta::makeContainer<bool>(range);
}

TEST(result, vector3)
{
    vb8 result = doStuff(std::vector<int>(5)); // the real test is that this line compiles at all
    EXPECT_EQ(nv::size(result), 5);
}

TEST(result, array3)
{
    const std::array<bool, 5> result = doStuff(std::array<int, 5>()); // the real test is that this line compiles at all
    EXPECT_EQ(result.size(), 5);
}

}
