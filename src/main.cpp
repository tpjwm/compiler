#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>

enum class TokenType {
    _return,
    _int_lit,
    _semicolon
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

/**
*   Get the uncompiled program in string form
*/
std::string get_pgm_contents(char* program_name){
    std::fstream input(program_name, std::ios::in);
    std::stringstream contents_stream;
    contents_stream << input.rdbuf();
    return contents_stream.str();
}

/*
*   Temporary thing to get the return value
*/
std::string get_ret_val(std::string& str, int index){
    index++;
    std::string buffer;
    for (int i = index; i < str.length(); i++){
        char c = str.at(i);
        if (c == ';') break;
        buffer.push_back(c);
    }
    return buffer;
}

std::vector<Token> tokenize(std::string& str){
    std::vector<Token> tokens;
    std::string buffer;
    for (int i = 0; i < str.length(); i++){
        char c = str.at(i);
        if (std::isalpha(c)){
            buffer.push_back(c);
            if (str.length() > 1) i++;
            while (std::isalnum(str.at(i)) && str.length() != i){
                buffer.push_back(str.at(i));
                i++;
            }
            i--;
            if (buffer == "return"){
                std::optional<std::string> ret_val = get_ret_val(str, i);
                tokens.push_back({.type = TokenType::_return, .value = ret_val});
            } else {
                std::cerr << "Ya done fucked up" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    return tokens;
}

int main(int argc, char* argv[]) {
    if (argc != 2){
        printf("Incorrect usage\nCorrect usage: %s <file.dnp>\n",argv[0]);
        return EXIT_FAILURE;
    }

    std::string contents = get_pgm_contents(argv[1]);

    std::cout << contents << std::endl;
    std::vector<Token> tokens = tokenize(contents);
    for (Token token : tokens){
        if (token.type == TokenType::_return) std::cout << "return" << token.value.value() <<std::endl;
    }

    return EXIT_SUCCESS;
}
