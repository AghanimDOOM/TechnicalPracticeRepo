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
#include "decorator.h"
#include "iterator.h"
#include <utility>

void class_test()
{
    std::cout<<"类基本测试："<<std::endl;
    myString str1 = "这是第一个类";
    myString str2 = "这是第二个类";
    myString str3 = "这是第三个类";

    std::cout<<str1<<std::endl;
    std::cout<<str2<<std::endl;
    std::cout<<str3<<std::endl;

    std::cout<<"类拷贝构造&类拷贝赋值："<<std::endl;
    myString str4(str1);
    std::cout<<str4<<std::endl;
    str4 = str2;
    std::cout<<str4<<std::endl;

    myString str5 = std::move(str1);
    std::cout<<str1<<std::endl;
    std::cout<<str2<<std::endl;
    std::cout<<str3<<std::endl;
    std::cout<<str4<<std::endl;
    std::cout<<str5<<std::endl;

    str5 = std::move(str2);
    std::cout<<str1<<std::endl;
    std::cout<<str2<<std::endl;
    std::cout<<str3<<std::endl;
    std::cout<<str4<<std::endl;
    std::cout<<str5<<std::endl;
}

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

    std::cout<<"new lazy singleton:"<<std::endl;
    newlazy* pnl = newlazy::get_instance();

    pnl->print_name();
    pnl->print_cnt();
    pnl->print_name();
    pnl->print_cnt();
    pnl->print_name();
    pnl->print_cnt();
}

void decorator_test()
{
    component* myText = new text();
    component* myButton = new button();
    component* mySlider = new slider(myText);
    component* myColor = new color(mySlider);

    myColor->display();

    delete myText;
    delete myButton;
    delete mySlider;
    delete myColor;
}

void iterator_test()
{
    std::string v1 = "第一个字符串！";
    std::string v2 = "第二个字符串！";
    std::string v3 = "第三个字符串！";

    std::cout<<"container test:"<<std::endl;
    container<std::string> myContainer;
    myContainer.print_container();

    myContainer.add(v1);
    myContainer.add(v2);
    myContainer.add(v3);
    myContainer.print_container();

    myContainer.remove();
    myContainer.print_container();

    myContainer.clear();
    myContainer.print_container();

    std::cout<<"iterator test:"<<std::endl;
    myContainer.add(v1);
    myContainer.add(v2);
    myContainer.add(v3);
    myContainer.print_container();

    if(myContainer.begin() != myContainer.end()){
        for(auto i = myContainer.begin(); i != myContainer.end(); i++){
            *i = "添加prefix: " + *i;
            std::cout<<*i<<std::endl;
        }
    }

    myContainer.clear();
    myContainer.print_container();
}

int main()
{
    class_test();
}
