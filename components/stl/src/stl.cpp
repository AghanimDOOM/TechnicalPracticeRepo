#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

void vector_test()
{
    // 初始化、push_back、insert、默认sort、sort with lambda cmp func、sort with cmp class、find、binary_search、lower_bound、upper_bound、countif、countif with func adapter；

    // 初始化
    std::vector<int> myVector = {-9, 10, 60, 67, 34, 98, 18};
    for(auto val : myVector){
        std::cout<<"init: "<<val<<std::endl;
    }

    // push_back
    for(int32_t i = 0; i < 10; i++){
        myVector.push_back(rand()&0xff);
    }
    for(auto val : myVector){
        std::cout<<"push_back: "<<val<<std::endl;
    }

    // insert
    myVector.insert(myVector.begin() + 5, 123);
    for(auto val : myVector){
        std::cout<<"insert: "<<val<<std::endl;
    }

    // sort with lambda
    std::sort(myVector.begin(), myVector.end(), [](const int &a, const int &b) -> bool {return a < b;});
    for(auto val : myVector){
        std::cout<<"sort with lambda cmp func: "<<val<<std::endl;
    }

    // clear & init
    std::cout<<"----- myVect Clear & reinit -----"<<std::endl;
    myVector.clear();
    for(int32_t i = 0; i < 10; i++){
        myVector.push_back(rand()&0xff);
    }
    for(auto val : myVector){
        std::cout<<"clear & init: "<<val<<std::endl;
    }

    // sort with cmp class
    std::sort(myVector.begin(), myVector.end(), std::less<int>());
    for(auto val : myVector){
        std::cout<<"sort with cmp class std::less<int>(): "<<val<<std::endl;
    }

    // find
    {
        auto findIterator = std::find(myVector.begin(), myVector.end(), 123);
        if(findIterator != myVector.end()){
            std::cout<<"123 found"<<std::endl;
        } else {
            std::cout<<"123 not found"<<std::endl;
        }
    }
    

    // auto myIterator = std::find(myVector.begin(), myVector.end(), 108);
    // if(myIterator != myVector.end()){
    //     std::cout<<"found: "<<*myIterator<<std::endl;
    // } else {
    //     std::cout<<"not found"<<std::endl;
    // }
}