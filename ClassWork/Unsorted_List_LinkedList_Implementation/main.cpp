#include <iostream>
#include "unsortedtype.cpp"

template <class T>
void print(UnsortedType<T> arr){
    int len = arr.LengthIs();
    T item;

    while(len > 0){
        arr.GetNextItem(item);
        std::cout << item << " ";
        len--;
    }

    arr.ResetList();
    std::cout << "\n";
}

int main()
{
    UnsortedType<int> list1, list2, mergedList;

    list1.InsertItem(1), list1.InsertItem(3), list1.InsertItem(5),
    list2.InsertItem(2), list2.InsertItem(4), list2.InsertItem(6), list2.InsertItem(7), list2.InsertItem(10);

    int l1 = list1.LengthIs(), l2 = list2.LengthIs();

    int item_l1, item_l2;

    list1.GetNextItem(item_l1);
    list2.GetNextItem(item_l2);

    l1--, l2--;
    while(l1 > 0 || l2 > 0){
        if(item_l1 > item_l2){
            mergedList.InsertItem(item_l1);
            l1--;

            list1.GetNextItem(item_l1);
        }else{
            mergedList.InsertItem(item_l2);
            l2--;

            list2.GetNextItem(item_l2);
        }
    }

    print(mergedList);

    return 0;
}
