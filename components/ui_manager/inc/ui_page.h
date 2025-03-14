#ifndef __UI_PAGE_H__
#define __UI_PAGE_H__

#include <string>

class uiPage{
protected:
    std::string pageName;
public:
    virtual ~uiPage() = default;
    virtual std::string& get_page_name() = 0;
    virtual void page_load() = 0;
    virtual void page_unload() = 0;
    virtual void page_update() = 0;
};


#endif