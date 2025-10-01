#include "Lexical_Analyzator.hpp"
#include "Creat_Table.hpp"
#include "AttributeTranslator.hpp"
#include "SymbolTable.hpp"
#include "Complier.hpp"

bool fileExists(const string& filename) {
    FILE* file = nullptr;
    errno_t err = fopen_s(&file, filename.c_str(), "r");  
    if (err == 0 && file) {
        fclose(file);
        return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Compiler compiler;
    string filename;
    Lex_Analyze Pars;
    char name_file[] = "input.txt";
    Lexeme* lex = new Lexeme[200];
    lex = Pars.Lexical_analyzer(name_file);
    Pars.Print_Table_Lexem(lex);
    //Grammar grammar;
    //grammar = grammar.readGrammarFromFile("1.txt");
    //grammar.print();

    string possibleFiles = "input.txt";



    try {
        // Компилируем код
        string result = compiler.compile(possibleFiles.c_str());

        // Записываем результат в output.txt
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << result;
            outputFile.close();
            cout << "Compilation successful! Result written to output.txt" << endl;

            // Также выводим результат на консоль для информации
            cout << "Generated code:" << endl;
            cout << "==========================================" << endl;
            cout << result << endl;
            cout << "==========================================" << endl;
        }
        else {
            cerr << "Error: Could not open output.txt for writing" << endl;
            return 1;
        }
    }
    catch (const exception& e) {
        cerr << "Compilation error: " << e.what() << endl;

        // Записываем ошибку в output.txt
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << "// Compilation error: " << e.what() << endl;
            outputFile.close();
        }
        return 1;
    }

    return 0;

    ////НАЧ / КОН
    //vector<Start_End> SE = Set_Start_End(grammar);
    //Print_SE(SE, grammar);

    ////FIRS / TERMS / NONTERMS
    //vector<F> FIRST;
    //FIRST = Find_FIRST(FIRST, SE, grammar);
    ////Print_FIRST(FIRST);
    ////Print_Term(grammar);
    ////Print_NonTerm(grammar);

    ////таблица предшествования 
    //Parser parser(grammar, SE, FIRST);
    //parser.printPrecedenceTable();

}