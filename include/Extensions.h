#include <string>
#include <vector>

#pragma once

class Extensions {
public:
    enum Mode { Exclude, Include }; // Whether extensions in the vector will only be read or not be read

    std::vector<std::pmr::string> extensions;
    Mode mode;

    bool extension_help = false;
    bool extension_sensitive = false;
};
