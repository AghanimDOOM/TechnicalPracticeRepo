#ifndef __LVGL_UI_H__
#define __LVGL_UI_H__

#include <list>
#include <mutex>
#include <memory>
#include <iostream>
#include <string>
#include <pthread.h>

#include "ui_page.h"
#include "ui_manager.h"

enum class lvglPageLoadType{
    MainPage,
    subPage,
};

class lvglPage : public uiPage{
private:
    lvglPageLoadType pageType;
public:
    lvglPage(lvglPageLoadType type, char* name);
    lvglPageLoadType lvgl_get_page_type();
    virtual ~lvglPage();
    virtual std::string& get_page_name();
    virtual void page_load();
    virtual void page_unload();
    virtual void page_update();

    bool operator==(lvglPage& other);
    friend std::ostream& operator<<(std::ostream& cout, lvglPage& page);
};

class lvglManager : public uiManager{
private:
    static std::recursive_mutex lvglMngMutex;
    static pthread_t tid;
    static bool initFlg;
    static std::list<uiPage*> pageList;
    static std::list<uiPage*> pageStack;
    lvglManager() = default;
    ~lvglManager();
public:
    lvglManager(lvglManager&) = delete;
    lvglManager(lvglManager&&) = delete;
    lvglManager& operator=(lvglManager&) = delete;
    lvglManager operator=(lvglManager&&) = delete;
    static lvglManager& lvgl_mng_get_instance();
    static void lvgl_mng_scan_all_page();
    static void lvgl_mng_scan_stack();
    virtual void ui_init();
    virtual void ui_uninit();
    virtual void ui_page_add(uiPage* p);
    virtual void ui_page_del(uiPage* p);
    virtual void ui_page_del(char* pageName);
    virtual void ui_mng_stack_clear();
    virtual void ui_goto_page_with_stack(uiPage* p);
    virtual void ui_goto_page_with_stack(char* pageName);
    virtual void ui_goto_last_page();
};

#ifdef __cplusplus
extern "C"{
#endif
void lv_linux_disp_init(void);
#ifdef __cplusplus
}
#endif

#endif
