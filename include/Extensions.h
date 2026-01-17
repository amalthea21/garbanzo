#pragma once

#include <string>
#include <vector>

class Extensions {
public:
    enum Mode { Exclude, Include };

    std::vector<std::string> extensions;
    Mode mode;

    bool extension_help = false;
    bool extension_sensitive = false;


    void readExtensions(std::string argument);
    std::string extractExtension(std::string fileName);
    bool isLegalExtension(std::string extension);
};
