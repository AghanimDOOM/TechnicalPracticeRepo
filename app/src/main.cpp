#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "template.h"
#include "myString.h"

int main()
{
    myString first("hello world");
    std::cout<<add(1, 3.16)<<std::endl;
    TempClass<myString> test(first);
    std::cout<<test.get_val()<<std::endl;
}
