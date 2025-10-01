#include "AttributeTranslator.hpp"
#include "SymbolTable.hpp"
#include "Creat_Table.hpp"
#include "Parser.hpp"
#include "Lexical_Analyzator.hpp"
class Compiler {
private:
    Lex_Analyze lexer;
    Grammar grammar;
    unique_ptr<SyntaxParser> parser; // ���������� ����� ���������
    map<pair<string, string>, char> precedenceTable;

public:
    Compiler() {
        // �������� ���������� �� �����
        grammar = grammar.readGrammarFromFile("grammar.txt");

        // ���������� ������� ���������������
        vector<Start_End> SE = Set_Start_End(grammar);
        vector<F> FIRST = Find_FIRST(vector<F>(), SE, grammar);
        Parser tableParser(grammar, SE, FIRST);

        // ���������������� ��� ������:
        precedenceTable = tableParser.getPrecedenceTable();

        // ������� ������ � ���������� ��������
        parser = make_unique<SyntaxParser>(grammar, precedenceTable);
    }

    string compile(const char* filename) {
        // ����������� ������
        Lexeme* lexemes = lexer.Lexical_analyzer(filename);
        int count = lexer.count_word();

        if (lexemes == nullptr || count == 0) {
            return "// Error: No tokens found\n";
        }

        // �������������� ������ � ����������
        string resultCode = parser->parse(lexemes, count);

        // �������
        delete[] lexemes;

        return resultCode;
    }
};