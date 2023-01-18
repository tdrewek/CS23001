//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        Fall 2022
// Author:      Theodore Drewek
//
// Description: Class implementation for a log entry.
//
// 

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector> 

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    std::vector<String> vec = s.split(' ');
    if (vec.size() != 10){
        host = "";
        request = "";
        status = "";
        number_of_bytes = 0;
    } else {
        host = vec[0];
        time.setTime(date.setDate(vec[3]));
        request = vec[5] + vec[6] + vec[7];
        status = vec[8];
        if (vec[9] == '-'){
            number_of_bytes = 0;
        } else {
            number_of_bytes = StringToInt(vec[9]);
        }
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    while (!in.eof()){
        char line[200];
        in.getline(line, 200);
        if (in.eof()) break;
        LogEntry log(line);
        result.push_back(log);
    }
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::ostream& operator<<(std::ostream& OUT, const LogEntry& log){
    OUT << log;
    return OUT;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (unsigned i = 0; i < logs.size(); ++i){
        out << logs[i] << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& host) {
    for (unsigned i = 0; i < host.size(); ++i){
        out << host[i].getHost() << std::endl;
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& log) {
    int count = 0;
    for (unsigned i = 0; i < log.size(); ++i){
        count += log[i].getBytes();
    }
    return count;
}

std::vector<String> Date::setDate(String given) {
    std::vector<String> date = given.split('/');
    date[0] = (date[0].split('['))[1];
    std::vector<String> timevector = date[2].split(':');
    day = date[0];
    month = date[1];
    year = StringToInt(timevector[0]);
    return timevector;
}

void Time::setTime(std::vector<String> given) {
    hour = StringToInt(given[1]);
    minute = StringToInt(given[2]);
    second = StringToInt(given[3]);
}

int StringToInt(String given) {
    int stringint = 0, i = 0;
    while (i < given.length()){
        stringint = stringint * 10 + (given[i] - '0');
        ++i;
    }
    return stringint;
}

void Date::printDate(std::ostream& out) const{
    out << day << " " << month << " " << year;
}

void Time::printTime(std::ostream& out) const{
    out << hour<< " " << minute<< " " << second;
}

void LogEntry::printLogEntry(std::ostream& out) const{
    out << host << " ";
    date.printDate(out);
    out << " ";
    time.printTime(out);
    out << " " << request << " " << status << " " << number_of_bytes;
}