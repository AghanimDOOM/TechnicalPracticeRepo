#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>

class myString{
public:
    myString();
    myString(myString& ref);
    myString(const char* str);
    ~myString();

    myString& operator=(myString& ref);
    myString& operator=(const char* str);

    int len();

    friend std::ostream& operator<<(std::ostream& os, myString& owner);
private:
    char* charArry;
};

#endif
