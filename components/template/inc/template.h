#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

template <class T>
class TempClass{
private:
    T val;
public:
    TempClass(){};
    TempClass(T& v):val(v){};
    ~TempClass(){};
    T& get_val(){
        return val;
    }
};

template <class T1, class T2>
double add(T1 v1, T2 v2){
    return static_cast<double>(v1) + static_cast<double>(v2);
}

#endif
