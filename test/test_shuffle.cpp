#include <gtest/gtest.h>
#include <random>

#include "../src/iota.hpp"
#include "../src/shuffle.hpp"
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

namespace {

TEST(shuffle, nothing)
{
    std::mt19937 generator(0);
    vi32 nothing = nv::iota(0);
    vi32 result  = nv::shuffle(nothing, generator);

    ASSERT_EQ(size(result), 0);
}

TEST(shuffle, letters)
{
    std::mt19937 generator(0);
    vc8 alphabet{'A', 'B', 'C', 'D', 'E'};
    vc8 result = nv::shuffle(alphabet, generator);
    
    ASSERT_EQ(size(result), 5);

    EXPECT_NE(result[0], 'A');
    EXPECT_NE(result[1], 'B');
    EXPECT_NE(result[2], 'C');
    EXPECT_NE(result[3], 'D');
    EXPECT_NE(result[4], 'E');
}

}
