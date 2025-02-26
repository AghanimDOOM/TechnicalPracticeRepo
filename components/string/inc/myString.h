#ifndef __MYSTRING_H__
#define __MYSTRING_H__

class myString{
public:
    myString();
    myString(myString& ref);
    myString(char* str);
    ~myString();

    myString& operator=(myString& ref);
    int len();
private:
    char* charArry;
};

#endif
