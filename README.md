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
- rank
- gather (i.e. index operator[] in APL)
- scatter
- grade
- map

# TODO
- inner product (std::transform_reduce)
- scan (with an easier interface)
- match (equal)
- not match
- not
- greatest common divisor / or
- lowest common multiple / and
- alternating reduction for minus and division (or some way of doing this)
- encode
- decode
- zip
- roll
- deal
- binomial
- factorial
- union (?) -- using DSU perhaps?
- difference (?)
- intersection (?)

# TODO: Tensor algorithms for rank > 1
- transpose
- outer product
- reshape
- ravel (flatten)
- view to apply any algorithm around one specified axis (i.e. column-wise plus-reduce)
