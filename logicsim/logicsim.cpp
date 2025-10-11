#include <iostream>
#include <fstream>

#include "circuit.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <circuit_file>" << std::endl;
        return 1;
    }
    
    Circuit c;
    
    if(!c.parse(argv[1]))
    {
        std::cout << "Failed to parse circuit file: " << argv[1] << std::endl;
        return 1;
    }
    
    c.startUml(std::cout);
    c.run(std::cout);
    c.endUml(std::cout);
    
    return 0;
}