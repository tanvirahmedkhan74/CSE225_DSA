#include <iostream>
#include "sortedtype.cpp"
#include "timestamp.h"

int main()
{
    SortedType<timeStamp> arr = SortedType<timeStamp>();

    timeStamp t1 = timeStamp(15, 34, 23);
    timeStamp t2 = timeStamp(13, 13, 02);
    timeStamp t3 = timeStamp(43, 45, 12);
    timeStamp t4 = timeStamp(25, 36, 17);
    timeStamp t5 = timeStamp(52, 02, 20);

    arr.InsertItem(t1);
    arr.InsertItem(t2);
    arr.InsertItem(t3);
    arr.InsertItem(t4);
    arr.InsertItem(t5);

    arr.DeleteItem(t4);

    timeStamp temp = timeStamp();

    for(int i=0; i<arr.LengthIs(); i++)
    {
        arr.GetNextItem(temp);
        temp.print();
    }

    arr.ResetList();
    return 0;
}
