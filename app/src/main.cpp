#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    int val;
    std::string mystr("1234");
    std::stringstream(mystr)>>val;

    std::cout<<val<<std::endl;
}
