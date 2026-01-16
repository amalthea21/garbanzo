#include "../include/File.h"

File::File(string path, Arguments arguments) {
    if (arguments.file_name) {
        name = filesystem::path(path).filename().string();
    }

    if (arguments.file_content) {
        ifstream file(path);
        if (file) {
            string line;
            string fullContent;
            while (getline(file, line)) {
                fullContent += line + "\n";
            }
            content = fullContent;
        }
    }
}

int File::readFileName(string search) {
    if (!name.has_value())
        return 0;

    int amount = 0;
    string curName = name.value();


    for (int i = 0; i < curName.length() - search.length(); i++) {
        if (search == curName.substr(i, search.length()))
            amount++;
    }

    return amount;
}

int File::readFileContent(string search) {
    if (!content.has_value())
        return 0;

    int amount = 0;
    string curContent = content.value();

    for (int i = 0; i < curContent.length() - search.length(); i++) {
        if (search == curContent.substr(i, search.length()))
            amount++;
    }

    return amount;
}
