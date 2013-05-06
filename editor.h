// Author: Spencer Steers
// Date:   05.05.2013
// File:   editor.h
// Decleration of text editor class


#ifndef __pa6__editor__
#define __pa6__editor__

#include <vector>
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

    // Pre: None
    // Post: Starts editor in a loop that ends once the user quits
    void start_with_loop();

    // Pre: None
    // Post: Reads in input from the user to then issue commands
    void handle_input();

private:

    // Pre: None
    // Post: Displays how to use
    void help();

    // Pre: None
    // Post: Opens [filename] and reads into buffer
    void read_file();

    // Pre: None
    // Post: Opens [filename] and writes from buffer
    void write_file();

    // Pre: Position of line and text
    // Post: Inserts a line into the buffer with the text
    void insert_line(unsigned pos, std::string text);

    // Pre: Position of line
    // Post: Removes the line from the buffer
    void delete_line(unsigned pos);

    // Pre: Target and Replacement
    // Post: Removes [Target] and puts [Replacement] where it was in buffer
    void find_and_replace(std::string target, std::string replacement);

    // Pre: None
    // Post: Outputs the contents of the buffer to std::cout
    void view_buffer();

    // Pre: None
    // Post: Quits the text editor
    void quit();

    bool enabled;
    std::string filename;
    std::vector<std::string> line_buffer;
};

#endif
