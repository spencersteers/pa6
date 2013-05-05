
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "editor.h"

class editor
{
public:
    editor();
    editor(std::string filename):filename(this->filename);
    editor(char* filename):filename(this->filename);

private:
    std::string filename;
    std::list<std::string> line_buffer;
};