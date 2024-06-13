#include <gtest/gtest.h>
#include <vector>
#include "../src/iota.hpp"
#include "../src/filter.hpp"
#include "../src/size.hpp"
#include "../src/meta/datatype_aliases.hpp"

namespace {

TEST(filter, none)
{
    vi32 data   = {};
    vi32 result = nv::filter(data, [](int i){ (void)i; return true; });

    ASSERT_EQ(size(result), 0);
}

TEST(filter, one)
{
    vi32 data   = {0};
    vi32 result = nv::filter(data, [](int i){ return i == 0; });

    ASSERT_EQ(size(result), 1);
}

TEST(filter, one_of_three)
{
    vi32 data   = {0, 1, 2};
    vi32 result = nv::filter(data, [](int i){ return i == 1; });

    ASSERT_EQ(size(result), 1);
    EXPECT_EQ(result[0], 1);
}

TEST(filter, even)
{
    vi32 data   = {0, 1, 2, 3, 4};
    vi32 result = nv::filter(data, [](int i){ return i % 2 == 0; });

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 4);
}

TEST(filter, odd)
{
    vi32 data   = {0, 1, 2, 3, 4};
    vi32 result = nv::filter(data, [](int i){ return i % 2 == 1; });

    ASSERT_EQ(size(result), 2);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 3);
}

}
