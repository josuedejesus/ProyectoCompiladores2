#include "MiniJavaLexer.hpp"
#include "iostream"
#include "fstream"

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

    MiniJavaLexer lex(inputFile);

    lex.lex();
    
    std::cout << "Num lines: " << lex.num_lines << '\n'
                << "Num chars: " << lex.num_chars << '\n';
}