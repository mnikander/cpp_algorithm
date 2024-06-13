#include <cstdlib> // exit_success
#include <iostream>
#include "io/vector_stream.hpp"
#include "meta/global_datatypes.hpp"
#include "drop.hpp"
#include "reverse.hpp"
#include "take.hpp"

int main()
{
    vi32 v = vi32{1, 2, 4, 8, 16} | xpr::take(3) | xpr::drop(1) | xpr::reverse();
    std::cout << "The answer: " << v << std::endl;

    return EXIT_SUCCESS;
}
