//  Theodore Drewek
//  charArray Constructor
//  Tests: "abcd"
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
        String  str("abcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(str == "abcdefghijklmnopqrstuvwxyz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("HeLloWoRlD!");

        // VERIFY
        assert(str == "HeLloWoRlD!");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("this is a string with spaces");

        // VERIFY
        assert(str == "this is a string with spaces");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyqwertyqwertyuiopqw");

        // VERIFY
        assert(str == "qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyqwertyqwertyuiopqw");
    }

    
    std::cout << "---> TESTING COMPLETE FOR CHAR_ARRAY CONSTRUCTOR <---" << std::endl;
    return 0;
}
