#include "Lexer.h"
#include <string>
int main(int argc, char* argv[])
{
    std::ofstream file(argv[2], std::ios_base::binary);
    file.close();

    std::ifstream Script(argv[1]);
    std::string line;
    if (Script.is_open())
    {
        while (std::getline(Script, line))
        {
            Parse(lexer(line), argv[2]);
        }
    }
    //Parse(lexer("mov ax $ 10"), argv[2]);
    //uint8_t sas = 10;
    //WriteU8Value(argv[1], sas);
    return 0;
}
