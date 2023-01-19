//  
//  Test Substring
//  Tests: (start, end) 
// RETVAL: substring
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
        String sub = s1.substr(1, 7);
        
        // VERIFY
        assert(sub == "bcdefgh");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("This string will have a substring");
        String sub = s1.substr(11, 26);

        // VERIFY
        assert(sub == " will have a sub");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyz");
        String sub(s1.substr(5, 12));

        // VERIFY
        assert(sub == "fghijklm");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("motorcycles are fun but dangerous");
        String sub = s1.substr(0, 18);

        // VERIFY
        assert(sub == "motorcycles are fun");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("I prefer MacOS for programming");
        String sub = s1.substr(10, 29);
        // VERIFY
        assert(sub == "acOS for programming");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("But I prefer Windows for gaming");
        String sub = s1.substr(3, 19);
        // VERIFY
        assert(sub == " I prefer Windows");
    }

    std::cout << "---> TESTING COMPLETE FOR SUBSTRING <---" << std::endl;
    return 0;
}