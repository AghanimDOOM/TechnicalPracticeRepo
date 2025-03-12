#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <iostream>

template<typename T> class iterator;

template<typename T>
struct var{
    T val;
    var* next;
    var* pre;
};

template<class T>
class container{
private:
    var<T>* pfirst;
    var<T>* plast;
public:
    container():pfirst(nullptr),plast(nullptr){}
    void add(T& v){
        var<T>* n = new var<T>();
        n->val = v;
        if(pfirst == nullptr) {
            pfirst = n;
            pfirst->next = nullptr;
            pfirst->pre = nullptr;
            plast = pfirst;
        }else{
            plast->next = n;
            n->pre = plast;
            n->next = nullptr;
            plast = n;
        }
    };
    void remove(){
        if(pfirst == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        if(pfirst == plast){
            delete plast;
            pfirst = plast = nullptr;
        } else {
            var<T>* t = plast->pre;
            t->next = nullptr;
            delete plast;
            plast = t;
        }
    };
    void clear(){
        if(pfirst == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        var<T>* tmp = pfirst;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            delete tmp->pre;
            tmp->pre = nullptr;
        };
        delete tmp;
        pfirst = plast = nullptr;
    };
    void print_container(){
        if(pfirst == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        var<T>* tmp = pfirst;
        do{
            std::cout<<"container var is "<<tmp->val<<std::endl;
        }while((tmp = tmp->next) != nullptr);
    };
    bool empty(){if(pfirst == nullptr)return true; else return false;};
    iterator<T> begin(){
        return iterator<T>(this, pfirst);
    };
    iterator<T> end(){
        return iterator<T>(this, nullptr);
    };
};

template<typename T> 
class iterator{
private:
    container<T>* c;
    var<T>* p;
public:
    iterator(container<T>* c=nullptr, var<T>* p=nullptr):p(p),c(c){
        std::cout<<"iterator(container<T>* c=nullptr, var<T>* p=nullptr)"<<std::endl;
    };
    iterator(iterator& other):c(other.c),p(other.p){
        std::cout<<"iterator(iterator& other)"<<std::endl;
    };
    iterator(iterator&& other):c(other.c),p(other.p){
        std::cout<<"iterator(iterator&& other)"<<std::endl;
    };
    iterator& operator=(iterator& other){
        std::cout<<"iterator& operator=(iterator& other)"<<std::endl;
        if(&other == this || other.c != this->c)
            return *this;
        this->p = other.p;
        return *this;
    };
    iterator& operator=(iterator&& other){
        std::cout<<"iterator& operator=(iterator&& other)"<<std::endl;
        return this->operator=(other);
    };
    iterator& operator++(){
        std::cout<<"iterator& operator++()"<<std::endl;
        if(this->p != nullptr)
            this->p = this->p->next;
        return *this;
    };
    iterator operator++(int){                               // 返回临时对象的原因是，保证先返回值后++；
        std::cout<<"iterator operator++(int)"<<std::endl;   // 返回临时对象而非右值引用有两个原因：
        iterator<T> t = *this;                              // 1、临时对象可以让右值引用承接，保证连续赋值的情况可用；
        if(this->p != nullptr)                              // 2、临时对象会消失，使用右值引用会出现问题；
            this->p = this->p->next;
        return t;
    };
    T& operator*(){
        std::cout<<"T operator*()"<<std::endl;
        return p->val;
    };
    T* operator->(){
        std::cout<<"T* operator->()"<<std::endl;
        return &(p->val);
    };
    bool operator==(iterator& other){
        std::cout<<"bool operator==(iterator& other)"<<std::endl;
        if(this == &other) return true;
        if(this->c == other.c && this->p == other.p){
            return true;
        }
        return false;
    };
    bool operator!=(iterator& other){
        std::cout<<"bool operator!=(iterator& other)"<<std::endl;
        return !(this->operator==(other));
    };
    bool operator==(iterator&& other){
        std::cout<<"bool operator==(iterator&& other)"<<std::endl;
        return this->operator==(other);                             // 右值引用的本质是左值
    };
    bool operator!=(iterator&& other){
        std::cout<<"bool operator!=(iterator&& other)"<<std::endl;
        return !(this->operator==(other));                          // 右值引用的本质是左值
    };
};

#endif
