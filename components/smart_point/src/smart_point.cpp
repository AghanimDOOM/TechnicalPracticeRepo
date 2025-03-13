#include <memory>
#include <string>
#include "myString.h"


template<typename T>
void rref_mid_func(T&& p)
{
    T v = std::move(p);
    std::cout<<*v<<std::endl;
}

template<typename T>
void lref_mid_func(T& p)
{
    std::cout<<*p<<std::endl;
}

template<typename T>
void lval_mid_func(T p)
{
    std::cout<<*p<<std::endl;
}

template<typename T>
std::unique_ptr<T> unique_ptr_return()
{
    std::unique_ptr<T> myPoint(new T("这是第一个unique_ptr_return！"));
    return myPoint;
}

void unique_ptr_return_test()
{
    std::unique_ptr<myString> myPoint = unique_ptr_return<myString>();

    std::cout<<*myPoint<<std::endl;
}

void unique_ptr_test()
{
    std::unique_ptr<myString> myPoint(new myString("这是第一个unique point！"));

    std::cout<<*myPoint<<std::endl;

    std::cout<<"before rref_mid_func"<<std::endl;
    rref_mid_func<std::unique_ptr<myString>>(std::move(myPoint));
    std::cout<<"after rref_mid_func"<<std::endl;
}

void shared_ptr_test()
{
    std::shared_ptr<myString> myPoint(new myString("这是第一个unique point！"));

    std::cout<<*myPoint<<std::endl;

    std::cout<<"before lval_mid_func"<<std::endl;
    lval_mid_func<std::shared_ptr<myString>>(myPoint);
    std::cout<<"after lval_mid_func"<<std::endl;
}
