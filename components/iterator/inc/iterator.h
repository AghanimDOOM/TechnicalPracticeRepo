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
    var<T>* p;
public:
    container():p(nullptr){}
    void add(T& v){
        var<T>* n = new var<T>();
        n->val = v;
        if(p == nullptr) {
            p = n;
            p->next = nullptr;
            p->pre = nullptr;
        }else{
            var<T>* tmp = p;
            while(tmp->next != nullptr){tmp = tmp->next;};
            tmp->next = n;
            n->pre = tmp;
            n->next = nullptr;
        }
    };
    void remove(){
        if(p == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        var<T>* tmp = p;
        while(tmp->next != nullptr){tmp = tmp->next;};
        (tmp->pre)->next = nullptr;
        delete tmp;
    };
    void clear(){
        if(p == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        var<T>* tmp = p;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            delete tmp->pre;
            tmp->pre = nullptr;
            p = tmp;
        };
        delete tmp;
        p = nullptr;
    };
    void print_container(){
        if(p == nullptr){
            std::cout<<"empty container"<<std::endl;
            return;
        }
        var<T>* tmp = p;
        std::cout<<"container var is "<<tmp->val<<std::endl;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            std::cout<<"container var is "<<tmp->val<<std::endl;
        };
    };
    bool empty(){if(p == nullptr)return true; else return false;};
    iterator<T> begin(){
        return iterator<T>(this, p);
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
