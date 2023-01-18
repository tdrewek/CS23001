#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>
int main(){
{
    // SETUP
    std::vector<String> test = String("Hello World").split(' ');
    
    // VERIFY
    assert(test[0] == "Hello");
    assert(test[1] == "World");
}

{
    // SETUP
    std::vector<String> test = String("abc ef gh").split(' ');

    // VERIFY
    assert(test[0] == "abc");
    assert(test[1] == "ef");
    assert(test[2] == "gh");
}
{
    // SETUP
    std::vector<String> test = String("-Ab--c-").split('-');
    
    // VERIFY
    assert(test[0] == "");
    assert(test[1] == "Ab");
    assert(test[2] == "");
    assert(test[3] == "c");
    assert(test[4] == "");
}
{
    // SETUP
    std::vector<String> test = String("--56- 43-").split(' ');

    // VERIFY
    assert(test[0] == "--56-");
    assert(test[1] == "43-");
    
    
}
{
    // SETUP
    std::vector<String> test = String(" h ").split(' ');
    
    // VERIFY
    assert(test[0] == "");
    assert(test[1] == "h");
    assert(test[2] == "");

    
}
{
    // SETUP
    std::vector<String> test = String("T--E--D--D--Y").split('-');

    // VERIFY
    assert(test[0] == "T");
    assert(test[1] == "");
    assert(test[2] == "E");
    assert(test[3] == "");
    assert(test[4] == "D");
    assert(test[5] == "");
    assert(test[6] == "D");
    assert(test[7] == "");
    assert(test[8] == "Y");
}

std::cout << "---> TESTING COMPLETE FOR SPLIT <---" << std::endl;
}