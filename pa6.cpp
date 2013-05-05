// Author: Spencer Steers
// Date:   05.06.2013
// File:   pa6.cpp
// 

#include <iostream>
#include <string>
#include <vector>
#include "pa6functions.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> v;
    v.push_back("push_back");
    v.insert(v.begin(), "Begin");
    v.insert(v.begin() + 1, "5");

    std::string s = argv[0];

    for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    return 0;
}