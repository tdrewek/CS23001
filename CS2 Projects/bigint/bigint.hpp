//  DECLARATION
//  bigint.hpp
//  Project1
//
//  Created on 9/7/22.
//

#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>

const int CAPACITY = 200;

class bigint{
public:
    bigint(); // default constructor
    bigint(const char[]); // initialize constructor for const char
    bigint(int); // initialize constructor for int
    void debugPrint(std::ostream&) const; // debugPrint method for bigint
    
    friend std::ostream& operator<<(std::ostream&, const bigint&); // overload << for bigint
    friend std::istream& operator>>(std::istream&, bigint&); // overload >> for bigint
    
    bool operator==(const bigint&) const; // overload == for bigint
    bigint operator+(const bigint&) const; // overload + for bigint
    int operator[](int) const; // overload [] for bigint

    bigint operator*(const bigint&) const; // overload * for bigint
    bigint timesDigit(int) const; // multiply bigint and single integer
    bigint times10(int) const; // multiply a bigint by 10^n

    
private:
    int bigInteger[CAPACITY]; // int variable for bigint with MAX_SIZE
};




#endif // BIGINT_HPP



