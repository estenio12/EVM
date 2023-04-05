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

namespace Tools
{
    static std::vector<std::string> Split(std::string source, char condition)
    {
        std::vector<std::string> list;
        std::string chunk;

        for(char letter : source)
        {
            if(letter == condition)
            {
                list.push_back(chunk);
                chunk.clear();
            }
            else
            {
                chunk.push_back(letter);
            }
        }

        if(chunk.size() > 0)
        {
            list.push_back(chunk);
            chunk.clear();
        }

        return list;
    }
    
    static std::string Substring(std::string source, int start, int end)
    {
        std::string nstring;

        for(int i = start; i <= end; i++)
        {
            nstring.push_back(source[i]);
        }

        return nstring;
    }
}
