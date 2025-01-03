#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/filter.hpp"
#include "../../src/pipeline/size.hpp"

namespace {

TEST(filter, xpr)
{
    vi32 result = vi32{0, 1, 2, 3, 4} | xpr::filter([](int i){ return i % 2 == 0; });

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 4);
}

}
