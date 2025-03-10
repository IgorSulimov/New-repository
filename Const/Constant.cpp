#include <iostream>
#include <fstream>
using namespace std;

// Перечисление содержит константы для обозначения классов символьных лексем: ЦИФРА, ЗНАК, ПРОБЕЛ, ОШИБКА, КОНЕЦ.
enum SymbolicTokenClass { Digit, Sign, Error,EndOfLine,Symbol_E,Dot, EndOfFile };

// Перечисление содержит константы для обозначения состояний автомата и одну дополнительную константу s_Stop.
enum States { q0, q1, q2, q3,q4,q5,q6, s_Stop,s_Er };

// Структура для представления символьной лексемы.
struct SymbolicToken
{
    SymbolicTokenClass token_class; // Класс лексемы.
    int value;                      // Значение лексемы.
};

// Глобальные переменные, используемые процедурами автомата.
SymbolicToken s;    // Символьная лексема.
int RZ = 1;           // Регистр знака.
double RCH; // Регистр числа.
double RS; // Регист счётчика
double RP; // Регистр порядка
string str;
/* Функция транслитерации.
 * ch - символ
 * Возвращаемое значение - результат транслитерации символа ch
 */
SymbolicToken transliterator(int ch)
{
    SymbolicToken s;
    s.value = 0;
    if (isdigit(ch))
    {
        s.token_class = Digit;
        s.value = ch - '0';
    }
    else if (ch == '+' || ch == '-' )
    {
        s.token_class = Sign;
        s.value = ch;
    }
    else if (ch == '\n')
    {
        s.token_class = EndOfLine;
    }
    else if (ch == '.')
    {
        s.token_class = Dot;
    }
    else if (ch == 'E')
    {
        s.token_class = Symbol_E;
    }
    else if (ch == EOF)
    {
        s.token_class = EndOfFile;
    }
    else
    {
        s.token_class = Error;
    }
    return s;
}

// Процедуры автомата (от A1 до Exit1).
int P1()
{
    RCH += s.value;
    return q1;
}

int P2()
{
    RCH = 0;
    RS = 0;
    return q0;
}
int P3()
{
    RCH = RCH * 10 + s.value;
    return q1;
}
int P4()
{
    RS = 0;
    return q3;
}
int P5()
{
    RS = 0;
    return q2;
}
int P6()
{
    RCH = RCH * 10 + s.value;
    RS++;
    return q2;
}
int P7()
{

    return q3;
}
int P8()
{
    RP += s.value;
    RZ = 1;
    return q5;
}
int P9()
{
    if (s.value == '-')
        RZ = 0;
    if (s.value == '+')
        RZ = 1;
    return q4;
}
int P10()
{
    RP = s.value;
    return q5;
}
int P11()
{
    RP = RP * 10 + s.value;
    return q5;
}
int P12()
{
    RCH = s.value;
    RS = 1;
    return q2;
}

int Error1()
{
    cout << "Строка: " << str << endl;
    cout << "Обнаружена ошибка" << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return s_Er;
}

int k1()
{
    cout << "Строка: " << str;
    cout << RCH << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return q0;
}
int k2()
{
    cout << "Строка: " << str;
    cout << (RCH) / pow(10, RS) << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return q0;
}
int k3()
{
    if (RZ == 0)
        RS += RP;
    else
        RS -= RP;
    cout << "Строка: " << str;
    cout << RCH / pow(10,RS) << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return q0;
}
int Exit1()
{
    cout << "Строка: " << str;
    cout << RCH << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return s_Stop;
}
int Exit2()
{
    cout << "Строка: " << str;
    cout << (RCH) / pow(10, RS) << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return s_Stop;
}
int Exit3()
{
    if (RZ == 0)
        RS += RP;
    else
        RS -= RP;
    cout << "Строка: " << str;
    cout << RCH / pow(10, RS) << endl << endl;
    str = "";
    RCH = 0;
    RS = 0;
    RP = 0;
    return s_Stop;
}
// Размеры таблицы автомата.
const int state_number = 10; // Число состояний (без s_Stop).
const int class_number = 10; // Число символов входного алфавита.

// Таблица указателей на процедуры автомата.
typedef int (*function_pointer)();
function_pointer table[state_number][class_number];

// Функция инициализации таблицы указателей на процедуры автомата.
void initialize_table()
{
    // Сначала во все ячейки заносится указатель на процедуру обработки ошибок.
    for (int i = 0; i < state_number; i++)
    {
        for (int j = 0; j < class_number; j++)
        {
            table[i][j] = Error1;
        }
    }
    // Далее заполняются ячейки для остальных процедур.
    table[q0][Digit] = P1; table[q0][Dot] = P2;
    table[q1][Digit] = P3; table[q1][Symbol_E] = P4; table[q1][Dot] = P5; table[q1][EndOfFile] = Exit1; table[q1][EndOfLine] = k1;
    table[q2][Digit] = P6; table[q2][Symbol_E] = P7; table[q2][EndOfFile] = Exit2; table[q2][EndOfLine] = k2;
    table[q3][Digit] = P8; table[q3][Sign] = P9;
    table[q4][Digit] = P10;
    table[q5][Digit] = P11; table[q5][EndOfFile] = Exit3; table[q5][EndOfLine] = k3;
    table[q6][Digit] = P12;

}

// Основная функция анализа. Функция запускает конечный автомат на тексте из файла filename.
void parse(const char* filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "Не удалось открыть файл " << filename << endl;
        return;
    }

    int ch;             // Входной символ.
    int state = q0;   // Текущее состояние автомата.
    while (state != s_Stop)
    {
        // s_Stop - техническое состояние. Когда автомат попадает в s_Stop, цикл останавливается.
        if (state == s_Er)
        {
            while (ch != '\n' && ch != EOF)
            {
                ch = in.get();
            }
            if (ch == EOF)
                break;
            state = q0;
        }
        ch = in.get();
        if (ch != EOF)
            str += ch;
        else
            str += '\n';
        s = transliterator(ch);
        state = (*table[state][s.token_class])();
    }

    in.close();
}

// Вызов программы имеет вид ./имя-исполняемого-файла имя-входного-файла.
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    // Поскольку автомат не меняется, то таблица инициализируется один раз.
    initialize_table();
    char file[] = "i.txt";
    parse(file);

    return 0;
}
