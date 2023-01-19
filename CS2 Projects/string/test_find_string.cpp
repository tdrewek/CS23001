//  
//  Test Find String
//  Tests: (start, String) 
//  RETVAL: return index of start of String if found, if not fail
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
        String  s2("stuv");
        int pos = s1.findstr(3, s2);
        
        // VERIFY
        assert(pos == 18);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("Hello World");
        String  s2("World");
        int pos = s1.findstr(1, s2);
        
        // VERIFY
        assert(pos == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyz");
        String  s2("abcdefg");
        int pos = s1.findstr(0, s2);
        
        // VERIFY
        assert(pos == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("SkateboardingIsDangerous");
        String  s2("Is");
        int pos = s1.findstr(7, s2);
        
        // VERIFY
        assert(pos == 13);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("ThisProjectRequiresALotOfTime");
        String  s2("iresALo");
        int pos = s1.findstr(8, s2);
        
        // VERIFY
        assert(pos == 15);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        String  s2("efghijklmno");
        int pos = s1.findstr(50, s2);
        
        // VERIFY
        assert(pos == 56);
    }


    std::cout << "---> TESTING COMPLETE FOR FIND_STRING <---" << std::endl;
    return 0;
}