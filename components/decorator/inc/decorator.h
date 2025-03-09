#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>

class component {
public:
    virtual ~component(){};
    virtual void display() = 0;
};

class text : public component{
public:
virtual ~text(){};
virtual void display(){std::cout<<"text"<<std::endl;};
};

class button : public component{
public:
virtual ~button(){};
virtual void display(){std::cout<<"button"<<std::endl;};
};

class decorator: public component {
protected:
    component* pcomp = nullptr;
public:
    virtual ~decorator(){};
    virtual void display() = 0;
};

class color: public decorator {
public:
    color(component* p){pcomp = p;};
    virtual ~color(){};
    virtual void display(){
        if(pcomp!=nullptr){
            pcomp->display();
        }
        std::cout<<"color"<<std::endl;
    };
};

class slider: public decorator {
public:
    slider(component* p){pcomp = p;};
    virtual ~slider(){};
    virtual void display(){
        if(pcomp!=nullptr){
            pcomp->display();
        }
        std::cout<<"slider"<<std::endl;
    };
};

#endif