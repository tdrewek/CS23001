// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    //Add test cases!!
    
    {
        // Setup
        bigint bi(434);

        // Test
        int digit = bi[1];

        // Verify
        assert(bi    == 434);
        assert(digit == 3);
    }
    
    {
        // Setup
        bigint bi("1010101010101");

        // Test
        int digit = bi[5];

        // Verify
        assert(bi    == "1010101010101");
        assert(digit == 0);
    }
    
    {
        // Setup
        bigint bi(1516131718);

        // Test
        int digit = bi[6];

        // Verify
        assert(bi    == 1516131718);
        assert(digit == 6);
    }
    
    {
        // Setup
        bigint bi(342231216);

        // Test
        int digit = bi[8];

        // Verify
        assert(bi    == 342231216);
        assert(digit == 3);
    }
    
    {
        // Setup
        bigint bi("1234567890987654321012345678909876543210");

        // Test
        int digit = bi[16];

        // Verify
        assert(bi    == "1234567890987654321012345678909876543210");
        assert(digit == 4);
    }
    
    {
        // Setup
        bigint bi(1000001001);

        // Test
        int digit = bi[3];

        // Verify
        assert(bi    == 1000001001);
        assert(digit == 1);
    }
    

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}


