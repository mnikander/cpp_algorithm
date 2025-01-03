#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/any.hpp"
#include "../../src/pipeline/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(any, xpr)
{
    b8 a = vi32{0,0} | xpr::any(nv::Equal{}, vi32{0,0});
    EXPECT_TRUE(a);

    b8 b = vi32{0,1} | xpr::any(nv::Equal{}, vi32{0,0});
    EXPECT_TRUE(b);
    
    b8 c = vi32{1,0} | xpr::any(nv::Equal{}, vi32{0,0});
    EXPECT_TRUE(c);

    b8 d = vi32{1,1} | xpr::any(nv::Equal{}, vi32{0,0});
    EXPECT_FALSE(d);
}

TEST(any, xpr_lambda)
{
    b8 a = vi32{0,0} | xpr::any([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_TRUE(a);

    b8 b = vi32{0,1} | xpr::any([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_TRUE(b);

    b8 c = vi32{1,0} | xpr::any([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_TRUE(c);

    b8 d = vi32{1,1} | xpr::any([](int l, int r) { return l == r; }, vi32{0,0});
    EXPECT_FALSE(d);
}

}
