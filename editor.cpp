// Author: Spencer Steers
// Date:   05.05.2013
// File:   editor.cpp
// Implementation of text editor class

#include "editor.h"

void editor::start_with_loop()
{
    enabled = true;
    std::cout << "Spenzor Textzor - v0.1" << std::endl;
    std::cout << "    - see 'H' for help and usage" << std::endl;
    while(enabled)
    {
        handle_input();
    }
}

void editor::handle_input()
{
    std::string command, arg1, arg2, in;
    
    // Get input string into a stringstream
    getline(std::cin, in);
    std::stringstream line(in);

    // Parse into arguments
    int count = 0;
    while(std::getline(line, in, ' '))
    {
        switch (count) {
            case 0:
                command = in;
                break;
            case 1:
                // After geting next string put the rest of line in arg2
                arg1 = in;
                getline(line, in);
                arg2 = in;
                break;
        }
        ++count;
    }

    // Execute input command
    if (command == "H")
    {
        help();
    }
    else if(command == "R") 
    {
        read_file();
    }
    else if(command == "W")
    {
        write_file();
    }
    else if (command == "I")
    {
        int pos = atoi(arg1.c_str());
        if (pos < 0)
            pos = 0;
        insert_line(pos, arg2);
    }
    else if (command == "D")
    {
        int pos = atoi(arg1.c_str());
        if (pos < 0)
            pos = 0;
        delete_line(pos);
    }
    else if (command == "F")
    {
        find_and_replace(arg1, arg2);
    }
    else if (command == "V")
    {
        view_buffer();
    }
    else if (command == "Q")
    {
        quit();
    }
    else    
    {
        std::cout << "Input not recognized, try entering 'H' for help." << std::endl;
    }
}


void editor::help()
{
    std::cout << "Commands:" << std::endl;
    std::cout << "R: reads the input file overwritting the buffer" << std::endl;
    std::cout << "W: writes the buffer to the input file" << std::endl;
    std::cout << "I: insert new line" << std::endl;
    std::cout << "   [line number] the position at which to insert text" << std::endl;
    std::cout << "   [text] the text to insert" << std::endl;
    std::cout << "   ex: I 10 This will be inserted at line 10" << std::endl;
    std::cout << "D: delete line " << std::endl;
    std::cout << "   [line number] the position of the line to remove" << std::endl;
    std::cout << "   ex: D 10" << std::endl;
    std::cout << "F: find and replace" << std::endl;
    std::cout << "   [target] (cannot contain spaces) string to search for" << std::endl;
    std::cout << "   [replacement] string to replace target with" << std::endl;
    std::cout << "   ex: F hello goodbye" << std::endl;
    std::cout << "Q: exit the program" << std::endl;
}

void editor::read_file()
{
    std::ifstream f(filename.c_str());
    std::string line;

    std::vector<std::string> temp;
    while(getline(f, line))
    {
        temp.push_back(line);
    }
    line_buffer = temp;
}

void editor::write_file()
{
    std::ofstream f(filename.c_str());
    for (std::vector<std::string>::iterator i = line_buffer.begin(); i != line_buffer.end(); ++i)
        f << *i << std::endl;
}

void editor::insert_line(unsigned pos, std::string text)
{
    if (pos < 1)
    {
        std::cerr << "Line does not exist" << std::endl;
        return;
    }

    if (pos > line_buffer.capacity())
        line_buffer.resize(pos);

    line_buffer.insert(line_buffer.begin() + (pos - 1), text);
}

void editor::delete_line(unsigned pos)
{
    if (pos > line_buffer.capacity() || pos < 1)
    {
        std::cerr << "Line does not exist" << std::endl;
        return;
    }        
    line_buffer.erase(line_buffer.begin() + pos - 1);
}

void editor::find_and_replace(std::string target, std::string replacement)
{
    for (std::vector<std::string>::iterator i = line_buffer.begin(); i != line_buffer.end(); ++i)
    {
        std::string::size_type pos = i->find(target);
        if(pos != std::string::npos)
        {
            i->replace(pos, target.length(), replacement);
            return;
        }
    }
    std::cerr << "Target not found" << std::endl;
}

void editor::view_buffer()
{
    std::vector<std::string>::iterator itr;

    std::cout << "~" << std::endl;
    for (itr = line_buffer.begin(); itr != line_buffer.end(); ++itr)
        std::cout << *itr << std::endl;
    std::cout << "~" << std::endl;
}

void editor::quit()
{
    enabled = false;
}