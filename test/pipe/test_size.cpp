#include <gtest/gtest.h>
#include "../../src/pipe/size.hpp"
#include "../../src/datatype_aliases.hpp"

namespace {

TEST(pipe_size, none)
{
    vi32 data  = {};
    i32 result = data | xpr::size();
    EXPECT_EQ(result, 0);
}

TEST(pipe_size, one)
{
    vi32 data  = {0};
    i32 result = data | xpr::size();
    EXPECT_EQ(result, 1);
}

}
