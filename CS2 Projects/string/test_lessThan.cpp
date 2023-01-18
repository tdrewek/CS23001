//  Theodore Drewek
//  Test Less Than
//  Tests: s1 < s2
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
        String  s1("a");
        String  s2("b");

        // VERIFY
        assert(s1 < s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("sbcdefghijklmnopqrstuvwxyz");
        String  s2("tbcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(s1 < s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("xbcdefghijklmnopqrstuvwxyz");
        String  s2("ybcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(s1 < s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("dbcdefghijklmnopqrstuvwxyz");
        String  s2("rbcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(s1 < s2);
    }

    
    std::cout << "---> TESTING COMPLETE FOR LESS_THAN <---" << std::endl;
    return 0;
}
