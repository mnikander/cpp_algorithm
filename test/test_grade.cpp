#include <gtest/gtest.h>
#include <functional>
#include <string>
#include <vector>
#include "../src/iota.hpp"
#include "../src/gather.hpp"
#include "../src/grade.hpp"
#include "../src/size.hpp"
#include "../src/meta/global_datatypes.hpp"

namespace {

TEST(grade, nothing)
{
    vi32 result = nv::grade(nv::iota(0), std::less<int>{});
    
    ASSERT_EQ(size(result), 0);
}

TEST(grade, no_operation)
{
    vi32 result = nv::grade(nv::iota(5), std::less<int>{});
    
    ASSERT_EQ(size(result), 5);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 3);
    EXPECT_EQ(result[4], 4);
}

TEST(grade, reverse)
{
    vc8 data    = {'a', 'b', 'c'};
    vi32 result = nv::grade(data, std::greater<char>{});
    
    ASSERT_EQ(size(result), size(data));
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 0);
}

TEST(grade, weights)
{
    const std::vector<std::string> objects = {"person", "house", "car", "bottle", "backpack"};
    vf32 weight                            = {100.0, 10000.0, 1000.0, 1.0, 10.0};
    vi32 order                             = nv::grade(weight, std::less<float>{});

    ASSERT_EQ(size(objects), size(weight)); // if this fails the two data vectors in this test don't match
    ASSERT_EQ(size(order), size(weight));
    EXPECT_EQ(order[0], 3);
    EXPECT_EQ(order[1], 4);
    EXPECT_EQ(order[2], 0);
    EXPECT_EQ(order[3], 2);
    EXPECT_EQ(order[4], 1);

    const auto objectsByWeight = nv::gather(objects, order);

    EXPECT_EQ(objectsByWeight[0], "bottle");
    EXPECT_EQ(objectsByWeight[1], "backpack");
    EXPECT_EQ(objectsByWeight[2], "person");
    EXPECT_EQ(objectsByWeight[3], "car");
    EXPECT_EQ(objectsByWeight[4], "house");
}

TEST(grade, xpr)
{
    vi32 result = vc8{'b', 'a', 'c'} | xpr::grade(std::less<char>{});

    ASSERT_EQ(size(result), 3);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 2);
}

}
