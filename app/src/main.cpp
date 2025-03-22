#include <iostream>
#include <unistd.h>

#include "lvgl_ui.h"

int main()
{
    lvglManager& uiManager = lvglManager::lvgl_mng_get_instance();

    uiManager.ui_init();

    lvglPage* newPage = new lvglPage(lvglPageType::MainPage, "测试page");
    uiManager.ui_page_add(newPage);

    sleep(5);
    uiManager.ui_goto_page_with_stack("测试page");

    while(1){
        sleep(10);
    }
}

