#include <fstream>
#include <iostream>
#include <stdint.h>

void WriteU8Value(char* filepath, uint8_t &value)
{
    std::ofstream Outputfile(filepath, std::ios_base::binary | std::ios::app);
    Outputfile.write((char*)&value, sizeof(uint8_t));
    Outputfile.close();
}

void WriteU16Value(char* filepath, uint16_t &value)
{
    std::ofstream file(filepath, std::ios_base::binary | std::ios::app);
    file.write((char*)&value, sizeof(uint16_t));
    file.close();
}

void Parse(std::vector<Token> tokens, char* filepath)
{
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].tokenTypes == TokenTypes(MOV) || tokens[i].tokenTypes == TokenTypes(ADD) || tokens[i].tokenTypes == TokenTypes(SUB) && tokens.size() >= 4)
        {
            if(tokens[i + 1].tokenClass == TokenClass(REGISTER))
            {
                if(tokens[i + 2].tokenTypes == TokenTypes(ISNUM))
                {
                    WriteU8Value(filepath, tokens[i].U8Value);
                    WriteU8Value(filepath, tokens[i + 1].U8Value);
                    WriteU8Value(filepath, tokens[i + 2].U8Value);
                    WriteU16Value(filepath, tokens[i + 3].U16Value);
		    i = tokens.size();
                }
            }
        }
	else if(tokens[i].tokenTypes == TokenTypes(INC) || tokens[i].tokenTypes == TokenTypes(DEC) && tokens.size() >= 2)
	{
	    if(tokens[i + 1].tokenClass == TokenClass(REGISTER))
	    {
	         WriteU8Value(filepath, tokens[i].U8Value);
		 WriteU8Value(filepath, tokens[i + 1].U8Value);
		 i = tokens.size();
	    }
	}
	else if(tokens[i].tokenTypes == TokenTypes(LABLE) && tokens.size() >= 2)
	{
	    if(tokens[i + 1].tokenTypes == TokenTypes(NUM))
	    {
		Lable tmpLable;   

	       	std::fstream file(filepath);
                int filesize = 0;
                file.seekg (0, std::ios::end);
                filesize = file.tellg();
                file.close();

		tmpLable.LableName = tokens[i + 1].Name;
		tmpLable.Path = filesize + 1;
		LableList.push_back(tmpLable);

	//	std::cout << "Lable Name: " << tokens[i+1].Name << "Lable Path: " << filesize + 1;
	    }
	}
	else if(tokens[i].tokenClass == TokenClass(INTERRUPT))
	{
	    std::cout << "INT" << std::endl;
	    WriteU8Value(filepath, tokens[i].U8Value);
	    i = tokens.size();
	}
     }
}
