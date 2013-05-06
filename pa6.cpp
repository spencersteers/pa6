// Author: Spencer Steers
// Date:   05.06.2013
// File:   pa6.cpp
// 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "pa6functions.h"
#include "editor.h"

int main(int argc, char const *argv[])
{
    editor e(argv[1]);
    e.start_with_loop();
    return 0;   
}