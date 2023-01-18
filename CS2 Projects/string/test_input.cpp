//  Theodore Drewek
//  Test Input
//  Tests: INPUT >> s1
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
 
//===========================================================================
int main (){
    std::ifstream file("input1-1.txt");
    if (file.is_open()){
        String s1;
        // VERIFY
        file >> s1;
        assert(s1 == "some");
        file >> s1;
        assert(s1 == "text");
        file >> s1;
        assert(s1 == "in");
        file >> s1;
        assert(s1 == "a");
        file >> s1;
        assert(s1 == "file");
        file >> s1;
        assert(s1 == "on");
        file >> s1;
        assert(s1 == "multiple");
        file >> s1;
        assert(s1 == "lines");
        file >> s1;
        assert(s1 == "of");
        file >> s1;
        assert(s1 == "text");
        }else{
            std::cout << "Unable to open file" << std::endl;
        }
    file.close();
    std::cout << "---> TESTING COMPLETE FOR INPUT <---" << std::endl;
    return 0;
}