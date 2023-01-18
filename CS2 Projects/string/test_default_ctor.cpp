//  Theodore Drewek
//  Defualt Constructor
//  Tests: str[0] == '\0' 
//

#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        
        assert(str[0] == '\0');
        std::cout << "str == 0" << str << std::endl;

        std::cout << "---> TESTING COMPLETE FOR DEFAULT CONSTRUCTOR <---" << std::endl;

    return 0;
}

