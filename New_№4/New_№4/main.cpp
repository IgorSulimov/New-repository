#include "Lexical_Analyzator.hpp"
#include "Creat_Table.hpp"
#include "AttributeTranslator.hpp"
#include "SymbolTable.hpp"
#include "Complier.hpp"
#include "Stack.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    Compiler compiler;
    string filename;
    Lex_Analyze Pars;
    char name_file[] = "if.txt";
    Lexeme* lex = new Lexeme[200];
    lex = Pars.Lexical_analyzer(name_file);
    Pars.Print_Table_Lexem(lex);
    string possibleFiles = "if.txt";



    try {
        // Компилируем код
        string result = compiler.compile(possibleFiles.c_str());

        // Записываем результат в output.txt
        ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << result + "end ";
            outputFile.close();
            cout << "Compilation successful! Result written to output.txt" << endl;

            // Также выводим результат на консоль для информации
            cout << "Generated code:" << endl;
            cout << "==========================================" << endl;
            cout << result + "end " << endl;
            cout << "==========================================" << endl;
        }
        else {
            cerr << "Error: Could not open output.txt for writing" << endl;
            return 1;
        }
        char out_file[] = "output.txt";
        Lexeme_* l = Lexical_analyzer_(out_file);
        //Print_Table_Lex(l);
        Interpreter_int(l);
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