#include "AttributeTranslator.hpp"
#include "SymbolTable.hpp"
#include "Creat_Table.hpp"
#include "Parser.hpp"
#include "Lexical_Analyzator.hpp"
class Compiler {
private:
    Lex_Analyze lexer;
    Grammar grammar;
    unique_ptr<SyntaxParser> parser; // Используем умный указатель
    map<pair<string, string>, char> precedenceTable;

public:
    Compiler() {
        // Загрузка грамматики из файла
        grammar = grammar.readGrammarFromFile("grammar.txt");

        // Построение таблицы предшествования
        vector<Start_End> SE = Set_Start_End(grammar);
        vector<F> FIRST = Find_FIRST(vector<F>(), SE, grammar);
        Parser tableParser(grammar, SE, FIRST);

        // РАСКОММЕНТИРУЙТЕ эту строку:
        precedenceTable = tableParser.getPrecedenceTable();

        // Создаем парсер с правильной таблицей
        parser = make_unique<SyntaxParser>(grammar, precedenceTable);
    }

    string compile(const char* filename) {
        // Лексический анализ
        Lexeme* lexemes = lexer.Lexical_analyzer(filename);
        int count = lexer.count_word();

        if (lexemes == nullptr || count == 0) {
            return "// Error: No tokens found\n";
        }

        // Синтаксический анализ и трансляция
        string resultCode = parser->parse(lexemes, count);

        // Очистка
        delete[] lexemes;

        return resultCode;
    }
};