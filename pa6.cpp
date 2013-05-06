// Author: Spencer Steers
// Date:   05.06.2013
// File:   pa6.cpp
// This program is a line based text editor
// It takes in a filename at the command line
// to read and write to

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "pa6functions.h"
#include "editor.h"

int main(int argc, char const *argv[])
{
    std::cout << std::endl;
    pa6::greeting();
    std::cout << std::endl;

    // Error check and start editor
    if (argc < 1)
    {
        std::cerr << "Filename was not provided at runtime" << std::endl;
        return EXIT_FAILURE;
    }
    editor e(argv[1]);
    e.start_with_loop();

    return EXIT_SUCCESS;
}