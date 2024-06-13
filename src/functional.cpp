#include "functional.hpp"

namespace xpr {

// function overloads which just return the TAG

// logical
meta::LogicalNot logical_not() {return meta::LogicalNot{}; }
meta::LogicalAnd logical_and() {return meta::LogicalAnd{}; }
meta::LogicalOr logical_or() {return meta::LogicalOr{}; }

// unary
meta::Identity identity() {return meta::Identity{}; }
meta::Negate negate() {return meta::Negate{}; }

// binary
meta::Plus plus() {return meta::Plus{}; }
meta::Minus minus() {return meta::Minus{}; }
meta::Times times() {return meta::Times{}; }
meta::Divided divided() {return meta::Divided{}; }
meta::Power power() {return meta::Power{}; }
meta::Min min() {return meta::Min{}; }
meta::Max max() {return meta::Max{}; }
meta::Equal equal() {return meta::Equal{}; }
meta::Unequal unequal() {return meta::Unequal{}; }
meta::Less less() {return meta::Less{}; }
meta::LessEqual less_equal() {return meta::LessEqual{}; }
meta::Greater greater() {return meta::Greater{}; }
meta::GreaterEqual greater_equal() {return meta::GreaterEqual{}; }
meta::LeastCommonMultiple least_common_multiple() {return meta::LeastCommonMultiple{}; }
meta::GreatestCommonDivisor greatest_common_divisor() {return meta::GreatestCommonDivisor{}; }

}
