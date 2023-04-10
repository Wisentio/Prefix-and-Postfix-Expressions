#include <iostream>
#include "StackT.h"
#include "Forms.h"

int main()
{
    std::string s_infix = "";
    std::string s_postfix = "";
    std::string s_prefix = "";
    double rez;
    
    std::cout << "Scrieti forma infixata : ";
    std::cin >> s_infix;// a + b
    
    Inf2Post(s_infix,s_postfix);  //   ab+
    


    Post2Pre(s_postfix, s_prefix);   // +ab
    
    rez = prefix(s_prefix); //  rez = a + b
    
    std::cout << "Porma postfixata : " << s_postfix << '\n';
    std::cout << "Porma prefixata : " << s_prefix << '\n';
    std::cout << "Valoarea expresiei : " << rez << '\n';
    

    return 0;
}
