#include "./includes.h"

int main(int argc, char** args) {
    // if(argc != 3) {
    //     std::cerr << "Usage: " << args[0] << " <input.txt> <output.txt>" << std::endl;
    //     return EXIT_FAILURE;
    // }

    // std::string file_input = args[1];
    // std::string file_output = args[2];

    // if(!fs::exists(file_input)) {
    //     std::cerr << "Input file '" << file_input << "' does not exist." << std::endl;
    //     return EXIT_FAILURE;
    // }
    // if(!fs::exists(file_output)) fs::create(file_output);

    // std::string code = fs::read_file(file_input);
    // std::cout << code << std::endl;

    std::string code = "\"test 1 2 3\" test int 1 2 3 134.52 ";
    std::vector<Token> tokens = tokenize(code);

    for(Token t : tokens) {
        std::cout << magic_enum::enum_name<TokenType>(t.type) << " - " << t.value << std::endl;
    }

    return EXIT_SUCCESS;
}