// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <vector>
#include <string>
#include "../helpers/definition.hpp"
#include "../helpers/Tools.hpp"

class Memory
{
    private:
        std::vector<std::string> stack;

    public:
        Memory();
        ~Memory();

    public:
        data Read(address );
        void Write(address, data );
        void LoadProgram(std::vector<std::string> );

    private:
        void LoadStack();
};