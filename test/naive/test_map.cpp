#include <gtest/gtest.h>
#include "../../src/naive/iota.hpp"
#include "../../src/naive/map.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(map, nothing)
{
    vi32 data   = nv::iota(5);
    vi32 result = nv::map(data, [](int i){ return i; });
    ASSERT_EQ(size(data), size(result));
    EXPECT_EQ(data, result);
}

TEST(map, square)
{
    vi32 data   = nv::iota(5);
    vi32 result = nv::map(data, [](int i){ return i*i; });
    ASSERT_EQ(size(data), size(result));
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 4);
    EXPECT_EQ(result[3], 9);
    EXPECT_EQ(result[4], 16);
}

}
