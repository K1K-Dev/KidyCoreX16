#include "ReadBin.h"

//#include "KidyCore.h"

int main(int argc, char* argv[])
{
    window.clear();
    ReadBinFile(argv[1]);
    //reg = MOV_Instruction(1, 1, 10, reg);

//    std::cout << unsigned(reg.BP) << std::endl;

    //std::cout << unsigned(Read2ByteByPos(argv[1], 8)) << std::endl;

    //std::cout << argv[1] << std::endl;
    DrawWindow();
    return 0;
}
