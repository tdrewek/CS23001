// Theodore Drewek
// string.cpp
// CS23001

#include "string.hpp"

// Empty String
String::String(){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// Copy Constructor
// A new object is created from an existing object,
// as a copy of the existing object
String::String(const String& actual){
    stringSize = actual.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; ++i){
        str[i] = actual.str[i];
    }
}

// Destructor
String::~String(){
    delete[] str;
}

// String('x')
String::String(char ch){
    if (ch != '\0'){
        stringSize = 2;
        str = new char[stringSize];
        str[0] = ch;
        str[1] = '\0';
    }else{
        assert(ch == '\0');
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
    }
    
}

// String("abcd")
// REQUIRES: string to be null terminating, str.length() == capacity()
String::String(const char ch[]){
    stringSize = 0;
    while (ch[stringSize] != '\0'){
        ++stringSize;
    }
    ++stringSize;
    str = new char[stringSize];
    int i = 0;
    while(ch[i] != '\0'){
        str[i] = ch[i];
        ++i;
    }
    str[i] = '\0';
}

// Constant time swap
// No matter how big the array is, it is always the 
// same amount of assignment to swap them
void String::swap(String & rhs){
    char* tmp = str;
    str = rhs.str;
    rhs.str = tmp;
    int capTemp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = capTemp;
}

// Max chars that can be stored
int String::capacity() const{
    return length();
}

// Returns the length of the string
// OFFSET == length() == 0
// Number of char in string
int String::length() const{
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}

// REQUIRES: 0 <= i < length()
// Accessor/Modifier
char& String::operator[](int i){
    assert(0 <= i);
    if (length() == 0)
        return str[0];
    assert(i <= length());
    return str[i];
}

// REQUIRES: 0 <= i < length()
// Accessor
char String::operator[](int i) const{
    assert(0 <= i);
    if (length() == 0)
        return str[0];
    assert(i <= length());
    return str[i];
}

// Concatenation
//  s1("abcd");
//  s2("efgh");
//  s1 += s2;
//  s1 == "abcdefgh";
String& String::operator+=(const String& rhs){
    if (rhs.length() == 0){
        return *this;
    }
    if (length() == 0){
        *this = rhs;
        return *this;
    }
        int newLength = stringSize + rhs.stringSize;
        char* newStr = new char[newLength];
        int i = 0;
        while (str[i]!= '\0'){
            newStr[i] = str[i];
            ++i;
        }
        for (int j = 0; j < rhs.stringSize; ++j){
            newStr[i+j] = rhs.str[j];
        }
        delete[] str;
        str = newStr;
        stringSize = newLength;
    return *this;
}

// overload for ==
bool String::operator==(const String& rhs) const{
    for (int i = 0; i < length() || i < rhs.length(); i++){
        if (str[i] != rhs.str[i])
            return false;
    }
    return true;
}

// copy assignment
// An already initialized object is assigned a new value,
// from another existing object
String& String::operator=(String rhs){
    swap(rhs);
    return *this;
}

// overload for <
bool String::operator<(const String& rhs) const{
    int i = 0;
    while (str[i] != '\0' && rhs.str[i] != '\0' && str[i] == rhs.str[i]){ ++i; }
    return str[i] < rhs.str[i];
}

// REQUIRES: 0 <= start <= end && start <= end < length()
// Sub from starting to ending positions
String String::substr(int start, int end) const{
    String sub;
    if (start < 0) start = 0;
    if (end >= length()) end = length() - 1;
    if (end < start) return sub;
    if (start > end) return sub;
    int i = start;
    while (i <= end) {
        sub += str[i];
        ++i;
    }
    return sub;
}

// String ("abcde")
// findch(2, 'd')
// RETVAL == 3
// Location of character starting at a position
// REQUIRES: 0 <= start < length()
// ENSURES: RetVal == i where str[i] == ch ||
//          RetVal == -1 where str[start,..,length()-1] != ch
int String::findch(int start, char ch) const{
    if (start < 0 || start >= length())
        return -1;
    int i = start;
    while(str[i] != '\0'){
        if (str[i] == ch){
            return i;
        }
        ++i;
    }
    return -1;
}


// Location of string starting at a position
int String::findstr(int start, const String& rhs) const{
    bool found = false; // rhs found default set to false
    for (int i = start; i < length(); i++){
        if (str[i] == rhs[0]){
            for (int j = 0; j < rhs.length(); j++){
                if ((i + j) >= length())
                    break;
                if (str[i + j] != rhs[j])
                    found = false;
                else
                    found = true;
                if (found && j == (rhs.length() - 1))
                    return i;
            }
        }
    }
    // If not found
    return -1;
}

// friend overload >>
std::istream& operator>>(std::istream& IN, String& rhs){
    char result[rhs.stringSize];
    IN >> result;
    rhs = String(result);
    return IN;
}

// friend overload <<
std::ostream& operator<<(std::ostream& OUT, const String& rhs){
    for (int i = 0; rhs.str[i] != '\0'; ++i){
        OUT << rhs.str[i];
    }
    return OUT;
}

std::vector<String> String::split(char ch) const{
    std::vector<String> result;
    int start = 0;
    int end = findch(start, ch);
    while(end != -1){
        result.push_back(substr(start, end - 1));
        start = end + 1;
        end = findch(start, ch);
    }
    if (start <= length())
        result.push_back(substr(start, length() - 1));
    return result;
}

//----------------------------------------------------
// Free Functions
//----------------------------------------------------

String operator+(String result, const String& rhs){
    result += rhs;
    return result;
}

bool operator==(const char result[], const String& rhs){
    if (String(result) == rhs)
        return true;
    return false;
}

bool operator==(char ch, const String& rhs){
    return String(ch) == rhs;
}

bool operator<(const char ch[], const String& rhs){
    return String(ch) < rhs;
}

bool operator<(char ch, const String& rhs){
    return String(ch) < rhs;
}

bool operator<=(const String& result, const String& rhs){
    int i = 0;
    if (result[i] == '\0' && rhs[i] != '\0')
        return true;
    if (result[i] != '\0' && rhs[i] == '\0')
        return false;
    while (result[i] != '\0' && rhs[i] != '\0'){
        if (result[i] > rhs[i])
            return false;
        ++i;
    }
    return true;
}

bool operator!=(const String& result, const String& rhs){
    if (result == rhs)
        return false;
    return true;
}

bool operator>=(const String& result, const String& rhs){
    int i = 0;
    if (result[i] == '\0' && rhs[i] != '\0')
        return false;
    if (result[i] != '\0' && rhs[i] == '\0')
        return true;
    while (result[i] != '\0' && rhs[i] != '\0'){
        if (result[i] < rhs[i])
            return false;
        ++i;
    }
    return true;
}

bool operator>(const String& result, const String& rhs){
    int i = 0;
    while (i < rhs.length()){
        if (result[i] <= rhs[i])
        return false;
    }
    return true;
}

