// bigint Test Program
//
// Tests:  times_10, uses ==
//
// 
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(4);

        // Verify
        assert(bi == 30000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(56789);

        // Test 
        bi = bi.times10(4);

        // Verify
        assert(bi == 567890000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9999999);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 999999900);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(434434);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 4344340);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1123);

        // Test 
        bi = bi.times10(6);

        // Verify
        assert(bi == 1123000000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(69);

        // Verify
        assert(bi == 0);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times10(6);

        // Verify
        assert(bi == 1000000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("123456789123456789");

        // Test 
        bi = bi.times10(6);

        // Verify
        assert(bi == "123456789123456789000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("9999999999999999999999999999999999999999999999999999999999999999");

        // Test 
        bi = bi.times10(15);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999000000000000000");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("4343434343434343434343434343434343400043434343434300114343");

        // Test 
        bi = bi.times10(23);

        // Verify
        assert(bi == "434343434343434343434343434343434340004343434343430011434300000000000000000000000");
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}

