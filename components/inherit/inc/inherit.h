#ifndef __INHERIT_H__
#define __INHERIT_H__

class base{
protected:
    int val;
public:
    base(base& b);
    base(base&& b);
    base& operator=(base&& b);
    base(){val = 0;};
    void dis_val(){std::cout<<"val is "<<val<<std::endl;};
    void show();
    virtual void play();
};

class derive: public base{
public:
    derive(){val = 1;};
    void show();
    virtual void play();
};

class last: public derive{
public:
    last(){val = 2;};
    void show();
    virtual void play() final;
};

class errlast: public last{
public:
    errlast(){val = 3;};
    void show();
};

#endif
