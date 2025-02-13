#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>

struct Vector_uint16
{
    uint16_t X, Y; 
};


//char* TextVideoMemory[32];
std::string TextVideoMemory[32];
//std::vector<Vector_uint16> VideoMemory;

#include "KemuWindow/KemuWindow.h"

struct Registers
{
    uint16_t AX;
    uint16_t BX;
    uint16_t CX;
    uint16_t DX;
    uint16_t SI;
    uint16_t DI;
    uint16_t BP;
    uint16_t SP;
    uint16_t CS;
    uint16_t DS;
    uint16_t SS;
    uint16_t ES;
    uint16_t IP;
};

Registers reg;

void ResetRegisters()
{
    reg.AX = 0;
    reg.BX = 0;
    reg.CX = 0;
    reg.DX = 0;
    reg.SI = 0;
    reg.DI = 0;
    reg.BP = 0;
    reg.SP = 0;
    reg.CS = 0;
    reg.DS = 0;
    reg.SS = 0;
    reg.ES = 0;
    reg.IP = 0;
}

//Instructions

uint16_t GetRegisterValue(uint16_t regvalue)
{
    switch (regvalue)
    {
        case 1:
            return reg.AX;
            break;
        case 2:
            return reg.BX;
            break; 
        case 3:
            return reg.CX;
            break; 
        case 4:
            return reg.DX;
            break; 
        case 5:
            return reg.SI;
            break; 
        case 6:
            return reg.DI;
            break; 
       	case 7:
            return reg.BP;
            break;
       	case 8:
            return reg.SP;
            break;
       	case 9:
            return reg.CS;
            break;        
	case 10:
            return reg.DS;
            break;        
        default:
            break;
    }

    return 0;
}

void SetRegisterValue(uint16_t regpath, uint16_t value)
{
    switch (regpath)
    {
        case 1:
            reg.AX = value;
            break;
        case 2:
            reg.BX = value;
            break;
        case 3:
            reg.CX = value;
            break;
        case 4:
            reg.DX = value;
            break;
        case 5:
            reg.BX = value;
            break;
        case 6:
            reg.DI = value;
            break;
        case 7:
            reg.BP = value;
            break;
        case 8:
            reg.SP = value;
            break;
        case 9:
            reg.CS = value;
            break;
        case 10:
            reg.DS = value;
            break;
        default:
            break;
    }
}

void GraphicInterrupt()
{
    if(reg.AX == 16)
    {
        //DrawText((char)reg.BP);
        TextVideoMemory[CursorY] += (char)reg.BP;
        //std::cout << TextVideoMemory[0] << std::endl;
        CursorX += 1;
    }

    ResetRegisters();
}

void MOV_Instruction(const uint8_t &registerPath, const uint8_t &flags, const uint16_t &value)
{
    uint16_t regval = GetRegisterValue(value);
    if(flags == 1)
    {
        SetRegisterValue(registerPath, value);
    }
    else if(flags == 0)
    {
        SetRegisterValue(registerPath, regval);
    }

}
void ADD_Instruction(const uint8_t &registerPath, const uint8_t &flags, const uint16_t &value)
{
    uint16_t regval = GetRegisterValue(registerPath);
    if(flags == 1)
    {
	SetRegisterValue(registerPath, regval + value);
    }
    else if(flags == 0)
    {
	SetRegisterValue(registerPath, regval + GetRegisterValue(value));
    }
}
void SUB_Instruction(const uint8_t &registerPath, const uint8_t &flags, const uint16_t &value)
{
    uint16_t regval = GetRegisterValue(registerPath);
    if(flags == 1)
    {
	SetRegisterValue(registerPath, regval - value);
    }
    else if(flags == 0)
    {
	SetRegisterValue(registerPath, regval - GetRegisterValue(value));
    }
}

void INC_Instruction(const uint8_t &registerPath)
{
    SetRegisterValue(registerPath, GetRegisterValue(registerPath) + 1);
}
void DEC_Instruction(const uint8_t &registerPath)
{
    SetRegisterValue(registerPath, GetRegisterValue(registerPath) - 1);
}
