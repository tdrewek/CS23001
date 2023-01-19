// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(12345);
      bigint right("12345");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 12345);
      assert(right  == "12345");
      assert(result == 24690);
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1110000000000123");
      bigint right("1110000000000234");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "1110000000000123");
      assert(right  == "1110000000000234");
      assert(result == "2220000000000357");
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("9876001134");
      bigint right("4321006789");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   ==  "9876001134");
      assert(right  ==  "4321006789");
      assert(result == "14197007923");
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(999999999);
      bigint right(999999999);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999999999);
      assert(right  == 999999999);
      assert(result == 1999999998);
    }
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

