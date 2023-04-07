// # 
// # @author: Estenio Garcia
// # @license: MIT 
// # @copyright All (C) 
// # 

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../helpers/definition.hpp"
#include "../includes/memory.hpp"
#include "../includes/output.hpp"

class Cpu
{
    private:
        Memory* memory;

    private:
        std::vector<data> register_stack;
        std::vector<int> jsr_stack;
        _register REGISTER_CMP[2]
        {
            {model::template_8bits}, 
            {model::template_8bits}
        };

    private:
        int programCounter = 0;
        int stackPointer = SETTING::MAX_STACKPOINTER / 2;

    public:
        Cpu(Memory* memory);
        ~Cpu();

    private:
        void LoadRegister();
        void LoadStack();
        void ClearRegister(_register);
        void WriteInRegister(_register, data);
        data ReadFromRegister(_register);
        void IsValidRegisterName(_register);
        void IsValidAddress(address);
        void IncrementStackPointer();
        void DecrementStackPointer();
        void SetProgramCounter(int);

    public:
        void NOP();
        void LDX(address, _register);
        void STX(_register, address);
        void MOV(_register, _register);
        void ADD(_register, _register);
        void SUB(_register, _register);
        void MUL(_register, _register);
        void DIV(_register, _register);
        void JMP(address);
        void JSR(address);
        void RTS();
        void CMP(_register, _register);
        void BEQ(address, address);
        void BNE(address, address);
        void BGT(address, address);
        void BLT(address, address);
        void BGE(address, address);
        void BLE(address, address);
        void CLR(_register);
        void OFF();
        void AND(_register, _register);
        void OR(_register, _register);
        void XOR(_register, _register);
        void NOT(_register, _register);
        void NAND(_register, _register);
        void NOR(_register, _register);
        void XNOR(_register, _register);
        void SET(data, _register);
        void ROL(_register, _register);
        void ROR(_register, _register);
        void PRT(address, address);
        void INP(address);
};