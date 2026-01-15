#include "../include/Arguments.h"
#include <string>

using namespace std;

Arguments::Arguments(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {

            if (argv[i] == string("-h") || argv[i] == string("--help"))
                help = true;
            else if (argv[i] == string("-r") || argv[i] == string("--recursion"))
                recursion = true;
        }
    }
}
