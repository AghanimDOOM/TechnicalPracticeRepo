#include <iostream>
#include <unistd.h>

#include "lvgl_ui.h"

int main()
{
    lvglManager& uiManager = lvglManager::lvgl_mng_get_instance();

    uiManager.ui_init();

    lvglPage* newPage = new lvglPage(lvglPageType::MainPage, "测试page");
    uiManager.ui_page_add(newPage);

    uiManager.ui_goto_page_with_stack("测试page");

    sleep(5);
    lvgl_mutex_lock();
    lv_obj_t * cont_row = lv_obj_create(lv_scr_act());
    lv_obj_set_style_bg_color(cont_row, lv_color_hex(0xffff), 0);
    lv_obj_set_size(cont_row, 300, 75);
    lv_obj_align(cont_row, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_set_flex_flow(cont_row, LV_FLEX_FLOW_ROW);

    for(int32_t i = 0; i < 2; i++) {
        lv_obj_t * obj;
        lv_obj_t * label;

        /*Add items to the row*/
        obj = lv_button_create(cont_row);
        lv_obj_set_size(obj, 100, LV_PCT(100));

        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "Item: %d"LV_PRIu32"", i);
        lv_obj_center(label);
    }
    lvgl_mutex_unlock();

    sleep(5);
    lvgl_mutex_lock();
    for(int32_t i = 2; i < 4; i++) {
        lv_obj_t * obj;
        lv_obj_t * label;

        /*Add items to the row*/
        obj = lv_button_create(cont_row);
        lv_obj_set_size(obj, 100, LV_PCT(100));

        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "Item: %d"LV_PRIu32"", i);
        lv_obj_center(label);
    }
    lvgl_mutex_unlock();

    while(1){
        sleep(10);
    }
}

