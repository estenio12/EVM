#include "../includes/loader.hpp"

Loader::Loader(Memory* memory, std::string path):memory(memory)
{
    this->LoadBinaryContent(path);

    if(this->IsValidHeader())
    {
        this->Bootstrap();
    }
}

void Loader::LoadBinaryContent(std::string filePath)
{
    auto path = std::filesystem::path(filePath);

    if(std::filesystem::exists(path))
    {
        std::fstream file(filePath, std::ios::in | std::ios::binary);

        if(file.is_open() && file.good())
        {
            std::string line = "";

            while(std::getline(file, line))
            {
                this->BinaryContent = line;
            }
        }

        file.close();
    }
    else
    {
        Output::PrintError("File cannot be founded!");
        exit(EXIT_FAILURE);
    }
}

bool Loader::IsValidHeader()
{
    auto header = Tools::Substring(this->BinaryContent, 0, 25);
    
    if(header == this->defaultProtocolo) return true;

    return false;
}

void Loader::Bootstrap()
{
    auto binary  = Tools::Substring(this->BinaryContent, 26, this->BinaryContent.length());
    auto opcodes = Tools::Split(binary, '|');

    this->memory->LoadProgram(opcodes);
}
