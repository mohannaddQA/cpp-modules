#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Address of string:    " << &string << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of string:      " << string << std::endl;
    std::cout << "Value from stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value from stringREF: " << stringREF << std::endl;

    return 0;
}
