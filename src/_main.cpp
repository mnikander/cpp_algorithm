#include <cstdlib> // exit_success
#include <iostream>
#include "io/vector_stream.hpp"
#include "meta/global_datatypes.hpp"
#include "catenate.hpp"
#include "drop.hpp"
#include "iota.hpp"
#include "map.hpp"
#include "reverse.hpp"
#include "take.hpp"

int main()
{
    using namespace xpr;

    vi32 v = vi32{1, 2, 4, 8, 16} | take(3) | drop(1) | reverse();
    std::cout << "The answer: " << v << std::endl;

    vi32 squares    = iota(5) | map([](int i){return i*i;});
    vi32 palindrome = squares | catenate(squares | drop_last(1) | reverse());
    std::cout << "Palidrome: " << palindrome << std::endl;

    return EXIT_SUCCESS;
}
