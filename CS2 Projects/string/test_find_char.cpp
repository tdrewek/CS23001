//  Theodore Drewek
//  Test Find Char
//  Tests: (start, char) 
//  RETVAL: return char if found, if not fail
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
        String  s1("abcdefghijklmnopqrstuvwxyz");
        int pos = s1.findch(0, 'i');
        
        // VERIFY
        assert(pos == 8);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyz");
        int pos = s1.findch(0, 'a');
        
        // VERIFY
        assert(pos == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("I Love Skateboarding");
        int pos = s1.findch(5, 'a');
        
        // VERIFY
        assert(pos == 9);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("HelloWorld!");
        int pos = s1.findch(4, '!');
        
        // VERIFY
        assert(pos == 10);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("TestingFindChar");
        int pos = s1.findch(2, 'F');
        
        // VERIFY
        assert(pos == 7);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyz");
        int pos = s1.findch(20, 'z');
        
        // VERIFY
        assert(pos == 25);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("TheSkyIsBlueAndNot_GREEN");
        int pos = s1.findch(7, '_');
        
        // VERIFY
        assert(pos == 18);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("largeicedcoldbrewwithmochaandoatmilk");
        int pos = s1.findch(12, 'w');
        
        // VERIFY
        assert(pos == 16);
    }


    std::cout << "---> TESTING COMPLETE FOR FIND_CHAR <---" << std::endl;
    return 0;
}