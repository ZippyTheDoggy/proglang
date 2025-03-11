#include "./includes.h"

int main(int argc, char** args) {
    if(argc != 3) {
        std::cerr << "Usage: " << args[0] << " <input.txt> <output.txt>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string file_input = args[1];
    std::string file_output = args[2];

    if(!fs::exists(file_input)) {
        std::cerr << "Input file '" << file_input << "' does not exist." << std::endl;
        return EXIT_FAILURE;
    }
    if(!fs::exists(file_output)) fs::create(file_output);

    //

    return EXIT_SUCCESS;
}