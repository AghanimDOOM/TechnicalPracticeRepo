#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include <iostream>
#include "ui_page.h"

class uiManager{
public:
    virtual ~uiManager() = default;
    virtual void ui_init() = 0;
    virtual void ui_uninit() = 0;
    virtual void ui_page_add(uiPage* p) = 0;
    virtual void ui_page_del(uiPage* p) = 0;
    virtual void ui_page_del(char* pageName) = 0;
    virtual void ui_mng_stack_clear() = 0;
    virtual void ui_goto_page_with_stack(uiPage* p) = 0;
    virtual void ui_goto_page_with_stack(char* pageName) = 0;
    virtual void ui_goto_last_page() = 0;
};

#endif
