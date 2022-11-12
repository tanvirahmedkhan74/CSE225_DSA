#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

class timeStamp
{
public:
    timeStamp();
    timeStamp(int, int, int);
    bool operator>(timeStamp);
    bool operator<(timeStamp);
    bool operator!=(timeStamp);
    bool operator==(timeStamp);
    void print();
private:
    int second, minute, hours;
};

#endif // TIMESTAMP_H_INCLUDED
