#include <gtest/gtest.h>
#include "../src/size.hpp"
#include "../src/datatype_aliases.hpp"

namespace {

TEST(size, xpr_none)
{
    vi32 data  = {};
    i32 result = data | xpr::size();
    EXPECT_EQ(result, 0);
}

TEST(size, xpr_one)
{
    vi32 data  = {0};
    i32 result = data | xpr::size();
    EXPECT_EQ(result, 1);
}

}
