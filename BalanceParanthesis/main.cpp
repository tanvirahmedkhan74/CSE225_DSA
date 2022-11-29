#include <iostream>
#include "stacktype.cpp"

/**
    Program for
        Checking balanced Parenthesis
            using Stack

    Code By: Tanvir Ahmed Khan
**/

bool is_opening(char c){                    // returns true if param is a opening parenthesis or false otherwise
    return (c == '(' || c =='{' || c == '[');
}

int main()
{
    int t;
    std::cout << "Number of test cases: ";
    std::cin >> t;

    while(t--){                                    // Taking Multiple Input from the user
        StackType<char> paran = StackType<char>();

        std::string line;
        std::cout << "Enter the Line:   ";

        std::cin >> line;

        bool unbalance = false;

        /**
                    This code works for ( { [ ] } )
                        all types of parenthesis

                        Algorithm:
                            if opening      :- Push into the stack
                            else if closing :- Match with the stack's top element
                                               If Empty Stack or stack's top opening does not match the current closing
                                               Mark as Unbalanced and break
                            else             :- Continue the loop until end of the input


        **/

        for(char c: line){
            if(is_opening(c)) paran.Push(c) ;      // Pushing opening parenthesis into the stack
            else{

                if(c == ')'){                                   // For the closing first bracket )
                    if(paran.IsEmpty() || paran.Top() != '('){
                        unbalance = true;
                        break;
                       }else paran.Pop();
                }else if(c == '}'){                             // For the second or curly closing bracket }
                    if(paran.IsEmpty() || paran.Top() != '{'){
                        unbalance = true;
                        break;
                    }else paran.Pop();
                }else if(c == ']'){                             // For the Third closing bracket ]
                    if(paran.IsEmpty() || paran.Top() != '['){
                        unbalance = true;
                        break;
                       }else paran.Pop();
                }
            }
        }

        if(unbalance || !paran.IsEmpty()) std::cout << "Not Balanced\n";
        else std::cout << "Balanced\n";

    }
    return 0;
}
