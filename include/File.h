#include <string>
#include <optional>

#include "Arguments.h"

#pragma once

using namespace std;

class File {
public:
    string path;
    optional<string> name;
    optional<string> content;

    File(string path, Arguments arguments);

    int readFileName(string search);
    int readFileContent(string search);
};
