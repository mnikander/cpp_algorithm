#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/none.hpp"
#include "../../src/pipeline/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(none, xpr)
{
    b8 a = vi32{0,0} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(a);

    b8 b = vi32{0,1} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(b);
    
    b8 c = vi32{1,0} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(c);

    b8 d = vi32{1,1} | xpr::none(nv::Equal{}, vi32{0,0});
    EXPECT_TRUE(d);
}

TEST(none, xpr_lambda)
{
    b8 a = vi32{0,0} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(a);

    b8 b = vi32{0,1} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(b);

    b8 c = vi32{1,0} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(c);

    b8 d = vi32{1,1} | xpr::none([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_TRUE(d);
}

}
