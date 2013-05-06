// Author: Spencer Steers
// Date:   05.05.2013
// File:   editor.cpp
// Implementation of text editor class

#include "editor.h"

void editor::start_with_loop()
{
    enabled = true;
    while(enabled)
    {
        handle_input();
    }   
}

void editor::handle_input()
{
    std::string command, arg1, arg2, in;
    
    getline(std::cin, in);
    std::stringstream line(in);

    int count = 0;
    while(std::getline(line, in, ' '))
    {
        switch (count) {
            case 0:
                command = in;
                break;
            case 1:
                arg1 = in;
                break;  
            case 2:
                arg2 = in;
                break;
        }
        ++count;
    }

    std::cout << command << arg1 << arg2;
    std::cout << std::endl;
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
        insert_line(pos, arg2);
    }
    else if (command == "D")
    {
        int pos = atoi(arg1.c_str());
        delete_line(pos);
    }
    else if (command == "R")
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
    std::cout << "R: reads the input file to the buffer" << std::endl;
    std::cout << "W: writes the buffer to the input file" << std::endl;
    std::cout << "I: insert new line" << std::endl;
    std::cout << "   [line number] the position at which to insert text" << std::endl;
    std::cout << "   [text] the text to insert" << std::endl;
    std::cout << "   ex: I 10 This will be inserted at line 10" << std::endl;
    std::cout << "D: delete line " << std::endl;
    std::cout << "   [line number] the position of the line to remove" << std::endl;
    std::cout << "   ex: D 10" << std::endl;
    std::cout << "F: find and replace" << std::endl;
    std::cout << "   [target] string to search for" << std::endl;
    std::cout << "   [replacement] string to replace target with" << std::endl;
    std::cout << "   ex: F hello goodbye" << std::endl;
    std::cout << "Q: exit the program" << std::endl;
}

void editor::read_file()
{
    
}

void editor::write_file()
{

}

void editor::insert_line(unsigned pos, std::string text)
{

}

void editor::delete_line(unsigned pos)
{

}

void editor::find_and_replace(std::string target, std::string replacement)
{

}

void editor::view_buffer()
{

}

void editor::quit()
{
    enabled = false;
}