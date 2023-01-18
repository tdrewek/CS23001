//
//  profile.cpp
//
//  Created by Jonathan Maletic.
//  Copyright 2022 Kent State University. All rights reserved.
//  Fall  2022
//  Modified by: Theodore Drewek
//

#include "profile.hpp"

// Prints out the profile.
//
// TODO: Very basic, need to make it print neat columns with headings
// 
std::ostream& operator<< (std::ostream& out, const profile& p) {
    out << "|----------------------------------|" << std::endl;
    out << "|File: " << p.filename << "                  |" << std::endl;
    out << "|----------------------------------|" << std::endl;
    out << "|LINE  | NAME" << "          | COUNT     |" << std::endl;
    out << "|------|---------------|-----------|" << std::endl;
    for(std::map<std::string, int>::const_iterator i = p.stmt.begin(); i != p.stmt.end(); ++i) {
        out << "|" << i->first << i->second << "        |" << std::endl;   
        out << "|------|---------------|-----------|" << std::endl;     
    }
    return out;
}



// REQUIRES:  n >= 0
// ENSURES: Returns a text version of a positive integer long
//
std::string intToString(long n) {
    assert(n >= 0);
    std::string result;
    
    if (n == 0) return "0";
    while (n > 0) {
        result = char(int('0') + (n % 10)) + result;
        n = n / 10;
    }  
    return result;
}
