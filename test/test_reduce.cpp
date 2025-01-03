#include <gtest/gtest.h>
#include "../src/functional.hpp"
#include "../src/iota.hpp"
#include "../src/reduce.hpp"
#include "../src/meta/global_datatypes.hpp"

namespace {

TEST(reduce, five)
{
    vi32 data  = nv::iota(5);
    i32 result = nv::reduce(data, nv::Plus{});
    EXPECT_EQ(result, 10);
}

// TODO: test nv::plus reduction more thoroughly, including initial values
// TODO: test maximum reduction and minimum reduction

TEST(reduce, xpr_add)
{
    i32 result = vi32{1, 2, 4, 8, 16} | xpr::reduce(nv::Plus{}, 0);
    EXPECT_EQ(result, 31);
}

TEST(reduce, xpr_mul)
{
    i32 result = vi32{1, 2, 4} | xpr::reduce(nv::Multiply{}, 1);
    EXPECT_EQ(result, 8);
}

TEST(reduce, xpr_default_init)
{
    i32 result = vi32{1, 2, 4} | xpr::reduce(nv::Multiply{});
    EXPECT_EQ(result, 8);
}

}
