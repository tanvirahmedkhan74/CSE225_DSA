#include <bits/stdc++.h>
#include<string>

#include "stacktype.cpp"

bool is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool is_numerator(char c, int & num){
    int temp = c - '0';

    if(c >= 0  && c <= 10){
        return true;
    }else return false;
}

bool is_alpha(char c){
    return (c >= 'A' && c <= 'Z');
}

int main()
{
    std::string postFix = "";

    StackType<char> operators = StackType<char>();

    std::string line;
    std::getline(std::cin, line);

    int temp;

    for(char c: line){
        if(is_alpha(c)){
            postFix += c;
        }else if(is_operator(c)){
            if(operators.IsEmpty()){
                operators.Push(c);
            }else{
                if(c == '+' || c == '-'){
                    if(operators.Top() == '+' || operators.Top() == '-'){
                        postFix += operators.Top();
                        operators.Pop();

                        operators.Push(c);
                    }else operators.Push(c);
                }else{
                    if(operators.Top() == '*' || operators.Top() == '/'){
                        postFix += operators.Top();
                        operators.Pop();

                        operators.Push(c);
                    }else operators.Push(c);
                }
            }
        }
    }

    if(!operators.IsEmpty()){
        while(!operators.IsEmpty()){
            postFix += operators.Top();
            operators.Pop();
        }
    }

    std::cout << postFix << "\n";

}
