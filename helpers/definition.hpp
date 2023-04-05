// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>

using address  = std::string;
using _register = std::string;
using data     = std::string;

namespace model
{
    static const std::string template_8bits = "00000000";
}

namespace SETTING 
{
    static const int MAX_MEMORY   = 65536;
    static const int MAX_REGISTER = 31;
    static const int MIN_REGISTER = 0;
    static const int MAX_ADDRESS  = MAX_MEMORY - 1;
    static const int MIN_ADDRESS  = 0;
    static const int MAX_STACKPOINTER = 256;
}