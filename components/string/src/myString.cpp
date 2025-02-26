#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "myString.h"

myString::myString():charArry(nullptr)
{

}

myString::myString(myString& ref):charArry(nullptr)
{
    int refLen = ref.len();
    if(ref.charArry == nullptr || refLen == 0)
        return;

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, ref.charArry, refLen+1);

    return;
}

myString::myString(const char* str):charArry(nullptr)
{
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
    if(charArry == nullptr)
        return;

    delete charArry;
    charArry = nullptr;
    return;
}

myString& myString::operator=(myString& ref)
{
    int refLen;

    if(ref.charArry == nullptr)
        return *this;

    if(charArry != nullptr){
        delete charArry;
        charArry = nullptr;
    }

    refLen = strlen(ref.charArry);

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, ref.charArry, refLen+1);

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
        delete charArry;
        charArry = nullptr;
    }

    charArry = new char[refLen+1];
    memset(charArry, 0, refLen+1);
    strncpy(charArry, str, refLen+1);

    return *this;
}

std::ostream& operator<<(std::ostream& os, myString& owner)
{
    os << "Str len: " << owner.len() << ", cont is :" << owner.charArry;
    return os;
}

// std::istream& operator>>(std::istream& is, myString& owner)
// {
//     return is; // 返回流对象以支持链式调用
// }


int myString::len()
{
    if(charArry == nullptr)
        return 0;
    else
        return strlen(charArry);
}
