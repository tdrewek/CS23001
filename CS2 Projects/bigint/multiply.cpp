//
//  multiply.cpp
//  Project1
//
//  Created by Teddy Drewek on 9/29/22.
//

#include "bigint.hpp"

int main() {
    std::ifstream in;            // Define input stream
    in.open("data1-2.txt");      // Open file
    if (!in) {                   // Make sure file opened correctly
        std::cerr << "File not found: data1-2.txt" << std::endl;
        exit(1);
    }
    
    while (!in.eof()) {
        bigint a, b, c;
        in >> a;
        in >> b;
        if (a == 0 == false && b == 0 == false){
        std::cout << "---------------------------" << std::endl;
        std::cout << "The two bigints are: " << std::endl;
        std::cout << a << std::endl << "and" << std::endl << b << std::endl;
        c = a * b;
        std::cout << "The product of the two bigints: " << std::endl << c << std::endl;
    }
    }
    if (in.eof())
        std::cout << "---------------------------" << std::endl;
    in.close();
    return 0;
}