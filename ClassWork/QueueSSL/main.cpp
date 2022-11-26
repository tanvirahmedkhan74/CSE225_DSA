#include <iostream>
#include "quetype.cpp"
/**
Given a set of coin values and an amount of money,
determine the minimum number of coins to make the given
amount of money. The input starts with an integer n,
specifying the number of coin types. Next n integers are the
coin values. The final integer is the amount of money you
have to make. You can assume that the amount will always
be possible to make using the given coin types.
**/

int main()
{
    QueType<int> coin = QueType<int>();
    QueType<int> counts = QueType<int>();

    int n, money;
    std::cout << "Enter the number of coins: ";

    std::cin >> n;
    int *arr = new int[n];

    std::cout << "Enter the Coins: ";

    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        coin.Enqueue(arr[i]);
        counts.Enqueue(1);
    }

    std::cout << "Enter the money amount: ";

    std::cin >> money;

    int c, cnt, res;

    while(true){
        coin.Dequeue(c);
        counts.Dequeue(cnt);

        if(c == money){
            res = cnt;
            break;
        }

        cnt += 1;
        for(int i=0;i<n;i++){
            coin.Enqueue(c + arr[i]);
            counts.Enqueue(cnt);
        }

    }

    std::cout << res << "\n";

    return 0;
}
