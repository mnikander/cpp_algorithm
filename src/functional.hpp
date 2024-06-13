#pragma once

#include <algorithm>
#include <cmath>
#include <numeric> // gcd, lcm

namespace nv {

// Logical operators
template <typename T> struct LogicalNot  { T operator()(T t) const { return !t; } };
template <typename T> struct LogicalAnd  { T operator()(T lhs, T rhs) const { return lhs && rhs; } };
template <typename T> struct LogicalOr   { T operator()(T lhs, T rhs) const { return lhs || rhs; } };

// unary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Identity     { T operator()(T t) const { return t; } };
template <typename T> struct Negate       { T operator()(T t) const { return -t; } };

// binary ops, which are both: (1) a tag which represents the operation and (2) the implementation of that operation
template <typename T> struct Plus         { T operator()(T lhs, T rhs) const { return lhs + rhs; } };
template <typename T> struct Minus        { T operator()(T lhs, T rhs) const { return lhs - rhs; } };
template <typename T> struct Times        { T operator()(T lhs, T rhs) const { return lhs * rhs; } };
template <typename T> struct Divided      { T operator()(T lhs, T rhs) const { return lhs / rhs; } };
template <typename T> struct Power        { T operator()(T base, T exp) const { return std::pow(base, exp); } };
template <typename T> struct Min          { T operator()(T lhs, T rhs) const { return std::min(lhs, rhs); } };
template <typename T> struct Max          { T operator()(T lhs, T rhs) const { return std::max(lhs, rhs); } };
template <typename T> struct Equal        { bool operator()(T lhs, T rhs) const { return lhs == rhs; } };
template <typename T> struct Unequal      { bool operator()(T lhs, T rhs) const { return lhs != rhs; } };
template <typename T> struct Less         { bool operator()(T lhs, T rhs) const { return lhs < rhs; } };
template <typename T> struct LessEqual    { bool operator()(T lhs, T rhs) const { return lhs <= rhs; } };
template <typename T> struct Greater      { bool operator()(T lhs, T rhs) const { return lhs > rhs; } };
template <typename T> struct GreaterEqual { bool operator()(T lhs, T rhs) const { return lhs >= rhs; } };

template <typename T> struct LeastCommonMultiple { T operator()(T lhs, T rhs) const { return std::lcm(lhs,rhs); } };
template <> struct LeastCommonMultiple<bool> { bool operator()(bool lhs, bool rhs) const { return lhs && rhs; } };
// note that AND is a specialization of LCM for booleans

template <typename T> struct GreatestCommonDivisor { T operator()(T lhs, T rhs) const { return std::gcd(lhs,rhs); } };
template <> struct GreatestCommonDivisor<bool> { bool operator()(bool lhs, bool rhs) const { return lhs || rhs; } };
// note that OR is a specialization of GCD for booleans

}

namespace meta {

// NEVER use these meta-programming tags and functions in client code

// tags (without template parameters) which correspond to the above functors
struct LogicalNot{};
struct LogicalOr{};
struct LogicalAnd{};

struct Identity{};
struct Negate{};
struct Plus{};
struct Minus{};
struct Times{};
struct Divided{};
struct Power{};
struct Min{};
struct Max{};
struct Equal{};
struct Unequal{};
struct Less{};
struct LessEqual{};
struct Greater{};
struct GreaterEqual{};
struct LeastCommonMultiple{};
struct GreatestCommonDivisor{};

// dispatch function which converts the tag to the correct functor and sets the template T
// intended to simplify the signatures of algorithms such as 'map'
template <typename T> auto dispatch(LogicalNot tag, T) { return nv::LogicalNot<T>{}; }
template <typename T> auto dispatch(LogicalAnd tag, T) { return nv::LogicalAnd<T>{}; }
template <typename T> auto dispatch(LogicalOr tag, T) { return nv::LogicalOr<T>{}; }
template <typename T> auto dispatch(Identity tag, T) { return nv::Identity<T>{}; }
template <typename T> auto dispatch(Negate tag, T) { return nv::Negate<T>{}; }
template <typename T> auto dispatch(Plus tag, T) { return nv::Plus<T>{}; }
template <typename T> auto dispatch(Minus tag, T) { return nv::Minus<T>{}; }
template <typename T> auto dispatch(Times tag, T) { return nv::Times<T>{}; }
template <typename T> auto dispatch(Divided tag, T) { return nv::Divided<T>{}; }
template <typename T> auto dispatch(Power tag, T) { return nv::Power<T>{}; }
template <typename T> auto dispatch(Min tag, T) { return nv::Min<T>{}; }
template <typename T> auto dispatch(Max tag, T) { return nv::Max<T>{}; }
template <typename T> auto dispatch(Equal tag, T) { return nv::Equal<T>{}; }
template <typename T> auto dispatch(Unequal tag, T) { return nv::Unequal<T>{}; }
template <typename T> auto dispatch(Less tag, T) { return nv::Less<T>{}; }
template <typename T> auto dispatch(LessEqual tag, T) { return nv::LessEqual<T>{}; }
template <typename T> auto dispatch(Greater tag, T) { return nv::Greater<T>{}; }
template <typename T> auto dispatch(GreaterEqual tag, T) { return nv::GreaterEqual<T>{}; }
template <typename T> auto dispatch(LeastCommonMultiple tag, T) { return nv::LeastCommonMultiple<T>{}; }
template <typename T> auto dispatch(GreatestCommonDivisor tag, T) { return nv::GreatestCommonDivisor<T>{}; }

}

namespace xpr {

// function overloads: if there are NO arguments return the TAG, else if there ARE arguments execute the actual function

// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// This led me to introduce the prefix 'logical' to all of the names. 
                      auto logical_not() {return meta::LogicalNot{}; }                                       // get the tag
template <typename T> auto logical_not(T const& t) { return nv::LogicalNot<T>{}(t); }                        // execute function
                      auto logical_and() {return meta::LogicalAnd{}; }                                       // get the tag
template <typename T> auto logical_and(T const& lhs, T const& rhs) { return nv::LogicalAnd<T>{}(lhs, rhs); } // execute function
                      auto logical_or() {return meta::LogicalOr{}; }                                         // get the tag
template <typename T> auto logical_or(T const& lhs, T const& rhs) { return nv::LogicalOr<T>{}(lhs, rhs); }   // execute function

// unary
                      auto identity() {return meta::Identity{}; }                                     // get the tag
template <typename T> auto identity(T const& t) { return nv::Identity<T>{}(t); }                      // execute function
                      auto negate() {return meta::Negate{}; }                                         // get the tag
template <typename T> auto negate(T const& t) { return nv::Negate<T>{}(t); }                          // execute function

// binary
                      auto plus() {return meta::Plus{}; }                                             // get the tag
template <typename T> auto plus(T const& lhs, T const& rhs) { return nv::Plus<T>{}(lhs, rhs); }       // execute function
                      auto minus() {return meta::Minus{}; }                                           // get the tag
template <typename T> auto minus(T const& lhs, T const& rhs) { return nv::Minus<T>{}(lhs, rhs); }     // execute function
                      auto times() {return meta::Times{}; }                                           // get the tag
template <typename T> auto times(T const& lhs, T const& rhs) { return nv::Times<T>{}(lhs, rhs); }     // execute function
                      auto divided() {return meta::Divided{}; }                                       // get the tag
template <typename T> auto divided(T const& lhs, T const& rhs) { return nv::Divided<T>{}(lhs, rhs); } // execute function
                      auto power() {return meta::Power{}; }                                           // get the tag
template <typename T> auto power(T const& lhs, T const& rhs) { return nv::Power<T>{}(lhs, rhs); }     // execute function
                      auto min() {return meta::Min{}; }                                               // get the tag
template <typename T> auto min(T const& lhs, T const& rhs) { return nv::Min<T>{}(lhs, rhs); }         // execute function
                      auto max() {return meta::Max{}; }                                               // get the tag
template <typename T> auto max(T const& lhs, T const& rhs) { return nv::Max<T>{}(lhs, rhs); }         // execute function
                      auto equal() {return meta::Equal{}; }                                           // get the tag
template <typename T> auto equal(T const& lhs, T const& rhs) { return nv::Equal<T>{}(lhs, rhs); }     // execute function
                      auto unequal() {return meta::Unequal{}; }                                       // get the tag
template <typename T> auto unequal(T const& lhs, T const& rhs) { return nv::Unequal<T>{}(lhs, rhs); } // execute function
                      auto less() {return meta::Less{}; }                                             // get the tag
template <typename T> auto less(T const& lhs, T const& rhs) { return nv::Less<T>{}(lhs, rhs); }       // execute function
                      auto less_equal() {return meta::LessEqual{}; }                                             // get the tag
template <typename T> auto less_equal(T const& lhs, T const& rhs) { return nv::LessEqual<T>{}(lhs, rhs); }       // execute function
                      auto greater() {return meta::Greater{}; }                                                  // get the tag
template <typename T> auto greater(T const& lhs, T const& rhs) { return nv::Greater<T>{}(lhs, rhs); }            // execute function
                      auto greater_equal() {return meta::GreaterEqual{}; }                                       // get the tag
template <typename T> auto greater_equal(T const& lhs, T const& rhs) { return nv::GreaterEqual<T>{}(lhs, rhs); } // execute function
                      auto least_common_multiple() {return meta::LeastCommonMultiple{}; }                                           // get the tag
template <typename T> auto least_common_multiple(T const& lhs, T const& rhs) { return nv::LeastCommonMultiple<T>{}(lhs, rhs); }     // execute function
                      auto greatest_common_divisor() {return meta::GreatestCommonDivisor{}; }                                       // get the tag
template <typename T> auto greatest_common_divisor(T const& lhs, T const& rhs) { return nv::GreatestCommonDivisor<T>{}(lhs, rhs); } // execute function


}

// Unfortunately 'not' 'and' 'or' are reserved keywords in C++, so I cannot create functions with that name.
// Uppercase names would work.
// To be consistent, I would have to give all my functors and functions uppercase names...
// Or I force the user to differentiate between the tag 'Not' and the function 'Not'... that still doesn't change the
// fact it cannot be lowercase though. :(
// Another option would be to give them a special name by prefixing or postfixing something:
// _not, not_f, f_not, not_, 

// Specializing the the original functors to have zero-argument versions which are the tag, does not seem to work:
//
//     struct EmptyType {};
//     template <typename T> struct Not  { T operator()(T t) const { return !t; } };
//     template <> struct Not<EmptyType> {};
//
// results in compilation errors:
//
//     const auto t = Not<>{}; // error: wrong number of template arguments (0, should be 1)
//     const auto t = Not{};   // error: class template argument deduction failed
//
