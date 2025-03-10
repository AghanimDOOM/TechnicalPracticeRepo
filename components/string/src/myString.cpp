#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "myString.h"

myString::myString():charArry(nullptr)
{
    std::cout<<"construction func"<<std::endl;
}

myString::myString(myString& ref):charArry(nullptr)
{
    std::cout<<"cpy construction func"<<std::endl;
    int refLen = ref.len();
    if(ref.charArry == nullptr || refLen == 0)
        return;

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, ref.charArry, refLen+1);

    return;
}

myString::myString(myString&& ref):charArry(nullptr)
{
    std::cout<<"move construction func"<<std::endl;
    int refLen = ref.len();
    if(ref.charArry == nullptr)
        return;

    charArry = ref.charArry;
    ref.charArry = nullptr;
    return;
}

myString::myString(const char* str):charArry(nullptr)
{
    std::cout<<"char construction func"<<std::endl;
    int refLen;
    if(str == nullptr)
        return;

    refLen = strlen(str);
    if(refLen == 0)
        return;

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, str, refLen+1);

    return;
}

myString::~myString()
{
    std::cout<<"destory func"<<std::endl;
    if(charArry == nullptr)
        return;

    delete[] charArry;
    charArry = nullptr;
    return;
}

myString& myString::operator=(myString& ref)
{
    std::cout<<"cpy assign func"<<std::endl;
    int refLen;

    if(ref.charArry == nullptr || &ref == this)
        return *this;

    if(charArry != nullptr){
        delete[] charArry;
        charArry = nullptr;
    }

    refLen = strlen(ref.charArry);

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, ref.charArry, refLen+1);

    return *this;
}

myString& myString::operator=(myString&& ref)
{
    std::cout<<"move assign func"<<std::endl;
    int refLen;

    if(ref.charArry == nullptr || &ref == this)
        return *this;

    if(charArry != nullptr){
        delete[] charArry;
        charArry = nullptr;
    }

    charArry = ref.charArry;
    ref.charArry = nullptr;

    return *this;
}

myString& myString::operator=(const char* str)
{
    int refLen;

    if(str == nullptr)
        return *this;

    refLen = strlen(str);

    if(refLen == 0)
        return *this;

    if(charArry != nullptr){
        delete[] charArry;
        charArry = nullptr;
    }

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, str, refLen+1);

    return *this;
}

std::ostream& operator<<(std::ostream& os, myString& owner)
{
    if(owner.charArry != nullptr)
        os << "Str len: " << owner.len() << ", cont is : " << owner.charArry;
    else
        os << "Str len: " << owner.len() << ", cont is : nullptr";
    return os;
}

int myString::len()
{
    if(charArry == nullptr)
        return 0;
    else
        return strlen(charArry);
}
