#include <vector>
#include <iostream>
#include <string>
#include <cstdint>

// ASM VARS
struct Lable
{
    int Path;
    std::string LableName;
};

std::vector<Lable> LableList; 

int GetLablePath(std::string Name)
{
    for(int i = 0; i < LableList.size(); i++)
    {
        if(LableList[i].LableName == Name)
	{
	    return LableList[i].Path;
	}
    }
    return 16;
}

enum TokenTypes
{
    MOV,
    ADD,
    SUB,
    MUL,
    INC,
    DEC,
    LABLE,
    JMP,
    AX,
    BX,
    CX,
    DX,
    SI,
    DI,
    BP,
    SP,
    CS,
    DS,
    SS,
    LINK,
    ISNUM,
    NUM

};
enum TokenClass
{
    REGISTER,
    OPERATOR,
    INSTRUCTION,
    NONE
};

class Token
{
    public:
        TokenTypes tokenTypes;
        TokenClass tokenClass;
        int BitDepht;
        uint8_t U8Value;
        uint16_t U16Value;
	std::string Name;
};

#include "Parser.h"

std::vector<std::string> ParsedScript;
std::vector<Token> lexer(std::string Line)
{
    std::vector<Token> tokens;
    Token tmpToken;
    std::string tmpLine;
    for(int i = 0; i < Line.length(); i++)
    {
        if(Line[i] == ' ' || Line[i] == '$' || Line[i] == '&')
        {
            if(Line[i] == '$')
            {
                tmpToken.tokenTypes = TokenTypes(ISNUM);
                tmpToken.tokenClass = TokenClass(OPERATOR);
                tmpToken.U8Value = 01;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
            else if(Line[i] == '&')
            {
                tmpToken.tokenTypes = TokenTypes(LINK);
                tmpToken.tokenClass = TokenClass(OPERATOR);
                tmpToken.U8Value = 01;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
            tmpLine = "";
       }
        else
        {
            tmpLine += Line[i];

            if(tmpLine == "mov")
            {
                tmpToken.tokenTypes = TokenTypes(MOV);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 10;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "add")
           {
                tmpToken.tokenTypes = TokenTypes(ADD);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 11;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
	    else if(tmpLine == "sub")
            {
                tmpToken.tokenTypes = TokenTypes(SUB);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 12;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }   
            else if(tmpLine == "inc")
            {
                tmpToken.tokenTypes = TokenTypes(INC);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 13;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }    
            else if(tmpLine == "dec")
            {
                tmpToken.tokenTypes = TokenTypes(DEC);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 14;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
            else if(tmpLine == "lable")
            {
                tmpToken.tokenTypes = TokenTypes(LABLE);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 0;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 0;

                tokens.push_back(tmpToken);
	    }    
            else if(tmpLine == "jmp")
            {
                tmpToken.tokenTypes = TokenTypes(JMP);
                tmpToken.tokenClass = TokenClass(INSTRUCTION);
                tmpToken.U8Value = 101;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }            
	    else if(tmpLine == "ax")
            {
                tmpToken.tokenTypes = TokenTypes(AX);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 01;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
            else if(tmpLine == "bx")
            {
                tmpToken.tokenTypes = TokenTypes(BX);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 02;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
	   else if(tmpLine == "cx")
           {
                tmpToken.tokenTypes = TokenTypes(CX);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 03;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "dx")
           {
                tmpToken.tokenTypes = TokenTypes(DX);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 04;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "si")
           {
                tmpToken.tokenTypes = TokenTypes(SI);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 05;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "di")
           {
                tmpToken.tokenTypes = TokenTypes(DI);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 06;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "bp")
           {
                tmpToken.tokenTypes = TokenTypes(BP);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 07;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "sp")
           {
                tmpToken.tokenTypes = TokenTypes(SP);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 8;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "cs")
           {
                tmpToken.tokenTypes = TokenTypes(CS);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 9;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }
           else if(tmpLine == "DS")
           {
                tmpToken.tokenTypes = TokenTypes(DS);
                tmpToken.tokenClass = TokenClass(REGISTER);
                tmpToken.U8Value = 10;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }





             /*else if(tmpLine == "$")
            {
                tmpToken.tokenTypes = TokenTypes(LINK);
                tmpToken.tokenClass = TokenClass(OPERATOR);
                tmpToken.U8Value = 01;
                tmpToken.U16Value = 0;

                tmpToken.BitDepht = 8;

                tokens.push_back(tmpToken);
            }*/
            else if(i == Line.length() - 1)
            {
                tmpToken.tokenTypes = TokenTypes(NUM);
                tmpToken.tokenClass = TokenClass(NONE);
                tmpToken.U8Value = 00;
		if(tmpLine[0] >= '0' && tmpLine[0] <= '9')
		{
                    tmpToken.U16Value = std::stoul(tmpLine);
		}
		tmpToken.Name = tmpLine;
                tmpToken.BitDepht = 16;

                tokens.push_back(tmpToken);
            }
        }
    }

    //Parse(tokens, filepath);
    
    ParsedScript.clear();
    return tokens;
}
