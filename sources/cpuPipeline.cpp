#include "../includes/cpu.hpp"

void Cpu::Run()
{ 
    // auto t = memory->ReadChunk(0, 3);

    // for(auto s : t)
    // {
    //     Output::Print(s);
    // }

    while(this->run)
    {
        // Output::Print(this->memory->Read("00000000"));
        this->Decode(this->SeekInstruction());
        this->IncrementProgramCounter();
    }
}

void Cpu::IncrementProgramCounter()
{
    this->programCounter++;
    if(this->programCounter > SETTING::MAX_ADDRESS) exit(EXIT_SUCCESS);
}

data Cpu::SeekInstruction()
{
    return this->memory->ReadCommand(this->programCounter);
}

void Cpu::Decode(data instruction)
{
    auto opcode = DecimalConverter::FromBinary(Tools::Substring(instruction, 0, 7));

    // Output::Print(Tools::Substring(instruction, 0, 7));
    // Output::Print(instruction);

    switch (opcode)
    {
        case Opcodes::NOP:
            this->CallNOP();
        break;

        case Opcodes::LDX:
            this->CallLDX(instruction);
        break;
        
        case Opcodes::STX:
            this->CallSTX(instruction);
        break;

        case Opcodes::MOV:
            this->CallMOV(instruction);
        break;

        case Opcodes::ADD:
            this->CallADD(instruction);
        break;

        case Opcodes::SUB:
            this->CallSUB(instruction);
        break;

        case Opcodes::MUL:
            this->CallMUL(instruction);
        break;

        case Opcodes::DIV:
            this->CallDIV(instruction);
        break;

        case Opcodes::JMP:
            this->CallJMP(instruction);
        break;

        case Opcodes::JSR:
            this->CallJSR(instruction);
        break;

        case Opcodes::RTS:
            this->CallRTS(instruction);
        break;

        case Opcodes::CMP:
            this->CallCMP(instruction);
        break;

        case Opcodes::BEQ:
            this->CallBEQ(instruction);
        break;

        case Opcodes::BNE:
            this->CallBNE(instruction);
        break;

        case Opcodes::BGT:
            this->CallBGT(instruction);
        break;

        case Opcodes::BLT:
            this->CallBLT(instruction);
        break;

        case Opcodes::BGE:
            this->CallBGE(instruction);
        break;

        case Opcodes::BLE:
            this->CallBLE(instruction);
        break;

        case Opcodes::CLR:
            this->CallCLR(instruction);
        break;

        case Opcodes::OFF:
            Output::Print("Entrei");
            this->CallOFF(instruction);
        break;

        case Opcodes::AND:
            this->CallAND(instruction);
        break;

        case Opcodes::OR:
            this->CallOR(instruction);
        break;

        case Opcodes::XOR:
            this->CallXOR(instruction);
        break;

        case Opcodes::NOT:
            this->CallNOT(instruction);
        break;

        case Opcodes::NAND:
            this->CallNAND(instruction);
        break;

        case Opcodes::NOR:
            this->CallNOR(instruction);
        break;

        case Opcodes::XNOR:
            this->CallXNOR(instruction);
        break;

        case Opcodes::SET:
            this->CallSET(instruction);
        break;

        case Opcodes::ROL:
            this->CallROL(instruction);
        break;

        case Opcodes::ROR:
            this->CallROR(instruction);
        break;

        case Opcodes::PRT:
            this->CallPRT(instruction);
        break;

        case Opcodes::INP:
            this->CallINP(instruction);
        break;
    }
}

