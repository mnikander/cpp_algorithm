#include "functional.hpp"

namespace xpr {

// unary
nv::LogicalNot logical_not() { return nv::LogicalNot{}; }
nv::Identity identity() { return nv::Identity{}; }
nv::Negate negate() { return nv::Negate{}; }

// binary
nv::LogicalAnd logical_and() { return nv::LogicalAnd{}; }
nv::LogicalOr logical_or()  { return nv::LogicalOr{}; }
nv::Plus plus() { return nv::Plus{}; }
nv::Minus minus() { return nv::Minus{}; }
nv::Multiply multipy() { return nv::Multiply{}; }
nv::Divide divide() { return nv::Divide{}; }
nv::Power power() { return nv::Power{}; }
nv::Minimum minimum() { return nv::Minimum{}; }
nv::Maximum maximum() { return nv::Maximum{}; }
nv::Equal equal()  { return nv::Equal{}; }
nv::NotEqual not_equal() { return nv::NotEqual{}; }
nv::Less less()  { return nv::Less{}; }
nv::LessEqual less_equal() { return nv::LessEqual{}; }
nv::Greater greater() { return nv::Greater{}; }
nv::GreaterEqual greater_equal() { return nv::GreaterEqual{}; }
nv::LeastCommonMultiple least_common_multiple() { return nv::LeastCommonMultiple{}; }
nv::GreatestCommonDivisor greatest_common_divisor() { return nv::GreatestCommonDivisor{}; }

}
