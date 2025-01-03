// Copyright (c) 2024, Marco Nikander

#include <gtest/gtest.h>
#include <vector>
#include "../../src/meta/global_datatypes.hpp"
#include "../../src/pipeline/all.hpp"
#include "../../src/pipeline/iota.hpp"
#include "../../src/pipeline/size.hpp"
#include "../../src/functional.hpp"

namespace {

TEST(all, xpr)
{
    b8 t = vi32{0,1} | xpr::all(nv::Equal{}, vi32{0,1});
    b8 f = vi32{0,0} | xpr::all(nv::Equal{}, vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

TEST(all, xpr_lambda)
{
    b8 t = vi32{0,1} | xpr::all([](int l, int r) { return l == r; }, vi32{0,1});
    b8 f = vi32{0,0} | xpr::all([](int l, int r) { return l == r; }, vi32{0,1});
    EXPECT_TRUE(t);
    EXPECT_FALSE(f);
}

}
