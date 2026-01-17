#pragma once

class Arguments {
public:
    bool help = false;
    bool version = false;
    bool recursion = false;
    bool file_content = true;
    bool file_name = true;

    Arguments(int argc, char* argv[]);
};
