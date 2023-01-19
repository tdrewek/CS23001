//  
//  Test Equal
//  Tests: s1 == s2
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
        String  s2("abcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(s1 == s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("thisStringIsEqualToTheOther");
        String  s2("thisStringIsEqualToTheOther");

        // VERIFY
        assert(s1 == s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("HeLloWoRlD!!!ThisSttttringUsesMultipleCharactersInARowAndSpecialCharactersLike?<>()*&^%$#@!?___+=[]/.,");
        String  s2("HeLloWoRlD!!!ThisSttttringUsesMultipleCharactersInARowAndSpecialCharactersLike?<>()*&^%$#@!?___+=[]/.,");

        // VERIFY
        assert(s1 == s2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("QWERTYUIOP  qwertyuiop  ASDFGHJKL  asdfghjkl  ZXCVBNM  zxcvbnm");
        String  s2("QWERTYUIOP  qwertyuiop  ASDFGHJKL  asdfghjkl  ZXCVBNM  zxcvbnm");

        // VERIFY
        assert(s1 == s2);
    }

    
    std::cout << "---> TESTING COMPLETE FOR EQUAL <---" << std::endl;
    return 0;
}
