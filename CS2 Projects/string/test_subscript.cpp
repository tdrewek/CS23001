//  
//  Test Subscript
//  Tests: s1[int]
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
        String  s1("CS2");
        char value = s1[2];

        // VERIFY
        assert(value == '2');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("Hello World");
        char value = s1[5];

        // VERIFY
        assert(value == ' ');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("C++ is Awesome!");
        char value = s1[14];

        // VERIFY
        assert(value == '!');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("subscriptOperatorOverload");
        char value = s1[8];

        // VERIFY
        assert(value == 't');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("myNameIsTeddy");
        char value = s1[4];

        // VERIFY
        assert(value == 'm');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("wasp.cs.kent.edu");
        char value = s1[12];

        // VERIFY
        assert(value == '.');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("QWERTYUIOPqwertyuiopASDFGHJKLasdfghjklZXCVBNMzxcvbnm");
        char value = s1[48];

        // VERIFY
        assert(value == 'v');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("MaleticIsAwesome!");
        char value = s1[0];

        // VERIFY
        assert(value == 'M');
    }

    

    std::cout << "---> TESTING COMPLETE FOR SUBSCRIPT <---" << std::endl;
    return 0;
}