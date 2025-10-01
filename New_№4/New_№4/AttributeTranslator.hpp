// AttributeTranslator.hpp
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Lexical_Analyzator.hpp"
#include "SymbolTable.hpp"
#include "Creat_Table.hpp"
#include "Warning_Situations.hpp"
using namespace std;
// Структура для хранения атрибутов символов грамматики
struct Attribute {
    string code;        // Сгенерированный код
    string type;        // Тип данных (int, vector, etc.)
    string value;       // Значение (для констант и переменных)
    string name;        // Имя (для идентификаторов)
    string temp_var;    // Временная переменная
    string label;       // Метка для переходов
    Vector vectorValue; // векторное значение
    int line_number;    //Номер строки
    // Для хранения нескольких атрибутов
    string code2;
    string code3;
    string code4;
    string type2;
    string value2;

    string end_label;   // Метка конца switch
    string next_label;  // Метка для следующего условия

    vector<string> variable_list;

    Attribute() : line_number(-1) {}

    Attribute(const string& code, const string& type = "", const string& value = "",
        const string& name = "", const string& temp_var = "", int line = -1)
        : code(code), type(type), value(value), name(name), temp_var(temp_var), line_number(line) {
    }
};

void Warning_Lable(vector<string> labl_, vector<string> Labl_jm)
{
    if (Find_pars_lables(lable_, lable_jump_) == "size")
    {
        string error_msg = "There are not an pare lable";
        throw runtime_error(error_msg);
    }
    if (Find_pars_lables(lable_, lable_jump_) == "good")
        return;
    else
    {
        string error_msg = "Lable " + Find_pars_lables(lable_, lable_jump_) + " don't have pars";
        throw runtime_error(error_msg);
    }
}
class AttributeTranslator
{
private:
    int temp_counter;      // Счетчик для генерации временных переменных
    int label_counter;     // Счетчик для генерации меток
    SymbolTable symbolTable;

    // Стек для хранения контекста switch (для вложенных switch)
    stack<string> temp_var_stack;
    stack<string> end_label_stack;


public:
    AttributeTranslator() : temp_counter(0), label_counter(0) {}
    Attribute createAttributeFromLexeme(const Lexeme& lexeme)
    {
        Attribute attr;
        attr.name = lexeme.token_name;
        if (lexeme.token_value != nullptr)
        {
            if (std::holds_alternative<int>(*lexeme.token_value))
            {
                attr.value = to_string(get<int>(*lexeme.token_value));
            }
            else if (std::holds_alternative<Vector>(*lexeme.token_value))
            {
                attr.value = get<Vector>(*lexeme.token_value).output();
            }
        }
        attr.line_number = lexeme.token_str;

        // Определение типа лексемы
        switch (lexeme.token_class) {
        case 9:attr.type = "rel";
            attr.value = "rel";
            attr.type2 = "=";
            break;
        case 10:
            attr.type2 = "!=";
            attr.value = "rel";
            attr.type = "rel";
            break;
        case 11:
            attr.type2 = ">=";
            attr.type = "rel";
            attr.value = "rel";
            break;
        case 12:
            attr.type2 = "<=";
            attr.type = "rel";
            attr.value = "rel";
            break;
        case 18:
            attr.type2 = ">";
            attr.type = "rel";
            attr.value = "rel";
            break;
        case 19:
            attr.type2 = "<";
            attr.type = "rel";
            attr.value = "rel";
            break;
        case 31: // C2 - константа (vector)
            attr.type = "vector";
            attr.value = lexeme.token_name;
            break;
        case 37: // int
            attr.type = "int";
            break;
        case 38: // vector (тип)
            attr.type = "vector";
            break;
        case 39: // L (метка)
            attr.type = "label";
            attr.label = lexeme.token_name;
            break;
        case 45: // C (константа int)
            attr.type = "int";
            break;
        case 41: // V (переменная)
            attr.name = lexeme.token_name;
            attr.type = "unknown";
            break;
        default:
            attr.type = "unknown";
        }

        return attr;
    }

    // Генерация новой временной переменной
    string generateTempVar(const string& type = "int") {
        string temp_name = "t" + to_string(temp_counter++);
        symbolTable.addSymbol(temp_name, type);
        return temp_name;
    }

    // Семантические действия для правил грамматики

// В класс AttributeTranslator добавляем следующие методы:
    // Правило: <S> -> <Ob> <Prog>
    Attribute rule_S_Ob_Prog(const Attribute& ob_attr, const Attribute& prog_attr) {
        Attribute result;
        // Объединяем код объявлений и основной программы
        result.code = ob_attr.code + prog_attr.code;

        return result;
    }

    // Правило: <S> -> <Prog>
    Attribute rule_S_Prog(const Attribute& prog_attr) {
        return prog_attr;
    }
    // Правило: <Prog> -> <Oper> <Prog>
    Attribute rule_Prog_Oper_Prog(const Attribute& oper_attr, const Attribute& prog_attr) {
        Attribute result;
        result.code = oper_attr.code + prog_attr.code;
        return result;
    }

    // Правило: <Prog> -> <Oper>
    Attribute rule_Prog_Oper(const Attribute& oper_attr) {
        return oper_attr;
    }

    // Правило: <Ob> -> <Ob> <Ob2>
    Attribute rule_Ob_Ob_Ob2(const Attribute& ob_attr, const Attribute& ob2_attr) {
        Attribute result;
        result.code = ob_attr.code + ob2_attr.code;
        return result;
    }

    // Правило: <Ob> -> <Ob2>
    Attribute rule_Ob_Ob2(const Attribute& ob2_attr) {
        return ob2_attr;
    }

    // <Ob2> -> <Ob3> : <Type> ;
    Attribute rule_Ob2_Ob3_Type(const Attribute& ob3_attr, const Attribute& type_attr) {
        Attribute result;

        // Разбираем список переменных
        vector<string> variables;
        stringstream ss(ob3_attr.name);
        string var;
        while (getline(ss, var, ',')) {
            // Удаляем пробелы вокруг имени переменной
            var.erase(remove_if(var.begin(), var.end(), ::isspace), var.end());
            if (!var.empty()) {
                variables.push_back(var);
            }
        }

        // Объявляем переменные и генерируем код инициализации
        for (const auto& var_name : variables) {
            try {
                symbolTable.addSymbol(var_name, type_attr.type);

                if (type_attr.type == "int") {
                    result.code += "push 0\n";
                    result.code += "pop " + var_name + "\n";
                }
                else if (type_attr.type == "vector") {
                    result.code += "push [0]\n";
                    result.code += "pop " + var_name + "\n";
                }
            }
            catch (const runtime_error& e) {
                // Добавляем информацию о строке к ошибке
                string error_msg = e.what();
                if (ob3_attr.line_number != -1) {
                    error_msg += " at line " + to_string(ob3_attr.line_number);
                }
                throw runtime_error(error_msg);
            }
        }

        return result;
    }

    // <Ob3> -> dim V
    Attribute rule_Ob3_dim_V(const Attribute& v_attr) {
        Attribute result;
        result.name = v_attr.name;
        return result;
    }

    // <Ob3> -> <Ob4> V
    Attribute rule_Ob3_Ob4_V(const Attribute& ob4_attr, const Attribute& v_attr) {
        Attribute result;
        if (ob4_attr.name.empty()) {
            result.name = v_attr.name;
        }
        else {
            result.name = ob4_attr.name + "," + v_attr.name;
        }
        return result;
    }

    // <Ob4> -> <Ob3> ,
    Attribute rule_Ob4_Ob3_comma(const Attribute& ob3_attr) {
        return ob3_attr;
    }

    // Правило: <Type> -> int
    Attribute rule_Type_int() {
        Attribute result;
        result.type = "int";
        return result;
    }

    // Правило: <Type> -> vector
    Attribute rule_Type_vector() {
        Attribute result;
        result.type = "vector";
        return result;
    }

    // <Oper> -> ;
    Attribute rule_Oper_semicolon() {
        return Attribute(); // Пустой оператор
    }

    // Правило: <Oper> -> <Prisv> ;
    Attribute rule_Oper_Prisv_semicolon(const Attribute& prisv_attr) {
        return prisv_attr;
    }

    // <Prisv> -> <Prisv2> = <E>
    Attribute rule_Prisv_Prisv2_equal_E(const Attribute& prisv2_attr, const Attribute& e_attr) {
        Attribute result;
        result.line_number = prisv2_attr.line_number;

        // Разбираем список переменных для присваивания
        vector<string> variables;
        stringstream ss(prisv2_attr.name);
        string var;
        while (getline(ss, var, ',')) {
            var.erase(remove_if(var.begin(), var.end(), ::isspace), var.end());
            if (!var.empty()) {
                variables.push_back(var);
            }
        }

        // Проверяем, что все переменные объявлены
        for (const auto& var_name : variables) {
            if (!symbolTable.exists(var_name)) {
                string error_msg = "Variable '" + var_name + "' is not declared";
                if (result.line_number != -1) {
                    error_msg += " at line " + to_string(result.line_number);
                }
                throw runtime_error(error_msg);
            }
        }

        // Проверка типов для всех переменных
        for (const auto& var_name : variables) {
            string var_type = symbolTable.getType(var_name);
            if (var_type != e_attr.type) {
                string error_msg = "Type mismatch in assignment: cannot assign " +
                    e_attr.type + " to variable '" + var_name + "' of type " + var_type;
                if (result.line_number != -1) {
                    error_msg += " at line " + to_string(result.line_number);
                }
                throw runtime_error(error_msg);
            }
        }

        // Генерация кода присваивания
        if (variables.size() == 1) {
            result.code = e_attr.code + "pop " + variables[0] + "\n";
        }
        else {
            string temp = generateTempVar(e_attr.type);
            result.code = e_attr.code + "pop " + temp + "\n";
            for (const auto& var_name : variables) {
                result.code += "push " + temp + "\n";
                result.code += "pop " + var_name + "\n";
            }
        }

        return result;
    }

    // <Prisv2> -> set V
    Attribute rule_Prisv2_set_V(const Attribute& v_attr) {
        Attribute result;

        // Проверяем, что переменная объявлена
        if (!symbolTable.exists(v_attr.name)) {
            string error_msg = "Variable '" + v_attr.name + "' is not declared";
            if (v_attr.line_number != -1) {
                error_msg += " at line " + to_string(v_attr.line_number);
            }
            throw runtime_error(error_msg);
        }

        result.name = v_attr.name;
        result.type = symbolTable.getType(v_attr.name); // Получаем тип из таблицы символов
        result.line_number = v_attr.line_number;

        return result;
    }

    // <Prisv2> -> <Prisv3> V
    Attribute rule_Prisv2_Prisv3_V(const Attribute& prisv3_attr, const Attribute& v_attr) {
        Attribute result;
        if (prisv3_attr.name.empty()) {
            result.name = v_attr.name;
        }
        else {
            result.name = prisv3_attr.name + "," + v_attr.name;
        }
        result.type = v_attr.type;
        return result;
    }

    // <Prisv3> -> <Prisv2> ,
    Attribute rule_Prisv3_Prisv2_comma(const Attribute& prisv2_attr) {
        return prisv2_attr;
    }

    // Правило: <Oper> -> <For_1> end ;
    Attribute rule_Oper_For_1_end_semicolon(const Attribute& for1_attr) {
        return for1_attr;
    }

    // <For_1> -> <For_2> do <Prog>
    Attribute rule_For_1_For_2_do_Prog(const Attribute& for2_attr, const Attribute& prog_attr) {
        Attribute result;
        string m1 = generateLabel();
        string m2 = generateLabel();

        result.code = for2_attr.code2 + // инициализация итератора
            "pop " + for2_attr.name + "\n" +
            "label " + m1 + "\n" +
            "push " + for2_attr.name + "\n" +
            for2_attr.code + // верхняя граница
            ">\n" +
            "ji " + m2 + "\n" +
            prog_attr.code + // тело цикла
            "push " + for2_attr.name + "\n" +
            for2_attr.code3 + // инкремент
            "push 1\n" +
            "+\n" +
            "pop " + for2_attr.name + "\n" +
            "jmp " + m1 + "\n" +
            "label " + m2 + "\n";
        return result;
    }
    // <For_2> -> for each V in <E>
    Attribute rule_For_2_for_each_V_in_E(const Attribute& v_attr, const Attribute& e_attr) {
        Attribute result;
        result.line_number = v_attr.line_number;

        // Проверяем, что переменная объявлена
        if (!symbolTable.exists(v_attr.name)) {
            string error_msg = "Variable '" + v_attr.name + "' is not declared";
            if (result.line_number != -1) {
                error_msg += " at line " + to_string(result.line_number);
            }
            throw runtime_error(error_msg);
        }

        // Проверка типов
        string var_type = symbolTable.getType(v_attr.name);
        if (var_type != "int" || e_attr.type != "int") {
            string error_msg = "Type mismatch in for each loop: expected int types";
            if (result.line_number != -1) {
                error_msg += " at line " + to_string(result.line_number);
            }
            throw runtime_error(error_msg);
        }

        result.name = v_attr.name;
        result.code = e_attr.code;
        result.code2 = "push 0\n";
        result.code3 = "";

        return result;
    }

    // Правило: <Oper> -> <While> end ;
    Attribute rule_Oper_While_end_semicolon(const Attribute& while_attr) {
        return while_attr;
    }

    // <While> -> while <Test> do <Prog>
    Attribute rule_While_while_Test_do_Prog(const Attribute& test_attr, const Attribute& prog_attr) {
        Attribute result;
        string m1 = generateLabel();
        string m2 = generateLabel();

        result.code = "label " + m1 + "\n" +
            test_attr.code +
            "ji " + m2 + "\n" +
            prog_attr.code +
            "jmp " + m1 + "\n" +
            "label " + m2 + "\n";
        return result;
    }

    // <Oper> -> <If_1> end ;
    Attribute rule_Oper_If_1_end_semicolon(const Attribute& if1_attr) {
        Attribute result;
        string m = generateLabel();

        result.code = if1_attr.code + // условие
            "ji " + m + "\n" +
            if1_attr.code2 + // then часть
            "label " + m + "\n";       
        return result;
    }
    // <Oper> -> <If_1> <Else> end ;
    Attribute rule_Oper_If_1_Else_end_semicolon(const Attribute& if1_attr, const Attribute& else_attr) {
        Attribute result;
        string m1 = generateLabel();
        string m2 = generateLabel();

        result.code = if1_attr.code + // условие
            "ji " + m1 + "\n" +
            if1_attr.code2 + // then часть
            "jmp " + m2 + "\n" +
            "label " + m1 + "\n" +
            else_attr.code + // else часть
            "label " + m2 + "\n";
        return result;
    }

    // <If_1> -> if <Test> then <Prog>
    Attribute rule_If_1_if_Test_then_Prog(const Attribute& test_attr, const Attribute& prog_attr) {
        Attribute result;
        result.code = test_attr.code;  // условие
        result.code2 = prog_attr.code; // then часть
        return result;
    }

    // <Else> -> else <Prog>
    Attribute rule_Else_else_Prog(const Attribute& prog_attr) {
        return prog_attr;
    }

    // Правило: <Oper> -> <Cin> ;
    Attribute rule_Oper_Cin_semicolon(const Attribute& cin_attr) {
        return cin_attr;
    }

    // <Cin> -> cin <List_V1>
    Attribute rule_Cin_cin_List_V1(const Attribute& list_attr) {
        Attribute result;
        result.code = "read\n" + list_attr.code;
        return result;
    }

    // <List_V1> -> >> V <List_V1>
    Attribute rule_List_V1_shiftr_V_List_V1(const Attribute& v_attr, const Attribute& list_attr) {
        Attribute result;
        result.code = "pop " + v_attr.name + "\n" + list_attr.code;
        return result;
    }
    // <List_V1> -> >> V
    Attribute rule_List_V1_shiftr_V(const Attribute& v_attr) {
        Attribute result;
        result.code = "pop " + v_attr.name + "\n";
        return result;
    }

    // Правило: <Oper> -> <Output> ;
    Attribute rule_Oper_Output_semicolon(const Attribute& output_attr) {
        return output_attr;
    }

    // <Output> -> cout <List_E1>
    Attribute rule_Output_cout_List_E1(const Attribute& list_attr) {
        Attribute result;
        result.code = list_attr.code;
        return result;
    }

    // Правило: <List_E1> -> <Exp>
    Attribute rule_List_E1_Exp(const Attribute& exp_attr) {
        return exp_attr;
    }

    // <List_E1> -> << <E> <List_E1>
    Attribute rule_List_E1_shiftl_E_List_E1(const Attribute& e_attr, const Attribute& list_attr) {
        Attribute result;
        result.code = e_attr.code + "write\n" + list_attr.code;
        return result;
    }

    // <Exp> -> << <E>
    Attribute rule_Exp_shiftl_E(const Attribute& e_attr) {
        Attribute result;
        result.code = e_attr.code + "write\n";
        return result;
    }

    // <Oper> -> L:
    Attribute rule_Oper_L_colon(const Attribute& l_attr) {
        Attribute result;
        string l = l_attr.name;
        l.pop_back();
        result.code = "label " + l + "\n";
        return result;
    }

    // Правило: <Oper> -> <Jump> ;
    Attribute rule_Oper_Jump_semicolon(const Attribute& jump_attr) {
        return jump_attr;
    }

    // <Jump> -> jump L
    Attribute rule_Jump_jump_L(const Attribute& l_attr) {
        Attribute result;
        result.code = "jmp " + l_attr.label + "\n";
        return result;
    }


    // <Oper> -> <Switch_1> end ;
    Attribute rule_Oper_Switch_1_end(const Attribute& switch1_attr) {
        Attribute result;
        // Добавляем метку конца switch после всех веток
        result.code = switch1_attr.code + "label " + switch1_attr.end_label + "\n";

        // Удаляем контекст switch из стека
        if (!temp_var_stack.empty()) temp_var_stack.pop();
        if (!end_label_stack.empty()) end_label_stack.pop();

        return result;
    }

    // <Oper> -> <Switch_1> <Other> end ;
    Attribute rule_Oper_Switch_1_Other_end(const Attribute& switch1_attr, const Attribute& other_attr) {
        Attribute result;
        // Объединяем код switch, otherwise и добавляем метку конца
        result.code = switch1_attr.code + other_attr.code + "label " + switch1_attr.end_label + "\n";

        // Удаляем контекст switch из стека
        if (!temp_var_stack.empty()) temp_var_stack.pop();
        if (!end_label_stack.empty()) end_label_stack.pop();

        return result;
    }

    // <Switch_1> -> <Switch_2> <When1>
    Attribute rule_Switch_1_Switch_2_When1(const Attribute& switch2_attr, const Attribute& when1_attr) {
        Attribute result;

        // Объединяем код вычисления выражения и код всех веток
        result.code = switch2_attr.code + when1_attr.code;
        result.end_label = switch2_attr.end_label;

        return result;
    }

    // <Switch_2> -> switch ( <E> )
    Attribute rule_Switch_2_switch_lpar_E_rpar(const Attribute& e_attr) {
        Attribute result;

        // Проверка типа
        if (e_attr.type != "int") {
            throw runtime_error("Switch expression must be of type int");
        }

        // Сохраняем выражение во временную переменную
        string temp_var = generateTempVar("int");
        result.code = e_attr.code + "pop " + temp_var + "\n";
        result.end_label = generateLabel();

        // Сохраняем контекст switch в стек
        temp_var_stack.push(temp_var);
        end_label_stack.push(result.end_label);

        return result;
    }

    // <When1> -> <When3> <When1>
    Attribute rule_When1_When3_When1(const Attribute& when3_attr, const Attribute& when1_attr) {
        Attribute result;

        // Объединяем код текущей ветки и следующих веток
        result.code = when3_attr.code + when1_attr.code;
        result.end_label = when1_attr.end_label;

        return result;
    }

    // <When1> -> <When3>
    Attribute rule_When1_When3(const Attribute& when3_attr) {
        Attribute result;

        // Просто возвращаем код ветки
        result.code = when3_attr.code;
        result.end_label = when3_attr.end_label;

        return result;
    }

    // <When3> -> <When> : <Prog>
    Attribute rule_When3_When_colon_Prog(const Attribute& when_attr, const Attribute& prog_attr) {
        Attribute result;

        if (temp_var_stack.empty() || end_label_stack.empty()) {
            throw runtime_error("Switch context not found");
        }

        string end_label = end_label_stack.top();

        // Объединяем код проверки условий и код тела
        result.code = when_attr.code +                    // Код проверки условий
            prog_attr.code +                     // Код тела ветки
            "jmp " + end_label + "\n" +          // Переход в конец после выполнения тела
            "label " + when_attr.next_label + "\n"; // Метка для следующей проверки

        result.end_label = end_label;

        return result;
    }

    // <When> -> when C
    Attribute rule_When_when_C(const Attribute& c_attr) {
        Attribute result;

        if (temp_var_stack.empty() || end_label_stack.empty()) {
            throw runtime_error("Switch context not found");
        }

        string temp_var = temp_var_stack.top();
        string end_label = end_label_stack.top();

        string case_label = generateLabel();
        string next_case = generateLabel();

        // Генерируем проверку условия
        result.code = "push " + temp_var + "\n" +         // Выражение switch
            "push " + c_attr.value + "\n" +     // Значение для сравнения
            "==\n" +                            // Сравнение
            "ji " + case_label + "\n" +         // Условный переход на тело case
            "jmp " + next_case + "\n" +         // Безусловный переход на следующий case
            "label " + case_label + "\n";       // Метка начала тела case

        result.next_label = next_case;

        return result;
    }

    // <When> -> <When2> C
    Attribute rule_When_When2_C(const Attribute& when2_attr, const Attribute& c_attr) {
        Attribute result;

        if (temp_var_stack.empty() || end_label_stack.empty()) {
            throw runtime_error("Switch context not found");
        }

        string temp_var = temp_var_stack.top();
        string end_label = end_label_stack.top();

        string case_label = generateLabel();

        // Используем код из предыдущих условий и добавляем новое
        result.code = when2_attr.code +                      // Код предыдущих проверок
            "push " + temp_var + "\n" +            // Выражение switch
            "push " + c_attr.value + "\n" +        // Новое значение для сравнения
            "==\n" +                               // Сравнение
            "ji " + case_label + "\n" +            // Условный переход на тело case
            "jmp " + when2_attr.next_label + "\n" + // Переход к следующему условию
            "label " + case_label + "\n";          // Метка начала тела case

        result.next_label = when2_attr.next_label;

        return result;
    }

    // <When2> -> <When> ,
    Attribute rule_When2_When_comma(const Attribute& when_attr) {
        Attribute result;

        // Просто передаем атрибуты дальше
        result.code = when_attr.code;
        result.next_label = when_attr.next_label;

        return result;
    }

    // <Other> -> otherwise <Prog>
    Attribute rule_Other_otherwise_Prog(const Attribute& prog_attr) {
        Attribute result;

        // Ветка otherwise - просто выполняем код
        result.code = prog_attr.code;

        return result;
    }

    // <Test> -> <E> rel <E>
    Attribute rule_Test_E_rel_E(const Attribute& e1_attr, const Attribute& rel_attr, const Attribute& e2_attr) {
        Attribute result;
        result.line_number = e1_attr.line_number;

        // Проверка типов
        if (e1_attr.type != e2_attr.type) {
            string error_msg = "Type mismatch in comparison: cannot compare " + e1_attr.type + " with " + e2_attr.type;
            if (result.line_number != -1) {
                error_msg += " at line " + to_string(result.line_number);
            }
            throw runtime_error(error_msg);
        }

        string op;
        if (rel_attr.type2 == "!=") op = "!=";
        else if (rel_attr.type2 == ">=") op = ">=";
        else if (rel_attr.type2 == "<=") op = "<=";
        else if (rel_attr.type2 == ">") op = ">";
        else if (rel_attr.type2 == "<") op = "<";
        else op = rel_attr.type2;

        result.code = e1_attr.code + e2_attr.code + op + "\n";
        result.type = "bool";
        return result;
    }

    // Правило: <Comma> -> ,
    Attribute rule_Comma_comma() {
        return Attribute();
    }

    // Правило: <Oper> -> throw ;
    Attribute rule_Oper_throw_semicolon() {
        Attribute result;
        result.code = "throw;\n";
        return result;
    }

    // Правило: <Oper> -> rem
    Attribute rule_Oper_rem() {
        Attribute result;
        result.code = "rem\n";
        return result;
    }

    // <E> -> <T> <E'>
    Attribute rule_E_T_Eprime(const Attribute& t_attr, const Attribute& eprime_attr) {
        Attribute result;
        result.line_number = t_attr.line_number;

        if (eprime_attr.code.empty()) {
            result = t_attr;
        }
        else {
            // Проверка типов
            if (t_attr.type != eprime_attr.type) {
                string error_msg = "Type mismatch in expression: cannot operate on " + t_attr.type + " and " + eprime_attr.type;
                if (result.line_number != -1) {
                    error_msg += " at line " + to_string(result.line_number);
                }
                throw runtime_error(error_msg);
            }
            result.type = t_attr.type;
            result.temp_var = generateTempVar(result.type);
            result.code = t_attr.code + eprime_attr.code;
            result.code += result.temp_var + " = " + t_attr.temp_var + " " + eprime_attr.temp_var + ";\n";
        }
        return result;
    }

    // Правило: <E> -> <T>
    Attribute rule_E_T(const Attribute& t_attr) {
        return t_attr;
    }

    // <E'> -> + <T> <E'>
    Attribute rule_Eprime_plus_T_Eprime(const Attribute& t_attr, const Attribute& eprime_attr) {
        Attribute result;
        string temp = generateTempVar(t_attr.type);
        result.code = t_attr.code + eprime_attr.code;
        result.code += temp + " = " + t_attr.temp_var + " " + eprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <E'> -> - <T> <E'>
    Attribute rule_Eprime_minus_T_Eprime(const Attribute& t_attr, const Attribute& eprime_attr) {
        Attribute result;
        string temp = generateTempVar(t_attr.type);
        result.code = t_attr.code + eprime_attr.code;
        result.code += temp + " = " + t_attr.temp_var + " " + eprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <E'> -> + <T>
    Attribute rule_Eprime_plus_T(const Attribute& t_attr) {
        Attribute result;
        result.temp_var = "+ " + t_attr.temp_var;
        result.code = t_attr.code;
        return result;
    }

    // Правило: <E'> -> - <T>
    Attribute rule_Eprime_minus_T(const Attribute& t_attr) {
        Attribute result;
        result.temp_var = "- " + t_attr.temp_var;
        result.code = t_attr.code;
        return result;
    }

    // Правило: <T> -> <F> <T'>
    Attribute rule_T_F_Tprime(const Attribute& f_attr, const Attribute& tprime_attr) {
        Attribute result;
        if (tprime_attr.code.empty()) {
            return f_attr;
        }
        else {
            result.type = f_attr.type;
            result.temp_var = generateTempVar(result.type);
            result.code = f_attr.code + tprime_attr.code;

            string op = extractOperator(tprime_attr.temp_var);
            string right_operand = extractOperand(tprime_attr.temp_var);

            result.code += result.temp_var + " = " + f_attr.temp_var + " " + op + " " + right_operand + ";\n";
            return result;
        }
    }

    // Правило: <T> -> <F>
    Attribute rule_T_F(const Attribute& f_attr) {
        return f_attr;
    }

    // Правило: <T'> -> * <F> <T'>
    Attribute rule_Tprime_star_F_Tprime(const Attribute& f_attr, const Attribute& tprime_attr) {
        Attribute result;
        string temp = generateTempVar(f_attr.type);
        result.code = f_attr.code + tprime_attr.code;
        result.code += temp + " = " + f_attr.temp_var + " " + tprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <T'> -> / <F> <T'>
    Attribute rule_Tprime_slash_F_Tprime(const Attribute& f_attr, const Attribute& tprime_attr) {
        Attribute result;
        string temp = generateTempVar(f_attr.type);
        result.code = f_attr.code + tprime_attr.code;
        result.code += temp + " = " + f_attr.temp_var + " " + tprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <T'> -> % <F> <T'>
    Attribute rule_Tprime_percent_F_Tprime(const Attribute& f_attr, const Attribute& tprime_attr) {
        Attribute result;
        string temp = generateTempVar(f_attr.type);
        result.code = f_attr.code + tprime_attr.code;
        result.code += temp + " = " + f_attr.temp_var + " " + tprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <T'> -> & <F> <T'>
    Attribute rule_Tprime_ampersand_F_Tprime(const Attribute& f_attr, const Attribute& tprime_attr) {
        Attribute result;
        string temp = generateTempVar(f_attr.type);
        result.code = f_attr.code + tprime_attr.code;
        result.code += temp + " = " + f_attr.temp_var + " " + tprime_attr.temp_var + ";\n";
        result.temp_var = temp;
        return result;
    }

    // Правило: <T'> -> * <F>
    Attribute rule_Tprime_star_F(const Attribute& f_attr) {
        Attribute result;
        result.temp_var = "* " + f_attr.temp_var;
        result.code = f_attr.code;
        return result;
    }

    // Правило: <T'> -> / <F>
    Attribute rule_Tprime_slash_F(const Attribute& f_attr) {
        Attribute result;
        result.temp_var = "/ " + f_attr.temp_var;
        result.code = f_attr.code;
        return result;
    }

    // Правило: <T'> -> % <F>
    Attribute rule_Tprime_percent_F(const Attribute& f_attr) {
        Attribute result;
        result.temp_var = "% " + f_attr.temp_var;
        result.code = f_attr.code;
        return result;
    }

    // Правило: <T'> -> & <F>
    Attribute rule_Tprime_ampersand_F(const Attribute& f_attr) {
        Attribute result;
        result.temp_var = "& " + f_attr.temp_var;
        result.code = f_attr.code;
        return result;
    }

    // <F> -> V
    Attribute rule_F_V(const Attribute& v_attr) {
        Attribute result;

        // Проверяем, что переменная объявлена
        if (!symbolTable.exists(v_attr.name)) {
            string error_msg = "Variable '" + v_attr.name + "' is not declared";
            if (v_attr.line_number != -1) {
                error_msg += " at line " + to_string(v_attr.line_number);
            }
            throw runtime_error(error_msg);
        }

        // Получаем тип переменной из таблицы символов
        result.type = symbolTable.getType(v_attr.name);
        result.temp_var = v_attr.name;
        result.code = "push " + v_attr.name + "\n";
        result.line_number = v_attr.line_number;

        return result;
    }

    Attribute rule_F_C(const Attribute& c_attr) {
        Attribute result;

        if (c_attr.type == "int") {
            result.type = "int";
            result.code = "push " + c_attr.value + "\n";
            // Не используем временную переменную, потому что мы просто помещаем значение на стек
            // Временная переменная не нужна, т.к. мы не делаем вычислений, которые требуют временных переменных.
            // Присваивание заберет значение со стека.
        }
        else if (c_attr.type == "vector") {
            // Для векторных констант используем специальное правило
            return rule_F_C_vector(c_attr);
        }

        return result;
    }
    Attribute rule_F_C_vector(const Attribute& c_attr) {
        Attribute result;
        result.type = "vector";
        result.temp_var = generateTempVar("vector");


        Vector v = c_attr.vectorValue;
        result.code = "push " + v.output() + "\n";

        return result;
    }

    // Правило: <F> -> ( <E> )
    Attribute rule_F_lpar_E_rpar(const Attribute& e_attr) {
        return e_attr;
    }

    // <F> -> shiftl ( <E> <Comma> <E_brace>
    Attribute rule_F_shiftl_lpar_E_Comma_E_brace(const Attribute& e1_attr, const Attribute& e2_attr) {
        Attribute result;
        result.line_number = e1_attr.line_number;

        // Проверка типов
        if (e1_attr.type != "vector" && e2_attr.type != "int") {
            string error_msg = "Invalid argument types for shiftl function: expected vector and int";
            if (result.line_number != -1) {
                error_msg += " at line " + to_string(result.line_number);
            }
            throw runtime_error(error_msg);
        }

        result.temp_var = generateTempVar("vector");
        result.code = e1_attr.code + e2_attr.code;
        result.code += "shiftl\n";
        result.type = "vector";
        return result;
    }


    // <F> -> shiftr ( <E> <Comma> <E_brace>
    Attribute rule_F_shiftr_lpar_E_Comma_E_brace(const Attribute& e1_attr, const Attribute& e2_attr) {
        Attribute result;
        result.line_number = e1_attr.line_number;

        // Проверка типов
        if (e1_attr.type != "vector" && e2_attr.type != "int") {
            string error_msg = "Invalid argument types for shiftr function: expected vector and int";
            if (result.line_number != -1) {
                error_msg += " at line " + to_string(result.line_number);
            }
            throw runtime_error(error_msg);
        }

        result.temp_var = generateTempVar("vector");
        result.code = e1_attr.code + e2_attr.code;
        result.code += "shiftr\n";
        result.type = "vector";
        return result;
    }
    // <F> -> concat ( <E> <Comma> <E_brace>
    Attribute rule_F_concat_lpar_E_Comma_E_brace(const Attribute& e1_attr, const Attribute& e2_attr) {
        Attribute result;
        // Проверка типов
        if (e1_attr.type != "vector" && e2_attr.type != "vector") {
            throw runtime_error("Invalid argument types for concat function");
        }
        result.temp_var = generateTempVar("vector");
        result.code = e1_attr.code + e2_attr.code;
        result.code += "concat\n";
        result.type = "vector";
        return result;
    }

    // <F> -> subvec ( <E> <Comma> <E_brace'>
    Attribute rule_F_subvec_lpar_E_Comma_E_brace_prime(const Attribute& e1_attr, const Attribute& e2_attr) {
        Attribute result;
        // Проверка типов
        if (e1_attr.type != "vector" && e2_attr.type != "int" && e2_attr.type2 != "int") {
            throw runtime_error("Invalid argument types for subvec function");
        }
        result.temp_var = generateTempVar("vector");
        result.code = e1_attr.code + e2_attr.code + e2_attr.code2;
        result.code += "subvec\n";
        result.type = "vector";
        return result;
    }


    // <E_brace'> -> <E> <Comma> <E_brace>
    Attribute rule_E_brace_prime_E_Comma_E_brace(const Attribute& e1_attr, const Attribute& e2_attr) {
        Attribute result;
        result.temp_var = e1_attr.temp_var;
        result.code = e1_attr.code;
        result.type = e1_attr.type;
        result.code2 = e2_attr.code;
        result.type2 = e2_attr.type;
        return result;
    }

    // Правило: <E_brace> -> <E> )
    Attribute rule_E_brace_E_rpar(const Attribute& e_attr) {
        return e_attr;
    }

    // Вспомогательные методы
private:
    string extractOperator(const string& expression) {
        if (expression.find('+') != string::npos) return "+";
        if (expression.find('-') != string::npos) return "-";
        if (expression.find('*') != string::npos) return "*";
        if (expression.find('/') != string::npos) return "/";
        if (expression.find('%') != string::npos) return "%";
        if (expression.find('&') != string::npos) return "&";
        return "";
    }

    string extractOperand(const string& expression) {
        size_t pos = expression.find(' ');
        if (pos != string::npos) {
            return expression.substr(pos + 1);
        }
        return expression;
    }
};