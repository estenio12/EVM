#include "../includes/cpu.hpp"

void Cpu::NOP(){}

void Cpu::LDX(address origin, _register target)
{
    auto data = this->memory->Read(origin);
    this->WriteInRegister(target, data);
}

void Cpu::STX(_register target, address origin)
{
    auto data = this->ReadFromRegister(target);
    this->memory->Write(origin, data);
}

void Cpu::MOV(_register origin, _register destiny)
{
    this->IsValidRegisterName(origin);
    this->IsValidRegisterName(destiny);

    auto data = this->ReadFromRegister(origin);
    this->WriteInRegister(destiny, data);
}

void Cpu::ADD(_register operand_1, _register operand_2)
{
    this->IsValidRegisterName(operand_1);
    this->IsValidRegisterName(operand_2);

    int value_1 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_1));
    int value_2 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_2));

    int result = value_1 + value_2;

    if(result > SETTING::MAX_RANGE_MATH)
    {
        Output::PrintError("Invalid operation, resultant value is greater than "+std::to_string(SETTING::MAX_RANGE_MATH)+".");
        exit(EXIT_FAILURE);
    }

    auto data = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(operand_2, data);
}

void Cpu::SUB(_register operand_1, _register operand_2)
{
    this->IsValidRegisterName(operand_1);
    this->IsValidRegisterName(operand_2);

    int value_1 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_1));
    int value_2 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_2));

    int result = value_1 - value_2;

    if(result < SETTING::MIN_RANGE_MATH)
    {
        Output::PrintError("Invalid operation, resultant value is lesser than -"+std::to_string(SETTING::MAX_RANGE_MATH)+".");
        exit(EXIT_FAILURE);
    }

    auto data = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(operand_2, data);
}

void Cpu::MUL(_register operand_1, _register operand_2)
{
    this->IsValidRegisterName(operand_1);
    this->IsValidRegisterName(operand_2);

    int value_1 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_1));
    int value_2 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_2));

    int result = value_1 * value_2;

    if(result > SETTING::MAX_RANGE_MATH ||
       result < SETTING::MIN_RANGE_MATH)
    {
        Output::PrintError("Invalid operation, resultant value is greater or lesser than "+std::to_string(SETTING::MAX_RANGE_MATH)+".");
        exit(EXIT_FAILURE);
    }

    auto data = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(operand_2, data);
}

void Cpu::DIV(_register operand_1, _register operand_2)
{
    this->IsValidRegisterName(operand_1);
    this->IsValidRegisterName(operand_2);

    int value_1 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_1));
    int value_2 = DecimalConverter::FromBinary(this->ReadFromRegister(operand_2));

    if(value_1 == 0 || value_2 == 0)
    {
        Output::PrintError("Division by zero!");
        exit(EXIT_FAILURE);
    }

    int result = value_1 / value_2;

    if(result > SETTING::MAX_RANGE_MATH ||
       result < SETTING::MIN_RANGE_MATH )
    {
        Output::PrintError("Invalid operation, resultant value is greater or lesser than "+std::to_string(SETTING::MAX_RANGE_MATH)+".");
        exit(EXIT_FAILURE);
    }

    auto data = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(operand_2, data);
}

void Cpu::JMP(address target)
{
    int addr = DecimalConverter::FromBinary(target);
    this->SetProgramCounter(addr);
}

void Cpu::JSR(address target)
{
    this->jsr_stack[this->stackPointer] = this->programCounter;
    this->IncrementStackPointer();

    this->JMP(target);
}

void Cpu::RTS()
{
    this->DecrementStackPointer();
    int addr = this->jsr_stack[this->stackPointer];
    this->SetProgramCounter(addr);
}

void Cpu::CMP(_register target_1, _register target_2)
{
    this->IsValidRegisterName(target_1);
    this->IsValidRegisterName(target_2);

    this->REGISTER_CMP[0] = this->ReadFromRegister(target_1);
    this->REGISTER_CMP[1] = this->ReadFromRegister(target_2);
}

void Cpu::BEQ(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    if(this->REGISTER_CMP[0] == this->REGISTER_CMP[1])
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::BNE(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    if(this->REGISTER_CMP[0] != this->REGISTER_CMP[1])
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::BGT(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    int data_1 = DecimalConverter::FromBinary(this->REGISTER_CMP[0]);
    int data_2 = DecimalConverter::FromBinary(this->REGISTER_CMP[1]);

    if(data_1 > data_2)
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::BLT(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    int data_1 = DecimalConverter::FromBinary(this->REGISTER_CMP[0]);
    int data_2 = DecimalConverter::FromBinary(this->REGISTER_CMP[1]);

    if(data_1 < data_2)
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::BGE(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    int data_1 = DecimalConverter::FromBinary(this->REGISTER_CMP[0]);
    int data_2 = DecimalConverter::FromBinary(this->REGISTER_CMP[1]);

    if(data_1 >= data_2)
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::BLE(address branch_1, address branch_2)
{
    this->IsValidAddress(branch_1);
    this->IsValidAddress(branch_2);

    int data_1 = DecimalConverter::FromBinary(this->REGISTER_CMP[0]);
    int data_2 = DecimalConverter::FromBinary(this->REGISTER_CMP[1]);

    if(data_1 <= data_2)
    {
        this->JMP(branch_1);
    }
    else
    {
        this->JMP(branch_2);
    }
}

void Cpu::CLR(_register target)
{
    this->ClearRegister(target);
}

void Cpu::OFF()
{
    exit(EXIT_SUCCESS);
}

void Cpu::AND(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '1' &&
           data_2[i] == '1')
        {
            byte[i] = '1';
        }
        else
        {
            byte[i] = '0';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::OR(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '0' &&
           data_2[i] == '0')
        {
            byte[i] = '0';
        }
        else
        {
            byte[i] = '1';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::XOR(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '1' &&
           data_1[i] == '1' ||
           data_1[i] == '0' &&
           data_1[i] == '0')
        {
            byte[i] = '0';
        }
        else
        {
            byte[i] = '1';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::NOT(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '1')
        {
            byte[i] = '0';
        }
        else
        {
            byte[i] = '1';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::NAND(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '1' &&
           data_2[i] == '1')
        {
            byte[i] = '0';
        }
        else
        {
            byte[i] = '1';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::NOR(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '0' &&
           data_2[i] == '0')
        {
            byte[i] = '1';
        }
        else
        {
            byte[i] = '0';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::XNOR(_register target_1, _register target_2)
{
    this->IsValidAddress(target_1);
    this->IsValidAddress(target_2);

    data byte = model::template_8bits;

    auto data_1 = this->ReadFromRegister(target_1);
    auto data_2 = this->ReadFromRegister(target_2);

    for(int i = 0; i < data_1.length(); i++)
    {
        if(data_1[i] == '0' &&
           data_2[i] == '0' ||
           data_1[i] == '1' &&
           data_2[i] == '1')
        {
            byte[i] = '1';
        }
        else
        {
            byte[i] = '0';
        }
    }

    this->WriteInRegister(target_2, byte);
}

void Cpu::SET(data target, _register destiny)
{
    this->WriteInRegister(destiny, target);
}

void Cpu::ROL(_register origin, _register target)
{
    this->IsValidRegisterName(origin);
    this->IsValidRegisterName(target);

    int data  = DecimalConverter::FromBinary(this->ReadFromRegister(origin));
    int times = DecimalConverter::FromBinary(this->ReadFromRegister(target));

    int result = data << times;
    auto byte = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(target, byte);
}

void Cpu::ROR(_register origin, _register target)
{
    this->IsValidRegisterName(origin);
    this->IsValidRegisterName(target);

    int data  = DecimalConverter::FromBinary(this->ReadFromRegister(origin));
    int times = DecimalConverter::FromBinary(this->ReadFromRegister(target));

    int result = data >> times;
    auto byte = Tools::ComplementBinaryTo_8_Bits
    (
        BinaryConverter::FromDecimal(result)
    );

    this->WriteInRegister(target, byte);
}

void Cpu::PRT(address start, address end)
{
    this->IsValidAddress(start);
    this->IsValidAddress(end);

    if(start == end)
    {
        auto byte  = this->memory->Read(start);
        char tchar = DecimalConverter::FromBinary(byte);
        std::cout << tchar;
    }
    else
    {
        auto istart = DecimalConverter::FromBinary(start);
        auto iend   = DecimalConverter::FromBinary(end);
        auto chunk  = this->memory->ReadChunk(istart, iend);

        for(auto byte : chunk)
        {
            char tchar = DecimalConverter::FromBinary(byte);
            std::cout << tchar;
        }
    }
}

void Cpu::INP(address addr)
{
    this->IsValidAddress(addr);

    std::string input;
    std::cin >> input;
    std::vector<data> chunk;
    int startAddress = DecimalConverter::FromBinary(addr); 

    for(char byte : input)
    {
        auto btmp = Tools::ComplementBinaryTo_8_Bits
        (
            BinaryConverter::FromDecimal((int)byte)
        );

        chunk.push_back(btmp);
    }

    this->memory->WriteChunk(startAddress, chunk);
}