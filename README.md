# cpp_algorithm
A loose collection of algorithms inspired by C++ Ranges, Thrust, APL/BQN, Lisp, and others.

## Getting started
1. Clone the repo
2. cd cpp_algorithm
3. mkdir out
4. cd out
5. cmake ..
6. cmake --build . # out-of-source build
7. ./unit_tests

# APL and Thrust algorithms to implement
- iota (std::iota)
- repeat (similar to std::fill)
- reverse (std::reverse)
- rotate (around a specified axis)
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
- ravel

# Tensor support
How do I want to support tensors? Some options:

## Activate C++23 and use std::mdspan
- could save a lot of time
- I am unfamiliar with it
- not sure how good the C++23 support is with this compiler version

## My own flat vector implementation
- easy operations on all elements
- coordinate-based access is easy to implement (it's just the 'decode' algorithm which I will implement anyway)

## My own nested vector implementation
- allow efficient iteration along axes in the order given by the memory layout (but not any other orders)

# Design decisions
- hard-code to std::vector to simplify all interfaces
- implement the first version with hard-copies -- use views and expression templates in a later version

Do I want to make all data immutable, like the functional languages and BQN do it? With views and expression templates this could still be fine from a performance standpoint. Alternatively I could let the programmer decide what he wants.
