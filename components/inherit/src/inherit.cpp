#include <iostream>
#include "inherit.h"

base::base(base& b)
{
    if(&b == this)
        return;
    val = b.val;
    std::cout<<"func: base::base(base& b)"<<std::endl;
}

base::base(base&& b)
{
    if(&b == this)
        return;
    val = b.val;
    std::cout<<"func: base::base(base&& b)"<<std::endl;
}

base& base::operator=(base&& b)
{
    if(&b == this)
        return *this;
    val = b.val;
    std::cout<<"func: base& base::operator=(base&& b)"<<std::endl;
    return *this;
}

void base::show()
{
    std::cout<<"this is base class show!"<<std::endl;
}

void base::play()
{
    std::cout<<"this is base class play!"<<std::endl;
}

void derive::show()
{
    std::cout<<"this is derive class show!"<<std::endl;
}

void derive::play()
{
    std::cout<<"this is derive class play!"<<std::endl;
}

void last::show()
{
    std::cout<<"this is last class show!"<<std::endl;
}

void last::play()
{
    std::cout<<"this is last class play!"<<std::endl;
}

void errlast::show()
{
    std::cout<<"this is errlast class show!"<<std::endl;
}
