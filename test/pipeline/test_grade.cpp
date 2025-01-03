#include <gtest/gtest.h>
#include <functional>
#include <string>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/gather.hpp"
#include "../../src/pipeline/grade.hpp"
#include "../../src/pipeline/size.hpp"

namespace {

TEST(grade, xpr)
{
    vi32 result = vc8{'b', 'a', 'c'} | xpr::grade(std::less<char>{});

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 2);
}

}
