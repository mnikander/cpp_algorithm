#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/simple/iota.hpp"
#include "../../src/simple/reduce.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(reduce, five)
{
    vi32 data  = nv::iota(5);
    i32 result = nv::reduce(data, nv::Plus{});
    EXPECT_EQ(result, 10);
}

// TODO: test nv::plus reduction more thoroughly, including initial values
// TODO: test maximum reduction and minimum reduction

}
