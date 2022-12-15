#include <iostream>
#include "pqtype.cpp"

/**
You have N magical bags of candies in front of you. The
ith bag has Ai candies in it. It takes you one minute to
finish a bag of candies, no matter how many candies in
it. Every time you finish a bag with X candies in it, the
bag is magically replenished with X/2 (rounded down to
the nearest integer) more candies. Write a program
that determines the maximum number of candies you
can eat in K minutes.
The input is a sequence of integers. The first integer N
is the number of bags. The next integer K is the number
of minutes you have. The next N integers is the number
of candies in the bags. The output of your program is a
single integer which represents the maximum number
of candies you can eat.
**/

int main()
{

    std::cout << "Enter N & K: ";
    int n, k;
    std::cin >> n >> k;

    PQType<int> candy = PQType<int>(n);

    int temp;
    for(int i=0;i<n;i++){
        std::cin >> temp;
        candy.Enqueue(temp);
    }

    int total = 0;

    for(int i=0;i<k;i++){
        candy.Dequeue(temp);
        total += temp;

        candy.Enqueue(temp / 2);
    }

    std::cout << total << "\n";
    return 0;
}
