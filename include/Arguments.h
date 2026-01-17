#include <string>
#include <vector>

#include "Extensions.h"

#pragma once

class Arguments {
public:
    bool help = false;
    bool version = false;
    bool recursion = false;
    bool file_content = true;
    bool file_name = true;
    bool case_sensitive = true;

    Extensions extensions;

    Arguments(int argc, char* argv[]);
    void parseExtensionArguments(int& i, int argc, char* argv[]);
};
