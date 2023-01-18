//  
//
//  Tests: Default Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

//===========================================================================
int main ()
{
    {
        stack<int> test;
        assert(test.empty() == true); 
    }  
    
    {
        stack<int> test;
        assert(test.full() == false); 
    }
   

    {
        stack<String> test;
        assert(test.empty() == true); 
    }  


    {
        stack<String> test;
        assert(test.full() == false); 
    }


    {
        stack<char> test;
        assert(test.empty() == true); 
    }     
    
    {
        stack<char> test;
        assert(test.full() == false); 
    }
    

    {
        stack<String> test;
        assert(test.full() == false); 
    }


    
    std::cout << "-->>TESTING COMPLETE FOR DEFAULT CONSTRUCTOR<<--" << std::endl;
    return 0;
}
