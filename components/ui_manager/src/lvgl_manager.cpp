#include <iostream>
#include <algorithm>
#include <string>

#include "lvgl_ui.h"
#include "lvgl.h"

std::recursive_mutex lvglManager::lvglMutex;
bool lvglManager::initFlg;
std::list<uiPage*> lvglManager::pageList;
std::list<uiPage*> lvglManager::pageStack;

lvglManager& lvglManager::lvgl_mng_get_instance()
{
    static lvglManager instance;
    return instance;
}

void lvglManager::ui_init()
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    initFlg = true;
    std::cout<<"lvglManager init"<<std::endl;
}

void lvglManager::ui_uninit()
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    initFlg = false;
    std::cout<<"lvglManager uninit"<<std::endl;
}

void lvglManager::lvgl_mng_scan_all_page()
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager scan page: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager scan page"<<std::endl;
    for(auto item : pageList){
        std::cout<<item->get_page_name()<<std::endl;
    }
}

void lvglManager::lvgl_mng_scan_stack()
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager scan stack: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager scan stack"<<std::endl;
    for(auto item : pageStack){
        std::cout<<item->get_page_name()<<std::endl;
    }
}

void lvglManager::ui_page_add(uiPage* p)
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager page add: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager page add"<<std::endl;
    pageList.push_back(p);
    return;
}

void lvglManager::ui_page_del(uiPage* p)
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager page del: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager page del"<<std::endl;
    pageList.remove_if([p](uiPage* item)->bool{return p == item;});
}

void lvglManager::ui_page_del(char* pageName)
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager page del: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager page del"<<std::endl;
    std::string pageNameStr(pageName);
    for(auto i = pageList.begin(); i != pageList.end(); ++i){
        if(pageNameStr == (*i)->get_page_name()){
            delete *i;
            pageList.remove_if([i](uiPage* item)->bool{return item == *i;});
            break;
        }
    }
}

void lvglManager::ui_mng_stack_clear()
{
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager stack clear: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager stack clear"<<std::endl;
    pageStack.clear();
}

void lvglManager::ui_goto_page_with_stack(uiPage* p)
{
    lvglPage* currentPage;
    lvglPage* newPage;
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager goto with stack: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager goto with stack"<<std::endl;
    if(!pageStack.empty()){
        currentPage = dynamic_cast<lvglPage*>(*pageStack.rbegin());
        std::cout<<"current page name is : "<<*(currentPage)<<std::endl;
        currentPage->page_unload();
    }
    newPage = dynamic_cast<lvglPage*>(p);
    std::cout<<"new page name is : "<<*(newPage)<<std::endl;
    newPage->page_load();
    pageStack.push_back(p);
}

void lvglManager::ui_goto_page_with_stack(char* pageName)
{
    lvglPage* currentPage;
    lvglPage* newPage;
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager goto with stack: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager goto with stack"<<std::endl;
    if(!pageStack.empty()){
        currentPage = dynamic_cast<lvglPage*>(*pageStack.rbegin());
        std::cout<<"current page name is : "<<*(currentPage)<<std::endl;
        currentPage->page_unload();
    }
    std::string pageNameStr(pageName);
    for(auto i = pageList.begin(); i != pageList.end(); ++i){
        if(pageNameStr == (*i)->get_page_name()){
            newPage = dynamic_cast<lvglPage*>(*i);
            std::cout<<"new page name is : "<<*(newPage)<<std::endl;
            newPage->page_load();
            pageStack.push_back(newPage);
        }
    }
}

void lvglManager::ui_goto_last_page()
{
    lvglPage* currentPage;
    lvglPage* lastPage;
    std::lock_guard<std::recursive_mutex> lock(lvglMutex);
    if(!initFlg){
        std::cout<<"lvglManager goto last: lvgl need init"<<std::endl;
        return;
    }
    std::cout<<"lvglManager goto last"<<std::endl;
    if(pageStack.size() <= 1){
        return;
    }else {
        currentPage = dynamic_cast<lvglPage*>(*pageStack.rbegin());
        std::cout<<"current page name is : "<<*(currentPage)<<std::endl;
        currentPage->page_unload();
        pageStack.pop_back();
        lastPage = dynamic_cast<lvglPage*>(*pageStack.rbegin());
        std::cout<<"last page name is : "<<*(lastPage)<<std::endl;
        lastPage->page_load();
    }
}