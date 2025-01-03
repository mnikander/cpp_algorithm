#include <gtest/gtest.h>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/functional.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/reduce.hpp"

namespace {

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
