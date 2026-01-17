#pragma once

#include <string>
#include <optional>
#include <filesystem>

#include "Arguments.h"



class File {
public:
    std::string path;
    std::optional<std::string> name;
    std::optional<std::string> content;
    std::optional<std::string> extension;


    File(std::string path, Arguments arguments);
    int readFileName(std::string search, Arguments arguments);
    int readFileContent(std::string search, Arguments arguments);
};
