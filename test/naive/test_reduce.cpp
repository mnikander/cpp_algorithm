#include <gtest/gtest.h>
#include "../../src/naive/arithmetic.hpp"
#include "../../src/naive/iota.hpp"
#include "../../src/naive/reduce.hpp"
#include "../../src/common.hpp"

namespace {

TEST(reduce, five)
{
    vi32 data  = nv::iota(5);
    i32 result = nv::reduce(data, nv::Plus<int>{});
    EXPECT_EQ(result, 10);
}

// TODO: test nv::plus reduction more thoroughly, including initial values
// TODO: test max reduction and min reduction

}
