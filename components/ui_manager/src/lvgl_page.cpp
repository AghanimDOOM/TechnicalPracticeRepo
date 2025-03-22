#include <iostream>
#include <string>

#include "lvgl_ui.h"
#include "lvgl.h"

lvglPage::lvglPage(lvglPageType type, char* name):pageType(type)
{
    lvgl_mutex_lock();
    pageName = name;
    page = lv_obj_create(NULL);

    lv_obj_set_size(page, lv_disp_get_hor_res(lv_display_get_default()), lv_disp_get_ver_res(lv_display_get_default()));
    lv_obj_set_style_bg_color(page, lv_color_hex(0xffffff), 0);

    lv_obj_t* label = lv_label_create(page);
    lv_obj_set_style_text_font(label, lv_freetype_font_create("../resource/font/SourceHanSansSC-VF.ttf",\
        LV_FREETYPE_FONT_RENDER_MODE_BITMAP, 24, LV_FREETYPE_FONT_STYLE_NORMAL, 500), 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_text(label, name);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

    std::cout<<"lvgl page construct"<<std::endl;
    lvgl_mutex_unlock();
}

lvglPageType lvglPage::lvgl_get_page_type()
{
    return pageType;
}

lv_obj_t* lvglPage::lvgl_get_page()
{
    return page;
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
