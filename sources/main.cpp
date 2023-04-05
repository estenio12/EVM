#include <iostream>

#include "../includes/memory.hpp"
#include "../includes/loader.hpp"

int main(int argc, char** argv)
{
    auto memory = new Memory();
    auto bootstrap = new Loader(memory, argv[1]);

    Output::Print(memory->Read("0000000000000000"));

    return EXIT_SUCCESS;
}