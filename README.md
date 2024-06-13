# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Lisp, and others.

## Getting started
1. Clone the repo
2. cd cpp_algorithm
3. mkdir out
4. cmake out/
5. cmake --build out/ # out-of-source build
6. ./out/unit_tests

# APL and Thrust algorithms to implement
- iota (std::iota)
- repeat (similar to std::fill)
- reverse (std::reverse)
- rotate
- transpose
- reduce (with an easier interface)
- scan (with an easier interface)
- catenate (resize + std::copy or just std::copy)
- encode
- decode
- take
- drop
- greatest common divisor / or
- lowest common multiple / and
- tally (i.e. std::distance or size())
- rank
- match
- not match
- roll
- deal
- grade
- index (a.k.a. gather)
- scatter
- zip
- unzip (?)
- reshape
- ravel (flatten)
- inner product (std::transform reduce)
- outer product
- binomial
- factorial
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
