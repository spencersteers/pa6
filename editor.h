// Author: Spencer Steers
// Date:   05.05.2013
// File:   editor.h
// 


#ifndef __pa6__editor__
#define __pa6__editor__

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "stdlib.h"

class editor
{
public:
    editor(std::string filename):filename(filename) {}
    editor(char* filename):filename(filename) {}

    void start_with_loop();
    void handle_input();

private:
    
    void help();
    void read_file();
    void write_file();
    void insert_line(unsigned pos, std::string text);
    void delete_line(unsigned pos);
    void find_and_replace(std::string target, std::string replacement);
    void view_buffer();
    void quit();

    bool enabled;
    std::string filename;
    std::list<std::string> line_buffer;
};

#endif
