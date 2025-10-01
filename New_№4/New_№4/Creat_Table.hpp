#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
// Типы токенов
enum TokenType {
    TERMINAL,
    NON_TERMINAL,
    END
};

// Структура токена
struct Token {
    TokenType type;
    string value;

    Token() : type(END), value("") {}
    Token(TokenType t, string v = "") : type(t), value(v) {}
};
//FIRST
struct F
{
    string NonTerm = " ";
    vector<string> Terms;
};

struct GrammarRule
{
    string left;
    vector<string> right;

    GrammarRule(const string& l, const vector<string>& r) : left(l), right(r) {}
};
// Структура которая будет хранить КОН и НАЧ нетерминалов
struct Start_End
{
    string nonTerminals = " ";
    vector<string> Start;
    vector<string> End;

};
// Проверяет на повторы НАЧ и КОН
int Check_rep(vector<string> vec, string str);
// Грамматика
class Grammar {
private:
    vector<GrammarRule> rules;
    set<string> nonTerminals;
    set<string> terminals;
    vector<string> ALL_SYM;
    vector<string> nonTermss;
    vector<string> termss;


public:
    Grammar readGrammarFromFile(const string& filename);
    void addRule(const string& left, const vector<string>& right);
    vector<string> GET_NON()
    {
        return nonTermss;
    }
    vector<string> GET_TR()
    {
        return termss;
    }
    vector<string> Get_ALL()
    {
        return ALL_SYM;
    }
    const vector<GrammarRule>& getRules() const {
        return rules;
    }

    const set<string>& getNonTerminals() const {
        return nonTerminals;
    }

    const set<string>& getTerminals() const {
        return terminals;
    }


    void print() const {
        cout << "Правила:" << endl;
        for (const auto& rule : rules) {
            cout << rule.left << " -> ";
            for (const auto& sym : rule.right) {
                cout << sym << " ";
            }
            cout << endl;
        }
    }
};


class Lexer
{
private:
    const set<string>& terminals;

public:
    Lexer(const set<string>& terms) : terminals(terms) {}

};

class Parser {
private:
    typedef void(Parser::* fptr)();
    Grammar grammar;
    Lexer lexer;
    Token currentToken;
    stack<string> parseStack;
    map<std::pair<std::string, std::string>, char> precedenceTable;


    void buildPrecedenceTable(vector<Start_End> start_end, vector<F> FIRST);
    void findUnreachableNonTerminals(Grammar grammar);
    void findEpsilonRules(const Grammar& grammar);
    void findIndirectLeftRecursion(Grammar grammar);
    void findDirectLeftRecursion(const Grammar& grammar);



public:
    map<pair<string, string>, char> getPrecedenceTable() const {
        return precedenceTable;
    }
    Parser(Grammar g, vector<Start_End> start_end, vector<F> FIRST) : grammar(g), lexer(grammar.getTerminals())
    {
        findUnreachableNonTerminals(grammar);
        findDirectLeftRecursion(grammar);
        findEpsilonRules(grammar);
        findIndirectLeftRecursion(grammar);

        buildPrecedenceTable(start_end, FIRST);
    }

    void printPrecedenceTable();
};

//Функция возращает НАЧ и КОН всех не терминалов
vector<Start_End> Set_Start_End(Grammar grammar);

vector<F> Find_FIRST(vector<F> FIRST, vector<Start_End> SE, Grammar grammar);

void Print_Term(Grammar grammar);

void Print_NonTerm(Grammar grammar);

void Print_FIRST(vector<F> FIRST);

void Print_SE(vector<Start_End> SE, Grammar grammar);