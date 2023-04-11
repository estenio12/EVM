#include "../includes/cpu.hpp"

Cpu::Cpu(Memory* memory):memory(memory)
{
    this->LoadRegister();
    this->LoadStack();
}

Cpu::~Cpu()
{
    register_stack.clear();
}

void Cpu::LoadRegister()
{
    for(int i = 0; i < 32; i++)
    {
        this->register_stack.push_back(model::template_8bits);
    }
}

void Cpu::LoadStack()
{
    for(int i = 0; i < SETTING::MAX_STACKPOINTER; i++)
    {
        this->jsr_stack.push_back(0);
    }
}

void Cpu::WriteInRegister(_register name, data data)
{
    this->IsValidRegisterName(name);
    int target = DecimalConverter::FromBinary(name);
    this->register_stack[target] = data;
}

data Cpu::ReadFromRegister(_register name)
{
    this->IsValidRegisterName(name);
    int target = DecimalConverter::FromBinary(name);

    return this->register_stack[target];
}

void Cpu::ClearRegister(_register name)
{
    this->IsValidRegisterName(name);
    int target = DecimalConverter::FromBinary(name);
    this->register_stack[target] = model::template_8bits;
}

void Cpu::IsValidRegisterName(_register name)
{
    int target = DecimalConverter::FromBinary(name);

    if(target > SETTING::MAX_REGISTER || target < SETTING::MIN_REGISTER)
    {
        Output::PrintFatalError("Range of registers violated!");
        exit(EXIT_FAILURE);
    }
}

void Cpu::IsValidAddress(address addr)
{
    int target = DecimalConverter::FromBinary(addr);

    if(target > SETTING::MAX_ADDRESS ||
       target < SETTING::MIN_ADDRESS)
    {
        Output::PrintFatalError("Range of address violated!");
        exit(EXIT_FAILURE);
    }
}

void Cpu::IncrementStackPointer()
{
    this->stackPointer++;

    if(stackPointer > (SETTING::MAX_STACKPOINTER - 1)) this->stackPointer = 0;
}

void Cpu::DecrementStackPointer()
{
    this->stackPointer--;

    if(stackPointer < 0) this->stackPointer = SETTING::MAX_STACKPOINTER - 1;
}

void Cpu::SetProgramCounter(int addr)
{
    if(addr > SETTING::MAX_ADDRESS ||
       addr < SETTING::MIN_ADDRESS)
    {
        Output::PrintFatalError("Range of address violated!");
        exit(EXIT_FAILURE);
    }

    // # It's was applied (addr - 1) because, when the user input a new 
    // # address in program counter by jump, the next step,
    // # the cpu loop will increment the address, in this case,
    // # the address inputed by user will be ignored.
    this->programCounter = addr - 1;
}




