#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdint.h>

#include "KidyCore.h"

void Parse(const uint8_t &registerPath, const uint8_t &flag, const uint8_t &instruction, const uint16_t &value);

void ReadBinFile(char* Path)
{
    int16_t y = 100;
    int16_t z = 228;
    int16_t x;

    uint8_t Register;
    uint8_t Instruction;
    uint8_t IsLink;
    uint16_t Value;


    /*std::ofstream file("test.bin", std::ios_base::binary);
    file.write((char*)&y, sizeof(uint16_t));
    file.write((char*)&z, sizeof(uint16_t));
    file.close();*/
    std::fstream file(Path);
    int filesize = 0;
    file.seekg (0, std::ios::end);
    filesize = file.tellg();
    file.close();

    //int filesize = std::filesystem::file_size(Path);
    std::ifstream file2(Path, std::ios_base::binary);
    for(int i = 0; i < filesize; i++)
    {
        file2.read((char*)&Instruction, sizeof(uint8_t));
        if(Instruction == 10 || Instruction == 11 || Instruction == 12)
        {
            file2.read((char*)&Register, sizeof(uint8_t));
            file2.read((char*)&IsLink, sizeof(uint8_t));
            file2.read((char*)&Value, sizeof(uint16_t));
            i += 4;
        }
	else if(Instruction == 13 || Instruction == 14)
	{
	    file2.read((char*)&Register, sizeof(uint8_t));
	    i++;
	}
	else if(Instruction == 101)
	{
	    file2.read((char*)&Value, sizeof(uint16_t));
	    file2.seekg(unsigned(Value));
	    i = unsigned(value);
	}
        Parse(Register, IsLink, Instruction, Value);
        //std::cout << "Инструкции << " << unsigned(Instruction) << std::endl;
        //file2.read((char*)&x, sizeof(uint16_t));
        //std::cout << x << std::endl;
    }
//    std::cout << unsigned(Instruction) << " " << unsigned(Register) << " " << unsigned(IsLink) << " " << unsigned(Value) << " " << std::endl;
    //file2.read((char*)&x, sizeof(uint16_t));
    //file2.read((char*)&y, sizeof(uint16_t));
    file2.close();
}

uint8_t ReadByteByPos(char* Path, int Pos)
{
    uint8_t tmp;

    std::ifstream file(Path, std::ios_base::binary);
    file.seekg(Pos);
    file.read((char*)&tmp, sizeof(uint8_t));
    file.close();
    return tmp;
}

uint16_t Read2ByteByPos(char* Path, int Pos)
{
    uint16_t tmp;

    std::ifstream file(Path, std::ios_base::binary);
    file.seekg(Pos);
    file.read((char*)&tmp, sizeof(uint16_t));
    file.close();
    return tmp;
}

void Parse(const uint8_t &registerPath, const uint8_t &flag, const uint8_t &instruction, const uint16_t &value)
{
    if(instruction == 10)
    {
        MOV_Instruction(registerPath, flag, value);
    }
    else if(instruction == 11)
    {
        ADD_Instruction(registerPath, flag, value);
    }   
    else if(instruction == 12)
    {
        SUB_Instruction(registerPath, flag, value);
    }   
    else if(instruction == 13)
    {
        INC_Instruction(registerPath);
    }   
    else if(instruction == 14)
    {
	DEC_Instruction(registerPath);
    }
    else if(instruction == 16)
    {
        //std::cout << "Работа графики" << std::endl;
        GraphicInterrupt();
    }
}
