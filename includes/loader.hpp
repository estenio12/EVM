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
#include "../includes/Output.hpp"

class Loader
{
    private:
        Memory* memory;
        std::string BinaryContent = "";

    private:
        // # first 24 byte is signature
        // # the last 2 bytes is module, exemple: 00 = 8 bits architecture
        const std::string defaultProtocolo = "01100101011101100110110100";

    public:
        Loader(Memory* memory, std::string );
        ~Loader();

    private:
        void LoadBinaryContent(std::string );
        void Bootstrap();
        bool IsValidHeader();
};