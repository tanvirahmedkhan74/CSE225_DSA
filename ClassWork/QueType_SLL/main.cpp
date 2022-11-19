#include <iostream>
#include "quetype.cpp"
#include <string>

int dec_to_bin(int n){
    int ans = 0;
    int mul = 1;

    for(int i=31;i>=0;i--){
        int k = n >> i;

        if(k&1){
            ans += (k * mul);
            mul *= 10;
        }else ans *= 10;
    }

    return ans;
}


int main()
{
    // Program tp print Binary Equivalent using Queue DSA
    std::string s1, s2;
    int n;

    std::cout << "Enter N: ";
    std::cin >> n;

    QueType<std::string> que = QueType<std::string>(n + 1);
    que.Enqueue("1");

    while(n--){
        que.Dequeue(s1);
        std::cout << s1 << "\n";

        s2 = s1;
        que.Enqueue(s2 + "0");
        que.Enqueue(s2 + "1");
    }

    return 0;
}
