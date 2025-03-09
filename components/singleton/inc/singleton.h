#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <mutex>

typedef struct{
    const char* name;
    int cnt;
}singleton;

class hungry{
private:
hungry()=default;
~hungry()=delete;
static hungry* instance;
static singleton val;
public:
static hungry* get_instance();
void print_name();
void print_cnt();
};

class lazy{
private:
lazy()=default;
~lazy()=delete;
static std::mutex mutex;
static lazy* instance;
static singleton val;
public:
static lazy* get_instance();
void print_name();
void print_cnt();
};

#endif
