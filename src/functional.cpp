#include "functional.hpp"

namespace xpr {

// unary
nv::LogicalNot not_l() { return nv::LogicalNot{}; }
nv::Identity id()    { return nv::Identity{}; }
nv::Negate neg()   { return nv::Negate{}; }

// binary
nv::LogicalAnd and_l() { return nv::LogicalAnd{}; }
nv::LogicalOr or_l()  { return nv::LogicalOr{}; }
nv::Plus add() { return nv::Plus{}; }
nv::Minus sub() { return nv::Minus{}; }
nv::Times mul() { return nv::Times{}; }
nv::Divided div() { return nv::Divided{}; }
nv::Power pow() { return nv::Power{}; }
nv::Min min() { return nv::Min{}; }
nv::Max max() { return nv::Max{}; }
nv::Equal eq()  { return nv::Equal{}; }
nv::Unequal ueq() { return nv::Unequal{}; }
nv::Less le()  { return nv::Less{}; }
nv::LessEqual leq() { return nv::LessEqual{}; }
nv::Greater gre() { return nv::Greater{}; }
nv::GreaterEqual geq() { return nv::GreaterEqual{}; }
nv::LeastCommonMultiple lcm() { return nv::LeastCommonMultiple{}; }
nv::GreatestCommonDivisor gcd() { return nv::GreatestCommonDivisor{}; }

}
