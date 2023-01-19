//  IMPLEMENTATION
//  add.cpp
//  Project1
//
//  Created on 9/25/22.
//

#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-1.txt");      // Open a file
    if (!in) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    bigint a, b, c;
    while (!in.eof()) {
        in >> a;
        in >> b;
        if (a == 0 == false && b == 0 == false){
        std::cout << "---------------------------" << std::endl;
        std::cout << "The two bigints are: " << std::endl;
        std::cout << a << std::endl << "and" << std::endl << b << std::endl;
        c = a + b;
        std::cout << "The sum of the two bigints: " << std::endl << c << std::endl;
    }
    }
    if (in.eof())
        std::cout << "---------------------------" << std::endl;
    in.close();
    return 0;
}




