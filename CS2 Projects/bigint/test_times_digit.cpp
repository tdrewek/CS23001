// bigint Test Program
//
// Tests:  times_digit, uses ==
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
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 12);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(8);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 72);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(500);

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 2500);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(420420);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 3783780);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1216);

        // Test 
        bi = bi.timesDigit(6);

        // Verify
        assert(bi == 7296);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(43416434);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 43416434);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9999999);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 89999991);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("12345678909876543211234567890987654321");

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == "61728394549382716056172839454938271605");  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test 
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == "6999999999999999999999999999999999999999999999999999999999999999999999999999999999993");  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010");

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == "2020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020");  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("789789789789789789789789789789");

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == "789789789789789789789789789789");  
    }

    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
