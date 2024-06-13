#include <gtest/gtest.h>
#include "../../src/naive/arithmetic.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/reduce.hpp"
#include "../../src/common.hpp"

namespace naive {

TEST(reduce, five)
{
    vi32 data  = iota(5);
    i32 result = reduce(data, Plus<int>{});
    EXPECT_EQ(result, 10);
}

// TODO: test plus reduction more thoroughly, including initial values
// TODO: test max reduction and min reduction

}
