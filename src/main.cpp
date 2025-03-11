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

    std::string code = fs::read_file(file_input);
    // std::string code = "let a = 5";
    std::vector<Token> tokens = tokenize(code);

    std::stringstream ss;
    for(Token t : tokens) {
        ss << magic_enum::enum_name<TokenType>(t.type) << " - " << t.value << std::endl;
    }
    fs::write_file(file_output, ss.str());

    return EXIT_SUCCESS;
}