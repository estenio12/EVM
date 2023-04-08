#include <iostream>

#include "../includes/memory.hpp"
#include "../includes/loader.hpp"
#include "../includes/cpu.hpp"

int main(int argc, char** argv)
{
    // # Create instances
    auto memory    = new Memory();
    auto bootstrap = new Loader(memory, argv[1]);
    auto cpu       = new Cpu(memory);

    // # Run interpreter
    cpu->Run();
    
    // # Unload entities
    delete cpu;
    delete bootstrap;
    delete memory;

    return EXIT_SUCCESS;
}