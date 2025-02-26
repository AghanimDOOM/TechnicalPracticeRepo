#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "myString.h"

int main()
{
    myString firstStr("1st string");
    myString secondStr(firstStr);
    myString thridStr, fourthStr, fifthStr;

    thridStr = "3rd string";

    fifthStr = fourthStr = thridStr;

    std::cout<<firstStr<<std::endl;
    std::cout<<secondStr<<std::endl;
    std::cout<<thridStr<<std::endl;
    std::cout<<fourthStr<<std::endl;
    std::cout<<fifthStr<<std::endl;
}
