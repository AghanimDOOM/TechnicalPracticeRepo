#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

std::mutex printMutex;

void thread_print(int32_t delaySec)
{
    int32_t cnt = 10;

    while(cnt>0){
        printMutex.lock();
        std::cout<<"delay time is: "<<delaySec<<std::endl;
        printMutex.unlock();
        sleep(delaySec);
        cnt--;
    }
}

void thread_mutex_test()
{
    std::thread t1(thread_print, 1);
    std::thread t2(thread_print, 4);

    t1.join();
    t2.join();
}
