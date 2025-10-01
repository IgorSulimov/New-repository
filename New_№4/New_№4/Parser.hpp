#include <stack>
#include <vector>
#include <map>
#include <functional>
#include "Creat_Table.hpp"
#include "AttributeTranslator.hpp"

using namespace std;

class SyntaxParser {
private:
    Grammar grammar;
    map<pair<string, string>, char> precedenceTable;
    AttributeTranslator translator;
    SymbolTable symbolTable;

    // Состояние парсера
    stack<pair<string, Attribute>> parseStack;
    vector<pair<string, Attribute>> inputTokens;
    int currentTokenIndex;

    // Сопоставление лексем с терминалами грамматики
    map<int, string> tokenToSymbol = {
        {48, "dim"}, {41, "V"}, {37, "int"}, {38, "vector"}, {24, ";"}, {50, ":"},
        {49, ","}, {9, "="}, {1, "if"}, {2, "then"}, {3, "else"}, {4, "while"},
        {5, "each"}, {6, "end"}, {7, "in"}, {8, "cin"}, {10, "!="}, {11, ">="},
        {12, "<="}, {13, "+"}, {14, "-"}, {15, "*"}, {16, "%"}, {17, "/"},
        {18, ">"}, {19, "<"}, {20, "shiftr"}, {21, "shiftl"}, {22, "concat"},
        {23, "subvec"}, {25, "&"}, {26, "set"}, {27, "for"}, {28, ">>"}, {29, "<<"},
        {30, "cout"},{31,"C"}, { 32, "jump" }, {33, "switch"}, {34, "when"}, {35, "throw"},
        {36, "rem"}, {39, "L"}, {40, "do"}, {43, "("}, {44, ")"}, {45, "C"},
        {46, "L:"}, {47, "otherwise"}
    };

    // Правила грамматики для свертки
    vector<pair<string, vector<string>>> reductionRules = {
        {"<S>", {"<Ob>", "<Prog>"}},
        {"<S>", {"<Prog>"}},
        {"<Prog>", {"<Oper>", "<Prog>"}},
        {"<Prog>", {"<Oper>"}},
        {"<Ob>", {"<Ob>", "<Ob2>"}},
        {"<Ob>", {"<Ob2>"}},
        {"<Ob2>", {"<Ob3>", ":", "<Type>", ";"}},
        {"<Ob3>", {"dim", "V"}},
        {"<Ob3>", {"<Ob4>", "V"}},
        {"<Ob4>", {"<Ob3>", ","}},
        {"<Type>", {"int"}},
        {"<Type>", {"vector"}},
        {"<Oper>", {";"}},
        {"<Oper>", {"<Prisv>", ";"}},
        {"<Prisv>", {"<Prisv2>", "=", "<E>"}},
        {"<Prisv2>", {"set", "V"}},
        {"<Prisv2>", {"<Prisv3>", "V"}},
        {"<Prisv3>", {"<Prisv2>", ","}},
        {"<Oper>", {"<For_1>", "end", ";"}},
        {"<For_1>", {"<For_2>", "do", "<Prog>"}},
        {"<For_2>", {"for", "each", "V", "in", "<E>"}},
        {"<Oper>", {"<While>", "end", ";"}},
        {"<While>", {"while", "<Test>", "do", "<Prog>"}},
        {"<Oper>", {"<If_1>", "end", ";"}},
        {"<Oper>", {"<If_1>", "<Else>", "end", ";"}},
        {"<If_1>", {"if", "<Test>", "then", "<Prog>"}},
        {"<Else>", {"else", "<Prog>"}},
        {"<Oper>", {"<Cin>", ";"}},
        {"<Cin>", {"cin", "<List_V1>"}},
        {"<List_V1>", {">>", "V", "<List_V1>"}},
        {"<List_V1>", {">>", "V"}},
        {"<Oper>", {"<Output>", ";"}},
        {"<Output>", {"cout", "<List_E1>"}},
        {"<List_E1>", {"<Exp>"}},
        {"<List_E1>", {"<<", "<E>", "<List_E1>"}},
        {"<Exp>", {"<<", "<E>"}},
        {"<Oper>", {"L:"}},
        {"<Oper>", {"<Jump>", ";"}},
        {"<Jump>", {"jump", "L"}},
        {"<Oper>", {"<Switch_1>", "end", ";"}},
        {"<Oper>", {"<Switch_1>", "<Other>", "end", ";"}},
        {"<Switch_1>", {"<Switch_2>", "<When1>"}},
        {"<Switch_2>", {"switch", "(", "<E>", ")"}},
        {"<When1>", {"<When3>", "<When1>"}},
        {"<When1>", {"<When3>"}},
        {"<When3>", {"<When>", ":", "<Prog>"}},
        {"<When>", {"when", "C"}},
        {"<When>", {"<When2>", "C"}},
        {"<When2>", {"<When>", ","}},
        {"<Other>", {"otherwise", "<Prog>"}},
        {"<Test>", {"<E>", "rel", "<E>"}},
        {"<Comma>", {","}},
        {"<Oper>", {"throw", ";"}},
        {"<Oper>", {"rem"}},
        {"<E>", {"<T>", "<E'>"}},
        {"<E>", {"<T>"}},
        {"<E'>", {"+", "<T>", "<E'>"}},
        {"<E'>", {"-", "<T>", "<E'>"}},
        {"<E'>", {"+", "<T>"}},
        {"<E'>", {"-", "<T>"}},
        {"<T>", {"<F>", "<T'>"}},
        {"<T>", {"<F>"}},
        {"<T'>", {"*", "<F>", "<T'>"}},
        {"<T'>", {"/", "<F>", "<T'>"}},
        {"<T'>", {"%", "<F>", "<T'>"}},
        {"<T'>", {"&", "<F>", "<T'>"}},
        {"<T'>", {"*", "<F>"}},
        {"<T'>", {"/", "<F>"}},
        {"<T'>", {"%", "<F>"}},
        {"<T'>", {"&", "<F>"}},
        {"<F>", {"V"}},
        {"<F>", {"C"}},
        {"<F>", {"(", "<E>", ")"}},
        {"<F>", {"shiftl", "(", "<E>", "<Comma>", "<E_brace>"}},
        {"<F>", {"shiftr", "(", "<E>", "<Comma>", "<E_brace>"}},
        {"<F>", {"concat", "(", "<E>", "<Comma>", "<E_brace>"}},
        {"<F>", {"subvec", "(", "<E>", "<Comma>", "<E_brace'>"}},
        {"<E_brace'>", {"<E>", "<Comma>", "<E_brace>"}},
        {"<E_brace>", {"<E>", ")"}}
    };
public:
    SyntaxParser(const Grammar& g, const map<pair<string, string>, char>& table)
        : grammar(g), precedenceTable(table) {
    }
    // Преобразование лексем в входные символы для парсера
    void prepareInput(Lexeme* lexemes, int count) {
        inputTokens.clear();
        for (int i = 0; i < count; i++) {
            string symbol;

            if (lexemes[i].token_class == 10 || // !=
                lexemes[i].token_class == 11 || // >=  
                lexemes[i].token_class == 12 || // <=
                lexemes[i].token_class == 18 || // >
                lexemes[i].token_class == 19) { // <
                symbol = "rel";
            }                                     
            else if (lexemes[i].token_class == 9)   // =
                symbol = "=";
            else {
                auto it = tokenToSymbol.find(lexemes[i].token_class);
                if (it != tokenToSymbol.end()) {
                    symbol = it->second;
                }
                else {
                    symbol = lexemes[i].token_name;
                }
            }
            Attribute attr = translator.createAttributeFromLexeme(lexemes[i]);

            // Сохраняем оригинальное значение оператора в атрибут
            if (lexemes[i].token_class == 10) attr.type2 = "!=";
            else if (lexemes[i].token_class == 11) attr.type2 = ">=";
            else if (lexemes[i].token_class == 12) attr.type2 = "<=";
            else if (lexemes[i].token_class == 18) attr.type2 = ">";
            else if (lexemes[i].token_class == 19) attr.type2 = "<";
            else if (lexemes[i].token_class == 9) attr.type2 = "=";
            // Проверка меток 
            else if (lexemes[i].token_class == 39) // L
            {
                if (Find_Lable_jump(lexemes[i].token_name) == -1)
                {
                    string error_msg = "Repeat lable jump";
                    error_msg += " at line " + to_string(lexemes[i].token_str);
                    throw runtime_error(error_msg);
                }
            }
            else if (lexemes[i].token_class == 46)  // L:
            {
                if (Find_Lable(lexemes[i].token_name) == -1)
                {
                    string error_msg = "Repeat lable";
                    error_msg += " at line " + to_string(lexemes[i].token_str);
                    throw runtime_error(error_msg);
                }
            }  

            inputTokens.push_back({ symbol, attr });
        }

        inputTokens.push_back({ "$", Attribute() });
        currentTokenIndex = 0;
    }

    // Поиск правила для свертки
    pair<string, int> findReductionRule(const vector<string>& symbols) {
        for (const auto& rule : reductionRules) {
            if (rule.second.size() == symbols.size()) {
                bool match = true;
                for (size_t i = 0; i < rule.second.size(); i++) {
                    if (rule.second[i] != symbols[symbols.size() - rule.second.size() + i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return { rule.first, rule.second.size() };
                }
            }
        }
        return { "", 0 };
    }

    // Основной алгоритм синтаксического анализа
    string parse(Lexeme* lexemes, int count) {
        prepareInput(lexemes, count);

        while (!parseStack.empty()) parseStack.pop();
        parseStack.push({ "$", Attribute() });

        Warning_Lable(lable_,lable_jump_);

        currentTokenIndex = 0;
        while (currentTokenIndex < inputTokens.size()){
            string stackTop = parseStack.top().first;
            string currentInput = inputTokens[currentTokenIndex].first;
            int currentLine = inputTokens[currentTokenIndex].second.line_number;
            if (stackTop == "<S>" && currentInput == "$") {
                break;
            }
            try {

                auto relationIt = precedenceTable.find({ stackTop, currentInput });
                if (relationIt == precedenceTable.end()) {
                    string error_msg = "No precedence relation between " + stackTop + " and " + currentInput;
                    if (currentLine != -1) {
                        error_msg += " at line " + to_string(currentLine);
                    }
                    throw runtime_error(error_msg);
                }

                char relation = relationIt->second;

                if (relation == '<' || relation == '=') {
                    parseStack.push(inputTokens[currentTokenIndex]);
                    currentTokenIndex++;
                }
                else if (relation == '>') {
                    // Свертка
                    vector<string> handle;
                    vector<Attribute> handleAttributes;
                    while (true) {
                        handle.insert(handle.begin(), parseStack.top().first);
                        handleAttributes.insert(handleAttributes.begin(), parseStack.top().second);
                        parseStack.pop();

                        if (parseStack.size() == 0) break;

                        auto prevRelation = precedenceTable.find({ parseStack.top().first, handle[0] });
                        if (prevRelation != precedenceTable.end() && prevRelation->second == '<') {
                            break;
                        }
                    }

                    auto reduction = findReductionRule(handle);
                    if (reduction.first.empty()) {
                        string error_msg = "No reduction rule found for handle";
                        if (!handleAttributes.empty() && handleAttributes[0].line_number != -1) {
                            error_msg += " at line " + to_string(handleAttributes[0].line_number);
                        }
                        throw runtime_error(error_msg);
                    }

                    Attribute newAttr = applySemanticAction(reduction.first, handle, handleAttributes);
                    parseStack.push({ reduction.first, newAttr });

                }
                else {
                    string error_msg = "Invalid precedence relation";
                    if (currentLine != -1) {
                        error_msg += " at line " + to_string(currentLine);
                    }
                    throw runtime_error(error_msg);
                }
            }
            catch (const runtime_error& e) {
                // Перебрасываем исключение с информацией о строке
                throw;
            }
        }

        if (parseStack.size() >= 2) {
            return parseStack.top().second.code;
        }

        return "";
    }

private:
    // Применение семантических действий при свертке
    Attribute applySemanticAction(const string& left, const vector<string>& right,
        const vector<Attribute>& attributes) {
        // Простейшая реализация - вызов соответствующих методов транслятора
        // В реальной реализации здесь должен быть большой switch/case или таблица переходов

        Attribute result;

        // Примеры обработки некоторых правил
        if (left == "<S>" && right.size() == 2 && right[0] == "<Ob>" && right[1] == "<Prog>") {
            result = translator.rule_S_Ob_Prog(attributes[0], attributes[1]);
        }
        else if (left == "<S>" && right.size() == 1 && right[0] == "<Prog>") {
            result = translator.rule_S_Prog(attributes[0]);
        }
        else if (left == "<Prog>" && right.size() == 2 && right[0] == "<Oper>" && right[1] == "<Prog>") {
            result = translator.rule_Prog_Oper_Prog(attributes[0], attributes[1]);
        }
        else if (left == "<Prog>" && right.size() == 1 && right[0] == "<Oper>") {
            result = translator.rule_Prog_Oper(attributes[0]);
        }
        else if (left == "<Ob>" && right.size() == 2 && right[0] == "<Ob>" && right[1] == "<Ob2>") {
            result = translator.rule_Ob_Ob_Ob2(attributes[0], attributes[1]);
        }
        else if (left == "<Ob>" && right.size() == 1 && right[0] == "<Ob2>") {
            result = translator.rule_Ob_Ob2(attributes[0]);
        }
        else if (left == "<Ob2>" && right.size() == 4 && right[0] == "<Ob3>" && right[1] == ":" &&
            right[2] == "<Type>" && right[3] == ";") {
            result = translator.rule_Ob2_Ob3_Type(attributes[0], attributes[2]);
        }
        else if (left == "<Ob3>" && right.size() == 2 && right[0] == "dim" && right[1] == "V") {
            result = translator.rule_Ob3_dim_V(attributes[1]);
        }
        else if (left == "<Ob3>" && right.size() == 2 && right[0] == "<Ob4>" && right[1] == "V") {
            result = translator.rule_Ob3_Ob4_V(attributes[0], attributes[1]);
        }
        else if (left == "<Ob4>" && right.size() == 2 && right[0] == "<Ob3>" && right[1] == ",") {
            result = translator.rule_Ob4_Ob3_comma(attributes[0]);
        }
        else if (left == "<Type>" && right.size() == 1 && right[0] == "int") {
            result = translator.rule_Type_int();
        }
        else if (left == "<Type>" && right.size() == 1 && right[0] == "vector") {
            result = translator.rule_Type_vector();
        }
        else if (left == "<Oper>" && right.size() == 1 && right[0] == ";") {
            result = translator.rule_Oper_semicolon();
        }
        else if (left == "<Oper>" && right.size() == 2 && right[0] == "<Prisv>" && right[1] == ";") {
            result = translator.rule_Oper_Prisv_semicolon(attributes[0]);
        }
        else if (left == "<Prisv>" && right.size() == 3 && right[0] == "<Prisv2>" && right[1] == "=" && right[2] == "<E>") {
            result = translator.rule_Prisv_Prisv2_equal_E(attributes[0], attributes[2]);
        }
        else if (left == "<Prisv2>" && right.size() == 2 && right[0] == "set" && right[1] == "V") {
            result = translator.rule_Prisv2_set_V(attributes[1]);
        }
        else if (left == "<Prisv2>" && right.size() == 2 && right[0] == "<Prisv3>" && right[1] == "V") {
            result = translator.rule_Prisv2_Prisv3_V(attributes[0], attributes[1]);
        }
        else if (left == "<Prisv3>" && right.size() == 2 && right[0] == "<Prisv2>" && right[1] == ",") {
            result = translator.rule_Prisv3_Prisv2_comma(attributes[0]);
        }
        else if (left == "<Oper>" && right.size() == 3 && right[0] == "<For_1>" && right[1] == "end" && right[2] == ";") {
            result = translator.rule_Oper_For_1_end_semicolon(attributes[0]);
        }
        else if (left == "<For_1>" && right.size() == 3 && right[0] == "<For_2>" && right[1] == "do" && right[2] == "<Prog>") {
            result = translator.rule_For_1_For_2_do_Prog(attributes[0], attributes[2]);
        }
        else if (left == "<For_2>" && right.size() == 5 && right[0] == "for" && right[1] == "each" && right[2] == "V" &&
            right[3] == "in" && right[4] == "<E>") {
            result = translator.rule_For_2_for_each_V_in_E(attributes[2], attributes[4]);
        }
        else if (left == "<Oper>" && right.size() == 3 && right[0] == "<While>" && right[1] == "end" && right[2] == ";") {
            result = translator.rule_Oper_While_end_semicolon(attributes[0]);
        }
        else if (left == "<While>" && right.size() == 4 && right[0] == "while" && right[1] == "<Test>" &&
            right[2] == "do" && right[3] == "<Prog>") {
            result = translator.rule_While_while_Test_do_Prog(attributes[1], attributes[3]);
        }
        else if (left == "<Oper>" && right.size() == 3 && right[0] == "<If_1>" && right[1] == "end" && right[2] == ";") {
            result = translator.rule_Oper_If_1_end_semicolon(attributes[0]);
        }
        else if (left == "<Oper>" && right.size() == 4 && right[0] == "<If_1>" && right[1] == "<Else>" &&
            right[2] == "end" && right[3] == ";") {
            result = translator.rule_Oper_If_1_Else_end_semicolon(attributes[0], attributes[1]);
        }
        else if (left == "<If_1>" && right.size() == 4 && right[0] == "if" && right[1] == "<Test>" &&
            right[2] == "then" && right[3] == "<Prog>") {
            result = translator.rule_If_1_if_Test_then_Prog(attributes[1], attributes[3]);
        }
        else if (left == "<Else>" && right.size() == 2 && right[0] == "else" && right[1] == "<Prog>") {
            result = translator.rule_Else_else_Prog(attributes[1]);
        }
        else if (left == "<Oper>" && right.size() == 2 && right[0] == "<Cin>" && right[1] == ";") {
            result = translator.rule_Oper_Cin_semicolon(attributes[0]);
        }
        else if (left == "<Cin>" && right.size() == 2 && right[0] == "cin" && right[1] == "<List_V1>") {
            result = translator.rule_Cin_cin_List_V1(attributes[1]);
        }
        else if (left == "<List_V1>" && right.size() == 3 && right[0] == ">>" && right[1] == "V" && right[2] == "<List_V1>") {
            result = translator.rule_List_V1_shiftr_V_List_V1(attributes[1], attributes[2]);
        }
        else if (left == "<List_V1>" && right.size() == 2 && right[0] == ">>" && right[1] == "V") {
            result = translator.rule_List_V1_shiftr_V(attributes[1]);
        }
        else if (left == "<Oper>" && right.size() == 2 && right[0] == "<Output>" && right[1] == ";") {
            result = translator.rule_Oper_Output_semicolon(attributes[0]);
        }
        else if (left == "<Output>" && right.size() == 2 && right[0] == "cout" && right[1] == "<List_E1>") {
            result = translator.rule_Output_cout_List_E1(attributes[1]);
        }
        else if (left == "<List_E1>" && right.size() == 1 && right[0] == "<Exp>") {
            result = translator.rule_List_E1_Exp(attributes[0]);
        }
        else if (left == "<List_E1>" && right.size() == 3 && right[0] == "<<" && right[1] == "<E>" && right[2] == "<List_E1>") {
            result = translator.rule_List_E1_shiftl_E_List_E1(attributes[1], attributes[2]);
        }
        else if (left == "<Exp>" && right.size() == 2 && right[0] == "<<" && right[1] == "<E>") {
            result = translator.rule_Exp_shiftl_E(attributes[1]);
        }
        else if (left == "<Oper>" && right.size() == 1 && right[0] == "L:") {
            result = translator.rule_Oper_L_colon(attributes[0]);
        }
        else if (left == "<Oper>" && right.size() == 2 && right[0] == "<Jump>" && right[1] == ";") {
            result = translator.rule_Oper_Jump_semicolon(attributes[0]);
        }
        else if (left == "<Jump>" && right.size() == 2 && right[0] == "jump" && right[1] == "L") {
            result = translator.rule_Jump_jump_L(attributes[1]);
        }
        else if (left == "<Oper>" && right.size() == 3 && right[0] == "<Switch_1>" && right[1] == "end" && right[2] == ";") {
            result = translator.rule_Oper_Switch_1_end(attributes[0]);
            }
        else if (left == "<Oper>" && right.size() == 4 && right[0] == "<Switch_1>" && right[1] == "<Other>" &&
            right[2] == "end" && right[3] == ";") {
            result = translator.rule_Oper_Switch_1_Other_end(attributes[0], attributes[1]);
            }
        else if (left == "<Switch_1>" && right.size() == 2 && right[0] == "<Switch_2>" && right[1] == "<When1>") {
            result = translator.rule_Switch_1_Switch_2_When1(attributes[0], attributes[1]);
            }
        else if (left == "<Switch_2>" && right.size() == 4 && right[0] == "switch" && right[1] == "(" &&
            right[2] == "<E>" && right[3] == ")") {
            result = translator.rule_Switch_2_switch_lpar_E_rpar(attributes[2]);
            }
        else if (left == "<When1>" && right.size() == 2 && right[0] == "<When3>" && right[1] == "<When1>") {
            result = translator.rule_When1_When3_When1(attributes[0], attributes[1]);
            }
        else if (left == "<When1>" && right.size() == 1 && right[0] == "<When3>") {
            result = translator.rule_When1_When3(attributes[0]);
            }
        else if (left == "<When3>" && right.size() == 3 && right[0] == "<When>" && right[1] == ":" && right[2] == "<Prog>") {
            result = translator.rule_When3_When_colon_Prog(attributes[0], attributes[2]);
            }
        else if (left == "<When>" && right.size() == 2 && right[0] == "when" && right[1] == "C") {
            result = translator.rule_When_when_C(attributes[1] );
            }
        else if (left == "<When>" && right.size() == 2 && right[0] == "<When2>" && right[1] == "C") {
            result = translator.rule_When_When2_C(attributes[0], attributes[1]);
            }
        else if (left == "<When2>" && right.size() == 2 && right[0] == "<When>" && right[1] == ",") {
            result = translator.rule_When2_When_comma(attributes[0]);
            }
        else if (left == "<Other>" && right.size() == 2 && right[0] == "otherwise" && right[1] == "<Prog>") {
            result = translator.rule_Other_otherwise_Prog(attributes[1]);
            }
        else if (left == "<Test>" && right.size() == 3 && right[0] == "<E>" && right[1] == "rel" && right[2] == "<E>") {
            result = translator.rule_Test_E_rel_E(attributes[0], attributes[1], attributes[2]);
        }
        else if (left == "<Comma>" && right.size() == 1 && right[0] == ",") {
            result = translator.rule_Comma_comma();
        }
        else if (left == "<Oper>" && right.size() == 2 && right[0] == "throw" && right[1] == ";") {
            result = translator.rule_Oper_throw_semicolon();
        }
        else if (left == "<Oper>" && right.size() == 1 && right[0] == "rem") {
            result = translator.rule_Oper_rem();
        }
        else if (left == "<E>" && right.size() == 2 && right[0] == "<T>" && right[1] == "<E'>") {
            result = translator.rule_E_T_Eprime(attributes[0], attributes[1]);
        }
        else if (left == "<E>" && right.size() == 1 && right[0] == "<T>") {
            result = translator.rule_E_T(attributes[0]);
        }
        else if (left == "<E'>" && right.size() == 3 && right[0] == "+" && right[1] == "<T>" && right[2] == "<E'>") {
            result = translator.rule_Eprime_plus_T_Eprime(attributes[1], attributes[2]);
        }
        else if (left == "<E'>" && right.size() == 3 && right[0] == "-" && right[1] == "<T>" && right[2] == "<E'>") {
            result = translator.rule_Eprime_minus_T_Eprime(attributes[1], attributes[2]);
        }
        else if (left == "<E'>" && right.size() == 2 && right[0] == "+" && right[1] == "<T>") {
            result = translator.rule_Eprime_plus_T(attributes[1]);
        }
        else if (left == "<E'>" && right.size() == 2 && right[0] == "-" && right[1] == "<T>") {
            result = translator.rule_Eprime_minus_T(attributes[1]);
        }
        else if (left == "<T>" && right.size() == 2 && right[0] == "<F>" && right[1] == "<T'>") {
            result = translator.rule_T_F_Tprime(attributes[0], attributes[1]);
        }
        else if (left == "<T>" && right.size() == 1 && right[0] == "<F>") {
            result = translator.rule_T_F(attributes[0]);
        }
        else if (left == "<T'>" && right.size() == 3 && right[0] == "*" && right[1] == "<F>" && right[2] == "<T'>") {
            result = translator.rule_Tprime_star_F_Tprime(attributes[1], attributes[2]);
        }
        else if (left == "<T'>" && right.size() == 3 && right[0] == "/" && right[1] == "<F>" && right[2] == "<T'>") {
            result = translator.rule_Tprime_slash_F_Tprime(attributes[1], attributes[2]);
        }
        else if (left == "<T'>" && right.size() == 3 && right[0] == "%" && right[1] == "<F>" && right[2] == "<T'>") {
            result = translator.rule_Tprime_percent_F_Tprime(attributes[1], attributes[2]);
        }
        else if (left == "<T'>" && right.size() == 3 && right[0] == "&" && right[1] == "<F>" && right[2] == "<T'>") {
            result = translator.rule_Tprime_ampersand_F_Tprime(attributes[1], attributes[2]);
        }
        else if (left == "<T'>" && right.size() == 2 && right[0] == "*" && right[1] == "<F>") {
            result = translator.rule_Tprime_star_F(attributes[1]);
        }
        else if (left == "<T'>" && right.size() == 2 && right[0] == "/" && right[1] == "<F>") {
            result = translator.rule_Tprime_slash_F(attributes[1]);
        }
        else if (left == "<T'>" && right.size() == 2 && right[0] == "%" && right[1] == "<F>") {
            result = translator.rule_Tprime_percent_F(attributes[1]);
        }
        else if (left == "<T'>" && right.size() == 2 && right[0] == "&" && right[1] == "<F>") {
            result = translator.rule_Tprime_ampersand_F(attributes[1]);
        }
        else if (left == "<F>" && right.size() == 1 && right[0] == "V") {
            result = translator.rule_F_V(attributes[0]);
        }
        else if (left == "<F>" && right.size() == 1 && right[0] == "C") {
            result = translator.rule_F_C(attributes[0]);
        }
        else if (left == "<F>" && right.size() == 3 && right[0] == "(" && right[1] == "<E>" && right[2] == ")") {
            result = translator.rule_F_lpar_E_rpar(attributes[1]);
        }
        else if (left == "<F>" && right.size() == 5 && right[0] == "shiftl" && right[1] == "(" &&
            right[2] == "<E>" && right[3] == "<Comma>" && right[4] == "<E_brace>") {
            result = translator.rule_F_shiftl_lpar_E_Comma_E_brace(attributes[2], attributes[4]);
        }
        else if (left == "<F>" && right.size() == 5 && right[0] == "shiftr" && right[1] == "(" &&
            right[2] == "<E>" && right[3] == "<Comma>" && right[4] == "<E_brace>") {
            result = translator.rule_F_shiftr_lpar_E_Comma_E_brace(attributes[2], attributes[4]);
        }
        else if (left == "<F>" && right.size() == 5 && right[0] == "concat" && right[1] == "(" &&
            right[2] == "<E>" && right[3] == "<Comma>" && right[4] == "<E_brace>") {
            result = translator.rule_F_concat_lpar_E_Comma_E_brace(attributes[2], attributes[4]);
        }
        else if (left == "<F>" && right.size() == 5 && right[0] == "subvec" && right[1] == "(" &&
            right[2] == "<E>" && right[3] == "<Comma>" && right[4] == "<E_brace'>") {
            result = translator.rule_F_subvec_lpar_E_Comma_E_brace_prime(attributes[2], attributes[4]);
        }
        else if (left == "<E_brace'>" && right.size() == 3 && right[0] == "<E>" && right[1] == "<Comma>" && right[2] == "<E_brace>") {
            result = translator.rule_E_brace_prime_E_Comma_E_brace(attributes[0], attributes[2]);
        }
        else if (left == "<E_brace>" && right.size() == 2 && right[0] == "<E>" && right[1] == ")") {
            result = translator.rule_E_brace_E_rpar(attributes[0]);
        }
        // Для неподдерживаемых правил возвращаем объединенный код
        else {
            for (const auto& attr : attributes) {
                result.code += attr.code;
            }
            // Можно добавить отладочное сообщение
            cout << "Warning: No semantic action for rule " << left << " -> ";
            for (const auto& sym : right) {
                cout << sym << " ";
            }
            cout << endl;
        }
        return result;
    }
};
