#include "timeStamp.h"
#include <iostream>

timeStamp::timeStamp()
{
    hours = 0;
    minute = 0;
    second = 0;
}

timeStamp::timeStamp(int s, int m, int h)
{
    hours = h;
    minute = m;
    second = s;
}

bool timeStamp::operator<(timeStamp t)
{
    if(hours < t.hours)
    {
        return true;
    }
    else if(hours == t.hours)
    {
        if(minute < t.minute)
            return true;
        else if(minute == t.minute)
        {
            return (second < t.second);
        }
        else
            return false;
    }
    else
        return false;
}

bool timeStamp::operator>(timeStamp t)
{
    if(hours > t.hours)
    {
        return true;
    }
    else if(hours == t.hours)
    {
        if(minute > t.minute)
            return true;
        else if(minute == t.minute)
        {
            return (second > t.second);
        }
        else
            return false;
    }
    else
        return false;
}

bool timeStamp::operator!=(timeStamp t)
{
    return (hours != t.hours || minute != t.minute || second != t.second);
}

bool timeStamp::operator==(timeStamp t)
{
    return (hours == t.hours && minute == t.minute && second == t.second);
}

void timeStamp::print()
{
    if(second < 10)
        std::cout << 0;
    std::cout << second << " ";
    if(minute < 10)
        std::cout << 0;
    std::cout << minute << " ";
    if(hours < 10)
        std::cout << 0;
    std::cout << hours << "\n";
}
