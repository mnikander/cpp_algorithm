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

## My own StridedRange implementation
- holds a shared_ptr to a templated container type
- has shape and axis order
- supports free functions rank(t), shape(t), order(t), size(t)
- support for std::array and vector (array could be a challenge for axis-wise operations or catenate for example, requires some meta-programming to manipulate the shape, order, and array-size)
- would allow axis-wise operations (using a strided iterator) on the range

# Mutable vs. immutable
Do I want to make all data immutable, like the functional languages and BQN do it? With views and expression templates this could still be fine from a performance standpoint. Alternatively I could let the programmer decide what he wants.

# Design decisions
- hard-code to std::vector to simplify all interfaces
- implement the first version with hard-copies -- use views and expression templates in a later version
