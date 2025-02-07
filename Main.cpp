#include "MiniJavaLexer.hpp"
#include "MiniJavaParser.hpp"
#include <iostream>
#include <unordered_map>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Must include file." << std::endl;
        return 1;
    }

    std::string fileName = argv[1];

    std::ifstream inputFile(fileName);

    if (!inputFile) {
        std::cerr << "Cannot open " << fileName << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> vars;
    MiniJavaLexer lex(inputFile);
    Expr::Parser parser(lex, vars);

    try {
        parser.parse();
    } catch (const std::runtime_error &err) {
        std::cerr << err.what() << '\n';
        return 1;
    }
}