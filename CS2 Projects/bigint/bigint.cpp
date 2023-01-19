//  DEFINITION
//  bigint.cpp
//  Project1
//
//  Created on 9/7/22.
//

#include "bigint.hpp"

// default constructor
bigint::bigint() {
    for (int i = 0; i < CAPACITY; ++i) {
        bigInteger[i] = 0;
    }
}

// initialize constructor for const char[]
bigint::bigint(const char ch[]) {
    int count = 0;
    for (int i = 0; i < CAPACITY; ++i) {
        bigInteger[i] = 0;
    }
    for (int i = 0; ch[i] != '\0'; ++i) {
        count++;
    }
    for (int i = 0; ch[i] != '\0'; ++i) {
        bigInteger[i] = int(ch[count - i - 1] - '0');
    }
}

// initialize constructor for int
bigint::bigint(int num) {
    for (int i = 0; i < CAPACITY; ++i) {
        int digit = 0;
        digit = num % 10;
        num = num / 10;
        bigInteger[i] = digit;
    }
}

// friend method overload << for bigint
std::ostream& operator<<(std::ostream& OUT, const bigint& rhs) {
    int count = 0;
    bool found = false;
    int digits = 0;
    for (int i = CAPACITY - 1; i >= 0; --i) {
        if (rhs.bigInteger[i] != 0) {
            ++count;
            break;
        }
    }
        for (int i = CAPACITY - 1; i >= 0; --i) {
            if (rhs.bigInteger[i] == 0 && found == false)
                continue;
            else {
                found = true;
                if (digits % 80 != 0 || digits == 0)
                    OUT << rhs.bigInteger[i];
                else
                    OUT << std::endl << rhs.bigInteger[i];
                ++digits;
            }
        }
    return OUT;
}

// overload >> for bigint
std::istream& operator>>(std::istream& IN, bigint& rhs) {
    char result[CAPACITY];
    char ch;
    int i = 0;
    while (IN >> ch && ch != ';') {
       result[i] = ch;
       ++i;
    }
    result[i] = '\0';
    rhs = bigint(result);
    return IN;
}

// method overload == for bigint
bool bigint::operator==(const bigint& rhs) const {
    for (int i = 0; i < CAPACITY; ++i) {
        if (bigInteger[i] != rhs.bigInteger[i])
            return false;
    }
    return true;
}

// debugPrint method for bigint
void bigint::debugPrint(std::ostream& OUT) const {
    for (int i = CAPACITY - 1; i == 0; --i) {
        if (bigInteger[i] != 0)
            OUT << bigInteger[i] << " | ";
    }
}

// overload + for bigint
bigint bigint::operator+(const bigint& rhs) const {
    bigint result;
    for (int i = 0; i < CAPACITY; ++i) {
        int element = 0;
        int carry = 0;
        element = (bigInteger[i] + rhs.bigInteger[i]) % 10;
        result.bigInteger[i] += element;
        carry = (bigInteger[i] + rhs.bigInteger[i]) / 10;
        if (i + 1 < CAPACITY)
            result.bigInteger[i + 1] = carry;
    }
    return result;
}

// overload [] for bigint
int bigint::operator[](int index) const {
    return bigInteger[index];
}

// method for timesDigit
bigint bigint::timesDigit(int rhs) const{
    bigint result;
    for (int i = 0; i < CAPACITY; ++i){
        int element = 0;
        int carry = 0;
        element = (bigInteger[i] * rhs) % 10;
        result.bigInteger[i] += element;
        carry = (bigInteger[i] * rhs) / 10;
        if (i + 1 < CAPACITY)
            result.bigInteger[i + 1] = carry;
    }
    return result;
}

// method for times10
// REQUIRES: 0 <= rhs < CAPACITY
bigint bigint::times10(int rhs) const{
    bigint result;
    for (int i = CAPACITY - rhs - 1; i >= 0; --i){
        result.bigInteger[i + rhs] = bigInteger[i];
    }
    return result;
}

// overload operator * for bigint
bigint bigint::operator*(const bigint& rhs) const{
    bigint lhs;
    bigint temp;
    bigint result;
    for (int i = 0; i < CAPACITY; ++i){
        lhs.bigInteger[i] = bigInteger[i];
    }
    for (int i = 0; i < CAPACITY; ++i){
        temp = lhs.timesDigit(rhs.bigInteger[i]);
        result = (result + temp.times10(i));
    }
    return result;
}

