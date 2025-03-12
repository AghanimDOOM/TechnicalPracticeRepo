#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

void vector_test()
{
    // 初始化、push_back、insert、默认sort、sort with lambda cmp func、sort with cmp class、find、binary_search、lower_bound、upper_bound、replace、replace_if、countif、countif with func adapter；

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
            std::cout<<"find: 123 found"<<std::endl;
        } else {
            std::cout<<"find: 123 not found"<<std::endl;
        }
    }
    
    // binary_search
    {
        if(std::binary_search(myVector.begin(), myVector.end(), 123)){
            std::cout<<"binary_search: 123 found"<<std::endl;
        } else {
            std::cout<<"binary_search: 123 not found"<<std::endl;
        }
    }

    // lower_bound
    {
        int findVal = 123;
        auto findIterator = std::lower_bound(myVector.begin(), myVector.end(), findVal);
        if(findIterator != myVector.end()){
            std::cout<<"lower_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"lower_bound: "<<findVal<<" end"<<std::endl;
        }
    }

    // upper_bound
    {
        int findVal = 124;
        auto findIterator = std::upper_bound(myVector.begin(), myVector.end(), findVal);
        if(findIterator != myVector.end()){
            std::cout<<"upper_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"upper_bound: "<<findVal<<" end"<<std::endl;
        }
    }

    // replace
    {
        int oldVal = 124;
        int newVal = 127;
        for(auto val : myVector){
            std::cout<<"before replace: "<<val<<std::endl;
        }
        std::replace(myVector.begin(), myVector.end(), oldVal, newVal);
        for(auto val : myVector){
            std::cout<<"after replace: "<<val<<std::endl;
        }
    }

    // replace_if
    {
        for(auto val : myVector){
            std::cout<<"before replace_if: "<<val<<std::endl;
        }
        std::replace_if(myVector.begin(), myVector.end(), std::not1(std::bind2nd(std::less<int>(), 250)), 400);
        for(auto val : myVector){
            std::cout<<"after replace_if: "<<val<<std::endl;
        }
    }
}

void set_test()
{
    // 初始化、push_back、insert、默认sort、sort with lambda cmp func、sort with cmp class、find、binary_search、lower_bound、upper_bound、replace、replace_if、countif、countif with func adapter；

    // 初始化
    std::set<int> myset = {-9, 10, 60, 67, 34, 98, 18};
    for(auto val : myset){
        std::cout<<"init: "<<val<<std::endl;
    }

    // insert
    for(int32_t i = 0; i < 10; i++){
        myset.insert(rand()&0xff);
    }
    for(auto val : myset){
        std::cout<<"insert: "<<val<<std::endl;
    }

    // lower_bound
    {
        int findVal = 123;
        auto findIterator = myset.lower_bound(findVal);
        if(findIterator != myset.end()){
            std::cout<<"lower_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"lower_bound: "<<findVal<<" end"<<std::endl;
        }
    }

    // upper_bound
    {
        int findVal = 124;
        auto findIterator = myset.upper_bound(findVal);
        if(findIterator != myset.end()){
            std::cout<<"upper_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"upper_bound: "<<findVal<<" end"<<std::endl;
        }
    }
}

void map_test()
{
    // 初始化、push_back、insert、默认sort、sort with lambda cmp func、sort with cmp class、find、binary_search、lower_bound、upper_bound、replace、replace_if、countif、countif with func adapter；

    // 初始化
    std::map<int, std::string> myMap;
    // insert
    for(int32_t i = 0; i < 10; i++){
        char randChar[10] = {0};
        snprintf(randChar, 10, "%d", rand()&0xff);
        myMap.insert(std::pair<int, std::string>(i, std::string(randChar)));
    }
    for(auto val : myMap){
        std::cout<<"insert: key["<<val.first<<"], val["<<val.second<<"]"<<std::endl;
    }

    // lower_bound
    {
        int findVal = 123;
        auto findIterator = myMap.lower_bound(findVal);
        if(findIterator != myMap.end()){
            std::cout<<"lower_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"lower_bound: "<<findVal<<" end"<<std::endl;
        }
    }

    // upper_bound
    {
        int findVal = 124;
        auto findIterator = myMap.upper_bound(findVal);
        if(findIterator != myMap.end()){
            std::cout<<"upper_bound: "<<findVal<<" not end"<<std::endl;
        } else {
            std::cout<<"upper_bound: "<<findVal<<" end"<<std::endl;
        }
    }
}
