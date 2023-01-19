#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        Fall 2022
// Author:
//
// Description: Class definition for a log entry.
//
// 
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
            String getDay() const {return day;};
            String getMonth() const {return month;};
            int getYear() const {return year;};
            void printDate(std::ostream&) const;
            std::vector<String> setDate(String);
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
            int getHour() const {return hour;};
            int getMinute() const {return minute;};
            int getSecond() const {return second;};
            void printTime(std::ostream&) const;
            void setTime(std::vector<String>);
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
    LogEntry() {};
    LogEntry(String);
    String getHost() const {return host;};
    Date getDate() const {return date;};
    Time getTime() const {return time;};
    String getRequest() const {return request;};
    String getStatus() const {return status;};
    int getBytes() const {return number_of_bytes;};
    void printLogEntry(std::ostream&) const;
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
int StringToInt(String);

#endif
 
