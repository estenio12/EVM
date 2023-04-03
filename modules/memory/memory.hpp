// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include "../helpers/definition.hpp"

class Memory
{
    private:
        

    public:
        Memory();
        ~Memory();

    public:
        _data Read(_address );
        void Write(_address, _data );
};