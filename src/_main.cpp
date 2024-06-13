#include <cstdlib> // exit_success
#include <iostream>
#include "io/vector_stream.hpp"
#include "meta/bind.hpp"
#include "meta/global_datatypes.hpp"
#include "catenate.hpp"
#include "drop.hpp"
#include "functional.hpp"
#include "iota.hpp"
#include "map.hpp"
#include "reverse.hpp"
#include "take.hpp"

int main()
{
    using namespace xpr;

    vi32 v = vi32{1, 2, 4, 8, 16} | take(3) | drop(1) | reverse();
    std::cout << "    The answer: " << v << std::endl; // ( 4 2 )

    vi32 squared_values = iota(5) | map(power() <<= 2);
    std::cout << "Squared values: " << squared_values << std::endl; // ( 0 1 4 9 16 )

    // create a palindrome from those squared numbers
    vi32 palindrome = squared_values | catenate(squared_values | drop_last(1) | reverse());
    std::cout << "     Palidrome: " << palindrome << std::endl; // ( 0 1 4 9 16 9 4 1 0 )

    return EXIT_SUCCESS;
}
