#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <stack>
#include <variant>
#include <map>
#include <list>
#include "Vector.hpp"
enum SymbolicTokenClass { Symbol, Digit, Arithmetic, Comparison, EndOfLine, Semicolon, Space, Error, EndOfFile };

enum States {
    A1, /*??????*/
    Sy_B1, /*??? ???????*/
    Co_B2, /* < >*/
    Ar_A1, /*+,-,%,>=,<=.....*/
    Ar_B2, //??????

    Sy_L1, /*L*/
    Sy_J1,
    Sy_E1, /*end*/
    Sy_E3,
    Sy_E2,
    Sy_I1,
    Sy_I2,
    Sy_I3,
    Sy_W1,
    Sy_W2,
    Sy_C1,
    Sy_C2,
    Sy_C3,
    Sy_S1,
    Sy_S2,
    Sy_S3,
    Sy_S4,
    Sy_S5,
    Sy_T1,
    Sy_T2,
    Sy_R1,
    Sy_D1,
    Sy_D2,
    Sy_F1,
    Sy_V1,
    Sy_O1,
    Sy_Z60,// ?????????
    Sy_Z50,// ??????????

    Ar_C2,
    Ar_D2,
    Stop
};
struct SymbolicToken
{
    SymbolicTokenClass token_class; // ????? ???????.
    int value;                      // ???????? ???????.
    string value_c;
};
struct Lexeme
{
    int token_str;
    int token_class;
    string token_name;
    std::string token_message;
    std::variant<int, Vector>* token_value = nullptr;
};

struct Initial_vector
{
    char symbol;
    int detection;

};
struct Detection_Table
{
    int state = Sy_B1;
    char symbol;
    int alternative = 0;
};
class Lex_Analyze
{
private:
    int size_ = 5;
    int Value_Word_Lexems = 0;
    int size_array_ = 5;
    void See_number(int number_line = 0, int number_lex = 0, string Lex_ = "", std::variant<int, Vector>* Table = 0);

    SymbolicToken transliterator(int ch);

    Lexeme* Inc_size(Lexeme* Table);

    int* Inc_arr(int* arr, int size_a);

    void Initial_Vect(Initial_vector* vec_);

    void Detection_Tab(Detection_Table* table_);


public:
    int count_word()
    {
        return Value_Word_Lexems;
    }
    void Print_Table_Lexem(Lexeme* Table);
    Lexeme* Lexical_analyzer(const char* filename);
};