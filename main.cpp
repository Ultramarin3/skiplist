/* ************************************************************************
> File Name:     main.cpp
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Sun Dec  2 20:21:41 2018
> Description:   

> Modify : Zhiheng
> 2022/12/22 
 ************************************************************************/
#include <iostream>
#include "skiplist.h"
#define FILE_PATH "./store/dumpFile"

int main() {

    // 键值中的key用int型，如果用其他类型，需要自定义比较函数
    // 而且如果修改key的类型，同时需要修改skipList.load_file函数
    SkipList<int, std::string> skipList(6);
	skipList.insert_element(1, "Talk"); 
	skipList.insert_element(3, "is"); 
	skipList.insert_element(7, "cheap"); 
	skipList.insert_element(8, "show"); 
	skipList.insert_element(9, "me"); 
	skipList.insert_element(19, "the code"); 
	skipList.update_element(19, "code"); 

    std::cout << "skipList size:" << skipList.get_size() << std::endl;

    skipList.dump_file();

    // skipList.load_file();

    skipList.search_element(9);
    skipList.search_element(18);


    skipList.display_list();

    skipList.delete_element(3);
    skipList.delete_element(7);

    std::cout << "skipList size:" << skipList.get_size() << std::endl;

    skipList.display_list();
}
