#include <cstdlib> // exit_success
#include <iostream>
#include <iterator> // ostream_iterator
#include "drop.hpp"
#include "reverse.hpp"
#include "size.hpp"
#include "take.hpp"
#include "meta/global_datatypes.hpp"

int main()
{
    vi32 v = vi32{1, 2, 4, 8, 16} | xpr::take(3) | xpr::drop(1) | xpr::reverse();

    std::cout << "The answer: ( ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<i32>(std::cout, " "));
    std::cout << ")" << std::endl;

    return EXIT_SUCCESS;
}
