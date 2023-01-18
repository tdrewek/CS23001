#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "../string/string.hpp"

void toPostfix(std::ifstream& in, std::ostream& out); 
void toAssembly(std::ifstream& in, std::ostream& out);
void toPrefix(std::ifstream& in, std::ostream& out);   // Extra Credit Challenge
std::string intToString(int);
std::string getOperator(const std::string& op);
std::string getToken(std::ifstream& in); 

#endif // UTILITIES_HPP


