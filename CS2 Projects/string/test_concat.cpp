//  
//  Test Concatenation
//  Tests: s1 += s2
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
        s1 += s2;

        // VERIFY
        assert(s1 == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
        assert(s2 == "abcdefghijklmnopqrstuvwxyz");

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("myNameIs ");
        String  s2("Teddy");
        s1 += s2;

        // VERIFY
        assert(s1 == "myNameIs Teddy");
        assert(s2 == "Teddy");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("A group of things linked together or occurring together in a way that produces a particular result or effect ");
        String  s2("is called concatenation.");
        s1 += s2;

        // VERIFY
        assert(s1 == "A group of things linked together or occurring together in a way that produces a particular result or effect is called concatenation.");
        assert(s2 == "is called concatenation.");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("the act of concatenating things");
        String  s2(" or the state of being concatenated");
        s1 += s2;

        // VERIFY
        assert(s1 == "the act of concatenating things or the state of being concatenated");
        assert(s2 == " or the state of being concatenated");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("(This is s1)");
        String  s2(" and ");
        String  s3("(This is s3)");
        s1 += s2;
        s1 += s3;

        // VERIFY
        assert(s1 == "(This is s1) and (This is s3)");
        assert(s2 == " and ");
        assert(s3 == "(This is s3)");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("I love C++ ");
        String  s2("and everything that a programmer can do with it!");
        s1 += s2;

        // VERIFY
        assert(s1 == "I love C++ and everything that a programmer can do with it!");
        assert(s2 == "and everything that a programmer can do with it!");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  s1("s1 += s2 ");
        String  s2("is called concatenation");
        s1 += s2;

        // VERIFY
        assert(s1 == "s1 += s2 is called concatenation");
        assert(s2 == "is called concatenation");
    }

    std::cout << "---> TESTING COMPLETE FOR CONCATENATION(+=) <---" << std::endl;
    return 0;
}
