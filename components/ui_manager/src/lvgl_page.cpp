#include <iostream>
#include <string>

#include "lvgl_ui.h"
#include "lvgl.h"

lvglPage::lvglPage(lvglPageLoadType type, char* name):pageType(type)
{
    pageName = name;
    lv_obj_t* screen = lv_obj_create(NULL);

    std::cout<<"lvgl page construct"<<std::endl;
}

lvglPageLoadType lvglPage::lvgl_get_page_type()
{
    return pageType;
}

std::string& lvglPage::get_page_name()
{
    return pageName;
}

lvglPage::~lvglPage()
{
    std::cout<<"lvgl page destory"<<std::endl;
}

void lvglPage::page_load()
{
    std::cout<<"lvgl page load"<<std::endl;
}

void lvglPage::page_unload()
{
    std::cout<<"lvgl page unload"<<std::endl;
}

void lvglPage::page_update()
{
    std::cout<<"lvgl page update"<<std::endl;
}

bool lvglPage::operator==(lvglPage& other)
{
    if(this == &other || this->pageName == other.pageName)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, lvglPage& page)
{
    os<<page.pageName;

    return os;
}
