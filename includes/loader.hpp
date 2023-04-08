// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <string>
#include <filesystem>
#include <fstream>

#include "../includes/memory.hpp"
#include "../includes/output.hpp"

class Loader
{
    private:
        Memory* memory;
        std::string BinaryContent = "";

    private:
        // # Binary signature
        const std::string signature = "011001010111011001101101";

    public:
        Loader(Memory* memory, std::string );
        ~Loader();

    private:
        void LoadBinaryContent(std::string );
        void Bootstrap();
        bool IsValidHeader();
};