#include "../includes/cpu.hpp"

void Cpu::CallNOP(){}

void Cpu::CallLDX(data data)
{
    auto address      = Tools::Substring(data, 8, 23);
    auto registerName = Tools::Substring(data, 24, 32);

    this->LDX(address, registerName);
}

void Cpu::CallSTX(data data)
{
    auto registerName = Tools::Substring(data, 8, 15);
    auto address      = Tools::Substring(data, 16, 32);

    this->STX(registerName, address);
}

void Cpu::CallMOV(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->MOV(register_1, register_2);
}

void Cpu::CallADD(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->ADD(register_1, register_2);
}

void Cpu::CallSUB(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->SUB(register_1, register_2);
}

void Cpu::CallMUL(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->MUL(register_1, register_2);
}

void Cpu::CallDIV(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->DIV(register_1, register_2);
}

void Cpu::CallJMP(data data)
{
    auto address = Tools::Substring(data, 8, 23);

    this->JMP(address);
}

void Cpu::CallJSR(data data)
{
    auto address = Tools::Substring(data, 8, 23);
    
    this->JSR(address);
}

void Cpu::CallRTS(data data)
{
    this->RTS();
}

void Cpu::CallCMP(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->CMP(register_1, register_2);
}

void Cpu::CallBEQ(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BEQ(address_1, address_2);
}

void Cpu::CallBNE(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BNE(address_1, address_2);
}

void Cpu::CallBGT(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BGT(address_1, address_2);
}

void Cpu::CallBLT(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BLT(address_1, address_2);
}

void Cpu::CallBGE(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BGE(address_1, address_2);
}

void Cpu::CallBLE(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->BLE(address_1, address_2);
}

void Cpu::CallCLR(data data)
{
    auto registerName = Tools::Substring(data, 8, 15);

    this->CLR(registerName);
}

void Cpu::CallOFF(data data)
{
    this->OFF();
}

void Cpu::CallAND(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->AND(register_1, register_2);
}

void Cpu::CallOR(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->OR(register_1, register_2);
}

void Cpu::CallXOR(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->XOR(register_1, register_2);
}

void Cpu::CallNOT(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->NOT(register_1, register_2);
}

void Cpu::CallNAND(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->NAND(register_1, register_2);
}

void Cpu::CallNOR(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->NOR(register_1, register_2);
}

void Cpu::CallXNOR(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->XNOR(register_1, register_2);
}

void Cpu::CallSET(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->SET(register_1, register_2);
}

void Cpu::CallROL(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->ROL(register_1, register_2);
}

void Cpu::CallROR(data data)
{
    auto register_1 = Tools::Substring(data, 8, 15);
    auto register_2 = Tools::Substring(data, 16, 23);

    this->ROR(register_1, register_2);
}

void Cpu::CallPRT(data data)
{
    auto address_1 = Tools::Substring(data, 8, 23);
    auto address_2 = Tools::Substring(data, 24, 48);

    this->PRT(address_1, address_2);
}

void Cpu::CallINP(data data)
{
    auto address = Tools::Substring(data, 8, 23);

    this->INP(address);
}
