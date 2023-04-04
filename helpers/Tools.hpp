// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>
#include <vector>
#include <cmath>
#include "../helpers/definition.hpp"

namespace BinaryMapper
{
    static const int Bit(char bit)
    {
        if(bit == '1') return 1;
        return 0;
    }
}

namespace DecimalConverter
{
    static const int FromBinary(data value)
    {
        int FinalValue = 0;

        for(int i = 0; i < value.length(); i++)
        {
            int power = i - (value.length() - 1);
            FinalValue += pow(2, power) * BinaryMapper::Bit(i);
        }

        return FinalValue;
    }
}

