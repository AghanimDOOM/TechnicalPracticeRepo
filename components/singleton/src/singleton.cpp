#include "singleton.h"
#include <mutex>
#include <iostream>

hungry* hungry::instance = new hungry();
singleton hungry::val = {.name = "hungry", .cnt = 0};

hungry* hungry::get_instance()
{
    return instance;
}

void hungry::print_name()
{
    std::cout<<"singleton name is "<<val.name<<std::endl;
    val.cnt++;
}

void hungry::print_cnt()
{
    std::cout<<"singleton cnt is "<<val.cnt<<std::endl;
}

lazy* lazy::instance = nullptr;
singleton lazy::val;
std::mutex lazy::mutex;

lazy* lazy::get_instance()
{
    if(instance == nullptr){
        std::lock_guard<std::mutex> lock(mutex);
        val.name = "lazy";
        val.cnt = 0;
        if(instance == nullptr){
            instance = new lazy();
        }
    }
    return instance;
}

void lazy::print_name()
{
    std::cout<<"singleton name is "<<val.name<<std::endl;
    val.cnt++;
}

void lazy::print_cnt()
{
    std::cout<<"singleton cnt is "<<val.cnt<<std::endl;
}

singleton newlazy::val;

newlazy::newlazy()
{
    val.name = "newlazy";
    val.cnt = 0;
}

newlazy* newlazy::get_instance()
{
    static newlazy* instance = new newlazy();
    return instance;
}

void newlazy::print_name()
{
    std::cout<<"singleton name is "<<val.name<<std::endl;
    val.cnt++;
}

void newlazy::print_cnt()
{
    std::cout<<"singleton cnt is "<<val.cnt<<std::endl;
}