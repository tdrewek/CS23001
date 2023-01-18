//  Theodore Drewek
//  Test Len Cap
//  Tests: length() && capacity()
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

        // VERIFY
        assert(s1.length() == 26);
        assert(s1.capacity() == 26);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        // VERIFY
        assert(s1.length() == 234);
        assert(s1.capacity() == 234);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("Hello!");

        // VERIFY
        assert(s1.length() == 6);
        assert(s1.capacity() == 6);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("ThisProjectIsReallyFun");

        // VERIFY
        assert(s1.length() == 22);
        assert(s1.capacity() == 22);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("C++ Is The Best Programming Language!");

        // VERIFY
        assert(s1.length() == 37);
        assert(s1.capacity() == 37);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("Professor Maletic Is The Best Programmer On Planet Earth!");

        // VERIFY
        assert(s1.length() == 57);
        assert(s1.capacity() == 57);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("coffee is a necessity on a monday morning");

        // VERIFY
        assert(s1.length() == 41);
        assert(s1.capacity() == 41);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("Kent_State_Has_The_Best_Professors");

        // VERIFY
        assert(s1.length() == 34);
        assert(s1.capacity() == 34);

    }

    std::cout << "---> TESTING COMPLETE FOR LENGTH() AND CAPACITY() <---" << std::endl;
    return 0;
}