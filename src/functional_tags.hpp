#pragma once

namespace meta {

// NEVER use these meta-programming tags and functions in client code

template <typename T> struct Tag{};

struct LogicalNot : Tag<LogicalNot> {};
struct LogicalOr : Tag<LogicalOr> {};
struct LogicalAnd : Tag<LogicalAnd> {};
struct Identity : Tag<Identity> {};
struct Negate : Tag<Negate> {};
struct Plus : Tag<Plus>{};
struct Minus : Tag<Minus> {};
struct Times : Tag<Times> {};
struct Divided : Tag<Divided> {};
struct Power : Tag<Power> {};
struct Min : Tag<Min> {};
struct Max : Tag<Max> {};
struct Equal : Tag<Equal> {};
struct Unequal : Tag<Unequal> {};
struct Less : Tag<Less> {};
struct LessEqual : Tag<LessEqual> {};
struct Greater : Tag<Greater> {};
struct GreaterEqual : Tag<GreaterEqual> {};
struct LeastCommonMultiple : Tag<LeastCommonMultiple> {};
struct GreatestCommonDivisor : Tag<GreatestCommonDivisor> {};

}
