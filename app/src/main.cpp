#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "template.h"
#include "myString.h"
#include "inherit.h"
#include "singleton.h"

void static_cast_test(char c)
{
    int a;
    double b = 3.14;

    a = static_cast<int>(b);
    a = static_cast<int>(c);
}

void inherit_test()
{
    std::cout<<"基本展示："<<std::endl;
    base myBase;
    derive myDerive;
    last myLast;
    errlast myErrlast;

    myBase.dis_val();
    myBase.show();
    myBase.play();

    myDerive.dis_val();
    myDerive.show();
    myDerive.base::show();
    myDerive.play();

    myLast.dis_val();
    myLast.show();
    myLast.derive::base::show();
    myLast.derive::show();
    myLast.play();

    myErrlast.dis_val();
    myErrlast.show();
    myErrlast.derive::base::show();
    myErrlast.derive::show();
    myErrlast.play();

    std::cout<<"static_cast 对象向基类转换展示："<<std::endl;
    base castBase = static_cast<base>(myDerive);
    castBase.dis_val();
    castBase.show();
    castBase.play();

    castBase = static_cast<base>(myLast);
    castBase.dis_val();
    castBase.show();
    castBase.play();

    castBase = static_cast<base>(myErrlast);
    castBase.dis_val();
    castBase.show();
    castBase.play();

    std::cout<<"static_cast 对象向派生类转换不可行"<<std::endl;
    std::cout<<"static_cast 对象指针向基类转换展示：(不需要展示，这是cpp多态的基础能力)"<<std::endl;
    std::cout<<"static_cast 对象指针向派生类转换展示："<<std::endl;
    base* pbase;
    derive* pderive;

    pbase = &myDerive;
    pbase->dis_val();
    pbase->show();
    pbase->play();

    pderive = static_cast<derive*>(pbase);
    pderive->dis_val();
    pderive->show();
    pderive->base::show();
    pderive->play();

    std::cout<<"dynamic_cast 对象指针向派生类转换展示："<<std::endl;
    base* pdynamicBase;
    derive* pdynamicDerive;

    pdynamicBase = &myDerive;
    pdynamicBase->dis_val();
    pdynamicBase->show();
    pdynamicBase->play();

    pdynamicDerive = dynamic_cast<derive*>(pdynamicBase);
    pdynamicDerive->dis_val();
    pdynamicDerive->show();
    pdynamicDerive->base::show();
    pdynamicDerive->play();

    std::cout<<"typeid 展示："<<std::endl;
    if(typeid(pdynamicBase) == typeid(derive*))
        std::cout<<"type equ"<<std::endl;
    else
        std::cout<<"type not equ"<<std::endl;

    if(typeid(*pdynamicBase) == typeid(derive))
        std::cout<<"type equ"<<std::endl;
    else
        std::cout<<"type not equ"<<std::endl;

    std::cout<<"typeid(pdynamicBase) name is "<<typeid(pdynamicBase).name()<<std::endl;
    std::cout<<"typeid(*pdynamicBase) name is "<<typeid(*pdynamicBase).name()<<std::endl;
    std::cout<<"typeid(derive*) name is "<<typeid(derive*).name()<<std::endl;
    std::cout<<"typeid(derive) name is "<<typeid(derive).name()<<std::endl;
}

void singleton_test()
{
    std::cout<<"hungry singleton:"<<std::endl;
    hungry* ph = hungry::get_instance();

    ph->print_name();
    ph->print_cnt();
    ph->print_name();
    ph->print_cnt();
    ph->print_name();
    ph->print_cnt();

    std::cout<<"lazy singleton:"<<std::endl;
    lazy* pl = lazy::get_instance();

    pl->print_name();
    pl->print_cnt();
    pl->print_name();
    pl->print_cnt();
    pl->print_name();
    pl->print_cnt();
}

int main()
{
    singleton_test();
}
