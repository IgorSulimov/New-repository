#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <stack>
#include "Vector.hpp"
using namespace std;
int size_ = 5;
int Warning = 0;
// Перечисление содержит константы для обозначения классов символьных лексем: ЦИФРА, ЗНАК, ПРОБЕЛ, ОШИБКА, КОНЕЦ.
enum Symbol_icTokenClass { Symbol_, Digit_, Arithmetic_, Comparison_, EndOfLine_, Semicolon_, Space_, LeftBracket_, RightBracke_t, Comma_, Error_, EndOfFile_ };

// Перечисление содержит константы для обозначения состояний автомата и одну дополнительную константу Stop_.
enum States_ {
    A1_, /*начало*/
    Sy_B1_, /*все лексемы*/
    Sy_D8, Sy_D2_, /*Константа*/
    Sy_E4, Sy_F4, /*Числа*/
    Sy_E5,
    Ar_B1, /*проверка до ;*/
    Co_B2_, /* < >*/
    Sy_Z1_, /* pop */
    Sy_Z2_, /*write*/
    Sy_Z3_, /*read*/
    Sy_Z4_, /*end*/
    Sy_Z5_, /*jmp*/
    Sy_Z6, /*push*/
    Sy_E2_, /*push x || push 1*/
    Sy_Z7,/*shiftl*/
    Sy_Z8, /*shiftr*/
    Sy_Z9, /*+,-,%,>=,<=.....*/
    Sy_Z1_0,/*ji*/
    Sy_Z1_1,/*subvec*/
    Sy_Z1_2,/*concat*/
    Sy_L1_, /*lable*/
    VectorStart,    // Начало вектора
    VectorNumber,   // Число в векторе
    VectorComma_,    // Запятая в векторе
    VectorEnd,       // Конец вектора
    Stop_
};

// Структура для представления символьной лексемы.
struct Symbol_icToken
{
    Symbol_icTokenClass token_class; // Класс лексемы.
    int value;                      // Значение лексемы.
    char value_c;

};
//Word:
// push число = 1
// push значение = 2
// pop = 3
// write = 4
// read = 5
// end = 6
// ji = 7
// jmp = 8
// == = 9
// != = 10
// >= = 11
// <= = 12
// + = 13
// - = 14
// * = 15
// % = 16
// / = 17
// > = 18
// < = 19
// shiftr = 20
// shiftl =21
// concat = 22
// subvec = 23
// ; = 24
// & = 25
// push = 26 вектор
// lable = 27
struct Lexeme_
{

    int number_line = 0;
    vector<int> Word;
    int value_int;
    string value_char;
    vector<int> value_vector; // Добавить это поле
    int int_or_char = -1; // 0-символ, 1-цифра, 2-вектор

};


void See_number(int number)
{
    if (number == 1)
        cout << "push";
    if (number == 2)
        cout << "push";
    if (number == 3)
        cout << "pop";
    if (number == 4)
        cout << "write";
    if (number == 5)
        cout << "read";
    if (number == 6)
        cout << "end";
    if (number == 7)
        cout << "ji";
    if (number == 8)
        cout << "jmp";
    if (number == 9)
        cout << "==";
    if (number == 10)
        cout << "!=";
    if (number == 11)
        cout << ">=";
    if (number == 12)
        cout << "<=";
    if (number == 13)
        cout << "+";
    if (number == 14)
        cout << "-";
    if (number == 15)
        cout << "*";
    if (number == 16)
        cout << "%";
    if (number == 17)
        cout << "/";
    if (number == 18)
        cout << ">";
    if (number == 19)
        cout << "<";
    if (number == 20)
        cout << "shiftr";
    if (number == 21)
        cout << "shiftl";
    if (number == 22)
        cout << "concat";
    if (number == 23)
        cout << "subvec";
    if (number == 24)
        cout << ";";
    if (number == 25)
        cout << "&";
    if (number == 26)
        cout << "push";
    if (number == 27)
        cout << "lable";
}

void Print_Table_Lex(Lexeme_* Table)
{
    cout << left << setw(10) << "Номер" << setw(10) << "Лексема" << right << setw(10) << "Значение" << endl;
    for (int i = 0; i < size_; i++)
    {
        if (Table[i].int_or_char == 0)
        {
            cout << left << setw(10) << Table[i].number_line << right << setw(15);
            for (int j = 0; j < Table[i].Word.size(); j++)
            {
                cout << left << setw(1);
                See_number(Table[i].Word[j]);
            }
            cout << right << setw(8);
            cout << " " << right << setw(5);
            cout << Table[i].value_char << endl;
        }
        else if (Table[i].int_or_char == 1)
        {
            cout << left << setw(10) << Table[i].number_line << right << setw(15);
            for (int j = 0; j < Table[i].Word.size(); j++)
            {
                cout << left << setw(1);
                See_number(Table[i].Word[j]);
            }
            cout << right << setw(8);
            cout << " " << right << setw(5);
            cout << Table[i].value_int << endl;
        }
        else if (Table[i].int_or_char == 2)
        {
            cout << left << setw(10) << Table[i].number_line << right << setw(15);
            for (int j = 0; j < Table[i].Word.size(); j++)
            {
                cout << left << setw(1);
                See_number(Table[i].Word[j]);
            }
            cout << right << setw(8);
            cout << " " << right << setw(5);
            cout << "[";
            for (size_t k = 0; k < Table[i].value_vector.size(); k++)
            {
                cout << Table[i].value_vector[k];
                if (k < Table[i].value_vector.size() - 1)
                    cout << ",";
            }
            cout << "]" << endl;
        }
        else
        {
            cout << left << setw(10) << Table[i].number_line << right << setw(15);
            for (int j = 0; j < Table[i].Word.size(); j++)
            {
                cout << left << setw(1);
                See_number(Table[i].Word[j]);
            }
            cout << endl;
        }
    }
}



Symbol_icToken transliterator(int ch)
{
    Symbol_icToken s;
    s.value = 0;

    if (isdigit(ch))
    {
        s.token_class = Digit_;
        s.value = ch - '0';
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/' || ch == '&')
    {
        s.token_class = Arithmetic_;
    }
    else if (ch == '=' || ch == '!' || ch == '<' || ch == '>')
    {
        s.token_class = Comparison_;
    }
    else if (ch == ' ' || ch == '\t')
    {
        s.token_class = Space_;
    }
    else if (ch == '\n')
    {
        s.token_class = EndOfLine_;
    }
    else if (ch == ';')
    {
        s.token_class = Semicolon_;
    }
    else if (ch == EOF)
    {
        s.token_class = EndOfFile_;
    }
    else if (ch >= 'A' && ch <= 'z' && ch != '[' && ch != ']' && ch != ',')
    {
        s.token_class = Symbol_;
        s.value_c = ch;
    }
    else if (ch == '[') {
        s.token_class = LeftBracket_;
    }
    else if (ch == ']') {
        s.token_class = RightBracke_t;
    }
    else if (ch == ',') {
        s.token_class = Comma_;
    }
    else
    {
        s.token_class = Error_;
    }
    return s;
}


Lexeme_* Inc_size(Lexeme_* Table)
{
    Lexeme_* New_Table = new Lexeme_[size_ * 2];
    for (int i = 0; i < size_; i++)
    {
        New_Table[i].int_or_char = Table[i].int_or_char;
        New_Table[i].Word = Table[i].Word;
        New_Table[i].number_line = Table[i].number_line;
        New_Table[i].value_char = Table[i].value_char;
        New_Table[i].value_int = Table[i].value_int;
        New_Table[i].value_vector = Table[i].value_vector;
    }
    size_ *= 2;
    delete[] Table;
    Table = New_Table;
    return Table;
}

struct Initial_vector_
{
    char Symbol_;
    int detection;
};
void Initial_Vect(Initial_vector_* vec_)
{
    vec_[0].Symbol_ = 'p';
    vec_[0].detection = 6;
    vec_[1].Symbol_ = 'w';
    vec_[1].detection = 14;
    vec_[2].Symbol_ = 'r';
    vec_[2].detection = 11;
    vec_[3].Symbol_ = 'e';
    vec_[3].detection = 1;
    vec_[4].Symbol_ = 'j';
    vec_[4].detection = 3;
    vec_[5].Symbol_ = 's';
    vec_[5].detection = 23;
    vec_[6].Symbol_ = 'c';
    vec_[6].detection = 18;
    vec_[7].Symbol_ = 'l';
    vec_[7].detection = 34;
}
struct Detection_Table_
{
    int state = Sy_B1_;
    char Symbol_;
    int alternative = 0;
};

void Detection_Tab(Detection_Table_* table_)
{
    table_[0].state = Error_;
    table_[1].Symbol_ = 'n';
    table_[2].Symbol_ = 'd';
    table_[2].state = Sy_Z4_;
    table_[3].Symbol_ = 'i';
    table_[3].state = Sy_Z1_0;//Sy_L2_
    table_[3].alternative = 4;
    table_[4].Symbol_ = 'm';
    table_[5].Symbol_ = 'p';
    table_[5].state = Sy_Z5_; //Sy_L2_
    table_[6].Symbol_ = 'o';
    table_[6].alternative = 8;
    table_[7].Symbol_ = 'p';
    table_[7].state = Sy_Z1_;
    table_[8].Symbol_ = 'u';
    table_[9].Symbol_ = 's';
    table_[10].Symbol_ = 'h';
    table_[10].state = Sy_Z6;
    table_[11].Symbol_ = 'e';
    table_[12].Symbol_ = 'a';
    table_[13].Symbol_ = 'd';
    table_[13].state = Sy_Z3_;
    table_[14].Symbol_ = 'r';
    table_[15].Symbol_ = 'i';
    table_[16].Symbol_ = 't';
    table_[17].Symbol_ = 'e';
    table_[17].state = Sy_Z2_;
    table_[18].Symbol_ = 'o';
    table_[19].Symbol_ = 'n';
    table_[20].Symbol_ = 'c';
    table_[21].Symbol_ = 'a';
    table_[22].Symbol_ = 't';
    table_[22].state = Sy_Z1_2;
    table_[23].Symbol_ = 'h';
    table_[23].alternative = 29;
    table_[24].Symbol_ = 'i';
    table_[25].Symbol_ = 'f';
    table_[26].Symbol_ = 't';
    table_[27].Symbol_ = 'l';
    table_[27].state = Sy_Z7;
    table_[27].alternative = 28;
    table_[28].Symbol_ = 'r';
    table_[28].state = Sy_Z8;
    table_[29].Symbol_ = 'u';
    table_[30].Symbol_ = 'b';
    table_[31].Symbol_ = 'v';
    table_[32].Symbol_ = 'e';
    table_[33].Symbol_ = 'c';
    table_[33].state = Sy_Z1_1;
    table_[34].Symbol_ = 'a';
    table_[35].Symbol_ = 'b';
    table_[36].Symbol_ = 'l';
    table_[37].Symbol_ = 'e';
    table_[37].state = Sy_L1_;

}
Lexeme_* Lexical_analyzer_(const char* filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "Не удалось открыть файл " << filename << endl;
    }
    int count_line = 0;
    Initial_vector_ vec_[8];
    Initial_Vect(vec_);
    Detection_Table_ table_2[38];
    Detection_Tab(table_2);
    Lexeme_* Table_Of_Lexeme_s = new Lexeme_[size_];
    int ch;
    string Lex;
    Symbol_icToken s;
    int detection = 0;
    int alternative = 0;
    int state = A1_;
    string number_c = "";
    bool stop = false;
    while (!stop)
    {
        ch = in.get();
        s = transliterator(ch);
        switch (state)
        {
        case A1_:
            Table_Of_Lexeme_s[count_line].number_line = count_line + 1;
            switch (s.token_class)
            {
            case Symbol_:
                Lex += ch;
                for (int j = 0; j < 8; j++)
                {
                    if (ch == vec_[j].Symbol_)
                    {
                        state = Sy_B1_;
                        detection = vec_[j].detection;
                        break;
                    }
                }
                if (state != Sy_B1_)
                {
                    state = Stop_;
                    break;
                }
                break;
            case Arithmetic_:
                state = Sy_Z9;
                Lex += ch;
                break;

            case Space_:
                break;

            case Semicolon_:
                while (ch != '\n' && ch != EOF)
                    ch = in.get();
                Table_Of_Lexeme_s[count_line].Word.push_back(24);
                if (ch == EOF)
                    stop = true;
                else
                {
                    if (count_line >= size_ - 1)
                        Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                    count_line++;
                }
                state = A1_;
                Lex = "";
                break;

            case Comparison_:
                Lex += ch;
                state = Co_B2_;
                break;

            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_B1_:
        {
            switch (s.token_class)
            {
            case Symbol_:
            {
                while (detection != 0)
                {
                    if (ch == table_2[detection].Symbol_)
                    {
                        state = table_2[detection].state;
                        detection++;
                        break;
                    }
                    else
                    {
                        detection = table_2[detection].alternative;
                    }
                }
            }
            break;
            default:
                state = Stop_;
                break;
            }
        }
        break;
        case Sy_Z9:
            int zn;
            if (Lex == "&")
                zn = 25;
            if (Lex == "+")
                zn = 13;
            if (Lex == "-")
                zn = 14;
            if (Lex == "*")
                zn = 15;
            if (Lex == "%")
                zn = 16;
            if (Lex == "/")
                zn = 17;
            if (Lex == "==")
                zn = 9;
            if (Lex == ">=")
                zn = 11;
            if (Lex == "<=")
                zn = 12;
            if (Lex == "!=")
                zn = 10;
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(zn);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(zn);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(zn);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Co_B2_: // >= <= !=
            int zn_;
            if (Lex == ">")
                zn_ = 18;
            if (Lex == "<")
                zn_ = 19;
            switch (s.token_class)
            {
            case Comparison_:
                if (ch == '=')
                {
                    Lex += ch;
                    state = Sy_Z9;
                }
                break;
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(zn_);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(zn_);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case Ar_B1: // +-*/%
            switch (s.token_class)
            {
            case Space_:
                state = Ar_B1;
                break;
            case EndOfLine_:
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case Semicolon_:
                while (ch != '\n' && ch != EOF)
                    ch = in.get();
                Table_Of_Lexeme_s[count_line].Word.push_back(24);
                if (ch == EOF)
                {
                    stop = true;
                }
                else
                {
                    if (count_line >= size_ - 1)
                        Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                    count_line++;
                }
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z6:
            switch (s.token_class)
            {
            case Space_:
                state = Sy_E2_;
                break;
            case EndOfLine_:
                state = Error_;
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_E2_: //push
            switch (s.token_class)
            {
            case Space_:
                break;

            case Symbol_:
                Table_Of_Lexeme_s[count_line].Word.push_back(2);
                Table_Of_Lexeme_s[count_line].int_or_char = 0;
                state = Sy_D8;
                number_c = ch;
                break;
            case Digit_:
                Table_Of_Lexeme_s[count_line].Word.push_back(1);
                Table_Of_Lexeme_s[count_line].int_or_char = 1;
                Table_Of_Lexeme_s[count_line].value_int = s.value;
                state = Sy_F4;
                break;
                // Обработка вектора
            case LeftBracket_:
                Table_Of_Lexeme_s[count_line].Word.push_back(26); // Новый код для push вектора
                Table_Of_Lexeme_s[count_line].int_or_char = 2; // 2 - признак вектора
                state = VectorStart;
                break;
            case EndOfLine_:
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case VectorStart:
            switch (s.token_class) {
            case Digit_:
                Table_Of_Lexeme_s[count_line].value_vector.push_back(s.value);
                state = VectorNumber;
                break;
            case RightBracke_t: // пустой вектор
                state = VectorEnd;
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case VectorNumber:
            switch (s.token_class) {
            case Digit_:
                Table_Of_Lexeme_s[count_line].value_vector.back() =
                    Table_Of_Lexeme_s[count_line].value_vector.back() * 10 + s.value;
                break;
            case Comma_:
                state = VectorComma_;
                break;
            case RightBracke_t:
                state = VectorEnd;
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case VectorComma_:
            switch (s.token_class) {
            case Digit_:
                Table_Of_Lexeme_s[count_line].value_vector.push_back(s.value);
                state = VectorNumber;
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case VectorEnd:
            switch (s.token_class) {
            case Space_:
                state = Ar_B1;
                break;
            case EndOfLine_:
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case Sy_Z1_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(3);
                state = Sy_D2_;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(3);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(3);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_D2_:
            switch (s.token_class)
            {
            case Space_:
                break;
            case Symbol_:

                Table_Of_Lexeme_s[count_line].int_or_char = 0;
                number_c = s.value_c;
                state = Sy_D8;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_D8:
            switch (s.token_class)
            {
            case Space_:
                for (int j = 0, i = 0; j < 7; j++)
                {
                    if (number_c[i] == vec_[j].Symbol_)
                    {
                        detection = vec_[j].detection;
                        j = 7;
                        i++;
                        while (detection != 0 && detection != 2 && detection != 3 && detection != 5 && detection != 7 && detection != 10 && detection != 13 && detection != 17 && detection != 22 && detection != 27 && detection != 28 && detection != 33)
                        {
                            if (number_c[i] == table_2[detection].Symbol_)
                            {
                                detection++;
                                i++;
                            }
                            else
                            {
                                detection = table_2[detection].alternative;
                            }
                        }
                        if (detection == 0)
                        {
                            Table_Of_Lexeme_s[count_line].value_char = number_c;
                            state = Ar_B1;
                            Lex = "";
                            break;
                        }
                        else
                        {
                            if (number_c.size() <= i + 1)
                            {
                                state = Stop_;
                                break;
                            }
                            else
                            {
                                Table_Of_Lexeme_s[count_line].value_char = number_c;
                                state = Ar_B1;
                                Lex = "";
                                break;
                            }
                        }
                    }
                }
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                number_c = "";
                state = Ar_B1;
                Lex = "";
                break;
            case EndOfLine_:
                for (int j = 0, i = 0; j < 7; j++)
                {
                    if (number_c[i] == vec_[j].Symbol_)
                    {
                        detection = vec_[j].detection;
                        j = 7;
                        i++;
                        while (detection != 0 && detection != 2 && detection != 3 && detection != 5 && detection != 7 && detection != 10 && detection != 13 && detection != 17 && detection != 22 && detection != 27 && detection != 28 && detection != 33)
                        {
                            if (number_c[i] == table_2[detection].Symbol_)
                            {
                                detection++;
                                i++;
                            }
                            else
                            {
                                detection = table_2[detection].alternative;
                            }
                        }
                        if (detection == 0)
                        {
                            Table_Of_Lexeme_s[count_line].value_char = number_c;
                            state = A1_;
                            Lex = "";
                            break;
                        }
                        else
                        {
                            if (number_c.size() <= i + 1)
                            {
                                state = Stop_;
                                if (count_line >= size_ - 1)
                                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                                count_line++;
                                break;
                            }
                            else
                            {
                                Table_Of_Lexeme_s[count_line].value_char = number_c;
                                state = A1_;
                                Lex = "";
                                break;
                            }
                        }
                    }
                }
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                state = A1_;
                Lex = "";
                number_c = "";
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                break;
            case EndOfFile_:
                for (int j = 0, i = 0; j < 7; j++)
                {
                    if (number_c[i] == vec_[j].Symbol_)
                    {
                        detection = vec_[j].detection;
                        j = 7;
                        i++;
                        while (detection != 0 && detection != 2 && detection != 3 && detection != 5 && detection != 7 && detection != 10 && detection != 13 && detection != 17 && detection != 22 && detection != 27 && detection != 28 && detection != 33)
                        {
                            if (number_c[i] == table_2[detection].Symbol_)
                            {
                                detection++;
                                i++;
                            }
                            else
                            {
                                detection = table_2[detection].alternative;
                            }
                        }
                        if (detection == 0)
                        {
                            Table_Of_Lexeme_s[count_line].value_char = number_c;
                            state = A1_;
                            Lex = "";
                            break;
                        }
                        else
                        {
                            if (number_c.size() <= i + 1)
                            {
                                state = Stop_;
                                break;
                            }
                            else
                            {
                                Table_Of_Lexeme_s[count_line].value_char = number_c;
                                state = A1_;
                                Lex = "";
                                break;
                            }
                        }
                    }
                }
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                state = A1_;
                Lex = "";
                break;
                break;
            case Symbol_:
                number_c += ch;
                break;
            case Digit_:
                number_c += ch;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z2_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(4);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(4);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(4);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z3_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(5);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(5);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(5);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_E4:
            switch (s.token_class)
            {
            case Space_:
                state = Sy_E4;
                break;
            case Digit_:
                Table_Of_Lexeme_s[count_line].int_or_char = 1;
                Table_Of_Lexeme_s[count_line].value_int = s.value;
                state = Sy_F4;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_F4:
            switch (s.token_class)
            {
            case Space_:
                state = Ar_B1;
                break;
            case Digit_:
                Table_Of_Lexeme_s[count_line].value_int = Table_Of_Lexeme_s[count_line].value_int * 10 + s.value;
                break;
            case EndOfLine_:
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z4_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(6);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(6);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(6);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_E5:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].int_or_char = 0;
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                state = A1_;
                number_c = "";
                Lex = "";
                break;
            case Digit_:
                number_c += ch;
                state = Sy_E5;
                break;
            case Symbol_:
                number_c += ch;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].int_or_char = 0;
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                state = A1_;
                count_line++;
                number_c = "";
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].int_or_char = 0;
                Table_Of_Lexeme_s[count_line].value_char = number_c;
                state = A1_;
                number_c = "";
                Lex = "";
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z1_1:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(23);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(23);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(23);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z1_2:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(22);
                state = Ar_B1;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(22);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(22);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z5_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(8);
                state = Sy_E5;
                break;

            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z1_0:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(7);
                state = Sy_E5;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_L1_:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(27);
                state = Sy_E5;
                break;

            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z7:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(21);
                state = Sy_E4;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(21);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(21);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;
        case Sy_Z8:
            switch (s.token_class)
            {
            case Space_:
                Table_Of_Lexeme_s[count_line].Word.push_back(20);
                state = Sy_E4;
                break;
            case EndOfLine_:
                Table_Of_Lexeme_s[count_line].Word.push_back(20);
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
                state = A1_;
                Lex = "";
                break;
            case EndOfFile_:
                Table_Of_Lexeme_s[count_line].Word.push_back(20);
                stop = true;
                break;
            default:
                state = Stop_;
                break;
            }
            break;

        case Stop_:
            cout << "Обнаружена ошибка в строке №" << count_line + 1 << endl;
            Warning = 1;
            while (ch != '\n' && ch != EOF)
                ch = in.get();
            if (ch == EOF)
            {
                stop = true;
            }
            else
            {
                if (count_line >= size_ - 1)
                    Table_Of_Lexeme_s = Inc_size(Table_Of_Lexeme_s);
                count_line++;
            }
            state = A1_;
            Lex = "";
            break;
        }
    }
    size_ = count_line;
    return Table_Of_Lexeme_s;
    in.close();
}

struct Variable
{
    string name = "";
    int type = -1;
    int integer_value;
    Vector vector_value;
};
void Interpreter_int(Lexeme_* Table_Lex)
{
    char ch = 0;
    stack<Variable> st;
    vector<Variable> vect_variable_mean;
    int line = 0;

    // Пропускаем пустые строки
    while (line < size_ && Table_Lex[line].Word.empty())
        line++;

    while (line < size_ && Table_Lex[line].Word.back() != 6)
    {
        if (Table_Lex[line].Word[0] == 5) // read
        {
            Variable value;
            if (cin.peek() == '[')
            {
                cin >> value.vector_value;
                value.type = 0; // вектор
                st.push(value);
            }
            else
            {
                cin >> value.integer_value;
                value.type = 1; // число
                st.push(value);
            }
            cin.ignore(); // игнорируем символ новой строки
            line++;
        }
        else if (Table_Lex[line].Word[0] == 1 || Table_Lex[line].Word[0] == 2) // push число или переменную
        {
            if (Table_Lex[line].int_or_char == 0) // переменная
            {
                bool found = false;
                for (int i = 0; i < vect_variable_mean.size(); i++)
                {
                    if (vect_variable_mean[i].name == Table_Lex[line].value_char)
                    {
                        st.push(vect_variable_mean[i]);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    Variable new_var;
                    new_var.name = Table_Lex[line].value_char;
                    new_var.type = -1; // неинициализированная переменная
                    st.push(new_var);
                }
            }
            else if (Table_Lex[line].int_or_char == 1) // число
            {
                Variable value;
                value.integer_value = Table_Lex[line].value_int;
                value.type = 1;
                st.push(value);
            }
            line++;

        }
        else if (Table_Lex[line].Word[0] == 3) // pop
        {
            if (!st.empty() && Table_Lex[line].int_or_char == 0)
            {
                Variable top_val = st.top();
                st.pop();

                bool found = false;
                for (int i = 0; i < vect_variable_mean.size(); i++)
                {
                    if (vect_variable_mean[i].name == Table_Lex[line].value_char)
                    {
                        vect_variable_mean[i] = top_val;
                        vect_variable_mean[i].name = Table_Lex[line].value_char;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    top_val.name = Table_Lex[line].value_char;
                    vect_variable_mean.push_back(top_val);
                }
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 7) // ji
        {
            string name_lable = Table_Lex[line].value_char;
            if (!st.empty() || Table_Lex[line].int_or_char == 0)
            {
                Variable val = st.top();
                st.pop();
                if (val.type == 1 && val.integer_value != 0)
                {
                    line = 0;
                    while (Table_Lex[line].Word[0] != 27 || Table_Lex[line].value_char != name_lable)
                    {
                        line++;
                    }
                    line++;
                }
                else
                {
                    line++;
                }
            }
        }
        else if (Table_Lex[line].Word[0] == 8) // jmp
        {
            string name_lable = Table_Lex[line].value_char;
            line = 0;
            while (Table_Lex[line].Word[0] != 27 || Table_Lex[line].value_char != name_lable)
            {
                line++;
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 27) // lable
        {
            line++;
        }
        else if (Table_Lex[line].Word[0] == 13 || Table_Lex[line].Word[0] == 14 ||
            Table_Lex[line].Word[0] == 15 || Table_Lex[line].Word[0] == 16 ||
            Table_Lex[line].Word[0] == 17 || Table_Lex[line].Word[0] == 25) // арифметические операции
        {
            if (st.size() >= 2)
            {
                Variable b = st.top(); st.pop();
                Variable a = st.top(); st.pop();
                Variable c;

                if (a.type == 1 && b.type == 1) // оба числа
                {
                    c.type = 1;
                    switch (Table_Lex[line].Word[0])
                    {
                    case 13: c.integer_value = a.integer_value + b.integer_value; break;
                    case 14: c.integer_value = a.integer_value - b.integer_value; break;
                    case 15: c.integer_value = a.integer_value * b.integer_value; break;
                    case 17:
                        if (b.integer_value == 0) {
                            cout << "Ошибка: деление на ноль" << endl;
                            c.integer_value = 0;
                        }
                        else {
                            c.integer_value = a.integer_value / b.integer_value;
                        }
                        break;
                    case 16:
                        if (b.integer_value == 0) {
                            cout << "Ошибка: деление на ноль" << endl;
                            c.integer_value = 0;
                        }
                        else {
                            c.integer_value = a.integer_value % b.integer_value;
                        }
                        break;
                    case 25: c.integer_value = a.integer_value & b.integer_value; break;
                    }
                    st.push(c);
                }
                else if (a.type == 0 && b.type == 0) // оба вектора
                {
                    c.type = 0;
                    switch (Table_Lex[line].Word[0])
                    {
                    case 13: c.vector_value = a.vector_value + b.vector_value; break;
                    case 14: c.vector_value = a.vector_value - b.vector_value; break;
                    case 15: c.vector_value = a.vector_value * b.vector_value; break;
                    case 17: c.vector_value = a.vector_value / b.vector_value; break;
                    case 16: c.vector_value = a.vector_value % b.vector_value; break;
                    case 25:
                        c.type = 1;
                        c.integer_value = a.vector_value & b.vector_value;
                        break;
                    }
                    st.push(c);
                }
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 9 || Table_Lex[line].Word[0] == 10 ||
            Table_Lex[line].Word[0] == 11 || Table_Lex[line].Word[0] == 12 ||
            Table_Lex[line].Word[0] == 18 || Table_Lex[line].Word[0] == 19) // операции ==,!=,>=,<=,>,<
        {
            Variable b = st.top(); st.pop();
            Variable a = st.top(); st.pop();
            Variable c;
            if (a.type == 1 && b.type == 1)
            {
                c.type = 1;
                switch (Table_Lex[line].Word[0])
                {
                case 9: c.integer_value = (a.integer_value == b.integer_value); break;
                case 10: c.integer_value = (a.integer_value != b.integer_value); break;
                case 11: c.integer_value = (a.integer_value >= b.integer_value); break;
                case 12: c.integer_value = (a.integer_value <= b.integer_value); break;
                case 18: c.integer_value = (a.integer_value > b.integer_value); break;
                case 19: c.integer_value = (a.integer_value < b.integer_value); break;
                }
                st.push(c);
            }
            line++;

        }
        else if (Table_Lex[line].Word[0] == 20 || Table_Lex[line].Word[0] == 21) // shift
        {
            if (!st.empty())
            {
                Variable shift = st.top(); st.pop();
                Variable c = st.top(); st.pop();
                if (Table_Lex[line].Word[0] == 20)
                    c.vector_value.Shift_right(shift.integer_value);
                else
                    c.vector_value.Shift_left(shift.integer_value);
                st.push(c);
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 22) // concat
        {
            if (st.size() >= 2)
            {
                Variable a = st.top(); st.pop();
                Variable b = st.top(); st.pop();
                if (a.type == 0 && b.type == 0)
                {
                    Variable c;
                    c.type = 0;
                    c.vector_value = b.vector_value.Concatenation(a.vector_value);
                    st.push(c);
                }
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 23) // subvec
        {
            if (st.size() >= 3)
            {
                Variable to = st.top(); st.pop();
                Variable from = st.top(); st.pop();
                Variable a = st.top(); st.pop();
                Variable c;
                c.type = 0;
                c.vector_value = a.vector_value.Subvector_Selection(from.integer_value, to.integer_value);
                st.push(c);
            }
            line++;
        }
        else if (Table_Lex[line].Word[0] == 26) // push вектора
        {
            Variable value;
            value.type = 0; // вектор

            // Создаем массив для инициализации вектора
            int* arr = new int[Table_Lex[line].value_vector.size()];
            for (size_t i = 0; i < Table_Lex[line].value_vector.size(); i++) {
                arr[i] = Table_Lex[line].value_vector[i];
            }

            value.vector_value = Vector(arr, Table_Lex[line].value_vector.size());
            delete[] arr;

            st.push(value);
            line++;
        }
        else if (Table_Lex[line].Word[0] == 4) // write
        {
            if (!st.empty())
            {
                Variable c = st.top(); st.pop();
                if (c.type == 0)
                    cout << c.vector_value << endl;
                else if (c.type == 1)
                    cout << c.integer_value << endl;
            }
            line++;
        }
        else
        {
            line++;
        }

        // Пропускаем пустые строки
        while (line < size_ && Table_Lex[line].Word.empty())
            line++;
    }
}