//  Theodore Drewek
//  copy Constructor
//  Tests: String a("hello");
//         String b(a);
//         assert(b == a);
//         assert(b == "hello");
//

#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main (){
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("hello");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "hello");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("This is a string that is very long, this string is the longest string that there could possibly be, the longest of the long. Testing the copy constructor to the absolute max, and seeing if it is able to handle this massive dynamically allocated character array. This will be the longest string that you will ever see in any test case in your entire life. No other string will ever compare to this string. This string is bigger than mountain Everest. This string is longer than the great wall of China, and most importantly, this string will pass this test!");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "This is a string that is very long, this string is the longest string that there could possibly be, the longest of the long. Testing the copy constructor to the absolute max, and seeing if it is able to handle this massive dynamically allocated character array. This will be the longest string that you will ever see in any test case in your entire life. No other string will ever compare to this string. This string is bigger than mountain Everest. This string is longer than the great wall of China, and most importantly, this string will pass this test!");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()::;';';';;:::<>?<>?<>?<>?><>?><>?><>?><>?><>?><>?><>?><?><>?");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "!@#$%^&*()!@#$%^&*()!@#$%^&*()!@#$%^&*()::;';';';;:::<>?<>?<>?<>?><>?><>?><>?><>?><>?><>?><>?><?><>?");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("                                           space                                      ");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "                                           space                                      ");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("hello");
        // TEST
        String b(a);
        a = b;
        b = a;
        b += a;
        // VERIFY
        assert(b == "hellohello");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("1230 + 1230 = 2460");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "1230 + 1230 = 2460");    
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String a("C++C++C++C++C++C++C++C++C++C++C++C++C++C++C++");
        // TEST
        String b(a);
        // VERIFY
        assert(b == a);
        assert(b == "C++C++C++C++C++C++C++C++C++C++C++C++C++C++C++");    
    }

    std::cout << "---> TESTING COMPLETE FOR COPY CONSTRUCTOR <---" << std::endl;
    return 0;
}
