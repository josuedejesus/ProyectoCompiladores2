#include "MiniJavaLexer.hpp"
#include "MiniJavaParser.hpp"
#include "MiniJavaAst.hpp"
#include <iostream>
#include <unordered_map>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Must include file." << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string outFileName = fileName.substr(0, fileName.length() - 5) + ".ll";

    std::ifstream inputFile(fileName);
    std::ofstream outputFile(outFileName);

    if (!inputFile) {
        std::cerr << "Cannot open " << fileName << "\n";
        return 1;
    }

    std::unordered_map<std::string, std::string> types;
    std::unordered_map<std::string, std::string> literals;
    std::unordered_map<std::string, std::string> vars;
    function_table_t functions;

    Ast::Node *root;
    MiniJavaLexer lex(inputFile);
    Expr::Parser parser(lex, root);

    try {
        parser.parse();
        CodegenResult r = Ast::exprCompile(root, types, literals, functions, vars);

        if (!outputFile) {
            std::cerr << "Cannot open " << outFileName << "\n";
            return 1;
        }

        outputFile << r.code;
        outputFile.close();

        /*std::cout << root->toString() << '\n';
        std::cout << r.code << std::endl;

        for (const auto& pair : vars) {
            std::cout << "Variable: " << pair.first << " -> Tipo: " << pair.second << std::endl;
        }

        for (const auto& pair : functions) {
            std::cout << "Funcion: " << pair.first << " -> Nodo: " << pair.second << std::endl;
        }*/

        std::cout << "Sucess: Code generation finished without errors.\n";

    } catch (const std::runtime_error &err) {
        std::cerr << err.what() << '\n';
        return 1;
    }
}