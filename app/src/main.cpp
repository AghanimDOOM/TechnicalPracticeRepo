#include <iostream>

#include "lvgl_ui.h"

int main()
{
    lvglManager& uiManager = lvglManager::lvgl_mng_get_instance();

    uiManager.ui_init();

    for(int32_t i = 0; i < 10; i++){
        char pageName[20] = {0};
        snprintf(pageName, 20, "page[%d]", i);
        lvglPage* newPage = new lvglPage(lvglPageLoadType::MainPage, pageName);
        uiManager.ui_page_add(newPage);
    }

    uiManager.lvgl_mng_scan_all_page();
    uiManager.ui_goto_page_with_stack("page[0]");
    uiManager.ui_goto_page_with_stack("page[1]");
    uiManager.ui_goto_page_with_stack("page[2]");
    uiManager.ui_goto_page_with_stack("page[3]");
    uiManager.ui_goto_page_with_stack("page[4]");
    uiManager.ui_goto_page_with_stack("page[5]");
    uiManager.ui_goto_page_with_stack("page[6]");

    uiManager.ui_goto_last_page();
    uiManager.ui_goto_last_page();
    uiManager.ui_goto_last_page();
    uiManager.ui_goto_last_page();
}

