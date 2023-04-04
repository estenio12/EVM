#include "../includes/memory.hpp"

Memory::Memory()
{
    this->LoadStack();
}

Memory::~Memory()
{
    this->stack.clear();
}

void Memory::Write(address address, data data)
{
    this->stack[DecimalConverter::FromBinary(address)] = data;
}

data Memory::Read(address address)
{
    return this->stack[DecimalConverter::FromBinary(address)];
}

void Memory::LoadStack()
{
    for(int i = 0; i < SETTING::MAX_MEMORY; i++)
    {
        this->stack.push_back(model::template_8bits);
    }
}