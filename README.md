# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Lisp, and others.

## Getting started
1. Clone the repo
2. cd cpp_algorithm
3. mkdir out
4. cmake out/
5. cmake --build out/ # out-of-source build
6. ./out/unit_tests

# APL and Thrust algorithms
- iota (std::iota)
- repeat (similar to std::fill)
- reverse (std::reverse)
- rotate
- reduce (with an easier interface)
- catenate (resize + std::copy or just std::copy)
- take
- drop
- tally / size
- gather (i.e. index operator[] in APL)
- scatter

# TODO
- scan (with an easier interface)
- encode
- decode
- greatest common divisor / or
- lowest common multiple / and
- alternating reduction for minus and division (or some way of doing this)
- rank
- match
- not match
- roll
- deal
- grade
- zip
- unzip (?)
- inner product (std::transform reduce)
- binomial
- factorial

# TODO: Tensor algorithms for rank > 1
- transpose
- outer product
- reshape
- ravel (flatten)
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
