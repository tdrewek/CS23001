//  Theodore Drewek
//  char Constructor
//  Tests: "a" 
//

#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main (){
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str[0] == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('W');

        // VERIFY
        assert(str[0] == 'W');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('o');

        // VERIFY
        assert(str[0] == 'o');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('T');

        // VERIFY
        assert(str[0] == 'T');
    }

    
    std::cout << "---> TESTING COMPLETE FOR CHAR CONSTRUCTOR <---" << std::endl;
    return 0;
}
